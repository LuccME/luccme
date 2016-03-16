--- A component (demand algorithm), where the demand inputs set by the user on the
-- configuration file is used to distribute on the cells the correct among of this
-- demand according to the parameters rules.
-- The modeller informs pre-computed demand for each land use in each simulation year (see examples). 
-- These values may have been generated by any appropriate approach/method/external model.
-- @arg component An instance of the component itself (an object, with all the data).
-- @arg component.finalYearForInterpolation The year to be consider as the final
-- year to calculate the demand interpolation.
-- @arg component.landUseTypesForInterpolation The land use names within the data of
-- the final year to calculate the demand interpolation.
-- @arg component.directionForInterpolation Set the direction of the demand for each
-- landUseTypesForInterpolation (optional).
-- @arg component.run Handles with the execution method of a ComputeInputThreeDateMaps component.
-- @arg model.verify Handles with the verify method of a ComputeInputThreeDateMaps component.
-- @arg component.printDemand Print the generated demand.
-- @arg component.getCurrentDemand Return the current demand of the specified component.
-- @arg component.getPreviousDemand Return the previous demand of the specified component.
-- @arg component.getCurrentLuDemand Return the current demand for an specific luIndex.
-- @arg component.getPreviousLuDemand Return the previous demand for an specific luIndex.
-- @arg component.getCurrentLuDirection Return the current demand direction for an specific luIndex.
-- @arg component.changeLuDirection Invert the demand direction for an specific luIndex.
-- @return The modified component.
-- @usage demand = ComputeInputThreeDateMaps {
--  middleYearForInterpolation = 2002,
--  middleLandUseTypesForInterpolation = {"Dmiddle", "Fmiddle", "Omiddle"}
--  finalYearForInterpolation = 2004,
--  finalLandUseTypesForInterpolation = {"Dfinal", "Ffinal", "Ofinal"}
-- }
function ComputeInputThreeDateMaps(component)
	--- Handles with the rules of the component execution.
	-- @arg self A ComputeInputThreeDateMaps component.
	-- @arg event A representation of a time instant when the simulation engine must run.
	-- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
	-- @usage self.demand:run(event, model)
	component.run = function(self, event, luccMEModel)
		local increasing = 1
		local decreasing = -1
		local static = 0
    local step = 0
    local luTypes = luccMEModel.landUseTypes
	
		step = event:getTime() - luccMEModel.startTime + 1
		
		if (#self.annualDemand < step) then	
			error("Time required exceeds the demand set", 5)
		end
		
		self.currentDemand = self.annualDemand[step]
			
		if (event:getTime() == luccMEModel.startTime) then
		   self.previousDemand = self.currentDemand
		else
		   self.previousDemand = self.annualDemand[step - 1]
		end

		self.demandDirection = {}

		for i, lu in pairs (luTypes) do
			self.demandDirection[i] = static
			if (step > 1) then
				if (self.previousDemand[i] < self.currentDemand[i]) then
					self.demandDirection[i] = increasing
				end
				if (self.previousDemand[i] > self.currentDemand[i]) then
					self.demandDirection[i] = decreasing
				end
			end
		end -- for i
	end -- run
	
	--- Handles with the parameters verification and the generation for the Demand.
	-- @arg self A ComputeInputThreeDateMaps component.
	-- @arg event A representation of a time instant when the simulation engine must run.
	-- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
	-- @usage self.demand:verify(event, self)
	component.verify = function(self, event, luccMEModel)
	  print("Verifying Demand parameters")
		local yearsSimulated = (luccMEModel.endTime - luccMEModel.startTime) + 1
		
	   --  Check the middle year for interpolation
    if (self.middleYearForInterpolation == nil) then
      error("middleYearForInterpolation is missing", 5)
    end
	
		--  Check the final year for interpolation
		if (self.finalYearForInterpolation == nil) then
			error("finalYearForInterpolation is missing", 5)
    end
		
		--  Middle land use types for interpolation (correct number of uses)
		if (self.middleLandUseTypesForInterpolation == nil) then
			error("middleLandUseTypesForInterpolation is missing", 5)
    end
    
    --  Final land use types for interpolation (correct number of uses)
    if (self.finalLandUseTypesForInterpolation == nil) then
      error("finalLandUseTypesForInterpolation is missing", 5)
    end
		
    --  Check the number of parameters for the interpolation (initial and middle)
    if (#self.middleLandUseTypesForInterpolation ~= #luccMEModel.landUseTypes) then
      print("landUseTypes and middleLandUseTypesForInterpolation MUST have the same number of parameters.")
      error("landUseTypes: "..#luccMEModel.landUseTypes..". landUseTypesForInterpolation: "..#self.middleLandUseTypesForInterpolation, 5)
    end
		
		--  Check the number of parameters for the interpolation (initial and final)
		if (#self.finalLandUseTypesForInterpolation ~= #luccMEModel.landUseTypes) then
			print("landUseTypes and finalLandUseTypesForInterpolation MUST have the same number of parameters.")
			error("landUseTypes: "..#luccMEModel.landUseTypes..". landUseTypesForInterpolation: "..#self.finalLandUseTypesForInterpolation, 5)
		end
		
		-- Check, if used, the number of direction parameters
		if (self.directionForInterpolation ~= nil) then
			if (#self.landUseTypesForInterpolation ~= #self.directionForInterpolation) then
				error("landUseTypesForInterpolation and directionForInterpolation MUST have the same number of parameters", 5)
			end
		end

		-- Check the number of years to simulate
		if (yearsSimulated == 0) then
			error("The simulation time is zero", 5)
	  end
	
    -- check middleLandUseTypesForInterpolation within database
    for k, lu in pairs (self.middleLandUseTypesForInterpolation) do
      if (luccMEModel.cs.cells[1][lu] == nil) then
        error("middleLandUseTypesForInterpolation: "..lu.." not found within database", 2)
      end
    end
    
    -- check finalLandUseTypesForInterpolation within database
    for k, lu in pairs (self.finalLandUseTypesForInterpolation) do
      if (luccMEModel.cs.cells[1][lu] == nil) then
        error("finalLandUseTypesForInterpolation: "..lu.." not found within database", 2)
      end
    end

		-- Starts of annualDemand generation
		self.annualDemand = {}
		self.annualDemand = self:generateDemand(event, luccMEModel)
		
		
		-- Check if the demand is proper to the number of years to simulate
		if (#self.annualDemand < yearsSimulated) then
			error("The simulation time exceeds the demand set. annualDemand: "..#self.annualDemand..". yearsSimulated: "..yearsSimulated, 5)
		end	
		
    -- Check the land use types
    self.demandDirection = {}
    local luTypes = luccMEModel.landUseTypes
    self.numLU = 0

    for k, lu in pairs (luTypes) do
        self.demandDirection[k] = 0
        if (self.annualDemand[1][k] == nil) then
          error("Invalid number of land use in the demand table", 5)
        end
        self.numLU = self.numLU + 1
    end
	end -- verify

  --- Generate the annual demand based on the data provided by the user
  -- @arg self A ComputeInputThreeDateMaps component.
  -- @arg event A representation of a time instant when the simulation engine must run.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
  -- @return annualDemand The annual demand.
  component.generateDemand = function(self, event, luccMEModel)
    local parametersNumber = #luccMEModel.landUseTypes
    local j, i, k
    local initialDemand = {}
    local middleDemandForInterpolation = {}
    local finalDemandForInterpolation = {}
    local firstInterpolationFactor = {}
    local secondInterpolationFactor = {}
    local firstInterpolationDirection = {}
    local secondInterpolationDirection = {}
    local firstTimeToCalcInterpolation = (self.middleYearForInterpolation - luccMEModel.startTime)
    local secondTimeToCalcInterpolation = (self.finalYearForInterpolation - self.middleYearForInterpolation)
    local timeToGenerateDemand = luccMEModel.endTime - luccMEModel.startTime
    
    -- Get the demands on the database
    initialDemand = self:getDemand(initialDemand, luccMEModel.landUseTypes, luccMEModel)
    middleDemandForInterpolation = self:getDemand(middleDemandForInterpolation, self.middleLandUseTypesForInterpolation, luccMEModel)
    finalDemandForInterpolation = self:getDemand(finalDemandForInterpolation, self.finalLandUseTypesForInterpolation, luccMEModel)

        
    -- Get the interpolationFactor for each parameter
    firstInterpolationFactor = self:interpolationFactor(parametersNumber, firstInterpolationFactor, middleDemandForInterpolation, initialDemand, 
                                                        firstTimeToCalcInterpolation, luccMEModel)
    
    secondInterpolationFactor = self:interpolationFactor(parametersNumber, secondInterpolationFactor, finalDemandForInterpolation, middleDemandForInterpolation, 
                                                         secondTimeToCalcInterpolation, luccMEModel)
    
    -- Calculate interpolation direction
    firstInterpolationDirection = self:interpolationDirection(parametersNumber, firstInterpolationDirection, middleDemandForInterpolation, initialDemand, luccMEModel)
    
    secondInterpolationDirection = self:interpolationDirection(parametersNumber, secondInterpolationDirection, finalDemandForInterpolation, 
                                                               middleDemandForInterpolation, luccMEModel)
    
    -- generate the annualDemand
    for i = 1, timeToGenerateDemand + 1, 1 do
      if (self.annualDemand[i] == nil) then
        self.annualDemand[i] = {}
      end
      -- insert the initialDemand on the annualDemand
      if (i == 1) then
        for j, lu in pairs (luccMEModel.landUseTypes) do
          self.annualDemand[i][j] = initialDemand[j]
          self.annualDemand[i][j] = math.floor(self.annualDemand[i][j] + 0.5)
        end

      -- insert the middleDemandForInterpolation (validation) on the annualDemand
      elseif (i == firstTimeToCalcInterpolation + 1) then
        for j, lu in pairs (self.middleLandUseTypesForInterpolation) do
          self.annualDemand[i][j] = middleDemandForInterpolation[j]
          self.annualDemand[i][j] = math.floor(self.annualDemand[i][j] + 0.5)
        end

      -- insert the finalDemandForInterpolation (validation) on the annualDemand
      elseif (i == (firstTimeToCalcInterpolation + secondTimeToCalcInterpolation + 1)) then
        for j, lu in pairs (self.finalLandUseTypesForInterpolation) do
          self.annualDemand[i][j] = finalDemandForInterpolation[j]
          self.annualDemand[i][j] = math.floor(self.annualDemand[i][j] + 0.5)
        end

      -- compute the rest of the demand
      else
        -- calculate the demand for each parameter
        for j, lu in pairs (luccMEModel.landUseTypes) do
          if(i <= firstTimeToCalcInterpolation) then
            self.annualDemand[i][j] = self.annualDemand[i - 1][j] + (firstInterpolationFactor[j] * firstInterpolationDirection[j])
            self.annualDemand[i][j] = math.floor(self.annualDemand[i][j] + 0.5)
          else
            self.annualDemand[i][j] = self.annualDemand[i - 1][j] + (secondInterpolationFactor[j] * secondInterpolationDirection[j])
            self.annualDemand[i][j] = math.floor(self.annualDemand[i][j] + 0.5)
          end
        end
      end
    end

    -- print the demand
    self:printDemand(initialDemand, middleDemandForInterpolation, finalDemandForInterpolation, timeToGenerateDemand, luccMEModel)

    return self.annualDemand
  end -- generateDemand
  
  --- Calculate the interpolatin factor for 2 demands 
  -- @arg self  A ComputeInputThreeDateMaps component.
  -- @arg parametersNumber Number of LandUseTypes.
  -- @arg interpolationFactor The interpolation factor itself.
  -- @arg finalDemand The final demand to search the direction.
  -- @arg initialDemand The initial demand to search the direction.
  -- @arg timeToCalcInterpolation The period of years to calculate the interpolation.
  -- @arg luccMEModel A luccME model.
  -- @return interpolationFactor The interpolation factor.
  component.interpolationFactor = function(self, parametersNumber, interpolationFactor, finalDemand, initialDemand, timeToCalcInterpolation, luccMEModel)
    for i = 1, parametersNumber, 1 do
      -- create a new row
      if (interpolationFactor[i] == nil) then
        interpolationFactor[i] = {}
      end
      -- compute the interpolationFactor value
      interpolationFactor[i] = math.abs((finalDemand[i] - initialDemand[i]) / timeToCalcInterpolation)
    end
    
    return interpolationFactor
  end
  
  --- Calulate the interpolation direction for 2 demands
  -- @arg self  A ComputeInputThreeDateMaps component.
  -- @arg parametersNumber Number of LandUseTypes.
  -- @arg interpolationDirection The interpolation direction itself.
  -- @arg finalDemand The final demand to search the direction.
  -- @arg initialDemand The initial demand to search the direction.
  -- @aeg luccMEModel A luccME model.
  -- @return interpolationDirection The interpolation direction.
  component.interpolationDirection = function(self, parametersNumber, interpolationDirection, finalDemand, initialDemand, luccMEModel)
    local increasing = 1
    local decreasing = -1
    local static = 0
    
    for i = 1, parametersNumber, 1 do
      -- create a new row
      if (interpolationDirection[i] == nil) then
        interpolationDirection[i] = {}
      end

      -- convert the string to values
      if (self.directionForInterpolation ~= nil) then
        -- using directionForInterpolation parameter
        if (self.directionForInterpolation[i] == "Increase") then
          interpolationDirection[i] = 1
        elseif (self.directionForInterpolation[i] == "Decrease") then
          interpolationDirection[i] = -1
        else
          interpolationDirection[i] = 0
        end
      else
        -- not using directionForInterpolation parameter
        if (finalDemand[i] - initialDemand[i] > 0) then
          interpolationDirection[i] = increasing
        elseif (finalDemand[i] - initialDemand[i] < 0) then
          interpolationDirection[i] = decreasing
        else
          interpolationDirection[i] = static
        end
      end
    end
    
    return interpolationDirection
  end

  --- Get the demand on the database
  -- @arg self A ComputeInputThreeDateMaps component.
  -- @arg returnDemand The demand that are looking for.
  -- @arg luccMEModel A luccME Model
  -- @return returnDemand The value of the demand from the database
  component.getDemand = function(self, returnDemand, landUseTypes, luccMEModel)
    forEachCell(luccMEModel.cs, function(cell)
                                  for j, lu in pairs (landUseTypes) do
                                    if (returnDemand[j] == nil) then
                                      returnDemand[j] = 0
                                    end
                                    returnDemand[j] = returnDemand[j] + (cell[lu] * luccMEModel.cs.cellArea)
                                  end
                                end
                )
    
    return returnDemand
  end
  
	--- Print on screen the generated demand.
	-- @arg self A ComputeInputThreeDateMaps component.
	-- @usage self:printDemand(initialDemand, finalDemandForInterpolation, timeToGenerateDemand, luccMEModel)
	component.printDemand = function(self, initialDemand, middleDemandForInterpolation, finalDemandForInterpolation, timeToGenerateDemand, luccMEModel)
		-- Print on screen the demands (for conference)
		-- print the initial demand
		print("\n\tInitial Demand\t Year")
		local rowPrint = ""
		local j, i
		
		for j, lu in pairs (luccMEModel.landUseTypes) do
			rowPrint = rowPrint .. initialDemand[j] .. " "
		end
		print("\n", rowPrint, luccMEModel.startTime)
		rowPrint = ""
		
		-- print the middle demand (used for the interpolation calculation)
    print("\n\tInterpolation Middle Demand\t Year")
    rowPrint = ""
    for j, lu in pairs (self.middleLandUseTypesForInterpolation) do
      rowPrint = rowPrint .. middleDemandForInterpolation[j] .. " "
    end
    print("\n", rowPrint, self.middleYearForInterpolation)
    rowPrint = ""
		
		
		-- print the final demand (used for the interpolation calculation)
		print("\n\tInterpolation Final Demand\t Year")
		rowPrint = ""
		for j, lu in pairs (self.finalLandUseTypesForInterpolation) do
			rowPrint = rowPrint .. finalDemandForInterpolation[j] .. " "
		end
		print("\n", rowPrint, self.finalYearForInterpolation)
		rowPrint = ""
		
		-- print all the demand (Demand that will be used on run)
		print("\n\n\tAnnual Demand\t Year")
		rowPrint = ""
		for i = 1, timeToGenerateDemand + 1, 1 do
			for j, lu in pairs (luccMEModel.landUseTypes) do
				rowPrint = rowPrint .. self.annualDemand[i][j] .. " "
			end
			print("\n", rowPrint, luccMEModel.startTime + (i - 1))
			rowPrint = ""
		end
		print("\n")
	end
	
  --- Return the current demand of the specified component.
  -- @arg self A PreComputedValuesINPE component.
  -- Used on discrete allocation component
  -- @return self.currentDemand the current demand of the component.
  -- @usage currentDemand = demand:getCurrentDemand(i)
	component.getCurrentDemand = function(self)	
		return self.currentDemand
  end

	--- Return the previous demand of the specified component.
	-- @arg self A ComputeInputThreeDateMaps component.
	-- @return self.previousDemand the previous demand of the component.
	-- @usage previousDemand = demand:getPreviousDemand(i)
  component.getPreviousDemand = function(self)	
		return self.previousDemand
  end

  --- Return the current demand for an specific luIndex.
  -- Used on allocation and continuous potential components.
  -- @arg self A PreComputedValuesINPE component.
  -- @arg luIndex A land use index (an specific luIndex of a list of possible land uses).
  -- @return The current demand for an specific luIndex.
  -- @usage model:getCurrentLuDemand(luIndex)
  component.getCurrentLuDemand = function(self, luIndex)		
		if (luIndex > self.numLU) then
			error("Invalid land use index", 5)
		end
		
		return self.currentDemand[luIndex]
  end

  --- Return the previous demand for an specific luIndex.
  -- Used on continuous pontencial component.
  -- @arg self A PreComputedValuesINPE component.
  -- @arg luIndex A land use index (an specific luIndex of a list of possible land uses).
  -- @return The previous demand for an specific luIndex.
  -- @usage model:getPreviousLuDemand(luIndex)
	component.getPreviousLuDemand = function(self, luIndex)	
		if (luIndex > self.numLU) then
			error("Invalid land use index", 5)
		end	

		return self.previousDemand[luIndex]
  end

  --- Return the current demand direction for an specific luIndex.
  -- Used on continuous allocation component.
  -- @arg self a PreComputedValuesINPE component.
  -- @arg luIndex A land use index (an specific luIndex of a list of possible land uses).
  -- @return The current demand direction for an specific luIndex.
  -- @usage model:getCurrentLuDirection(luIndex)
	component.getCurrentLuDirection = function(self, luIndex)	
		if (luIndex > self.numLU) then
			error("Invalid land use index", 5)
		end	

		return self.demandDirection[luIndex]
  end	

  --- Invert the demand direction for an specific luIndex.
  -- Used on continuous allocation component.
  -- @arg self a PreComputedValuesINPE component.
  -- @arg luIndex A land use index (an specific luIndex of a list of possible land uses).
  -- @return The current demand direction for an specific luIndex.
  -- @usage model:changeLuDirection(luIndex)
  component.changeLuDirection = function(self, luIndex)
		local oppositeDirection = -1
		
		if (luIndex > self.numLU) then
			error("Invalid land use index", 5)
		end

		self.demandDirection[luIndex] = self.demandDirection[luIndex] * oppositeDirection
		
		return self.demandDirection[luIndex]
  end		

	return component
end -- ScenariosDemand
		