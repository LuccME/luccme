--- Based on the process of competition among classes in the same cell, adjusted iteratively to reach the demand when all cells are considered, as described in Verburg et al. (2002)
-- based on the process of competition among classes in the same cell, adjusted iteratively to reach the demand when all cells are considered, as described in Verburg et al. (1999),
-- extended to incorporate new features, such as change in blocks (optional, parametrized by cell).
-- @arg component.maxIteration Limit of interactions trying to allocate the demand.
-- @arg component.factorIteration Initial value of the parameter which controls the allocation interaction factor.
-- @arg component.maxDifference Maximum difference between informed demand and demand allocated by the model.
-- @arg transitionMatrix Indicates the allowable (1) and  not allowable (0) transition in a landuse x landuse matrix.
-- Must have at least one region.
-- @arg component.execute Handles with the rules of the component execution.
-- @arg component.verify Handles with the parameters verification.
-- @usage allocation = AllocationClueSLike {
-- maxIteration = 1000,
-- factorIteration = 0.00001,
-- maxDifference = 0.01,
-- transitionMatrix = {	{ -- Region 1
--							{1, 0, 0},
--							{1, 1, 0},
--							{0, 0, 1}} -- end Region 1
-- }}
function AllocationClueSLike(component)
	--- Handles with the rules of the component execution.
	-- @arg self A AllocationClueSLike component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg component A AllocationClueSLike component with all data.
	-- @usage self.allocation:execute(event, model)
	component.execute = function(self, event, model)
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

  		print ("Time : ", event:getTime())
    	print ("Step : ", step)

		if useLog == true then
			print ("----------------------------------------------------------------------------------------")
			print ("Cell Area "..cellarea)
			print ("Num of cells "..numofcells)
			print ("Max diff area "..maxdiffarea)	 		
			----------------------------------------------------
			for landuse, ivalues in pairs (luTypes) do        
				area = self:areaAllocated(cs, cellarea, luTypes[landuse], 1)
				print ("Initial area for land use : "..luTypes[landuse].." -> " ..area)
			end		
			print ("----------------------------------------------------------------------------------------")
	   	end
		
	   	local iteration = self:initIteration(luTypes)
	   	
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
				local lu_past = self:currentUse(cell, luTypes)
				local lu_maior = lu_past
				local probMaior = -999999999
				local maxLuNeigh
				if (cell.region == nil) then
					cell.region = 1
				end
				
				for i, lu in  pairs (luTypes) do	
					luind = self:toIndex(lu, luTypes)
					lu_pastIndex = self:toIndex(lu_past, luTypes)
					possibleTransitions = self.transitionMatrix[cell.region][lu_pastIndex][luind]
					
					-- POTENTIAL WITH ATTRACTION/REPULSION FACTOR "TAU"
					if cell["tau_"..lu] == nil then
						cell["tau_"..lu] = 0
					end
					
					local pot_plus_iter = (1 + cell["tau_"..lu]) * cell[lu.."_pot"] +  iteration[lu]

					if (possibleTransitions == 1)then
						if (pot_plus_iter > probMaior) then
							probMaior = pot_plus_iter
							lu_maior = lu
						end 	    		  
					end
				end	-- end for land use/cover types
			
				luind = self:toIndex(lu_maior, luTypes)

				cell.simUse = luind
				self:changeUse(cell, lu_past, lu_maior)
			end -- end for cell space
								  	
			local diff = self:calcDifferences(event, model)
			
			allocation_ok = self:convergency(cs, diff, luTypes, maxdiffarea)
			
			self:adjustIteration(cs, diff, luTypes, self.factorIteration, iteration, cellarea, maxdiffarea)
			
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
 	component.verify = function(self, event, modelParameters)
    -- check maxIteration
    if (self.maxIteration == nil) then
      error("maxIteration variable is missing", 2)
    end 
    
    -- check factorIteration
    if (self.factorIteration == nil) then
      error("factorIteration variable is missing", 2)
    end  
    
    -- check maxDifference
    if (self.maxDifference == nil) then
      error("maxDifference variable is missing", 2)
    end 
    
    -- check transitionMatrix
    if (self.transitionMatrix == nil) then
      error("transitionMatrix is missing", 2)
    end    
    
    local regionsNumber = #self.transitionMatrix

    -- check number of Regions
    if (regionsNumber == nil or regionsNumber == 0) then
      error("The model must have at least One region", 2)
    else
      for i = 1, regionsNumber, 1 do
        local transitionNumber = #self.transitionMatrix[i]
        local lutNumber = #modelParameters.landUseTypes
        
        -- check the number of transitions
        if (transitionNumber ~= lutNumber) then
          error("Invalid number of transitions on Region number "..i..". Transitions: "..transitionNumber.." LandUseTypes: "..lutNumber, 2)
        end
        
        for j = 1, transitionNumber, 1 do
          for k = 1, lutNumber, 1 do  
            -- check the matrix values
            if(self.transitionMatrix[i][j][k] ~= 0 and self.transitionMatrix[i][j][k] ~= 1) then
              error("Invalid data on transitionMatrix: "..self.transitionMatrix[i][j][k]..". Region: "..i.. " Position: "..j.."x"..k..". The acceptable values are 0 or 1", 2)
            end
          end -- for k
        end -- for j
      end -- for i
    end -- else
	end -- verify

  --- Calculate the difference between the value of the demand and the value to be allocate.
  -- @arg event A representation of a time instant when the simulation engine must execute.
  -- @arg component A AllocationClueSLike component with all data.
  -- @usage diff = self.calcDifferences(event, model)
  component.calcDifferences = function(self, event, component)
    local cs = component.cs
    local luTypes = component.landUseTypes
    local demand = component.demand
    local cellarea = cs.cellArea      
    local tot_diff = 0.0
    local maxdiff = 0.0
    local differences = {}
    local time = event:getTime()
    
    for luind, land in pairs (luTypes) do
      areaAlloc = self:areaAllocated(cs, cellarea, land, 1)
      dem = demand:getCurrentLuDemand(luind)
      differences[land] = (dem - (areaAlloc))
      if component.useLog == true then
        print(land.." -> " ..areaAlloc.."\t\tdemanda -> "..dem.." diferença -> "..differences[land])
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
  component.adjustIteration = function(self, cs, diff, luTypes, faciter, iter, cellarea, maxdiffarea)    --@todo apagar? cs, cellarea, maxdiffarea 
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
  -- @usage allocation_ok = self:convergency(cs, diff, luTypes, maxdiffarea)
  component.convergency = function(self, cs, diff, luTypes, maxdiffarea) --@todo apagar? cs
    local tot_diff = 0.0
    local maxdiff = 0.0
    
    for luind, land in pairs (luTypes) do
      if ((math.abs(diff[land])) > maxdiff) then
        maxdiff = (math.abs(diff[land]))
      end
    end
    if useLog == true then
      print ("\n  Maximum error of allocation : "..maxdiff.."  km²   Maximum permited error(km²) : "..maxdiffarea)
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
  -- @usage areaAlloc = self:areaAllocated(cs, cellarea, land, 1)
  component.areaAllocated = function(self, cs, cellarea, field, attr)
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
  -- @usage luind = self:toIndex(lu, luTypes)
  component.toIndex = function(self, lu, usetypes)
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
  -- @usage iteration = self:initIteration(luTypes)
  component.initIteration = function(self, lutypes)
    local iteration = {}  
    for k, lu in pairs (lutypes) do
      iteration[lu] = 0
    end
    
    return iteration
  end

  --- Handles with the change of an use for a cell area.
  -- @arg cell A cell area.
  -- @arg cur_use The current use.
  -- @arg higher_use The new use XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
  -- @usage self:changeUse(cell, lu_past, lu_maior)
  component.changeUse = function(self, cell, cur_use, higher_use)
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
  
  --- Return the current use for a cell area.
  -- @arg cell A cell area.
  -- @arg landuses A set of land use types.
  -- @usage lu_past = self:currentUse(cell, luTypes)
  component.currentUse = function(self, cell, landuses)
    for i, land  in pairs (landuses) do
      if (cell[land] == 1) then
        return land
      end
    end
  end  

	return component
end -- end of AllocationCluesLike
