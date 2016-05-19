--- Simple component developed as teaching material. Not to be used in real applications. Estimates cell potential for a given 
-- use according to the inverse of the distance to given attributes.
-- @arg component A InverseDistanceRule component.
-- @arg component.potentialData A table with the potential parameters for each attribute.
-- @arg component.potentialData.const A linear regression constant.
-- @arg component.potentialData.betas A linear regression betas for land use drivers.
-- @arg component.run Handles with the execution method of a InverseDistanceRule component.
-- @arg component.verify Handles with the verify method of a InverseDistanceRule component.
-- @return The modified component.
-- @usage --DONTRUN
-- P1 = InverseDistanceRule
--{
--  potentialData =
--  {
--    -- Region 1
--    {
--      -- floresta
--      {
--        const = -1.961,
--
--        betas =
--        {
--          dist_rodovias = 0.00008578,
--          assentamentos = -0.2604,
--          uc_us = 0.6064,
--          fertilidadealtaoumedia = 0.4393
--        }
--      },
--
--      -- desmatamento
--      {
--        const = 1.978,
--
--        betas =
--        {
--          dist_rodovias = -0.00008651,
--          assentamentos = 0.2676,
--          uc_us = -0.6376,
--          fertilidadealtaoumedia = 0.4565
--        }
--      },
--
--      -- outros
--      {
--        const = 0,
--
--        betas =
--        {
--          
--        }
--      }
--    }
--  }
--}
function InverseDistanceRule(component)
	--- Handles with the execution method of a InverseDistanceRule component.
	-- @arg self A InverseDistanceRule component.
	-- @arg event A representation of a time instant when the simulation engine must run.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
	-- @usage --DONTRUN self.potential:run(event, model)
	component.run = function(self, event, luccMEModel)
		local cs = luccMEModel.cs
		local luTypes = luccMEModel.landUseTypes
		local potentialData = self.potentialData
 		local landUseDrivers = self.landUseDrivers
		local filename = self.filename
	  local nRegions = #self.potentialData
		
		for k, cell in pairs (cs.cells) do
      for rNumber = 1, nRegions, 1 do
        if (cell.region == rNumber) then
      		for i, lu in pairs (luTypes) do
      			cell[lu.."_pot"] = 0
      			
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
      
      			cell[lu.."_pot"] =  potDrivers
      		end -- for i
    		end -- if region 
  		end -- for rNumber
		end -- for k
	end -- end run
	
	--- Handles with the verify method of a InverseDistanceRule component.
	-- @arg self A InverseDistanceRule component.
	-- @arg event A representation of a time instant when the simulation engine must run.
	-- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
	-- @usage --DONTRUN self.potential:verify(event, self)
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
end --close InverseDistanceRule
