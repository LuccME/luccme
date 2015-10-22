--- Based on the process of competition among classes in the same cell, adjusted iteratively to reach the demand when all cells are considered, as described
-- in Verburg et al. (1999).  Cells receive a percentage of the annual change that must be allocated to the whole area, proportionally to their potential.  
-- In the case of deforestation, cells with a positive change potential will receive a percentage of the annual change that must be allocated to the whole 
-- area, proportionally to their potential. The INPE version differs from the original CLUE model as it was adapted for the Brazilian context, for instance
-- to represent the Forest Code and law enforcement (Aguiar, 2006). For instance, there are parameters to control the amount and speed of change that can 
-- happen in each cell.
-- @arg component.maxDifference Maximum allocation error allowed for each land use in area.
-- @arg component.maxIteration Maximum number of iterations at each time step of the model.
-- @arg component.initialElasticity Initial elasticity value (iterationFactor).
-- @arg component.minElasticity Minimum elasticity value which controls the allocation interaction factor. 
-- @arg component.maxElasticity Maximum elasticity value which controls the allocation interaction factor.
-- @arg component.complementarLU The land use which will be recomputed in the end to sum exactly 100%.
-- @arg component.allocationData A table with two allocation parameters for each land use.
-- @arg component.allocationData.static Indicates if the variable can increase or decrease in each cell, or only change in the direction of the demand.
-- @arg component.allocationData.minValue Minimum value allowed for the percentage of a given land use  in a cell (as a result of new changes -  the original 
-- value can be out of the limits )
-- @arg component.allocationData.maxValue Maximum value  allowed for the percentage of a given land use  in a cell (as a result of new changes - the original
-- value can be out of the limits )
-- @arg component.allocationData.minChange Minimum change in a given land use in a cell in a time step until (saturation) threshold.
-- @arg component.allocationData.maxChange Maximum change in a given land use allowed in a cell in a time step until (saturation) threshold.
-- @arg component.allocationData.changeLimiarValue Threshold (or limier) refers to a given amount of the land use in each cell.  After this limier, the speed
-- of change of a given land use in the cell is modified. 
-- @arg component.allocationData.maxChangeAboveLimiar Maximum change in a given land use allowed in a cell in a time step after (saturation) threshold.
-- @arg component.execute Handles with the rules of the component execution.
-- @arg component.verify Handles with the verify method of a AllocationClueLike component.
-- @arg component.initElasticity Handles with the elasticity initialize considering a single
-- elasticity for each land use (all cells).
-- @arg component.computeChange Compute the Allocation change based on the potential of the cell.
-- @arg component.compareAllocationToDemand Compares the demand to the amount of allocated land
-- use/cover, then adapts elasticity.
-- @arg component.correctCellChange Corrects total land use/cover types to 100 percent
-- @arg component.countAllocatedLandUseArea Calculates total area allocated by the regression
-- equations for each land use/cover type.
-- @arg component.printAllocatedArea Calculates and prints the allocated by the regression
-- equations for each land use/cover type.
-- @usage allocation = AllocationClueLike { maxDifference = 50, maxIteration = 3000,
-- initialElasticity = 0.1, minElasticity = 0.001, maxElasticity = 1.5,
-- complementarLU = "VegN_2000",
-- allocationData = {{static = -1, minValue = 0.2, maxValue = 0.8, minChange = 0, maxChange = 0.06, changeLimiarValue = 0.4, maxChangeAboveLimiar = 0.03},-- VEGN
--                 {static = 0, minValue = 0.0, maxValue = 1.0, minChange = 0, maxChange = 0.06, changeLimiarValue = 0.4, maxChangeAboveLimiar = 0.03}, -- AG
--                 {static = 0, minValue = 0.0, maxValue = 1.0, minChange = 0, maxChange = 0.06, changeLimiarValue = 0.4, maxChangeAboveLimiar = 0.03}, -- P
--               {static = 1, minValue = 0.0, maxValue = 1.0, minChange = 0, maxChange = 0.0, changeLimiarVelue = 0.0, maxChangeAboveLimiar = 0.00}}  -- O
--}
function AllocationClueLike(component)
  --- Handles with the rules of the component execution.
  -- @arg self A AllocationClueLike component.
  -- @arg event A representation of a time instant when the simulation engine must execute.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
  -- @usage self.allocation:execute(event, model)
  component.execute = function(self, event, luccMEModel)  	 
    -- Synchronize cellular space in the first year
    local luTypes = luccMEModel.landUseTypes
    local cs = luccMEModel.cs

    --Init demandDirection and elasticity (internal component variables)
    self:initElasticity(luccMEModel, self.initialElasticity) 
    
    -- Define iteration loop variables
    local nIter = 0
    local allocation_ok = false
    local maxAdjust = self.maxDifference 
    local maxdiff = self.maxDifference * 1000 -- Used to have a large number of iterations
    local flagFlex = false

    -- Loop until maxdiff is achieved
    repeat
      -- compute tentative allocation
      self:computeChange(luccMEModel)
      self:correctCellChange(luccMEModel)
      
      if (luccMEModel.useLog == true) then
        self:printAllocatedArea(event, luccMEModel, nIter)
      end
      
      -- verify if allocation reaches demand
      maxdiff = self:compareAllocationToDemand(event, luccMEModel)    
      if (maxdiff <= maxAdjust) then
        allocation_ok = true
        if (luccMEModel.useLog) == true then
          print("Demand allocated correctly in ", event:getTime(), "number of iterations", nIter, "maximum error: ", maxdiff)
        end
      else 
        nIter = nIter + 1
        if (nIter >  self.maxIteration * 0.50) and (flagFlex == false) then
          maxAdjust = maxAdjust * 2 
          flagFlex = true 
        end   
      end
    until ((nIter >= self.maxIteration) or (allocation_ok == true))

    if (nIter == self.maxIteration) then
      error("Demand not allocated correctly in this time step: "..nIter)
    end       

    forEachCell(cs, function(cell)
                      local total = 0
                      for i, lu in pairs (luTypes) do
                        if (lu ~= luccMEModel.complementarLU) then
                          total = total + cell[lu]
                        end
                      end
                      if (luccMEModel.complementarLU ~= nil) then
                        cell[luccMEModel.complementarLU] = 1 - total
                      end
                    end
                )
       
    for i, lu in pairs (luTypes) do
      local out = lu.."_out"
      local diff = lu.."_change"
      for k, cell in pairs (cs.cells) do
        cell[out] = cell[lu]
        cell[diff] = cell[lu] - cell.past[lu]
      end
    end

    cs:synchronize()
  end
		
  --- Handles with the parameters verification.
  -- @arg self A AllocationClueLike component.
  -- @arg event A representation of a time instant when the simulation engine must execute.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
  -- @usage self.allocation:verify(event, self)
  component.verify = function(self, event, luccMEModel)
    print("Verifying Allocation parameters")
    -- check maxDifference
    if (self.maxDifference == nil) then
      error("maxDifference variable is missing", 2)
    end      
    
    -- check maxIteration
    if (self.maxIteration == nil) then
      error("maxIteration variable is missing", 2)
    end
    
    -- check initialElasticity
    if (self.initialElasticity == nil) then
      error("initialElasticity variable is missing", 2)
    end      
    
    -- check minElasticity
    if (self.minElasticity == nil) then
      error("minElasticity variable is missing", 2)
    end      
    
    -- check maxElasticity
    if (self.maxElasticity == nil) then
      error("maxElasticity variable is missing", 2)
    end     
    
    -- check complementarLU
    if (self.complementarLU == nil) then
      error("complementarLU variable is missing", 2)
    end   
    
    -- check allocationData
    if (self.allocationData == nil) then
      error("allocationData is missing", 2)
    end    
    
    local allocationNumber = #self.allocationData
    local lutNumber = #luccMEModel.landUseTypes
    
    -- check the number of aloccations
    if (allocationNumber ~= lutNumber) then
      error("Invalid number of allocations. Allocations: "..allocationNumber.." LandUseTypes: "..lutNumber)
    end
    
    -- check data into allocationData
    for j = 1, allocationNumber, 1 do
      -- check static variable
      if(self.allocationData[j].static == nil) then
        error("static variable is missing on Allocation number "..j, 2)
      end
     
      -- check minValue variable
      if (self.allocationData[j].minValue == nil) then
        error("minValue variable is missing on Allocation number "..j, 2)
      end
     
      -- check maxValue variable
      if (self.allocationData[j].maxValue == nil) then
        error("maxValue variable is missing on Allocation number "..j, 2)
      end

      -- check minChange variable
      if (self.allocationData[j].minChange == nil) then
        error("minChange variable is missing on Allocation number "..j, 2)
      end
      
      -- check maxChange variable
      if (self.allocationData[j].maxChange == nil) then
        error("maxChange variable is missing on Allocation number "..j, 2)
      end     
      
      -- check changeLimiarValue variable
      if (self.allocationData[j].changeLimiarValue == nil) then
        error("changeLimiarValue variable is missing on Allocation number "..j, 2)
      end
      
      -- check maxChangeAboveLimiar variable
      if (self.allocationData[j].maxChangeAboveLimiar == nil) then
        error("maxChangeAboveLimiar variable is missing on Allocation number "..j, 2)
      end      
    end

    -- check complementarLU within database
    if (self.complementarLU ~= nil) then
      local foundCLU = 0

      for k = 1, lutNumber, 1 do
        if (self.complementarLU == luccMEModel.landUseTypes[k]) then
          foundCLU = 1
          break
        end
      end
      
      if (foundCLU == 0) then
        error("complementarLU: "..self.complementarLU.." is not a landUseType defined on main file.", 2)
      end
    end
  end
	 
  --- Handles with the elasticity initialize considering a single elasticity for each land use (all cells).
  -- Similar to the coarse scale old clue.
  -- @arg self A AllocationClueLike component.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
  -- @arg value The elasticity value.
  -- @usage self:initElasticity(luccMEModel, self.initialElasticity)
  component.initElasticity = function(self, luccMEModel, value)
    -- Init elasticity. In this version of the component, a single elasticity for each land use (all cells).
    -- Similar to the coarse scale old clue
		local luTypes = luccMEModel.landUseTypes
		self.elasticity = {}	
		for k = 1, #luTypes, 1 do
			self.elasticity[k] = value
		end
	end

	--- Compute the Allocation change based on the potential of the cell.
  -- @arg self A AllocationClueLike component.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
  -- @usage self:computeChange(luccMEModel)
  component.computeChange = function(self, luccMEModel)
    local cs = luccMEModel.cs
    local luTypes = luccMEModel.landUseTypes

    for i, luAllocData in pairs (self.allocationData) do
      local lu = luTypes[i]
      local attr_pot = lu.."_pot"
      local luDirect = luccMEModel.demand:getCurrentLuDirection(i)

      for k, cell in pairs (cs.cells) do        
        local pot = cell[attr_pot]
        local luStatic = luAllocData.static
        
        local change = pot * self.elasticity[i]

        if (math.abs(change) < luAllocData.minChange) then
          pot = 0
          change = 0
        end
        
        if (math.abs(change) >= luAllocData.maxChange) then
            change = luAllocData.maxChange * (pot / math.abs(pot))
        end
          
        if (((pot >= 0) and (luDirect == 1) and (luStatic < 1)) or
           ((pot <= 0) and (luDirect == -1) and (luStatic < 1))) then
            cell[lu] = cell.past[lu] + change 
        elseif (luStatic ~= 0) then
          cell[lu] = cell.past[lu]
        end
  
        if (cell[lu] < 0) then
          cell[lu] = 0
        end
        
        if (cell[lu] > 1) then
          cell[lu] = 1
        end

        if (cell[lu] <= luAllocData.minValue) then  
          if (cell.past[lu] >= luAllocData.minValue) then
            cell[lu] = luAllocData.minValue
          else
            cell[lu] = cell.past[lu]
          end
        end

        if (cell[lu] > luAllocData.maxValue) then 
          if (cell.past[lu] <= luAllocData.maxValue) then 
            cell[lu] = luAllocData.maxValue
          else
            cell[lu] = cell.past[lu]
          end
        end
      end  -- for cell
    end -- for lu
  end -- computeChange

  --- Compares the demand to the amount of allocated land use/cover, then adapts elasticity.
  -- @arg self A AllocationClueLike component.
  -- @arg event A representation of a time instant when the simulation engine must execute.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
  -- @usage maxdiff = self:compareAllocationToDemand(event, luccMEModel)
  component.compareAllocationToDemand = function(self, event, luccMEModel)
    -- Compares the demand to the amount of allocated land use/cover, then adapts elasticity
    local cs = luccMEModel.cs
    local luTypes = luccMEModel.landUseTypes
    local areas = self:countAllocatedLandUseArea(cs, luTypes)
    local max = 0
    local tot = 0
    local nRegression = 0
    
    for j = 1, #luccMEModel.potential.regressionData, 1 do
      for i, lu in  pairs( luTypes) do
        local luDirect = luccMEModel.demand:getCurrentLuDirection(i)
        local currentDemand = luccMEModel.demand:getCurrentLuDemand(i) 
      
        if (luDirect == 0 and event:getTime() == luccMEModel.startTime) then 
        	if (currentDemand  >= areas[i]) then
        		luDirect = 1
        	else
        		luDirect = -1
        	end
        end
        
        if (luDirect == 1) then
      		self.elasticity[i] = self.elasticity[i] * (currentDemand / areas[i])
        else
      		self.elasticity[i]  = self.elasticity[i] * (areas[i] / currentDemand)
        end
      
        local flag = false
      
        if (self.elasticity[i] > self.maxElasticity) then  
          flag = true
      		self.elasticity[i] = self.maxElasticity
      		luccMEModel.potential:modify(luccMEModel, j, i, luDirect)			
        end
      
        if (self.elasticity[i] < self.minElasticity) then
          flag = true
        	if (self.allocationData[i].static < 0) then  
      		  self.elasticity[i] = self.minElasticity
      		  luccMEModel.potential:modify(luccMEModel, j, i, luDirect * (-1)) -- Original clue does not modify in this case, but AMAZALERT results are like this
        	else
        		  luccMEModel.demand:changeLuDirection(i)
        	end
        end
      
        if (luccMEModel.useLog == true and flag == true) then
          if (j > nRegression) then
             print("Region "..j)
             nRegression = j
          end
          print (lu, "elas: ", self.elasticity[i],"dir: ",luDirect,"const :",luccMEModel.potential.regressionData[j][i].const,"->", luccMEModel.potential.regressionData[j][i].newconst, 
                 luccMEModel.potential.regressionData[j][i].newminReg, luccMEModel.potential.regressionData[j][i].newmaxReg)
        end
      
      	local diff = math.abs((areas[i] - currentDemand)) 
      	
      	if (diff > max) then 
      		max =  diff
      	end
      	
      	tot = tot + math.abs(areas[i] - currentDemand )
      end -- for i
    end  -- for j
    
    return max
  end
		
  --- Corrects total land use/cover types to 100 percent.
  -- @arg self A AllocationClueLike component.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
  -- @usage self:correctCellChange(luccMEModel)
  component.correctCellChange = function(self, luccMEModel)
  -- corrects total land use/cover types to 100 percent
    local cs = luccMEModel.cs
    local luTypes = luccMEModel.landUseTypes
  
    local NCOV = #luTypes
    local BACKP = 0.5
    
    for k, cell in pairs (cs.cells) do
      local nostatic = 0
      local decr = 0
      local incr = 0
      local totcov = 0
      local totchange = 0
      local totstatic = 0
      local amin = cell[luTypes[1]] - cell.past[luTypes[1]]
      local amax = amin
      local max = math.abs(amax)
      local l = 0
      
      -- checks if total land use/covers from 100 percent
      for i, lu in pairs (luTypes) do
        totcov = totcov + cell[lu]
      end

      if (math.abs(totcov - 1) > 0.005) then
        for i, lu in pairs (luTypes) do
          local dif = cell[lu] - cell.past[lu]
          totchange = totchange + math.abs(dif)
          if (math.abs(dif) > max) then
            max = math.abs(dif)
          end
          if (dif > amax) then
            amax = dif
          end
          if (dif < amin) then
            amin = dif
          end
        end

        -- adapts land use/cover types if all of them change into the same direction
        if (totchange > 0) then
          if ((BACKP * totchange) > (max * 0.5)) then  
            BACKP = (max / (2 * totchange))
          end
        end

        for i, luAllocData in pairs (self.allocationData) do
          local lu = luTypes[i]
          local luStatic = luAllocData.static
          
          if ((cell[lu] <= luAllocData.minValue) or cell[lu] >= luAllocData.maxValue) then
            luStatic = 1
          end   
          
          if (luStatic < 1) then
            local dif = cell[lu] - cell.past[lu]
            
            if (dif > (-1 * BACKP * totchange)) then
              incr = incr + 1
            end
            
            if (dif < (BACKP * totchange)) then
              decr = decr + 1
            end
          else
            nostatic = nostatic + 1
          end
        end

        if (decr == (NCOV - nostatic)) or (incr == (NCOV - nostatic)) then
          for i, luAllocData in pairs (self.allocationData) do
            local lu = luTypes[i]
            local luDirect = luccMEModel.demand:getCurrentLuDirection(i)
            
            local luStatic = luAllocData.static
            if ((cell[lu] <= luAllocData.minValue) or cell[lu] >= luAllocData.maxValue) then
              luStatic = 1
            end   
            if (luStatic < 1) then
              if (incr == (NCOV - nostatic)) then
                cell[lu] = cell[lu] - (amin + (BACKP * totchange))
              end
              if (decr == (NCOV-nostatic)) then
                cell[lu] = cell[lu] + ((BACKP * totchange) - amax)
              end
              if (cell[lu] < 0) then
                cell[lu] = 0
              end
            end
            if ((luDirect == 1) and (cell[lu] < cell.past[lu]) and (luAllocData.static == -1)) then
              cell[lu] = cell.past[lu]
            end
            if ((luDirect == -1) and (cell[lu] > cell.past[lu]) and (luAllocData.static == -1)) then
              cell[lu] = cell.past[lu]
            end
          end
        end
        
        -- perform the corrections
        repeat
          l = l + 1
          totcov = 0
          totchange = 0
          totstatic = 0
          for i, luAllocData in pairs (self.allocationData) do
            local lu = luTypes[i]
            local luStatic = luAllocData.static
            
            if ((cell[lu] <= luAllocData.minValue) or cell[lu] >= luAllocData.maxValue) then
              luStatic = 1
            end   
            if (luStatic < 1) then
              totcov = totcov + cell[lu]
            else
              totstatic = totstatic +  cell[lu]
            end
            totchange = totchange + math.abs(cell[lu] - cell.past[lu])
          end
          if (math.abs(totcov - (1 - totstatic)) > 0.005) then
            if (totchange == 0) then
              for i, luAllocData in pairs (self.allocationData) do
                local lu = luTypes[i]
                local luStatic = luAllocData.static
                if ((cell[lu] <= luAllocData.minValue) or (cell[lu] >= luAllocData.maxValue)) then
                  luStatic = 1
                end   
                if (luStatic < 1) then
              
                   cell[lu] = cell[lu] * ((1-totstatic)/totcov)
                end
              end
            else
              for i, luAllocData in pairs (self.allocationData) do
                local lu = luTypes[i]
                local aux = cell[lu]
                cell[lu] = cell[lu] - (math.abs(cell[lu] - cell.past[lu]) * ((totcov - (1 - totstatic)) / totchange))
                if (cell[lu] < 0) then
                  cell[lu] = 0
                end
                
              end
            end
          end
        until ((math.abs(totcov - (1 - totstatic)) <= 0.005) or (l >= 25))

        if (l == 25) then
          totcov = 0
          totstatic = 0
          for i, luAllocData in pairs (self.allocationData) do
            local lu = luTypes[i]
            local luStatic = luAllocData.static
            if ((cell[lu] <= luAllocData.minValue) or (cell[lu] >= luAllocData.maxValue)) then
              luStatic = 1
            end     
            if (luStatic < 1) then
              totcov = totcov + cell[lu]
            else
              totstatic = totstatic + cell[lu]
            end
          end
          for i, luAllocData in pairs (self.allocationData) do
            local lu = luTypes[i]
            local luStatic = luAllocData.static
            if ((cell[lu] <= luAllocData.minValue) or cell[lu] >= luAllocData.maxValue) then
              luStatic = 1
            end     
            if (luStatic < 1) then
              cell[lu] = cell[lu] * ((1 - totstatic) / totcov)
            end
          end
        end -- if l
      end -- if totcov
    end -- for k
  end -- correctCellChange
	
  --- Calculates total area allocated by the regression equations for each land use/cover type.
  -- @arg self A AllocationClueLike component.
  -- @arg cs A multivalued set of Cells (Cell Space).
  -- @arg luTypes A set of land use types.
  -- @usage areas = self:countAllocatedLandUseArea(cs, luTypes)
  component.countAllocatedLandUseArea = function(self, cs, luTypes)
    -- Calculates total area allocated by the regression equations for each land use/cover type
    local areas = {}
    local cellarea = cs.cellArea
   
    for i, lu in pairs (luTypes) do
      local area = 0
      
      for k,cell in pairs (cs.cells) do
        local temp = cell[lu]
       
        if (temp > 0) then
          area = area + temp
        end
      end
      areas[i] = area * cellarea
    end
    
    return areas
  end
  
  --- Calculates and prints the allocated by the regression equations for each land use/cover type.
  -- @arg self A AllocationClueLike component.
  -- @arg event A representation of a time instant when the simulation engine must execute.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
  -- @arg nIter An iterator number.
  -- @usage self:printAllocatedArea(event, luccMEModel, nIter)
  component.printAllocatedArea = function(self, event, luccMEModel, nIter)
    -- Calculates and prints the allocated by the regression equations for each land use/cover type
    local cs = luccMEModel.cs
    local luTypes = luccMEModel.landUseTypes
    local areas = {}

    areas = self:countAllocatedLandUseArea(cs, luTypes)
    
    print("\nYear:"..event:getTime()," Step: "..nIter)  
    
    for i, lu in pairs (luTypes) do
      local currentDemand  = luccMEModel.demand:getCurrentLuDemand(i)
      print(lu.." area: \t"..math.floor(areas[i]), "Difference: ", math.floor(areas[i] - currentDemand)) 
    end
    
    io.flush()
  end

  return component
end -- close Allocation Component
