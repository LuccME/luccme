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
-- @arg component.execute Handles with the execution method of a PreComputedValuesINPE component.
-- @arg model.verify Handles with the verify method of a PreComputedValuesINPE component.
-- @arg component.getCurrentDemand Return the current demand of the specified component.
-- @arg component.getPreviousDemand Return the previous demand of the specified component.
-- @arg component.getCurrentLuDemand Return the current demand for an specific luIndex.
-- @arg component.getPreviousLuDemand Return the previous demand for an specific luIndex.
-- @arg component.getCurrentLuDirection Return the current demand direction for an specific luIndex.
-- @arg component.changeLuDirection Invert the demand direction for an specific luIndex.
-- @return the modified component.
-- @usage demand = PreComputedValuesINPE {
-- annualDemand = {	{	205	,	5706	,	3	},
--					{	253	,	5658	,	3	},
--					{	300	,	5611	,	3	},
--					{	348	,	5563	,	3	}}
-- }
function PreComputedValuesINPE(component)
	--- Handles with the rules of the component execution.
	-- @arg self A PreComputedValuesINPE component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
	-- @usage self.demand:execute(event, model)
	component.execute = function(self, event, luccMEModel)
		local increasing = 1
		local decreasing = -1
		local static = 0
		
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
		end
	end
	
	--- Handles with the parameters verification.
	-- @arg self A PreComputedValuesINPE component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
	-- @usage self.demand:verify(event, self)
	component.verify = function(self, event, luccMEModel)
		yearsSimulated = (luccMEModel.endTime - luccMEModel.startTime) + 1
		
		-- Check if the demand is proper to the number of years to simulate
		if (#self.annualDemand < yearsSimulated) then
			error("The simulation time exceeds the demand set", 5)
		end	
		
		-- Check the number of years to simulate
		if (yearsSimulated == 0) then
			error("The simulation time is zero", 5)
	    end

		-- Check the land use types
	    self.demandDirection = {}
		luTypes = luccMEModel.landUseTypes
		self.numLU = 0

	    for k, lu in pairs (luTypes) do
	        self.demandDirection[k] = 0
	        if (self.annualDemand[1][k] == nil) then
				error("Invalid number of land use in the demand table", 5)
	        end
	        self.numLU = self.numLU + 1
	    end
		
	    self.currentDemand = self.annualDemand[1]	
		self.previousDemand = self.annualDemand[1]
	end

	--- Return the current demand of the specified component.
	-- @arg self A PreComputedValuesINPE component.
	-- @return self.currentDemand the current demand of the component.
	-- @usage currentDemand = demand:getCurrentDemand(i)
	component.getCurrentDemand = function(self)	
		return self.currentDemand
    end

	--- Return the previous demand of the specified component.
	-- @arg self A PreComputedValuesINPE component.
	-- @return self.previousDemand the previous demand of the component.
	-- @usage previousDemand = demand:getPreviousDemand(i)
    component.getPreviousDemand = function(self)	
		return self.previousDemand
    end

	-- Return the current demand for an specific luIndex.
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

	-- Return the previous demand for an specific luIndex.
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
		