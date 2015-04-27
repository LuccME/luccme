-------------------------------------------------------------------------------------------
--LuccME - a framework for topdown land use change modeling.
--Copyright � 2009 - 2011 INPE.
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

function AllocationByOrdering (model)

	model.execute = function (self,event,model) 

------Global and Local Variables and Constants------
		local useLog = model.useLog
		local cs = model.cs
		local potential = model.potential		
		local cellarea = cs.cellArea
		local step = event:getTime() - model.startTime + 1;		
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
  		--Inicializa��o das demandas
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
		   	-- Crio o mapa de maiores probabilidades: simUse
	
			
			-- Ordena��o dos vetores de uso de acordo com as maiores probabilidades
			for ind, lu in  pairs( luTypes ) do	
				ord = Trajectory
				{
	    			target = cs,
	   				select = function(cell) return (cell.alloc ~= 1) end,
	    			greater = function(c, d) return c[lu.."_pot"] > d[lu.."_pot"] end
				 }

				 
				 --Sele��o de tantas c�lulas quanto forem necess�rias na demanda 
				 local j = 1
				 if dem[lu] == -1 then
				 	dem[lu] = demand:getCurrentDemand(model)
				 	dem[lu] = dem[lu][ind]
				 end
				 cs_size = #cs.cells
				 trj_size = #ord.cells	 
				 print ("demand", lu, dem[lu], "trajectory size",trj_size )
				 --table.foreach(ord.cells, print)
			
				 
 				 while (j < dem[lu]) and (j < (trj_size * cellarea))  do
				 	-- Este atributo ir� me indicar se a c�lula j� teve seu uso alocado ou n�o
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
				 -- Diferen�a total
				 diff = diff + math.abs(differences[lu])
			end
			if diff < maxdiffarea then
				allocation_ok = true
			end
 		if (allocation_ok == true) then  
 			--Atualizando os status de uso de cada uma das c�lulas se a demanda foi alocada corretamente
			for k,cell in pairs( cs.cells ) do			
 				--changeUse (cell,currentUse(cell,luTypes),toLU(cell.simUse,luTypes))
 				changeUse (cell,currentUse(cell,luTypes), cell.simUse)
 				cell.alloc = 0
 			end
      		print ("Demand allocated correctly in this time step:",step)
 			-- If the number of iteractions is larger than or equal to the maximum number of iteractions allowed
        else
        	print ("Demand not allocated correctly in this time step:", step)
        	os.exit();
        end      	
        
 	end -- end of 'execute' function started in line 28
 	
    model.verify = function (self,event)
	end

  return model
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

function toLU (lu, usetypes )
	for i, value in  pairs( usetypes ) do	
		if ( i == lu ) then
			return value
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

function changeUse(cell,cur_use, great_use)
	cell[cur_use] = 0
	cell[cur_use.."_out"] = 0
	cell[great_use] = 1
	cell[great_use.."_out"] = 1

	cell[great_use.."_change"] = 0
	if (cur_use ~= great_use) then 
	       cell[great_use.."_change"] = 1 
	       --print ("change ok  ", cur_use, great_use) 
	 end
	
end

function currentUse (cell, landuses)
	for i,land  in pairs( landuses ) do
		if ( cell[land] == 1 ) then
			return land
		end
	end
end

