---  
-- @arg component A Spatial Lag Regression component.
-- @return The modified component.
-- @usage myPontencial = MaximumEntropyLike {
--}
function MaximumEntropyLike(component)
  --- Handles with the execution method of a MaximumEntropyLike component.
  -- @arg self A MaximumEntropyLike component.
  -- @arg event A representation of a time instant when the simulation engine must execute.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
  -- @usage self.potential:execute(event, model)
  component.execute = function(self, event, luccMEModel)
    local cs = luccMEModel.cs
    local luDrivers = self.landUseDrivers
    local luTypes = luccMEModel.landUseTypes
    local demand = luccMEModel.demand
    local regionsNumber = #self.potentialData
    
    for rNumber = 1, regionsNumber, 1 do
      for i = 1, #luTypes, 1 do                         
        self:computePotential(luccMEModel, rNumber, i)
      end
    end
  end  -- function execute
  
  --- Handles with the verify method of a MaximumEntropyLike component.
  -- @arg self A SpatialLagRegression component.
  -- @arg event A representation of a time instant when the simulation engine must execute.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
  -- @usage self.potential:verify(event, self)
  component.verify = function(self, event, luccMEModel)
   print("Verifying Potential parameters")
   local cs = luccMEModel.cs
    
   if (self.regionAttr == nil) then
     self.regionAttr = "region"
   end   

   forEachCell(cs, function(cell)
                      cell["alternate_model"] = 0
                      if (cell[self.regionAttr] == nil) then
                        cell["region"] = 1
                      else
                        cell["region"] = cell[self.regionAttr]
                      end
                     end
               )
  
    -- check potentialData
    if (self.potentialData == nil) then
      error("potentialData is missing", 2)
    end    
    
    local regionsNumber = #self.potentialData

    -- check number of Regions
    if (regionsNumber == nil or regionsNumber == 0) then
      error("The model must have at least One region")
    else
      for i = 1, regionsNumber, 1 do
        local regressionNumber = #self.potentialData[i]
        local lutNumber = #luccMEModel.landUseTypes
        
        -- check the number of regressions
        if (regressionNumber ~= lutNumber) then
          error("Invalid number of regressions on Region number "..i.." . Regressions: "..regressionNumber.." LandUseTypes: "..lutNumber)
        end
        
        for j = 1, regressionNumber, 1 do
          -- check betas within database
          for k, lu in pairs (self.potentialData[i][j].attributesPerc) do
            if (luccMEModel.cs.cells[1][lu] == nil) then
              error("AttributePerc "..lu.." on Region "..i.." LandUseType number "..j.." not found within database", 2)
            end
          end
          
          for k, lu in pairs (self.potentialData[i][j].attributesClass) do
            if (luccMEModel.cs.cells[1][lu] == nil) then
              error("AttributeClass "..lu.." on Region "..i.." LandUseType number "..j.." not found within database", 2)
            end
          end
        end -- for j
      end -- for i
    end -- else
  end
  
  --- Handles with the modify method of a MaximumEntropyLike component.
  -- @arg self A MaximumEntropyLike component.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
  -- @arg rNumber The potential region number.
  -- @arg luIndex A land use index (an specific luIndex of a list of possible land uses).
  -- @arg direction The direction for the regression.
  -- @usage luccMEModel.potential:modify(luccMEModel, j, i, luDirect) 
  component.modify = function (self, luccMEModel, rNumber, luIndex, direction)
  end
  
  --- Handles with the compute potential method of a LinearRegression component.
  -- @arg self A LinearRegression component.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
  -- @arg rNumber The potential region number.
  -- @arg luIndex A land use index (an specific luIndex of a list of possible land uses).
  -- @usage self:computePotential(luccMEModel, luIndex)   
  component.computePotential = function(self, luccMEModel, rNumber, luIndex)
    local cs = luccMEModel.cs 
    local luTypes = luccMEModel.landUseTypes
    local lu = luTypes[luIndex]
    local luData = self.potentialData[rNumber][luIndex]
    local pot = lu.."_pot"
    local activeRegionNumber = 0
    local countSample = 1
    local countClass = 0
    local class = {{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{}}
    local sample = {}
    
    -- Search on the CS for samples of the LU
    for k, cell in pairs (cs.cells) do
      if (cell.region == rNumber) then
         activeRegionNumber = rNumber
         
         -- Check the LU % on the cell to consider a sample
         if (cell[lu] > 0.5) then
           sample[countSample] = cell
           countSample = countSample + 1
         end
         
         if (#luData.attributesPerc == 0 and #luData.attributesClass == 0) then
           cell[pot] = 0
         end
      end 
    end

    -- Copy the categoric values to process it later
    for t, attribute in pairs (luData.attributesClass) do
      for k, cell in pairs (cs.cells) do
         class[t][k] = cell[attribute]
      end 
    end

    -- Create the range, and store the categoric values
    local min = {}
    local max = {}
    local values = {{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{}}
   
    -- Initialize the range "arrays"
    for i = 1, #luData.attributesPerc, 1 do
      min[i] = 1000000000
      max[i] = -1000000000
    end
    
    -- Store the categoric values on a table (simplifying to unique values)
    local countDiff = 1
    for i = 1, #class, 1 do
      values[i][1] = class[i][1]
      for j = 1, #class[i], 1 do
        for w = 1, #values[i], 1 do
          if (values[i][w] ~= class[i][j]) then
            countDiff = countDiff + 1 
          end
        end
        if (countDiff > #values[i]) then
          values[i][#values[i] + 1] = class[i][j]
        end
        countDiff = 1
      end
    end
    
    -- Search the min and max values for the LU        
    for k = 1, #sample, 1 do
      for t, attribute in pairs (luData.attributesPerc) do
        if(min[t] > sample[k][attribute]) then
          min[t] = sample[k][attribute]
        end
        
        if(max[t] < sample[k][attribute]) then
          max[t] = sample[k][attribute]
        end
      end
    end
    
    print("\n")
    print(lu)
    print("Cell number", #sample)
    
    for i = 1, #min, 1 do
      print("min["..i.."]",min[i])
      print("max["..i.."]",max[i], "\n")
    end
    for i = 1, #values, 1 do
      for j = 1, #values[i], 1 do
        print("values["..i.."]["..j.."]",values[i][j])
      end
    end
    
    -- Calculaete the potential
    local percOK = {}
    local valueOK = {}
    
    countOne = 0
    countZero = 0
    
    for k, cell in pairs (cs.cells) do
      if(#luData.attributesPerc > 0) then
        for t, attribute in pairs (luData.attributesPerc) do
          if (cell[attribute] >= min[t] and cell[attribute] <= max[t]) then
            percOK[t] = 1
          else
            percOK[t] = 0
          end
        end
      end

      if(#luData.attributesClass > 0) then
        for t, attribute in pairs (luData.attributesClass) do
          for w, value in pairs (values) do
             valueOK[t] = 0
             if (cell[attribute] == values[t][w]) then
                valueOK[t] = 1
                break;
             end
          end
        end
      end
      
      local auxPerc = 1
      local auxValue = 1
      
      if (#percOK == 0 and #valueOK == 0) then
        auxPerc = 0
      else
        if(#percOK > 0) then
          auxPerc = 1
          for i = 1, #percOK, 1 do
            if (percOK[i] == 0) then
              auxPerc = 0
              break
            end
          end
        end
        
        if (#valueOK > 0) then
          auxValue = 1
          for i = 1, #valueOK, 1 do
            if (valueOK[i] == 0) then
              auxValue = 0
              break
            end
          end
        end
        
        if (auxPerc == 1 and auxValue == 1) then
          cell[pot] = 1
        else
          cell[pot] = 0
        end
      end
    
      if (cell[pot] == 1) then
        countOne = countOne + 1
      elseif (cell[pot] == 0) then
        countZero = countZero + 1
      end
      
    end
    

    print("\n")
    print(lu, "pot = 1", "\tpot = 0")
    print(pot, countOne, "\t"..countZero)
      
    if (luIndex == 3) then
--      error("Sair")
        io.read()
    end
            
    if (activeRegionNumber == 0) then
      error("Region ".. rNumber.." is not set into database.")  
    end
  end
  
  print("\n")
  return component
end