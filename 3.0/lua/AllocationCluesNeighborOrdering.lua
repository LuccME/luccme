-------------------------------------------------------------------------------------------
--LuccME - a framework for topdown land use change modeling.
--Copyright © 2009 - 2011 INPE.
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

function AllocationCluesNeighborOrdering (model)

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
  		local numofcells  = table.getn(cs.cells)
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

		if self.potentilOrdering then
			self.potentilOrdering = false
			-- Pointers
			for k,cell in pairs( cs.cells ) do
				for i, lu in  pairs( luTypes ) do
					cell["ord_"..lu] = cell
				end
			end
			
			-- Ordenate pointers
			for k,cell in pairs( cs.cells ) do
				print("Ordenamento: "..(k/numofcells*100).."%")
				if k > 1 then
					for i, lu in  pairs( luTypes ) do
							j = k - 1
							upCell = rawget(cs.cells,j)
							Cell = rawget(cs.cells,k)
							potentialCell = (1 + Cell["ord_"..lu]["tau_"..lu]) * Cell["ord_"..lu]["suit_"..lu]
							potentialupCell = (1 + upCell["ord_"..lu]["tau_"..lu]) * upCell["ord_"..lu]["suit_"..lu]
							while (potentialCell > potentialupCell) do 
								
								aux = Cell["ord_"..lu]
								Cell["ord_"..lu] = upCell["ord_"..lu]
								upCell["ord_"..lu] = aux

								Cell = rawget(cs.cells,j)
								j = j - 1
								if j > 0 then 
									upCell = rawget(cs.cells,j)
									potentialupCell = (1 + upCell["ord_"..lu]["tau_"..lu]) * upCell["ord_"..lu]["suit_"..lu]
								else
									break
								end
							end
					end
				end
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
				--if (model.region == nil) then cell.region = 1 end
				
				for i, lu in  pairs( luTypes ) do	
						
						luind = toIndex(lu ,luTypes)
						lu_pastIndex = toIndex(lu_past ,luTypes)
						possibleTransitions = self.transitionMatrix[cell.region][lu_pastIndex][luind] 
						local suit_plus_iter = (1 + cell["ord_"..lu]["tau_"..lu]) * cell["ord_"..lu]["suit_"..lu] +  iteration[lu]
											
						if (possibleTransitions == 1)then 
							if ( suit_plus_iter > probMaior) then
								probMaior = suit_plus_iter
								lu_maior = lu
								Cell = cell["ord_"..lu]
							end 	    		   
						end
				end	-- end for land use/cover types
			
				luind = toIndex(lu_maior ,luTypes)		
				cell.simUse = luind
				changeUse (Cell,lu_past,lu_maior)
			end -- end for cell space
								  	
			local diff = calcDifferences (event, model)
			
			allocation_ok = convergency(cs,diff, luTypes, maxdiffarea )
			
			adjustIteration (cs, diff, luTypes, self.factorIteration, iteration, cellarea, maxdiffarea )
			
			nIter= nIter + 1;
				
			if (allocation_ok == true) then  
				print ("Demand allocated correctly in this time step:",step)
				
			-- If the number of iteractions is larger than or equal to the maximum number of iteractions allowed
			elseif	(nIter >= max_iteration) then 
				print ("Demand not allocated correctly in this time step:", step)
				os.exit();
			end      		
      	end -- end of 'while do' started in line 61
 	end -- end of 'execute' function started in line 28
  return model
end -- end of AllocationCluesLike

-- ____________________________________
--			AUXILIARY FUNCTIONS
--_____________________________________

function calcDifferences (event,model)
	
	local cs = model.cs
	
	local luTypes = model.landUseTypes
	local demand = model.demand
	local cellarea  = cs.cellArea			
	local tot_diff = 0.0
	local maxdiff = 0.0
	local differences = {}
	local time = event:getTime()
	
	for luind, land in pairs( luTypes) do
		areaAlloc = areaAllocated(cs,cellarea,land,1)
		dem = demand:getDemand(model,time,land)
		differences[land] = (dem[luind] - (areaAlloc))
		if useLog == true then
			print (land.." -> " ..areaAlloc.."\t\tdemanda -> "..dem[luind].." diferença -> "..differences[land]) 
		end
	end
	return differences
end

function adjustIteration (cs, diff, luTypes, faciter, iter, cellarea, maxdiffarea )	 		
	for luind, land in pairs( luTypes) do
		iter[land] = iter[land] + (diff[land] * faciter );
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

function changeUse(cell,cur_use, great_use)
	cell[cur_use] = 0;
	cell[great_use] = 1;
end

function currentUse (cell, landuses)
	for i,land  in pairs( landuses ) do
		if ( cell[land] == 1 ) then
			return land
		end
	end
end

-- Considers M and N are the dimensions the modeller wants to evaluate.
-- As an example if M and N are equal 1 then the function below takes into account 
-- and area enclosing 9 cells such as the Moore´s neighbourhood.
-- The 'filter' atribute is a function of f(cell) type that returns cell.uso == forest and	cell.pa == 0 then, 
-- in this case the are considered encloses the 8 adjacent cells as long as the attribute pa is equal 0
-- It can be useful, as example, to guarantee that a property (land parcel) does not invade a forbidden area protected by spatial policies.
function cellsBuffer (c, cs, M, N, filter)
	local f = filter or function (cell) return true end; 
	cells = {}
	if( N < 0) then N = 1; end
	if( M < 0) then M = 1; end
	local lin;
	local col;
	local i=0;   
	
	for lin = -N,N,1 do
		 for col = -M,M,1 do                   
			 local coord = Coord{ x = (c.x + col), y = (c.y + lin)};                   
			 cell_i = cs:getCell( coord );
			 if( cell_i ) then
				if  f(cell_i) then
					table.insert(cells, cell_i );
				end
			end
		end
	end   
	return cells
end
