--- XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
-- @arg model A AttractRepulseLogisticRegression model.
-- @arg model.regressionData A table with the regression parameters for each attribute.
-- @arg model.regressionData.const A linear regression constant.
-- @arg model.regressionData.error A linear regression estimate error.
-- @arg model.regressionData.betas A linear regression betas for land use drivers
-- and the index of landUseDrivers to be used by the regression (attributes).
-- @arg model.regressionData.elasticity An elasticity value, closer to 1 is more difficulty
-- to transition for other land uses.
-- @arg model.regressionData.percNeighborsUse Percent of neighbours with the same use.
-- @arg model.landUseDrivers The land use drivers fields in database.
-- @arg model.execute Handles with the execution method of a AttractRepulseLogisticRegression model.
-- @arg model.verify Handles with the verify method of a AttractRepulseLogisticRegression model.
-- @arg model.toIndex Return an index to an specific land use.
-- @arg model.calcRegressionLogistic Handles with the calculation of the regression.
-- @arg model.probability Compute the probability logistic method of a AttractRepulseLogisticRegression model.
-- @return The modified model.
-- @usage myPontencial = NeighAttractionLogisticRegression {
-- regressionData =	{
-- 					-- Region 1
--					{ const  = -0.1,
--					  betas = {beta1 =	-0.05, beta2 =	0.2, beta3 = 0.1},
--					  elasticity = 0.5, percNeighborsUse = 0.5},
--					-- Region 2
--					{ isLog = false, error = 0.3, const  = -0.3,
--					  betas = {beta1 =	0.03, beta2 =	0.6, beta3 = 0.01},
--					  elasticity = 0.1, percNeighborsUse = 0.2},
--					-- Region 3
--					{ isLog = false, error = 0, const  = 0,
--					  betas = {beta1 =	0},
--					  elasticity = 0.5, percNeighborsUse = 0.5},
--					},
--					landUseDrivers = {},
--}
function AttractRepulseLogisticRegression(model)
	--- Handles with the execution method of a AttractRepulseLogisticRegression model.
	-- @arg self A AttractRepulseLogisticRegression model.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg modelParameters A parameter model.
	-- @usage self.potential:execute(event, model)
	model.execute = function(self, event, modelParameters)
		local cs = modelParameters.cs
		local luTypes = modelParameters.landUseTypes
		local regressionData = self.regressionData
		local landUseDrivers = self.landUseDrivers
		local filename = self.filename
		
		if (filename ~= nil) then
			loadGALNeighborhood(filename)
		else
			createMooreNeighborhood(cs)	
		end
 		
		local totalNeigh = 0
  		
  		for k, cell in pairs (cs.cells) do
  		 	if (model.region == nil) then
				cell.region = 1
			end
			
			-- Initialization
			totalNeigh = cell:getNeighborhood():size() - 1
			
			for i, inputValues in pairs (regressionData[cell.region]) do
				local lu = luTypes[i]
				if (cell[lu] == 1) then		
					cellType = toIndex(lu, luTypes)
				end
				cell["tau_"..lu] = 0.0
			end

			-- "TAU": ATTRACTION/REPULSION FACTOR
			for luind, inputValues in pairs (regressionData[cell.region]) do
				local lu = luTypes[luind]
				
				-- Step 1: Count neighbours
				local numNeigh = 0;
				forEachNeighbor(cell, function(cell, neigh)			
											if (neigh[lu] == 1 and neigh ~= cell) then		
												numNeigh = numNeigh + 1
											end						
										end
								)
				
				-- Step 2: Compute weight
				d = inputValues.percNeighborsUse * totalNeigh
				if (numNeigh < d) then
					w = 0.0
				elseif (numNeigh >= d) then
					w = (numNeigh - d) / (totalNeigh - d)
				end
				
				-- Step 3: Compute Attraction/Repulsion factor
				cell["tau_"..lu] = cell["tau_"..lu] + self.affinityMatrix[cell.region][cellType][luind] * w
				
				-- Step 4: Elasticity
				local elas = 0				
				if (cell[lu] == 1) then
					elas = inputValues.elasticity
				end
				
				-- Step 5: Calculates the regression estimates
				local regrProb = model.calcRegressionLogistic(cell, inputValues, landUseDrivers,self)
				
				-- Step 6: Compute the potential
				cell["suit_"..lu] = regrProb + elas
			end -- use type
		end -- end cells
	end -- end execute

	--- Return an index to an specific land use.
	-- @arg lu A specific land use.
	-- @arg usestype A set of land use types.
	-- @usage toIndex(lu, luTypes)
	function toIndex(lu, usetypes)
		local index = 0
				for i, value in pairs (usetypes) do
					if (value == lu) then
						index = i
						break
					end
				end
		return index
	end
	
	--- Handles with the verify method of a AttractRepulseLogisticRegression model.
	-- @arg self A AttractRepulseLogisticRegression model.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage self.potential:verify(event, self)
	model.verify = function(self, event)
		local range_drivers = #self.landUseDrivers
		
		for i, inputValues in pairs (self.regressionData[1]) do
			if (#inputValues.betas ~= #inputValues.attributes) then
				error("Betas and attributes must have the same size", 3)
			end
			for i, attr in pairs (inputValues.attributes) do
				if ((attr < 1) or (attr > range_drivers)) then
					error ("Invalid attribute index", 3)
				end
			end
		end
	end
	
	--- Handles with the calculation of the regression.
	-- logistic method of a AttractRepulseLogisticRegression model.
	-- @arg cell A spatial location with homogeneous internal content.
	-- @arg inputValues A parameter model.
	-- @arg luDrivers The land use drivers fields in database.
	-- @arg model A AttractRepulseLogisticRegression model.
	-- @usage model.calcRegressionLogistic(cell, inputValues, landUseDrivers,self)
	model.calcRegressionLogistic = function(cell, inputValues, luDrivers, model)
		local regrLogit = inputValues.const
		local betas = inputValues.betas
		local attrs = inputValues.attributes
		
		for i, coef in pairs (betas) do
			local driverIndex = attrs[i]
			local driver = cell[luDrivers[driverIndex]]
			
			if (driver == nil) then
				print("Atribute "..driver.." not found in database")
				os.exit()
			end
			regrLogit = regrLogit + coef * driver
		end
		
		return model.probability(regrLogit)
	end	
	
	--- Compute the probability.
	-- @arg z A value used to calculate the probability (second parameter of a pow).
	-- @usage model.probability(regrLogit)
	model.probability = function(z)
		local euler  = 2.718281828459045235360287
		local zEuler = math.pow(euler, z)
		local prob = zEuler / (1 + zEuler)
			
		return prob
	end
	
	return model
end --close RegressionLogistcModelNeighbourhood
