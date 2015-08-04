--- Uses linear regression techniques to estimate the cell potential for change. Based on the original 
-- continuous CLUE model proposal, the change potential for each use (increase or decrease the percentage
-- in the cell at a given time is estimated as the difference between the regression cover and the actual 
-- land use percentage at a given time (see Verburg et al. 1999 for a detailed description). 
-- @arg component A Linear Regression component.
-- @arg component.regressionData A table with the regression parameters for each attribute.
-- @arg component.regressionData.const A linear regression constant.
-- @arg component.regressionData.error A linear regression estimate error.
-- @arg component.regressionData.betas A linear regression betas for land use drivers
-- and the index of landUseDrivers to be used by the regression (attributes).
-- @arg component.regressionData.isLog Inform whether the model is part of a coupling model.
-- @arg component.landUseDrivers The land use drivers fields in database.
-- @arg component.execute Handles with the execution method of a LinearRegression component.
-- @arg component.verify Handles with the verify method of a LinearRegression component.
-- @arg component.modify Handles with the modify method of a LinearRegression component.
-- @arg component.adaptRegressionConstants Handles with the constants regression method of a
-- LinearRegression component.
-- @arg component.computePotential Handles with the modify method of a LinearRegression component.
-- @return The modified component.
-- @usage myPontencial = LinearRegression {
-- regressionData = {
--          --Natural vegetation
--          { isLog = false, error = 0.1, const  = -0.1,
--            betas = {beta1 =  -0.05, beta2 =  0.2, beta3 = 0.1}},
--          -- Deforestation
--          { isLog = false, error = 0.3, const  = -0.3,
--            betas = {beta1 =  0.03, beta2 = 0.6, beta3 = 0.01}},
--          -- Others
--          { isLog = false, error = 0, const  = 0,
--            betas = {beta1 =  0}}
--          },
--}
function LinearRegression(component)
  --- Handles with the execution method of a LinearRegression component.
  -- @arg self A PreComputedValuesAutoDemand component.
  -- @arg event A representation of a time instant when the simulation engine must execute.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
  -- @usage self.potential:execute(event, model)
  component.execute = function(self, event, luccMEModel)
		local cs = luccMEModel.cs
		local luDrivers = self.landUseDrivers
		local luTypes = luccMEModel.landUseTypes
    local demand = luccMEModel.demand
    local regionsNumber = #self.regressionData
    
    -- Create an internal constant that can be modified during allocation
    for rNumber = 1, regionsNumber, 1 do
  		for i, luData in pairs (self.regressionData[rNumber]) do
  			if (luData.const  == nil) then 
  			  luData.const = 0 
  		  end
  			
  			luData.newconst = luData.const
  		end
  		
      if (event:getTime() > luccMEModel.startTime) then 
  			self:adaptRegressionConstants(demand, rNumber, event )
      end
  	
  		for i = 1, #luTypes, 1 do                         
  		  self:computePotential(luccMEModel, rNumber, i)
      end
    end
  end  -- function execute

  --- Handles with the verify method of a LinearRegression component.
  -- @arg self A LinearRegression component.
  -- @arg event A representation of a time instant when the simulation engine must execute.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
  -- @usage self.potential:verify(event, self)
  component.verify = function(self, event, luccMEModel)
   local cs = luccMEModel.cs
   
   forEachCell(cs, function(cell)
                      cell["alternate_model"] = 0
                      cell["region"] = 1
                     end
               )

    if (self.regionAttr == nil) then
      self.regionAttr = "region"
    end
  
    -- check regressionData
    if (self.regressionData == nil) then
      error("regressionData is missing", 2)
    end    
    
    local regionsNumber = #self.regressionData

    -- check number of Regions
    if (regionsNumber == nil or regionsNumber == 0) then
      error("The model must have at least One region")
    else
      for i = 1, regionsNumber, 1 do
        local regressionNumber = #self.regressionData[i]
        local lutNumber = #luccMEModel.landUseTypes
        
        -- check the number of regressions
        if (regressionNumber ~= lutNumber) then
          error("Invalid number of regressions on Region number "..i.." . Regressions: "..regressionNumber.." LandUseTypes: "..lutNumber)
        end
        
        for j = 1, regressionNumber, 1 do
          -- check isLog variable
          if(self.regressionData[i][j].isLog == nil) then
            error("isLog variable is missing on Region "..i.." LandUseType number "..j, 2)
          end
         
          -- check const variable
          if (self.regressionData[i][j].const == nil) then
            error("const variable is missing on Region "..i.." LandUseType number "..j, 2)
          end
         
          -- check betas variable
          if (self.regressionData[i][j].betas == nil) then
            rror("betas variable is missing on Region "..i.." LandUseType number "..j, 2)
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
  end
 
  --- Handles with the potential modify method of a LinearRegression component.
  -- This method is called by the Allocation component.
  -- @arg self A SpatialLagLinearRoads component.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
  -- @arg luIndex A land use index (an specific luIndex of a list of possible land uses).
  -- @arg direction The direction for the regression.
  -- @arg event A representation of a time instant when the simulation engine must execute.
  -- @usage luccMEModel.potential:modify(luccMEModel, j, i, luDirect, event)
  component.modify = function (self, luccMEModel, rNumber, luIndex, direction)
    local luData = self.regressionData[rNumber][luIndex] 
  	     
  	if (luData.newconst == nil) then 
  	  luData.newconst = 0 
    end	
  	 
    if (luData.isLog) then 
      luData.newconst = luData.newconst - math.log(10, 0.1) * direction
  	else
  		luData.newconst = luData.newconst + 0.1 * direction
  	end
      self:computePotential (luccMEModel, rNumber, luIndex)
  end	-- function	modify	

  --- Handles with the constants regression method of a LinearRegression component.
  -- @arg self A LinearRegression component.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
  -- @arg demand A demand to calculate the potential.
  -- @arg event A representation of a time instant when the simulation engine must execute.
  -- @usage self:adaptRegressionConstants(demand, rNumber, event)
  component.adaptRegressionConstants = function(self, demand, rNumber, event)
     for i, luData in pairs (self.regressionData[rNumber]) do			
      	local currentDemand = demand:getCurrentLuDemand(i)
        local previousDemand = demand:getPreviousLuDemand(i) 
        local plus = ((currentDemand - previousDemand) / previousDemand)
                           
        luData.newconst = luData .const
      			
        if( luData.isLog ) then
      	 	if (plus > 0) then 
      			luData.newconst = luData.newconst - math.log(10, plus) * 0.01 
        	end
        	if (plus < 0) then 
            luData.newconst = luData.newconst + math.log(10, (-1) * plus) * 0.01
        	end
       else 
          luData.newconst = luData.newconst + plus * 0.01  
       end 
    end
  end	-- function adaptRegressionConstants
		
  --- Handles with the compute potential method of a LinearRegression component.
  -- @arg self A LinearRegression component.
  -- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
  -- @arg luIndex A land use index (an specific luIndex of a list of possible land uses).
  -- @usage self:computePotential(luccMEModel, luIndex)		
  component.computePotential = function(self, luccMEModel, rNumber, luIndex)
    local cs = luccMEModel.cs	
    local luTypes = luccMEModel.landUseTypes
    local lu = luTypes[luIndex]
    local luData = self.regressionData[rNumber][luIndex]
    local pot = lu.."_pot"
    local activeRegionNumber = 0
    
    for k,cell in pairs (cs.cells) do
      if (cell.region == rNumber) then
        local regression = luData.newconst
        	
        for var, beta in pairs (luData.betas) do 
        	regression = regression + beta * cell[var]
        end
        	
        if (luData.isLog) then -- if the land use is log transformed
      		regression = math.pow(10, regression)
      	end 
        
        if (regression > 1) then
      		regression = 1
      	end
        		
      	if (regression < 0) then
      		regression = 0
      	end
        		
      	if (luccMEModel.landUseNoData ~= nil) then     
      		regression = regression * (1 - cell[luccMEModel.landUseNoData]) 
      	end
        	        
      	cell[pot] = regression - cell.past[lu] 
    	end 
    end
    
    if (activeRegionNumber == 0) then
      error("Region ".. rNumber.." is not set into database.")  
    end
  end  -- function computePotential

  return component
end -- component definition
