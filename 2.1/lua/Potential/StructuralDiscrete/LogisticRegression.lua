--- Calculates  potential of change  for each cell, based on logistic regression coefficients.
-- Can be used when land use data are discrete.
-- @arg model A Logistic Regression model.
-- @arg model.regressionData A table with the regression parameters for each attribute.
-- @arg model.regressionData.const A linear regression constant.
-- @arg model.regressionData.error A linear regression estimate error.
-- @arg model.regressionData.betas A linear regression betas for land use drivers
-- and the index of landUseDrivers to be used by the regression (attributes).
-- @arg model.regressionData.elasticity An elasticity value, closer to 1 is more difficulty
-- to transition for other land uses.
-- @arg model.landUseDrivers The land use drivers fields in database.
-- @arg model.execute Handles with the execution method of a LogisticRegression model.
-- @arg model.verify Handles with the verify method of a LogisticRegression model.
-- @arg model.calcRegressionLogistic Handles with the calculation of the regression
-- @arg model.probability Compute the probability logistic method of a LogisticRegression model.
-- @return The modified model.
-- @usage myPontencial = LogisticRegression {
-- regressionData =	{
-- 					-- Region 1
--					{ const  = -0.1,
--					  betas = {beta1 =	-0.05, beta2 =	0.2, beta3 = 0.1},
--					  elasticity = 0.5},
--					-- Region 2
--					{ isLog = false, error = 0.3, const  = -0.3,
--					  betas = {beta1 =	0.03, beta2 =	0.6, beta3 = 0.01},
--					  elasticity = 0.1},
--					-- Region 3
--					{ isLog = false, error = 0, const  = 0,
--					  betas = {beta1 =	0},
--					  elasticity = 0.5},
--					},
--					landUseDrivers = {}
--}
function LogisticRegression(model)  --@todo verificar o LandUse
	--- Handles with the execution method of a LogisticRegression model.
	-- @arg self A LogisticRegression model.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg modelParameters A parameter model.
	-- @usage self.potential:execute(event, model)
	model.execute = function(self, event, modelParameters)
		local cs = modelParameters.cs
		local regressionData = self.regressionData
 		local luTypes = modelParameters.landUseTypes
 		local landUseDrivers = self.landUseDrivers
  		
  		for k, cell in pairs (cs.cells) do
			if (modelParameters.region == nil) then
				cell.region = 1
			end

 			for luind, inputValues in pairs (regressionData[cell.region]) do
				local lu = luTypes[luind]
  				
  				-- Step 1: Calculates the regression estimates
   				local regrLogit = model.calcRegressionLogistic(cell, inputValues, landUseDrivers, self)
				
   				-- Step 2: Calculates the elasticity
				local elas = 0				
				if (cell[lu] == 1) then
					elas = inputValues.elasticity
				end	
				
				--Step 3 : Computes the total probability
				cell[lu.."_pot"] = regrLogit + elas
			end	--close for region
		end -- close for cell
	end
	
	--- Handles with the verify method of a LogisticRegression model.
	-- @arg self A LogisticRegression model.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage self.potential:verify(event, self)
	model.verify = function(self, event)
	end
	
	--- Handles with the calculation of the regression logistic method of a LogisticRegression model.
	-- @arg cell A spatial location with homogeneous internal content.
	-- @arg inputValues A parameter model.
	-- @arg luDrivers The land use drivers fields in database.
	-- @arg model A LogisticRegression model.
	-- @usage model.calcRegressionLogistic(cell, inputValues, landUseDrivers, self)
	model.calcRegressionLogistic = function(cell, inputValues, luDrivers, model)
		local regrLogit = inputValues.const
		local betas = inputValues.betas
		local attrs = inputValues.attributes
	
		for var, beta in pairs (betas) do
			regrLogit = regrLogit + beta * cell[var]
		end
			
		return (model.probability(regrLogit))
	end	--end calcRegressionLogistic
	
	--- Compute the probability.
	-- @arg z A value used to calculate the probability (second parameter of a pow).
	-- @usage model.probability(regrLogit)
	model.probability = function(z)
		local euler  = 2.718281828459045235360287;
		local zEuler = math.pow(euler, z);
		local prob = zEuler/(1 + zEuler);
		
		return prob
	end
	
	return model
 end --close RegressionLogistcModel	
