--- Simple component developed as teaching material. Not to be used in real applications. Estimates cell potential for a given 
-- use according to the inverse of the distance to given attributes.
-- @arg component A InverseDistanceRule component.
-- @arg component.potentialData A table with the potential parameters for each attribute.
-- @arg component.execute Handles with the execution method of a InverseDistanceRule component.
-- @arg component.verify Handles with the verify method of a InverseDistanceRule component.
-- @return The modified component.
-- @usage potential = InverseDistanceRule {
--  potentialData = {
--          { -- Region 1 
--            {factor = 0.01, multipliers = {dist_estradas = 0.5, dist_br = 0.3}},  --D
--					  {factor = 0.01, multipliers = {dist_estradas = -0.5}},  				--F
--					  {factor = 0.000, multipliers = {dist_estradas = 0}}					--O
--          }
--					}}
function InverseDistanceRule(component)
	--- Handles with the execution method of a InverseDistanceRule component.
	-- @arg self A InverseDistanceRule component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg modelParameters A parameter model.
	-- @usage self.potential:execute(event, model)
	component.execute = function(self, event, modelParameters)
		local cs = modelParameters.cs
		local luTypes = modelParameters.landUseTypes
		local potentialData = self.potentialData
 		local landUseDrivers = self.landUseDrivers
		local filename = self.filename
	  local nRegions = #self.potentialData
		
		for k, cell in pairs (cs.cells) do
		  if (cell.region == nil) then
        cell.region = 1
      end

      for rNumber = 1, nRegions, 1 do
    		for i, lu in pairs (luTypes) do
    			cell[lu.."_pot"] = 0
    			
    			local luData = self.potentialData[rNumber][i]
    			local potDrivers = 0

    			for var, coef in pairs (luData.multipliers) do
    				if (cell[var] > 0) then
    					potDrivers = potDrivers + coef * 1 / cell[var] * luData.factor
    				else
    					potDrivers = potDrivers + luData.factor
    				end
    			end
    
    			if (potDrivers > 1) then
    				potDrivers = 1
    			end
    
    			cell[lu.."_pot"] =  potDrivers
    		end -- for i
  		end -- for luind
		end -- for k
	end -- end execute
	
	--- Handles with the verify method of a InverseDistanceRule component.
	-- @arg self A InverseDistanceRule component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage self.potential:verify(event, self)
	component.verify = function(self, event, modelParameters)
	  -- check potentialData
    if (self.potentialData == nil) then
      error("regressionData is missing", 2)
    end    
    
     local regionsNumber = #self.potentialData

    -- check number of Regions
    if (regionsNumber == nil or regionsNumber == 0) then
      error("The model must have at least One region", 2)
    else
      for i = 1, regionsNumber, 1 do
        local regressionNumber = #self.potentialData[i]
        local lutNumber = #modelParameters.landUseTypes
        
        -- check the number of regressions
        if (regressionNumber ~= lutNumber) then
          error("Invalid number of regressions on Region number "..i.." . Regressions: "..regressionNumber.." LandUseTypes: "..lutNumber, 2)
        end
        
        for j = 1, regressionNumber, 1 do
          -- check factor variable
          if(self.potentialData[i][j].factor == nil) then
            error("factor variable is missing on Region "..i.." LandUseType number "..j, 2)
          end
         
          -- check multipliers variable
          if (self.potentialData[i][j].multipliers == nil) then
            error("multipliers variable is missing on Region "..i.." LandUseType number "..j, 2)
          end
          
          -- check betas within database
          for k, lu in pairs (self.potentialData[i][j].multipliers) do
            if (modelParameters.cs.cells[1][k] == nil) then
              error("Beta "..k.." on Region "..i.." LandUseType number "..j.." not found within database", 2)
            end
          end
        end -- for j
      end -- for i
    end -- else
	end -- verify
	
	return component
end --close InverseDistanceRule
