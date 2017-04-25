-------------------------------------------------------------------------------------------
--LuccME - a framework for top-down land use change modelling.
--Copyright © 2009 - 2015 INPE.
--
--This code is part of the LuccME framework.
--This framework is a free software; you can redistribute and/or
--modify it under the terms of the GNU Lesser General Public
--License as published by the Free Software Foundation; either
--version 3 of the License, or (at your option) any later version.
--
--You should have received a copy of the GNU Lesser General Public
--License along with this library.
--
--The authors reassure the license terms regarding the warranties.
--They specifically disclaim any warranties, including, but not limited to,
--the implied warranties of merchantability and fitness for a particular purpose.
--The framework provided hereunder is on an "as is" basis, and the authors have no
--obligation to provide maintenance, support, updates, enhancements, or modifications.
--In no event shall INPE be held liable to any part for direct,
--indirect, special, incidental, or consequential damages arising out of the use
--of this library and its documentation.
--
-------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------t
function AllocationBySimpleOrdering (component)

	component.execute = function (self,event,model) 

	------Global and Local Variables and Constants------
		local useLog = model.useLog
		local cs = model.cs
		local potential = model.potential		
		local cellarea = cs.cellArea
		local step = event:getTime() - model.startTime + 1	
		local start = model.startTime		
  		local demand = model.demand
		local nIter = 0
  		local allocation_ok = false
  		local numofcells  = #cs.cells
  		local totarea = (numofcells * cellarea)
  		local maxdiffarea = (self.maxDifference * totarea)
  		local luTypes = model.landUseTypes
  		local dem = {}
  		local differences = {}
  	
	--Inicialização das demandas
	   	for ind, lu in  pairs( luTypes ) do	
 			dem[lu] = -1
 		end
  		----------------------------------------------------
  		print ("Time : ",event:getTime())
    	print ("Step : ",step)
		if useLog == true then
			print ("----------------------------------------------------------------------------------------")
			print ("Cell Area "..cellarea)
			print ("Num of cells "..numofcells)
			print ("Max diff area "..maxdiffarea)	 		
			----------------------------------------------------
			for landuse, ivalues in pairs( luTypes ) do         
				area = areaAllocated(cs,cellarea, luTypes[landuse],1) 
				print ("Initial area for land use : "..luTypes[landuse].." -> " ..area) 
			end		
			print ("----------------------------------------------------------------------------------------")
	   	end
	   	for k, cell in pairs( cs.cells ) do
					for luind, lu in  pairs( luTypes ) do
					    cell[lu.."_change"] = 0
					    cell[lu.."_out"] = cell[lu]
					 end
					 cell.alloc = 0
					 cell.simUse = currentUse(cell, luTypes)
        end

	
		diff = 0
			
			-- Ordenação dos vetores de uso de acordo com as maiores probabilidades
			for ind, lu in  pairs( luTypes ) do	
			  if (lu ~= model.landUseNoData) then 
				ord = Trajectory
				{
	    			target = cs,
	   				select = function(cell) return (cell.alloc ~= 1 and cell.simUse ~= model.landUseNoData) end,
	    			greater = function(c, d) return c[lu.."_pot"] > d[lu.."_pot"] end
				 }

				 
				 --Seleção de tantas células quanto forem necessárias na demanda 
				 local j = 1
				 if dem[lu] == -1 then
				 	dem[lu] = demand:getCurrentDemand(model)
				 	dem[lu] = dem[lu][ind]
				 end
				 cs_size = #cs.cells
				 trj_size =#ord.cells	 
				 print ("demand", lu, dem[lu], "trajectory size",trj_size )
			
 				 while (j <= dem[lu]) and (j <= (trj_size * cellarea))  do 
				 	-- Este atributo irá me indicar se a célula já teve seu uso alocado ou não
				 	ord.cells[j].alloc = 1
				 	ord.cells[j].simUse = lu
				 	j = j + 1 
				 end

				 -- Quantidade alocada do uso neste passo de tempo
			     areaAlloc = areaAllocated(ord, cellarea, "alloc", 1)
			     print ("areaAlloc", lu, areaAlloc)
				 differences[lu] = (dem[lu] - areaAlloc)
	
				 if differences[lu]> 0 then
				 	dem[lu] = differences[lu] 
				 else
				 	dem[lu] = 0
				 end
				 -- Diferença total
				 diff = diff + math.abs(differences[lu])
			end
		 end
		if diff < maxdiffarea then
				allocation_ok = true
		end
 		if (allocation_ok == true) then  
 			--Atualizando os status de uso de cada uma das células se a demanda foi alocada corretamente
			for k,cell in pairs( cs.cells ) do			
 				changeUse (cell,currentUse(cell,luTypes), cell.simUse)
 				cell.alloc = 0
 			end
      		print ("Demand allocated correctly in this time step:",step)
 			-- If the number of iterations is larger than or equal to the maximum number of iterations allowed
        else
        	print ("Demand not allocated correctly in this time step:", step)
        	os.exit();
        end      	
        
 	end -- end of 'execute' function started in line 28
 	
    component.verify = function (self,event)
	end

  return component
end -- end of AllocationCluesLike

-- ____________________________________
--			AUXILIARY FUNCTIONS
--_____________________________________
function areaAllocated (cs,cellarea, field, attr)
	c = 0
	forEachCell( cs, function( cell )
		if (cell[field] == attr) then 
			c = c + 1 	
		end
	end)
	return (c * cellarea)
end 

function toIndex (lu, usetypes )
	local index = 0 
	for i, value in  pairs( usetypes ) do
	
		if ( value == lu ) then
			index = i
			break
		end
		
	end
	return index
end
   
function initIteration(lutypes)
	local iteration = {}	
	for k,lu in pairs( lutypes ) do
		iteration[lu] = 0
	end
	return iteration
end

function changeUse(cell,cur_use, higher_use)
	cell[cur_use] = 0
	cell[cur_use.."_out"] = 0
	cell[higher_use] = 1
	cell[higher_use.."_out"] = 1
	cell[higher_use.."_change"] = 0
	cell[cur_use.."_change"] = 0  

	if (cur_use ~= higher_use) then 
	       cell[higher_use.."_change"] = 1 
	       cell[cur_use.."_change"] = -1 
	 end
end

function currentUse (cell, landuses)
	for i,land  in pairs( landuses ) do
		if ( cell[land] == 1 ) then
			return land
		end
	end
end
