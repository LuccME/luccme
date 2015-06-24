--- Handles with a LuccME model behaviour.
-- @arg model.name The model name.
-- @arg model.startTime The initial year of simulation.
-- @arg model.endTime The final year of simulation.
-- @arg model.cs The spatial dimension definition (CellularSpace).
-- @arg model.landUseTypes The name of the use land types for simulation.
-- @arg model.landUseNoData The name of land use that is not consider on the simulation.
-- @arg model.potential The name of component that calculates the potential of change  for each cell.
-- @arg model.allocation The name of component that handles with the allocation on the cell
-- based on it potential and demand.
-- @arg model.demand The name of component that handles with the allocation demand.
-- @arg model.save The name of component that handles with the simulation data save in a database.
-- @arg model.isCoupled A flag to inform with the model for simulation is coupled to another.
-- @arg model.execute Handles with the execution method of a LuccMe model.
-- @arg model.verify Handles with the verify method of a LuccMe model.
-- @arg model.dinamicVars Handles with the dinamicVars method of a LuccMe model.
-- @usage MyModel = LuccMEModel {
-- -- APPLICATION MODEL DEFINITION
-- name = "MyModel_1",
-- startTime = 2013,
-- endTime = 2015,
-- cs = CellularSpace {database = "myDatabase.mdb", theme = "myTheme", cellArea = 1},
-- landUseTypes = {"Deforest", "Forest", "Others"},
-- landUseNoData = "Border",
-- potential = NeighSimpleRule {},
-- allocation = AllocationByOrdering {maxDifference = 0.001},
-- demand  = PreComputedValuesAutoDemand {finalYearForInterpolation = 2015,
--										  landUseTypesForInterpolation = {"D", "F", "O"}},					
-- save = {outputTheme = "myTheme_", yearly = true},
-- isCoupled = false
--}
-- -- ENVIROMMENT DEFINITION
-- timer = Timer {Event { time = MyModel.startTime, period = 1, priority = 1,
--						  action = function(event) MyModel:execute(event) end }}
-- envMymodel = Environment{}
-- envMymodel:add(timer)
-- -- ENVIROMMENT EXECUTION
-- if MyModel.isCoupled == false then
-- 	saveResults = databaseSave(MyModel)
-- 	envMymodel:add(saveResults)
-- 	envMymodel:execute(MyModel.endTime)
-- 	saveSingleTheme(MyModel, true)
-- end
function LuccMEModel(model)
	--- Implements the execution method of a LuccMe model.
	-- @arg self The LuccMe model itself.
	-- @arg event An Event represents a time instant when the simulation engine must execute some computation.
	-- @usage luccMeModel:execute(event)
	model.execute = function(self, event)
		if (event:getTime() == self.startTime) then
			model:verify(event)
		end
		
		if (self.updateYears ~= nil) then
			model:dinamicVars(event)
		end
		
		-- execute the components 
		self.demand:execute(event, model)
	  self.potential:execute(event, model)
		self.allocation:execute(event, model)
	end

	--- Implements the verify method of a LuccMe model.
	-- @arg self The LuccMe model itself.
	-- @arg event An Event represents a time instant when the simulation engine must execute some computation.
	-- @usage luccMeModel:verify(event)
	model.verify = function(self, event)
	  -- Verify the model name
		if (model.name == nil) then
			error("Model name not defined", 2)
		end
	
	  -- Verify the scenario name
		if (self.name == nil) then
			error("A scenario name is required", 2)
		end
	 
	  -- Verify the scenario start time
		if (self.startTime == nil) then
			error("A scenario start time is required", 2)
		end
	
	  -- Verify the scenario stop time
    if (self.endTime == nil) then
      error("A scenario end time is required", 2)
    end
    
    -- Verify the scenario date
    if (self.endTime <= self.startTime) then
      error("The scenario end time must be higher than the scenario start time", 2)
    end

    -- Verify the cellular space
    if (not self.cs) then
      error("A Cellular Space must be defined", 2)
    end

    -- Verify whether the land use no data is declared and its valid
    if(self.landUseNoData == nil) then
      error("Land use no data type is missing", 2)
    elseif(self.cs.cells[1][self.landUseNoData] == nil) then
      error("landUseNoData: "..self.landUseNoData.." not found within database", 2)
    end
    
		self.result = {}

		-- Verify whether the attributes to be saved were calculated in the model
		for i, lu in pairs (self.landUseTypes) do
			if (self.cs.cells[1][lu] == nil) then
				error("landUseType: "..lu.." not found within database", 2)
			end
			local equal = 1
		end
		
		if (equal == 0) then
			error("Attributes to be saved must be calculated as land use type in the model", 2)
		end

		local luTypes = self.landUseTypes
		local cs = self.cs
		
		if (cs.cells[1].past[luTypes[1]] == nil) then
			cs:synchronize()
		end
		
		-- Print model status during its execution
		if (self.useLog == nil) then
			self.useLog = true 			
		end
		
		-- Inform whether the model is part of a coupling model
		if (self.isCoupled == nil) then
			isCoupled = false 			
		end
		
		io.flush()
		
		-- Verify wheter the demand compontent was declared
    if (not self.demand) then
        error("A demand component must be specified", 2)
    end
    
    -- Verify wheter the potential compontent was declared
    if (not self.potential) then
      error("A potential component must be specified", 2)     
    end
		
		-- Verify wheter the allocation compontent was declared
    if (not self.allocation) then
      error("An allocation component must be specified", 2)     
    end
    
    -- Verify the dates to be saved
    -- This verification is done on Save.lua, because it necessary to execute before here.

		-- Verify the components
		self.demand:verify(event, self)
		self.potential:verify(event, self)
		self.allocation:verify(event, self)
	end
	
	--- Implements the variables dynamic method of a LuccMe model.
	-- @arg self The LuccMe model itself.
	-- @arg event An Event represents a time instant when the simulation engine must execute some computation.
	-- @usage luccMeModel:dinamicVars(event)
	model.dinamicVars = function(self, event)
		currentTime = event:getTime()
		
		for i, updtYear in pairs (self.updateYears) do
			-- If current year needs to update variables
			if (currentTime == updtYear) then
				print("Updating dynamic variables...")
				if ((self.scenarioStartTime ~= nil) and (currentTime >= self.scenarioStartTime)) then
				    cs_temp = CellularSpace {	host = self.cs.host, user = self.cs.user, password = self.cs.password,
              												database = self.cs.database,
              												theme = self.cs.theme.."_"..self.scenarioName.."_"..updtYear
											              }
					print (self.cs.theme.."_"..self.scenarioName.."_"..updtYear)
				else
					cs_temp = CellularSpace {	host = self.cs.host, user = self.cs.user, password = self.cs.password,
				      							        database = self.cs.database,
												            theme = self.cs.theme.."_"..updtYear
											            }
					print (self.cs.theme.."_"..updtYear)
				end

				-- For each cell in the original cs, variables are contained in cs_temp is updated
				local flag = false
			       		
		    forEachCellPair(cs, cs_temp, function(cell, cell_temp)
              													for var, value in pairs (cell_temp) do
              														if (var ~= "cObj_" and var ~= "objectId_" and
              															var ~= "y" and var ~= "x" and var ~= "past" and
              															var ~= "agents" and var ~= "agents_" and
              															var ~= "object_id_") then
              																if (cell[var] ~= nil) then
              																	cell[var] = cell_temp[var]
              																	if (flag == false) then
              																		print("          ", var, cell[var])
              																	end		          					
              																end
              														end -- 1st inner if
              													end -- for var
              													flag = true
              											 end -- function
							          )
			end -- if currentTime
		end -- for				
	end -- dinamicVars

	return model
end
