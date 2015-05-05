--- Modification of the SpatialLagRegression component to allow the use of simple linear regression in specific cases, 
-- when roads are created or paved. The component is an example of how the framework can be extended for specific 
-- applications. It was created to allow the representation of the creation new deforestation frontiers in the Brazilian Amazon.
-- @arg component A Spatial Lag Regression component.
-- @arg component.regressionData A table with the regression parameters for each attribute.
-- @arg component.regressionData.const A linear regression constant.
-- @arg component.regressionData.ro Auto regressive coefficient.
-- @arg component.regressionData.minReg A coefficient to minimize the regression value.
-- @arg component.regressionData.maxReg A coefficient to potentiality the regression value.
-- @arg component.regressionData.betas A linear regression betas for land use drivers
-- and the index of landUseDrivers to be used by the regression (attributes).
-- @arg component.regressionData.isLog Inform whether the model is part of a coupling model.
-- @arg component.landUseDrivers The land use drivers fields in database.
-- @arg component.execute Handles with the execution method of a SpatialLagLinearRoads component.
-- @arg component.verify Handles with the verify method of a SpatialLagLinearRoads component.
-- @arg component.modify Handles with the modify method of a SpatialLagLinearRoads component.
-- @arg component.modifyRegression Handles with the modify regression method of a
-- SpatialLagLinearRoads component.
-- @arg component.adaptRegressionConstants Handles with the constants regression method of a
-- SpatialLagLinearRoads component.
-- @arg component.computePotential Handles with the modify method of a SpatialLagLinearRoads component.
-- @return The modified component.
-- @usage myPontencial = SpatialLagLinearRoads {
-- regressionData =	{
-- 					--Natural vegetation
--					{ isLog = false, ro = 0.1, const  = -0.1, minReg = 0.15, maxReg = 0.92,
--					  betas = {beta1 =	-0.05, beta2 =	0.2, beta3 = 0.1}},
--					-- Deforestation
--					{ isLog = false, ro = 0.3, const  = -0.3, minReg = 0.13, maxReg = 0.89,
--					  betas = {beta1 =	0.03, beta2 =	0.6, beta3 = 0.01}},
--					-- Others
--					{ isLog = false, ro = 0, const  = 0, minReg = 0, maxReg = 1,
--					  betas = {beta1 =	0}}
--					},
--		 			landUseNoData = "UsesPrcClass",
--}
function SpatialLagLinearRoads(component)
	--- Handles with the execution method of a SpatialLagLinearRoads component.
	-- @arg self A SpatialLagLinearRoads component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
	-- @usage self.potential:execute(event, model)
	component.execute = function(self, event, luccMEModel)
		local cs = luccMEModel.cs
		local luDrivers = self.landUseDrivers
		local luTypes = luccMEModel.landUseTypes
		local demand = luccMEModel.demand
		
        -- create an internal constant that can be modified during allocation
		for i, luData in pairs (self.regressionData) do
			if (luData.const == nil) then
				luData.const = 0
			end
			
			if (luData.minReg == nil) then
				luData.minReg = 0
			end
			
			if (luData.maxReg == nil) then
				luData.maxReg = 1
			end
			
			luData.newconst = luData.const
			luData.newminReg = luData.minReg
			luData.newmaxReg = luData.maxReg
		end
		
		if (self.constChange == nil) then
			self.constChange = 0.1 			-- original clue value
		end

        if (event:getTime() > luccMEModel.startTime) then
			self:adaptRegressionConstants(demand, event) -- LOG TIRAR
        end
	
		for i, luData in pairs (self.regressionData) do
		    self:computePotential(luccMEModel, i, event)
	    end
	end  -- function execute
	
	--- Handles with the verify method of a SpatialLagLinearRoads component.
	-- @arg self A SpatialLagLinearRoads component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
	-- @usage self.potential:verify(event, self)
	component.verify = function(self, event, luccMEModel)
		cs = luccMEModel.cs

		forEachCell(cs, function(cell)
							cell["alternate_model"] = 0
						end
					)

		for i, luData in pairs (self.regressionData) do
			if (luccMEModel.landUseTypes[i] == nil) then
				error("Invalid number of regressions", 2)
			end
			for var, beta in pairs (luData.betas) do
				if (luccMEModel.cs.cells[1][var] == nil) then
					error("Invalid land use driver", 2)
				end
			end
			if (luData.ro == nil) then
				error("ro parameter must be defined", 2)
			end	
		end

		local find = false	

		if (luccMEModel.landUseNoData == nil) then
			find = true
			luccMEModel.landUseNoData = "defaultlandUseNoData"

			forEachCell(cs, function(cell)
								cell[luccMEModel.landUseNoData] = 0
							end
						)
		end		

		for j, lu in pairs (luccMEModel.landUseTypes) do
			if (self.regressionData[j] == nil) then
				error("Invalid number of regressions", 2)
			end

			if (luccMEModel.landUseNoData == lu) then
				find = true
			end
		end
			
		if (find == false) then	
			error("Invalid land use no data variable", 2)
		end

		local filename = self.filename
		
		if (filename ~= nil) then
			loadGALNeighborhood(filename)
		else
			cs:createNeighborhood()	
		end
	end

	--- Handles with the modify method of a SpatialLagLinearRoads component.
	-- @arg self A SpatialLagLinearRoads component.
	-- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
	-- @arg luIndex A land use index (an specific luIndex of a list of possible land uses).
	-- @arg direction The direction for the regression.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXxxx
	component.modify = function(self, luccMEModel, luIndex, direction, event)
		luData = self.regressionData[luIndex]

		if (luData.newconst == nil) then
			luData.newconst = 0
		end	
		if (luData.isLog) then
			local const_unlog = math.pow(10, luData.newconst) + self.constChange * direction
			if (const_unlog ~= 0) then
				luData.newconst = math.log(10, const_unlog)
			end	
		else
			luData.newconst = luData.newconst + self.constChange * direction
		end

		self:computePotential(luccMEModel, luIndex, event)
	end	-- function	modifyPotential

	-------------------------------------------------------------------
	-- SUBROUTINES FOR THIS COMPONENT
	-------------------------------------------------------------------
	--- Handles with the modify regression method of a SpatialLagLinearRoads component.
	-- @arg self A SpatialLagLinearRoads component.
	-- @arg roadsModel A road model.
	-- @arg cell A spatial location with homogeneous internal content.
	-- @arg oldRegression XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage self:modifyRegression(luData.roadsModel, cell, regression, event)
	component.modifyRegression = function(self, roadsModel, cell, oldRegression, event)
		currentTime = event:getTime()
		local regression = roadsModel.const

		for var, beta in pairs (roadsModel.betas) do
			regression = regression + beta * cell[var]
		end

		if (currentTime < cell["alternate_model"] + 3) then
			return regression
		end
		
		if (currentTime == cell["alternate_model"] + 3) then
			  cell["alternate_model"] = 0
		end

		for i, attr in pairs (roadsModel.attrs) do
			local diff = cell[attr] - cell.past[attr]
			if ((roadsModel.change < 0 and diff < 0 and diff < roadsModel.change) or
				(roadsModel.change > 0 and diff > 0 and diff > roadsModel.change)) then
					cell["alternate_model"]  = currentTime
					return regression
			end
		end
		
		return oldRegression
	end

	--- Handles with the constants regression method of a SpatialLagLinearRoads component.
	-- @arg self A SpatialLagLinearRoads component.
	-- @arg demand A demand to calculate the potential.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage self:adaptRegressionConstants(demand, event)
	component.adaptRegressionConstants = function(self, demand, event)
		for i, luData in pairs (self.regressionData) do			
			local currentDemand = demand:getCurrentLuDemand(i)
			local previousDemand = demand:getPreviousLuDemand(i)
			local plus = 0.01 * ((currentDemand - previousDemand) / previousDemand)

			luData.newconst = luData.const
				
			if (luData.isLog) then
				local const_unlog = math.pow(10, luData.newconst) + plus
				if (const_unlog ~= 0) then
					luData.newconst = math.log(10, const_unlog)
				end
			else
				luData.newconst = luData.newconst + plus
			end

			luData.newminReg = luData.newminReg + plus
			luData.newmaxReg = luData.newmaxReg + plus
			luData.const = luData.newconst
		end
	end	-- function adaptRegressionConstants
	
	--- Handles with the compute potential method of a SpatialLagLinearRoads component.
	-- @arg self A SpatialLagLinearRoads component.
	-- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
	-- @arg luIndex A land use index (an specific luIndex of a list of possible land uses).
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage self:computePotential(luccMEModel, luIndex, event)
	component.computePotential = function(self, luccMEModel, luIndex, event)
		local cs = luccMEModel.cs	
		local luTypes = luccMEModel.landUseTypes
		local lu = luTypes[luIndex]
		local luData = self.regressionData[luIndex]
		local pot = lu.."_pot"

		for k, cell in pairs (cs.cells) do
			local regressionX = 0
			local regresY = 0   
			local neighSum = 0
			local count = 0
			
			for var, beta in pairs (luData.betas) do
				regressionX = regressionX + beta * cell[var]
			end
			
			regresDrivers = regressionX
			
			forEachNeighbor (cell, function(cell, neigh, weight)
										Y = cell.past[lu]
										neighY = neigh.past[lu]

										if (cell[luccMEModel.landUseNoData] ~= 1) then
											Y = Y / (1 - cell[luccMEModel.landUseNoData])
										end
										if (neigh[luccMEModel.landUseNoData] ~= 1) then
											neighY = neighY / (1 - neigh[luccMEModel.landUseNoData])
										end

										if (neigh[luccMEModel.landUseNoData] < 1) then
											count = count + 1
											neighSum = neighSum + neighY
										end
									end
							)
		
			if (count > 0) then
				regresY = ((Y + neighSum) / (count + 1)) * luData.ro  
			else
				regresY = Y * luData.ro
			end	
			
			if (luData.isLog) then -- if the land use is log transformed
				regresY = math.log(10, regresY + 0.0001)  
			end

	        local regression = luData.newconst + regressionX + regresY		
			local regressionLimit = luData.const + regressionX + regresY   		
	
			if (luData.roadsModel ~= nil) then
			    local newRegression = self:modifyRegression(luData.roadsModel, cell, regression, event)
				
				if (newRegression ~= regression) then
				     regression = newRegression
				     regressionLimit = regression
				end
		    end

			if (luData.isLog) then -- if the land use is log transformed
				regression = math.pow(10, regression) - 0.0001			
				regressionLimit = math.pow(10, (regressionLimit)) - 0.0001
			end

			if (regressionLimit > luData.maxReg) then
				regression = 1
			end
				
			if (regressionLimit < luData.minReg) then
				regression = 0
			end
					
			if (regression > 1) then
				regression = 1
			end
				
			if (regression < 0) then
				regression = 0
			end

			regression = regression * (1 - cell[luccMEModel.landUseNoData])
			cell[pot] = regression - cell.past[lu]
		end
	end  -- function computePotential

   return component
end -- component definition
