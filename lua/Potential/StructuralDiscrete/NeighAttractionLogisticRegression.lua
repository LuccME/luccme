--- Calculates  potential of change  for each cell, based on logistic regression coefficients,
-- considering cells neighbourhood. Can be used when land use data are discrete.
-- @arg model A NeighAttractionLogisticRegression model.
-- @arg model.regressionData A table with the regression parameters for each attribute.
-- @arg model.regressionData.const A linear regression constant.
-- @arg model.regressionData.error A linear regression estimate error.
-- @arg model.regressionData.betas A linear regression betas for land use drivers
-- and the index of landUseDrivers to be used by the regression (attributes).
-- @arg model.regressionData.elasticity An elasticity value, closer to 1 is more difficulty
-- to transition for other land uses.
-- @arg model.regressionData.percNeighborsUse Percent of neighbours with the same use.
-- @arg model.landUseDrivers The land use drivers fields in database.
-- @arg model.execute Handles with the execution method of a NeighAttractionLogisticRegression model.
-- @arg model.verify Handles with the verify method of a NeighAttractionLogisticRegression model.
-- @arg model.calcRegressionLogistic Handles with the calculation of the regression.
-- @arg model.probability Compute the probability logistic method of a NeighAttractionLogisticRegression model.
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
function NeighAttractionLogisticRegression(model)
	--- Handles with the execution method of a NeighAttractionLogisticRegression model.
	-- @arg self A NeighAttractionLogisticRegression model.
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
			cs:createNeighborhood()		
		end
 		
		local totalNeigh = 0
  		
  		for k, cell in pairs (cs.cells) do
			totalNeigh = cell:getNeighborhood():size()
  		 	
			if (model.region == nil) then
				cell.region = 1
			end 	
			
			for luind, inputValues in pairs (regressionData[cell.region]) do
				local lu = luTypes[luind]
				
				-- Step 1: Calculates the regression estimates
				local regrProb = model.calcRegressionLogistic(cell, inputValues, landUseDrivers, self)
				
				-- Step 2: Calculates the elasticity
				local elas = 0				
				if (cell[lu] == 1) then
					elas = inputValues.elasticity
				end	
				
				-- Step 3: Consider the neighbours
				local numNeigh = 0;
				
				forEachNeighbor(cell, function(cell, neigh)				
											if (neigh[lu] == 1 and neigh ~= cell) then					
												numNeigh = numNeigh + 1
											end
										end
								)
				
				-- Step 4: Compute potential
				if numNeigh <= (totalNeigh * inputValues.percNeighborsUse - 1) then
				   cell[lu.."_pot"] = regrProb + elas 				
				elseif numNeigh > (totalNeigh * inputValues.percNeighborsUse - 1) then
					cell[lu.."_pot"] = (regrProb + elas) * (numNeigh / (totalNeigh * inputValues.percNeighborsUse))
				end
			end
		end
	end -- end execute
	
	--- Handles with the verify method of a NeighAttractionLogisticRegression model.
	-- @arg self A NeighAttractionLogisticRegression model.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage self.potential:verify(event, self)
	model.verify = function(self, event)
	end
	
	--- Handles with the calculation of the regression.
	-- logistic method of a NeighAttractionLogisticRegression model.
	-- @arg cell A spatial location with homogeneous internal content.
	-- @arg inputValues A parameter model.
	-- @arg luDrivers The land use drivers fields in database.
	-- @arg model A NeighAttractionLogisticRegression model.
	-- @usage model.calcRegressionLogistic(cell, inputValues, landUseDrivers, self)
	model.calcRegressionLogistic = function(cell, inputValues, luDrivers, model)
			local regrLogit = inputValues.const
			local betas = inputValues.betas
			local attrs = inputValues.attributes
		
			for var, beta in pairs (betas) do
				regrLogit = regrLogit + beta * cell[var]
			end
			
		return model.probability(regrLogit)
	end	--end calcRegressionLogistic
	
	--- Compute the probability.
	-- @arg z A value used to calculate the probability (second parameter of a pow).
	-- @usage model.probability(regrLogit)
	model.probability = function(z)
		local euler  = 2.718281828459045235360287
		local zEuler = math.pow(euler, z)
		local prob = zEuler/(1 + zEuler)
			
		return prob
	end
	
	return model
end --close RegressionLogistcModelNeighbourhood
