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
-------------------------------------------------------------------------------------------
function AllocationClueSLike (component)

	component.execute = function (self,event,model) 

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
  		local max_iteration = self.maxIteration  
  		
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
		
	   	local iteration = initIteration(luTypes)
	   	
	   		for k, cell in pairs( cs.cells ) do
					for luind, lu in  pairs( luTypes ) do
					    cell[lu.."_change"] = 0
					    cell[lu.."_out"] = cell[lu]
					 end
	       end
	   	
		while ((nIter <= max_iteration) and (allocation_ok == false) ) do	
			if useLog == true then
				print ("\nStep -> "..step.." Iteration -> "..nIter)
			end	
			for k,cell in pairs( cs.cells ) do
			
				local lu_past = currentUse(cell,luTypes);
				local lu_maior = lu_past;
				local probMaior = -999999999
				local maxLuNeigh
				if (cell.region == nil) then cell.region = 1 end
				
				for i, lu in  pairs( luTypes ) do	
						
						luind = toIndex(lu ,luTypes)
						lu_pastIndex = toIndex(lu_past ,luTypes)
						possibleTransitions = self.transitionMatrix[cell.region][lu_pastIndex][luind]
						
						-- POTENTIAL WITH ATTRACTION/REPULSION FACTOR "TAU"
						if cell["tau_"..lu] == nil then
							cell["tau_"..lu] = 0
						end
						
						local pot_plus_iter = (1 + cell["tau_"..lu]) * cell[lu.."_pot"] +  iteration[lu]

						if (possibleTransitions == 1)then 
							if ( pot_plus_iter > probMaior) then
								probMaior = pot_plus_iter
								lu_maior = lu
							end 	    		   
						end
				end	-- end for land use/cover types
			
				luind = toIndex(lu_maior ,luTypes)

				cell.simUse = luind
				changeUse (cell,lu_past,lu_maior)
			end -- end for cell space
								  	
			local diff = calcDifferences (event, model)
			
			allocation_ok = convergency(cs,diff, luTypes, maxdiffarea )
			
			adjustIteration (cs, diff, luTypes, self.factorIteration, iteration, cellarea, maxdiffarea )
			
			nIter= nIter + 1
	      		
			if (allocation_ok == true) then  
			
      			print ("Demand allocated correctly in this time step:",step)
      			
			-- If the number of iterations is larger than or equal to the maximum number of iterations allowed
       		elseif	(nIter >= max_iteration) then 
       			print ("Demand not allocated correctly in this time step:", step)
       			os.exit();
       		end      		
      	end -- end of 'while do' started in line 61
 	end -- end of 'execute' function started in line 28
 	
 	component.verify = function (self,event)
	end

	return component
end -- end of AllocationCluesLike

-- ____________________________________
--			AUXILIARY FUNCTIONS
--_____________________________________

function calcDifferences (event,component)
	local cs = component.cs
	local luTypes = component.landUseTypes
	local demand = component.demand
	local cellarea  = cs.cellArea			
	local tot_diff = 0.0
	local maxdiff = 0.0
	local differences = {}
	local time = event:getTime()
	
	for luind, land in pairs( luTypes) do
		areaAlloc = areaAllocated(cs,cellarea,land,1)
		dem = demand:getCurrentLuDemand(luind)
		differences[land] = (dem - (areaAlloc))
		if component.useLog == true then
			print (land.." -> " ..areaAlloc.."\t\tdemanda -> "..dem.." diferença -> "..differences[land]) 
		end
	end
	return differences
end

function adjustIteration (cs, diff, luTypes, faciter, iter, cellarea, maxdiffarea )	 		
	for luind, land in pairs( luTypes) do
		iter[land] = iter[land] + (diff[land] * faciter )
	end
end
	
function convergency(cs,diff, luTypes, maxdiffarea )
					
	local tot_diff = 0.0
	local maxdiff = 0.0
	
	for luind, land in pairs( luTypes) do
		if ( (math.abs(diff[land])) > maxdiff) then maxdiff = (math.abs(diff[land])); end
	end
	if useLog == true then
		print ("\n  Maximum error of allocation : "..maxdiff.."  km²   Maximum permited error(km²) : "..maxdiffarea)
		print ("---------------------------------------------------------------------------------------------------------------------")
	end
	if (maxdiff <= maxdiffarea ) then
		return true
	else
		return false
	end
end

function areaAllocated (cs,cellarea, field,attr)
	local count = 0
	forEachCell( cs, function( cell )
		if (cell[field] == attr) then count = count + 1 end
	end)
	return (count*cellarea)
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
