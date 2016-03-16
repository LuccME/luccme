--- Uses logistic regression techniques to compute cell probability for each land use. 
-- Based on the original CLUE-S framework potential calculation (Verburg et al., 2002), 
-- modifies the probability with a user defined elasticity, for the current land use.
-- @arg component A Logistic Regression component.
-- @arg component.potentialData A table with the regression parameters for each attribute.
-- @arg component.potentialData.const A linear regression constant.
-- @arg component.potentialData.elasticity An elasticity value, closer to 1 is more easy
-- to transition for other land uses.
-- @arg component.potentialData.betas A linear regression betas for land use drivers
-- and the index of landUseDrivers to be used by the regression (attributes).
-- @arg component.run Handles with the execution method of a LogisticRegression component.
-- @arg component.verify Handles with the verify method of a LogisticRegression component.
-- @arg component.calcRegressionLogistic Handles with the calculation of the regression
-- @arg component.probability Compute the probability logistic method of a LogisticRegression component.
-- @return The modified component.
-- @usage potential  =  LogisticRegression {
--    potentialData = { 
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
	-- @arg event A representation of a time instant when the simulation engine must run.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
	-- @usage self.potential:run(event, model)
	component.run = function(self, event, luccMEModel)
		local cs = luccMEModel.cs
		local potentialData = self.potentialData
 		local luTypes = luccMEModel.landUseTypes
 		local landUseDrivers = self.landUseDrivers
  		
		for k, cell in pairs (cs.cells) do
  		for luind, inputValues in pairs (potentialData[cell.region]) do
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
	-- @arg event A representation of a time instant when the simulation engine must run.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
	-- @usage self.potential:verify(event, self)
	component.verify = function(self, event, luccMEModel)
	  local cs = luccMEModel.cs
	  print("Verifying Potential parameters")
    -- check potentialData
    if (self.potentialData == nil) then
      error("potentialData is missing", 2)
    end    
    
    local regionsNumber = #self.potentialData

    -- check number of Regions
    if (regionsNumber == nil or regionsNumber == 0) then
      error("The model must have at least One region", 2)
    else
      for i = 1, regionsNumber, 1 do
        local regressionNumber = #self.potentialData[i]
        local lutNumber = #luccMEModel.landUseTypes
        local activeRegionNumber = 0
        
        -- check the number of regressions
        if (regressionNumber ~= lutNumber) then
          error("Invalid number of regressions on Region number "..i.." . Regressions: "..regressionNumber.." LandUseTypes: "..lutNumber, 2)
        end
        
        -- check active regions
        for k,cell in pairs (cs.cells) do
          if (cell.region == nil) then
            cell.region = 1
          end         
          if (cell.region == i) then
            activeRegionNumber = i
          end
        end
        if (activeRegionNumber == 0) then
          error("Region ".. i.." is not set into database.")  
        end
                   
        
        for j = 1, regressionNumber, 1 do
          -- check constant variable
          if(self.potentialData[i][j].const == nil) then
            error("const variable is missing on Region "..i.." LandUseType number "..j, 2)
          end
         
          -- check elasticity variable
          if (self.potentialData[i][j].elasticity == nil) then
            error("elasticity variable is missing on Region "..i.." LandUseType number "..j, 2)
          end
         
          -- check betas variable
          if (self.potentialData[i][j].betas == nil) then
            error("betas variable is missing on Region "..i.." LandUseType number "..j, 2)
          end
          
          -- check betas within database
          for k, lu in pairs (self.potentialData[i][j].betas) do
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
