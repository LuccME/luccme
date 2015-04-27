--- Allocate the  land uses based on potential  calculated for each cell.
-- XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
-- @arg model.maxIteration Limit of interactions trying to allocate the demand.
-- @arg model.factorIteration Initial value of the parameter which controls the allocation interaction factor.
-- @arg model.maxDifference Maximum difference between informed demand and demand allocated by the model.
-- @arg transitionMatrix Indicates the allowable (1) and  not allowable (0) transition in a landuse x landuse matrix.
-- Must have at least one region.
-- @arg model.execute Handles with the rules of the component execution.
-- @arg model.verify Handles with the parameters verification.
-- @usage allocation = AllocationClueSLike {
-- maxIteration = 1000,
-- factorIteration = 0.00001,
-- maxDifference = 0.01,
-- transitionMatrix = {	{ -- Region 1
--							{1, 0, 0},
--							{1, 1, 0},
--							{0, 0, 1}} -- end Region 1
-- }}
function AllocationClueSLike(model)
	--- Handles with the rules of the component execution.
	-- @arg self A AllocationClueSLike component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg component A AllocationClueSLike component with all data.
	-- @usage self.allocation:execute(event, model)
	model.execute = function(self, event, component)
		------Global and Local Variables and Constants------
		local useLog = component.useLog
		local cs = component.cs
		local potential = component.potential		
		local cellarea = cs.cellArea
		local step = event:getTime() - component.startTime + 1;		
		local start = component.startTime		
  		local demand = component.demand
		local nIter = 0
  		local allocation_ok = false
  		local numofcells  = #cs.cells
  		local totarea = (numofcells * cellarea)
  		local maxdiffarea = (self.maxDifference * totarea)
  		local luTypes = component.landUseTypes
  		local max_iteration = self.maxIteration 
  		
  		----------------------------------------------------
  		print ("Time : ", event:getTime())
    	print ("Step : ", step)
		if useLog == true then
			print ("----------------------------------------------------------------------------------------")
			print ("Cell Area "..cellarea)
			print ("Num of cells "..numofcells)
			print ("Max diff area "..maxdiffarea)	 		
			----------------------------------------------------
			for landuse, ivalues in pairs (luTypes) do        
				area = areaAllocated(cs, cellarea, luTypes[landuse], 1)
				print ("Initial area for land use : "..luTypes[landuse].." -> " ..area)
			end		
			print ("----------------------------------------------------------------------------------------")
	   	end
		
	   	local iteration = initIteration(luTypes)
	   	
		for k, cell in pairs (cs.cells) do
			for luind, lu in  pairs (luTypes) do
				cell[lu.."_change"] = 0
				cell[lu.."_out"] = cell[lu]
			end
		end
	   	
		while ((nIter <= max_iteration) and (allocation_ok == false)) do	
			if useLog == true then
				print ("\nStep -> "..step.." Iteration -> "..nIter)
			end	
			for k, cell in pairs (cs.cells) do
				local lu_past = currentUse(cell, luTypes)
				local lu_maior = lu_past
				local probMaior = -999999999
				local maxLuNeigh
				if (component.region == nil) then
					cell.region = 1
				end
				
				for i, lu in  pairs (luTypes) do	
					luind = toIndex(lu, luTypes)
					lu_pastIndex = toIndex(lu_past, luTypes)
					possibleTransitions = self.transitionMatrix[cell.region][lu_pastIndex][luind]
					
					--local pot_plus_iter =  cell[lu.."_pot"] +  iteration[lu]
					
					-- POTENTIAL WITH ATTRACTION/REPULSION FACTOR "TAU"
					if cell["tau_"..lu] == nil then
						cell["tau_"..lu] = 0
					end
					
					local pot_plus_iter = (1 + cell["tau_"..lu]) * cell[lu.."_pot"] +  iteration[lu]
						--print("TAU: "..cell["tau_"..lu])				

					if (possibleTransitions == 1)then
						--print ("lu", lu, " regiao ", cell.region)
						if (pot_plus_iter > probMaior) then
							probMaior = pot_plus_iter
							lu_maior = lu
						end 	    		  
					end
				end	-- end for land use/cover types
			
				luind = toIndex(lu_maior, luTypes)

				cell.simUse = luind
				changeUse(cell, lu_past, lu_maior)
			end -- end for cell space
								  	
			local diff = calcDifferences(event, component)
			print("-----------------------")
			--table.foreach(diff, print)
			print("-----------------------")
			
			allocation_ok = convergency(cs, diff, luTypes, maxdiffarea)
			
			adjustIteration(cs, diff, luTypes, self.factorIteration, iteration, cellarea, maxdiffarea)
			
			nIter= nIter + 1
	      		
			if (allocation_ok == true) then 
      			print ("Demand allocated correctly in this time step:", step)
			-- If the number of iterations is larger than or equal to the maximum number of iterations allowed
       		elseif	(nIter >= max_iteration) then
       			print ("Demand not allocated correctly in this time step:", step)
       			os.exit();
       		end      		
      	end -- end of 'while do'
 	end -- end of 'execute'
 	
	--- Handles with the parameters verification.
	-- @arg self A allocationClueLike component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
	-- @usage self.allocation:verify(event, self)
 	model.verify = function(self, event)
	end

	return model
end -- end of AllocationCluesLike

-- ____________________________________
--			AUXILIARY FUNCTIONS
-- ____________________________________
--- Calculate the difference between the value of the demand and the value to be allocate.
-- @arg event A representation of a time instant when the simulation engine must execute.
-- @arg component A AllocationClueSLike component with all data.
-- @usage diff = calcDifferences (event, component)
function calcDifferences(event, component)
	local cs = component.cs
	local luTypes = component.landUseTypes
	local demand = component.demand
	local cellarea = cs.cellArea			
	local tot_diff = 0.0
	local maxdiff = 0.0
	local differences = {}
	local time = event:getTime()
	
	for luind, land in pairs (luTypes) do
		areaAlloc = areaAllocated(cs, cellarea, land, 1)
		dem = demand:getCurrentLuDemand(luind)
		differences[land] = (dem - (areaAlloc))
		if component.useLog == true then
			print(land.." -> " ..areaAlloc.."\t\tdemanda -> "..dem.." diferen�a -> "..differences[land])
		end
	end
	
	return differences
end

--- Modify for each land use the value of the cell area for an iteration.
-- @arg cs A multivalued set of Cells (Cell Space).
-- @arg diff XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
-- @arg luTypes A set of land uses types.
-- @arg faciter XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
-- @arg iter XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
-- @arg cellarea XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
-- @arg maxdiffarea XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
-- @usage adjustIteration(cs, diff, luTypes, self.factorIteration, iteration, cellarea, maxdiffarea)
function adjustIteration (cs, diff, luTypes, faciter, iter, cellarea, maxdiffarea)	 	--@todo apagar? cs, cellarea, maxdiffarea	
	for luind, land in pairs (luTypes) do
		iter[land] = iter[land] + (diff[land] * faciter)
	end
end

--- Handles with the allocation convergence based on maxdiffarea.
-- @arg cs A multivalued set of Cells (Cell Space).
-- @arg diff XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
-- @arg luTypes A set of land uses types.
-- @arg faciter XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
-- @arg maxdiffarea XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
-- @usage allocation_ok = convergency(cs, diff, luTypes, maxdiffarea)
function convergency(cs, diff, luTypes, maxdiffarea) --@todo apagar? cs
	local tot_diff = 0.0
	local maxdiff = 0.0
	
	for luind, land in pairs (luTypes) do
		if ((math.abs(diff[land])) > maxdiff) then
			maxdiff = (math.abs(diff[land]))
		end
	end
	if useLog == true then
		print ("\n  Maximum error of allocation : "..maxdiff.."  km�   Maximum permited error(km�) : "..maxdiffarea)
		print ("---------------------------------------------------------------------------------------------------------------------")
	end
	if (maxdiff <= maxdiffarea) then
		return true
	else
		return false
	end
end

--- Count the number of allocated areas.
-- @arg cs A multivalued set of Cells (Cell Space).
-- @arg cellarea A cell area.
-- @arg field The field to be checked (Columns name).
-- @arg attr The attribute to be checked.
-- @usage areaAlloc = areaAllocated(cs, cellarea, land, 1)
function areaAllocated(cs, cellarea, field, attr)
	local count = 0
	forEachCell(cs, function(cell)
						if (cell[field] == attr) then
							count = count + 1
						end
					end
				)
				
	return (count*cellarea)
end

--- Return an Index for a land use type in a set of land use types.
-- @arg lu A land use type.
-- @arg usetypes A set of land use type.
-- @usage luind = toIndex(lu, luTypes)
function toIndex(lu, usetypes)
	local index = 0
	for i, value in  pairs (usetypes) do
		if (value == lu) then
			index = i
			break
		end		
	end
	
	return index
end

--- Initialise the iteration vector for each land use type.
-- @arg lutype A set of land uses type.  
-- @usage iteration = initIteration(luTypes)
function initIteration(lutypes)
	local iteration = {}	
	for k, lu in pairs (lutypes) do
		iteration[lu] = 0
	end
	
	return iteration
end

--- Handles with the change of an use for a cell area.
-- @arg cell A cell area.
-- @arg cur_use The current use.
-- @arg great_use The new use XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
-- @usage changeUse(cell, lu_past, lu_maior)
function changeUse(cell, cur_use, great_use)
	cell[cur_use] = 0
	cell[cur_use.."_out"] = 0
	cell[great_use] = 1
	cell[great_use.."_out"] = 1

	cell[great_use.."_change"] = 0
	cell[cur_use.."_change"] = 0  --ANAP
	if (cur_use ~= great_use) then
	       cell[great_use.."_change"] = 1
	       cell[cur_use.."_change"] = -1 --ANAP
	      -- print ("change ok  ", cur_use, great_use)
	end
end

--- Return the current use for a cell area.
-- @arg cell A cell area.
-- @arg landuses A set of land use types.
-- @usage lu_past = currentUse(cell, luTypes)
function currentUse(cell, landuses)
	for i, land  in pairs (landuses) do
		if (cell[land] == 1) then
			return land
		end
	end
end

--- Considers M and N are the dimensions the component wants to evaluate.
-- As an example if M and N are equal 1 then the function below takes into account
-- and area enclosing 9 cells such as the Moore's neighbourhood.
-- The 'filter' attribute is a function of f(cell) type that returns cell.uso == forest and	cell.pa == 0 then,
-- in this case the are considered encloses the 8 adjacent cells as long as the attribute pa is equal 0.
-- It can be useful, as example, to guarantee that a property (land parcel) does not invade a forbidden area protected by spatial policies.
-- @arg c XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
-- @arg cs XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
-- @arg M XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
-- @arg N XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
-- @arg filter XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
-- @usage XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
function cellsBuffer(c, cs, M, N, filter)
	local f = filter or function (cell) return true end;
	cells = {}
	if(N < 0) then N = 1; end
	if(M < 0) then M = 1; end
	local lin;
	local col;
	local i=0;  
	
	for lin = -N, N, 1 do
		 for col = -M, M, 1 do                  
			 local coord = Coord{ x = (c.x + col), y = (c.y + lin)};                  
			 cell_i = cs:getCell(coord);
			 if(cell_i) then
				if  f(cell_i) then
					table.insert(cells, cell_i);
				end
			end
		end
	end  
	
	return cells
end