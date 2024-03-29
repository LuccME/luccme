--- A component (demand algorithm), where the demand inputs set by the user on the
-- configuration file is used to distribute on the cells the correct among of this
-- demand according to the parameters rules.
-- The modeller informs pre-computed demand for each land use in each simulation year (see examples). 
-- These values may have been generated by any appropriate approach/method/external model.
-- @arg component An instance of the component itself (an object, with all the data).
-- @arg component.finalYearForInterpolation The year to be consider as the final
-- year to calculate the demand interpolation.
-- @arg component.finalLandUseTypesForInterpolation The land use names within the data of
-- the final year to calculate the demand interpolation.
-- @arg component.directionForInterpolation Set the direction of the demand for each
-- finalLandUseTypesForInterpolation (optional).
-- @arg component.run Handles with the execution method of a DemandComputeTwoDates component.
-- @arg model.verify Handles with the verify method of a DemandComputeTwoDates component.
-- @arg component.printDemand Print the generated demand.
-- @arg component.getCurrentDemand Return the current demand of the specified component.
-- @arg component.getPreviousDemand Return the previous demand of the specified component.
-- @arg component.getCurrentLuDemand Return the current demand for an specific luIndex.
-- @arg component.getPreviousLuDemand Return the previous demand for an specific luIndex.
-- @arg component.getCurrentLuDirection Return the current demand direction for an specific luIndex.
-- @arg component.changeLuDirection Invert the demand direction for an specific luIndex.
-- @return The modified component.
-- @usage --DONTRUN 
--D1 = DemandComputeTwoDates
--{
--  finalYearForInterpolation = 2014,
--  finalLandUseTypesForInterpolation = {"floresta2014", "desmatamento2014", "outros"},
--}
function DemandComputeTwoDates(component)
	-- Handles with the rules of the component execution.
	-- @arg event A representation of a time instant when the simulation engine must run.
	-- @arg luccMEModel A luccME Model.
	-- @usage --DONTRUN
	-- component.run(event, model)
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
	
	-- Handles with the parameters verification and the generation for the Demand.
	-- @arg event A representation of a time instant when the simulation engine must run.
	-- @arg luccMEModel A luccME Model.
	-- @usage --DONTRUN
	-- component.verify(event, self)
	component.verify = function(self, event, luccMEModel)
		print("Verifying Demand parameters")
		local yearsSimulated = (luccMEModel.endTime - luccMEModel.startTime) + 1

		--  Check the final year for interpolation
		if (self.finalYearForInterpolation == nil) then
			error("\nfinalYearForInterpolation is missing\n", 5)
		end

		--  Land use types for interpolation (correct number of uses)
		if (self.finalLandUseTypesForInterpolation == nil) then
			error("\nfinalLandUseTypesForInterpolation is missing\n", 5)
		end

		--  Check the number of parameters for the interpolation (initial and final)
		if (#self.finalLandUseTypesForInterpolation ~= #luccMEModel.landUseTypes) then
			error("\nlandUseTypes and finalLandUseTypesForInterpolation MUST have the same number of parameters\n", 5)
		end

		-- Check, if used, the number of direction parameters
		if (self.directionForInterpolation ~= nil) then
			if (#self.finalLandUseTypesForInterpolation ~= #self.directionForInterpolation) then
				error("\nfinalLandUseTypesForInterpolation and directionForInterpolation MUST have the same number of parameters\n", 5)
			end
		end

		-- Check the number of years to simulate
		if (yearsSimulated == 0) then
			error("The simulation time is zero", 5)
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
	
	-- Generate the annual demand based on the data provided by the user.
	-- @arg event A representation of a time instant when the simulation engine must run.
	-- @arg luccMEModel A luccME Model.
	-- @return annualDemand The annual demand.
	-- @usage --DONTRUN
	-- component.generateDemand(event, luccMEModel)
	component.generateDemand = function(self, event, luccMEModel)
		local increasing = 1
		local decreasing = -1
		local static = 0
		local parametersNumber = #luccMEModel.landUseTypes
		local j, i, k
		local initialDemand = {}
		local finalDemandForInterpolation = {}
		local interpolationFactor = {}
		local interpolationDirection = {}
		local timeToCalcInterpolation = (self.finalYearForInterpolation - luccMEModel.startTime)
		local timeToGenerateDemand = luccMEModel.endTime - luccMEModel.startTime


		-- Get the initialDemand on the database and the interpolation factor
		forEachCell(luccMEModel.cs, function(cell)
										for j, lu in pairs (luccMEModel.landUseTypes) do
											if (initialDemand[j] == nil) then
												initialDemand[j] = 0
											end
											initialDemand[j] = initialDemand[j] + (cell[lu] * luccMEModel.cs.cellArea)
										end
									end
					)

		-- Get the validation demand (finalDemandForInterpolation) on the database
		forEachCell(luccMEModel.cs, function(cell)
										for j, lu in pairs (self.finalLandUseTypesForInterpolation) do
											if (finalDemandForInterpolation[j] == nil) then
												finalDemandForInterpolation[j] = 0
											end
											finalDemandForInterpolation[j] = finalDemandForInterpolation[j] + (cell[lu] * luccMEModel.cs.cellArea)
										end
									end
					)

		-- Get the interpolationFactor for each parameter, if used the interpolationDirection too or calculate it
		for i = 1, parametersNumber, 1 do
			-- create a new row
			if (interpolationDirection[i] == nil) then
				interpolationDirection[i] = {}
			end

			-- create a new row
			if (interpolationFactor == nil) then
				interpolationFactor[i] = {}
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
				if (finalDemandForInterpolation[i] - initialDemand[i] > 0) then
					interpolationDirection[i] = increasing
				elseif (finalDemandForInterpolation[i] - initialDemand[i] < 0) then
					interpolationDirection[i] = decreasing
				else
					interpolationDirection[i] = static
				end
			end

			-- compute the interpolationFactor value
			interpolationFactor[i] = math.abs((finalDemandForInterpolation[i] - initialDemand[i]) / timeToCalcInterpolation)
		end

		-- generate the annualDemand
		for i = 1, timeToGenerateDemand + 1, 1 do
			if (self.annualDemand[i] == nil) then
				self.annualDemand[i] = {}
			end
			-- insert the initialDemand on the annualDemand
			if (i == 1) then
				for j, lu in pairs (self.finalLandUseTypesForInterpolation) do
					self.annualDemand[i][j] = initialDemand[j]
					self.annualDemand[i][j] = math.floor(self.annualDemand[i][j] + 0.5)
				end

			-- insert the finalDemandForInterpolation (validation) on the annualDemand
			elseif (i == timeToCalcInterpolation + 1) then
				for j, lu in pairs (self.finalLandUseTypesForInterpolation) do
					self.annualDemand[i][j] = finalDemandForInterpolation[j]
					self.annualDemand[i][j] = math.floor(self.annualDemand[i][j] + 0.5)
				end

			-- compute the rest of the demand
			else
				-- calculate the demand for each parameter
				for j, lu in pairs (self.finalLandUseTypesForInterpolation) do
					self.annualDemand[i][j] = self.annualDemand[i - 1][j] + (interpolationFactor[j] * interpolationDirection[j])
					self.annualDemand[i][j] = math.floor(self.annualDemand[i][j] + 0.5)
				end
			end
		end
			
		-- print the demand
		self:printDemand(initialDemand, finalDemandForInterpolation, timeToGenerateDemand, luccMEModel)

		return self.annualDemand
	end -- generateDemand

	-- Print on screen the generated demand.
	-- @arg initialDemand The demand values for the first year of simulation.
	-- @arg finalDemandForInterpolation The demand values of the end year of interpolatioin period.
	-- @arg timeToGenerateDemand The number of years to generate the demand values.
	-- @arg luccMEModel A luccME Model.
	-- @usage --DONTRUN
	-- component.printDemand(initialDemand, finalDemandForInterpolation, timeToGenerateDemand, luccMEModel)
	component.printDemand = function(self, initialDemand, finalDemandForInterpolation, timeToGenerateDemand, luccMEModel)
		-- Print on screen the demands (for conference)
		-- print the initial demand
		print("\n\tInitial Demand\t Year")
		local rowPrint = ""
		local j, i

		for j, lu in pairs (self.finalLandUseTypesForInterpolation) do
			rowPrint = rowPrint .. initialDemand[j] .. " "
		end
		
		print("\n"..rowPrint.."\t"..luccMEModel.startTime)
		rowPrint = ""

		-- print the final demand (used for the interpolation calculation)
		print("\n\tInterpolation Final Demand\t Year")
		rowPrint = ""
		
		for j, lu in pairs (self.finalLandUseTypesForInterpolation) do
			rowPrint = rowPrint .. finalDemandForInterpolation[j] .. " "
		end
		
		print("\n"..rowPrint.."\t"..self.finalYearForInterpolation)
		rowPrint = ""

		-- print all the demand (Demand that will be used on run)
		print("\n\n\tAnnual Demand\t Year")
		rowPrint = ""
		
		for i = 1, timeToGenerateDemand + 1, 1 do
			for j, lu in pairs (self.finalLandUseTypesForInterpolation) do
				rowPrint = rowPrint .. self.annualDemand[i][j] .. " "
			end
			
			print("\n"..rowPrint.."\t"..luccMEModel.startTime + (i - 1))
			rowPrint = ""
		end
		
		print("\n")
	end
	
	-- Return the current demand of the specified component.
	-- Used on discrete allocation component.
	-- @return self.currentDemand the current demand of the component.
	-- @usage --DONTRUN
	-- component.getCurrentDemand(i)
	component.getCurrentDemand = function(self)	
		return self.currentDemand
	end

	-- Return the previous demand of the specified component.
	-- @return self.previousDemand the previous demand of the component.
	-- @usage --DONTRUN 
	-- component.getPreviousDemand(i)
	component.getPreviousDemand = function(self)	
		return self.previousDemand
	end

	-- Return the current demand for an specific luIndex.
	-- Used on allocation and continuous potential components.
	-- @arg luIndex A land use index (an specific luIndex of a list of possible land uses).
	-- @return The current demand for an specific luIndex.
	-- @usage --DONTRUN
	-- component.getCurrentLuDemand(luIndex)
	component.getCurrentLuDemand = function(self, luIndex)		
		if (luIndex > self.numLU) then
			error("Invalid land use index", 5)
		end

		return self.currentDemand[luIndex]
	end

	-- Return the previous demand for an specific luIndex.
	-- Used on continuous pontencial component.
	-- @arg luIndex A land use index (an specific luIndex of a list of possible land uses).
	-- @return The previous demand for an specific luIndex.
	-- @usage --DONTRUN
	-- component.getPreviousLuDemand(luIndex)
	component.getPreviousLuDemand = function(self, luIndex)	
		if (luIndex > self.numLU) then
			error("Invalid land use index", 5)
		end	

		return self.previousDemand[luIndex]
	end

	-- Return the current demand direction for an specific luIndex.
	-- Used on continuous allocation component.
	-- @arg luIndex A land use index (an specific luIndex of a list of possible land uses).
	-- @return The current demand direction for an specific luIndex.
	-- @usage --DONTRUN
	-- component.getCurrentLuDirection(luIndex)
	component.getCurrentLuDirection = function(self, luIndex)	
		if (luIndex > self.numLU) then
			error("Invalid land use index", 5)
		end	

		return self.demandDirection[luIndex]
	end	

	-- Invert the demand direction for an specific luIndex.
	-- Used on continuous allocation component.
	-- @arg luIndex A land use index (an specific luIndex of a list of possible land uses).
	-- @return The current demand direction for an specific luIndex.
	-- @usage --DONTRUN
	-- component.changeLuDirection(luIndex)
	component.changeLuDirection = function(self, luIndex)
		local oppositeDirection = -1

		if (luIndex > self.numLU) then
			error("Invalid land use index", 5)
		end

		self.demandDirection[luIndex] = self.demandDirection[luIndex] * oppositeDirection

		return self.demandDirection[luIndex]
	end		

	collectgarbage("collect")
	return component
end -- DemandComputeTwoDates
	