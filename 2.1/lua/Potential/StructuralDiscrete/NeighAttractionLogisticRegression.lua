--- Modification of the LogisticRegression  combining cellular automata based models ideas. Cell potential is modified 
-- according to the attractiveness of the same class in a given (generic) neighbourhood.
-- @arg component A NeighAttractionLogisticRegression component.
-- @arg component.regressionData A table with the regression parameters for each attribute.
-- @arg component.regressionData.const A linear regression constant.
-- @arg component.regressionData.error A linear regression estimate error.
-- @arg component.regressionData.betas A linear regression betas for land use drivers
-- and the index of landUseDrivers to be used by the regression (attributes).
-- @arg component.regressionData.elasticity An elasticity value, closer to 1 is more difficulty
-- to transition for other land uses.
-- @arg component.regressionData.percNeighborsUse Percent of neighbours with the same use.
-- @arg component.landUseDrivers The land use drivers fields in database.
-- @arg component.execute Handles with the execution method of a NeighAttractionLogisticRegression component.
-- @arg component.verify Handles with the verify method of a NeighAttractionLogisticRegression component.
-- @arg component.calcRegressionLogistic Handles with the calculation of the regression.
-- @arg component.probability Compute the probability logistic method of a NeighAttractionLogisticRegression component.
-- @return The modified component.
-- @usage potential  =  NeighAttractionLogisticRegression {
--    regressionData = { { --  Region 1
--                        -- D
--                        { const = -0.1004, 
--                          betas = {beta1 = 0.05814, beta2 = -0.97500, beta3 = -2.51651},                
--                          elasticity =  0.5, 
--                          percNeighborsUse = 0.5
--                        },
--                        -- F
--                        { const = -2.34188, 
--                          betas = {beta1 = -0.02727, beta2 = -4.30977, beta3 = -3.10320},                                                              
--                          elasticity =  0.5, 
--                          percNeighborsUse = 0.5
--                        },
--                        -- O
--                        { const = 0,
--                          betas = {beta1 = 1},  
--                          elasticity = 1,
--                          percNeighborsUse = 0.5
--                        }   
--                       }  --end region 1 
--                      } -- end regressionData
--  }
function NeighAttractionLogisticRegression(component)
	--- Handles with the execution method of a NeighAttractionLogisticRegression component.
	-- @arg self A NeighAttractionLogisticRegression component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg modelParameters A parameter model.
	-- @usage self.potential:execute(event, model)
	component.execute = function(self, event, modelParameters)
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
  		 	
			if (cell.region == nil) then
				cell.region = 1
			end 	
			
			for luind, inputValues in pairs (regressionData[cell.region]) do
				local lu = luTypes[luind]
				
				-- Step 1: Calculates the regression estimates
				local regrProb = self.calcRegressionLogistic(cell, inputValues, landUseDrivers, self)
				
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
			end -- for luind
		end -- for k
	end -- end execute
	
	--- Handles with the verify method of a NeighAttractionLogisticRegression component.
	-- @arg self A NeighAttractionLogisticRegression component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage self.potential:verify(event, self)
	component.verify = function(self, event, modelParameters)
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
        local lutNumber = #modelParameters.landUseTypes
        
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
          
          -- check percNeighborsUse variable
          if (self.regressionData[i][j].percNeighborsUse == nil) then
            error("percNeighborsUse variable is missing on Region "..i.." LandUseType number "..j, 2)
          end
         
          -- check betas variable
          if (self.regressionData[i][j].betas == nil) then
            error("betas variable is missing on Region "..i.." LandUseType number "..j, 2)
          end
          
          -- check betas within database
          for k, lu in pairs (self.regressionData[i][j].betas) do
            if (modelParameters.cs.cells[1][k] == nil) then
              error("Beta "..k.." on Region "..i.." LandUseType number "..j.." not found within database", 2)
            end
          end
        end -- for j
      end -- for i
    end -- else
  end -- verify
	
	--- Handles with the calculation of the regression.
	-- logistic method of a NeighAttractionLogisticRegression component.
	-- @arg cell A spatial location with homogeneous internal content.
	-- @arg inputValues A parameter component.
	-- @arg luDrivers The land use drivers fields in database.
	-- @arg component A NeighAttractionLogisticRegression component.
	-- @usage component.calcRegressionLogistic(cell, inputValues, landUseDrivers, self)
	component.calcRegressionLogistic = function(cell, inputValues, luDrivers, component)
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
		local euler  = 2.718281828459045235360287
		local zEuler = math.pow(euler, z)
		local prob = zEuler/(1 + zEuler)
			
		return prob
	end
	
	return component
end --close NeighAttractionLogisticRegression
