--- Simple component developed as teaching material. Not to be used in real applications. Estimates cell potential combining above two methods.
-- @arg component A NeighInverseDistanceRule component.
-- @arg component.potentialData A table with the potential parameters for each attribute.
-- @arg component.execute Handles with the execution method of a NeighInverseDistanceRule component.
-- @arg component.verify Handles with the verify method of a LogisticRegression component.
-- @return The modified component.
-- @usage potential = NeighInverseDistanceRule{
--  potentialData = { 
--                    { -- Region 1            
--                      {const = 0.01, betas = {dist_estradas = 0.5, dist_br = 0.3}},  --D
--					            {const = 0.01, betas = {dist_estradas = -0.5}},  				       --F
--					            {const = 0.000, betas = {dist_estradas = 0}}					         --O
--                    }
--					}}  					
function NeighInverseDistanceRule(component)
	--- Handles with the execution method of a NeighInverseDistanceRule component.
	-- @arg self A NeighInverseDistanceRule component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg luccMEModel A parameter model.
	-- @usage self.potential:execute(event, model)
	component.execute = function(self, event, luccMEModel)
		local cs = luccMEModel.cs
		local luTypes = luccMEModel.landUseTypes
		local potentialData = self.potentialData
 		local landUseDrivers = self.landUseDrivers
		local filename = self.filename
    local nRegions = #self.potentialData
		
		if (filename ~= nil) then
			loadGALNeighborhood(filename)
		else
			cs:createNeighborhood()		
		end
 		
		local totalNeigh = 0
  		
		for k, cell in pairs (cs.cells) do
		 if (cell.region == nil) then
        cell.region = 1
     end

     for rNumber = 1, nRegions, 1 do
  			totalNeigh = cell:getNeighborhood():size()
  		 	if (cell.region == rNumber) then  
    			for i, lu in pairs (luTypes) do 
    				cell[lu.."_pot"] = 0
    				local numNeigh = 0;
    				
    				forEachNeighbor(cell, function(cell, neigh)				
              											if (neigh[lu] == 1) then					
              												numNeigh = numNeigh + 1
              											end
              										end
            								)
    								
    				-- Step 4: Compute potential
    				if (totalNeigh > 0) then
    					cell[lu.."_pot"] = numNeigh / totalNeigh 	
    				else 	
    					cell[lu.."_pot"] = 0
    				end	
    			
    				local luData = self.potentialData[rNumber][i]
    				local potDrivers = 0
    				
    				for var, coef in pairs (luData.betas) do
    					if (cell[var] > 0) then
    						potDrivers = potDrivers + coef * 1 / cell[var] * luData.const
    					else
    						potDrivers = potDrivers + luData.const
    					end
    				end
    
    				if (potDrivers > 1) then 
    				  potDrivers = 1 
  				  end
      
    				cell[lu.."_pot"] = cell[lu.."_pot"] + potDrivers
    			end -- for i
  			end -- if region
			end -- for rNumber
		end -- for k
	end -- end execute
	
	--- Handles with the verify method of a LogisticRegression component.
	-- @arg self A NeighInverseDistanceRule component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage self.potential:verify(event, self)
	component.verify = function(self, event, luccMEModel)
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
        local lutNumber = #luccMEModel.landUseTypes
        
        -- check the number of regressions
        if (regressionNumber ~= lutNumber) then
          error("Invalid number of regressions on Region number "..i.." . Regressions: "..regressionNumber.." LandUseTypes: "..lutNumber, 2)
        end
        
        for j = 1, regressionNumber, 1 do
          -- check const variable
          if(self.potentialData[i][j].const == nil) then
            error("const variable is missing on Region "..i.." LandUseType number "..j, 2)
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

	return component
end --close RegressionLogistcModelNeighbourhood
