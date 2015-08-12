--- Uses logistic regression techniques to compute cell probability for each land use. 
-- Based on the original CLUE-S framework potential calculation (Verburg et al., 2002), 
-- modifies the probability with a user defined elasticity, for the current land use.
-- @arg component A Logistic Regression component.
-- @arg component.regressionData A table with the regression parameters for each attribute.
-- @arg component.regressionData.const A linear regression constant.
-- @arg component.regressionData.error A linear regression estimate error.
-- @arg component.regressionData.betas A linear regression betas for land use drivers
-- and the index of landUseDrivers to be used by the regression (attributes).
-- @arg component.regressionData.elasticity An elasticity value, closer to 1 is more difficulty
-- to transition for other land uses.
-- @arg component.landUseDrivers The land use drivers fields in database.
-- @arg component.execute Handles with the execution method of a LogisticRegression component.
-- @arg component.verify Handles with the verify method of a LogisticRegression component.
-- @arg component.calcRegressionLogistic Handles with the calculation of the regression
-- @arg component.probability Compute the probability logistic method of a LogisticRegression component.
-- @return The modified component.
-- @usage potential  =  LogisticRegression {
--    regressionData = { 
--                      --  Region 1
--                      {
--                        {const = 0.01, betas = {dist_estradas = 0.5, dist_br = 0.3}, elasticy = 0.5},  --D
--                        {const = 0.01, betas = {dist_estradas = -0.5}, elasticy = 0.5},                --F
--                        {const = 0.00, betas = {dist_estradas = 0}, elasticy = 0.5}                    --O 
--                      }  
--                     } 
--  }
function LogisticRegression(component) 
	--- Handles with the execution method of a LogisticRegression component.
	-- @arg self A LogisticRegression component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg luccMEModel A parameter model.
	-- @usage self.potential:execute(event, model)
	component.execute = function(self, event, luccMEModel)
		local cs = luccMEModel.cs
		local regressionData = self.regressionData
 		local luTypes = luccMEModel.landUseTypes
 		local landUseDrivers = self.landUseDrivers
  		
		for k, cell in pairs (cs.cells) do
  		if (cell.region == nil) then
  			cell.region = 1
  		end
  
  		for luind, inputValues in pairs (regressionData[cell.region]) do
  			local lu = luTypes[luind]
  				
  			-- Step 1: Calculates the regression estimates
   			local regrLogit = self.calcRegressionLogistic(cell, inputValues, self)
  			
   				-- Step 2: Calculates the elasticity
  			local elas = 0				
  			
  			if (cell[lu] == 1) then
  				elas = inputValues.elasticity
  			end	
  			
  			--Step 3 : Computes the total probability
  			cell[lu.."_pot"] = regrLogit + elas
  		end	--close for region
		end -- for k
	end
	
	--- Handles with the verify method of a LogisticRegression component.
	-- @arg self A LogisticRegression component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage self.potential:verify(event, self)
	component.verify = function(self, event, luccMEModel)
	  print("Verifying Potential parameters")
    -- check regressionData
    if (self.regressionData == nil) then
      error("regressionData is missing", 2)
    end    
    
    local regionsNumber = #self.regressionData

    -- check number of Regions
    if (regionsNumber == nil or regionsNumber == 0) then
      error("The model must have at least One region", 2)
    else
      for i = 1, regionsNumber, 1 do
        local regressionNumber = #self.regressionData[i]
        local lutNumber = #luccMEModel.landUseTypes
        
        -- check the number of regressions
        if (regressionNumber ~= lutNumber) then
          error("Invalid number of regressions on Region number "..i.." . Regressions: "..regressionNumber.." LandUseTypes: "..lutNumber, 2)
        end
        
        for j = 1, regressionNumber, 1 do
          -- check constant variable
          if(self.regressionData[i][j].const == nil) then
            error("const variable is missing on Region "..i.." LandUseType number "..j, 2)
          end
         
          -- check elasticity variable
          if (self.regressionData[i][j].elasticity == nil) then
            error("elasticity variable is missing on Region "..i.." LandUseType number "..j, 2)
          end
         
          -- check betas variable
          if (self.regressionData[i][j].betas == nil) then
            error("betas variable is missing on Region "..i.." LandUseType number "..j, 2)
          end
          
          -- check betas within database
          for k, lu in pairs (self.regressionData[i][j].betas) do
            if (luccMEModel.cs.cells[1][k] == nil) then
              error("Beta "..k.." on Region "..i.." LandUseType number "..j.." not found within database", 2)
            end
          end
        end -- for j
      end -- for i
    end -- else
	end -- verify
	
	--- Handles with the calculation of the regression logistic method of a LogisticRegression component.
	-- @arg cell A spatial location with homogeneous internal content.
	-- @arg inputValues A parameter component.
	-- @arg luDrivers The land use drivers fields in database.
	-- @arg component A LogisticRegression component.
	-- @usage component.calcRegressionLogistic(cell, inputValues, self)
	component.calcRegressionLogistic = function(cell, inputValues, component)
		local regrLogit = inputValues.const
		local betas = inputValues.betas
		local attrs = inputValues.attributes
	
		for var, beta in pairs (betas) do
			regrLogit = regrLogit + beta * cell[var]
		end
			
		return component.probability(regrLogit)
	end	--end calcRegressionLogistic
	
	--- Compute the probability.
	-- @arg z A value used to calculate the probability (second parameter of a pow).
	-- @usage component.probability(regrLogit)
	component.probability = function(z)
		local euler  = 2.718281828459045235360287;
		local zEuler = math.pow(euler, z);
		local prob = zEuler/(1 + zEuler);
		
		return prob
	end
	
	return component
 end --close LogisticRegression	
