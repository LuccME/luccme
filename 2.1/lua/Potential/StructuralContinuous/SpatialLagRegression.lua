--- Similar to the LinearRegression approach, but relies spatial regression techniques to estimate the 
-- regression cover (considers the spatial dependence of the land use). 
-- @arg component A Spatial Lag Regression component.
-- @arg component.regressionData A table with the regression parameters for each attribute.
-- @arg component.regressionData.const A linear regression constant.
-- @arg component.regressionData.ro Auto regressive coefficient.
-- @arg component.regressionData.minReg A coefficient to minimize the regression value.
-- @arg component.regressionData.maxReg A coefficient to potentiality the regression value.
-- @arg component.regressionData.betas A linear regression betas for land use drivers
-- and the index of landUseDrivers to be used by the regression (attributes).
-- @arg component.regressionData.isLog Inform whether the model is part of a coupling model.
-- @arg component.landUseDrivers The land use drivers fields in database.
-- @arg component.execute Handles with the execution method of a SpatialLagRegression component.
-- @arg component.verify Handles with the verify method of a SpatialLagRegression component.
-- @arg component.modify Handles with the modify method of a SpatialLagRegression component.
-- @arg component.modifyRegression Handles with the modify regression method of a
-- SpatialLagRegression component.
-- @arg component.adaptRegressionConstants Handles with the constants regression method of a
-- SpatialLagRegression component.
-- @arg component.computePotential Handles with the modify method of a SpatialLagRegression component.
-- @return The modified component.
-- @usage myPontencial = SpatialLagRegression {
-- regressionData =	{
-- 					--Natural vegetation
--					{ isLog = false, ro = 0.1, const  = -0.1, minReg = 0.15, maxReg = 0.92,
--					  betas = {beta1 =	-0.05, beta2 =	0.2, beta3 = 0.1}},
--					-- Deforestation
--					{ isLog = false, ro = 0.3, const  = -0.3, minReg = 0.13, maxReg = 0.89,
--					  betas = {beta1 =	0.03, beta2 =	0.6, beta3 = 0.01}},
--					-- Others
--					{ isLog = false, ro = 0, const  = 0, minReg = 0, maxReg = 1,
--					  betas = {beta1 =	0}}
--					},
--}
function SpatialLagRegression(component)
	--- Handles with the execution method of a SpatialLagRegression component.
	-- @arg self A SpatialLagRegression component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
	-- @usage self.potential:execute(event, model)
	component.execute = function(self, event, luccMEModel)
		local cs = luccMEModel.cs
		local luDrivers = self.landUseDrivers
		local luTypes = luccMEModel.landUseTypes
		local demand = luccMEModel.demand
		
    -- create an internal constant that can be modified during allocation
    for j, luDataRegion in pairs (self.regressionData) do
  		for i, luData in pairs (luDataRegion) do
  			if (luData.const == nil) then
  				luData.const = 0
  			end
  			
  			if (luData.minReg == nil) then
  				luData.minReg = 0
  			end
  			
  			if (luData.maxReg == nil) then
  				luData.maxReg = 1
  			end
  			
  			luData.newconst = luData.const
  			luData.newminReg = luData.minReg
  			luData.newmaxReg = luData.maxReg
  		end
		end
		
		if (self.constChange == nil) then
			self.constChange = 0.1 			-- original clue value
		end

    if (event:getTime() > luccMEModel.startTime) then
			self:adaptRegressionConstants(demand, event) 
    end
	
		for i, luDataRegion in pairs (self.regressionData) do
      for i = 1, #luTypes, 1 do
	     self:computePotential(luccMEModel, i, event)
     end
    end
	end  -- function execute
	
	--- Handles with the verify method of a SpatialLagRegression component.
	-- @arg self A SpatialLagRegression component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
	-- @usage self.potential:verify(event, self)
	component.verify = function(self, event, luccMEModel)
		cs = luccMEModel.cs

		forEachCell(cs, function(cell)
        							cell["alternate_model"] = 0
        						end
      					)

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
          
          -- check minReg variable
          if(self.regressionData[i][j].minReg == nil) then
            error("minReg variable is missing on Region "..i.." LandUseType number "..j, 2)
          end
                
          -- check maxReg variable
          if(self.regressionData[i][j].maxReg == nil) then
            error("maxReg variable is missing on Region "..i.." LandUseType number "..j, 2)
          end
          
          -- check ro variable
          if(self.regressionData[i][j].ro == nil) then
            error("ro variable is missing on Region "..i.." LandUseType number "..j, 2)
          end                  
         
          -- check const variable
          if (self.regressionData[i][j].const == nil) then
            error("const variable is missing on Region "..i.." LandUseType number "..j, 2)
          end
         
          -- check betas variable
          if (self.regressionData[i][j].betas == nil) then
            error("minReg variable is missing on Region "..i.." LandUseType number "..j, 2)
          end
          
          -- check betas within database
          for k, lu in pairs (self.regressionData[i][j].betas) do
            if (luccMEModel.cs.cells[1][k] == nil) then
              error("Beta "..k.." on Region "..i.." LandUseType number "..j.." not found within database", 2)
            end
          end
        end -- for j
     end 
    end

		local filename = self.filename
		
		if (filename ~= nil) then
			loadGALNeighborhood(filename)
		else
			cs:createNeighborhood()	
		end
	end

	--- Handles with the modify method of a SpatialLagRegression component.
	-- @arg self A SpatialLagRegression component.
	-- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
	-- @arg luIndex A land use index (an specific luIndex of a list of possible land uses).
	-- @arg direction The direction for the regression.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage luccMEModel.potential:modify(luccMEModel, i, luDirect, event)  
  component.modify = function(self, luccMEModel, regIndex, luIndex, direction, event)
    luDataRegion = self.regressionData[regIndex]
    
    for i = 1, #luDataRegion, 1 do
      if (luDataRegion[i].newconst == nil) then 
        luDataRegion[i].newconst = 0 
      end  
       
      if (luDataRegion[i].isLog) then 
        local const_unlog = math.pow(10, luDataRegion[i].newconst) + self.constChange * direction
        if (const_unlog ~= 0) then
          luDataRegion[i].newconst = math.log(10, const_unlog)
        end 
      else
        luDataRegion[i].newconst = luDataRegion[i].newconst + self.constChange * direction
      end
    end

    self:computePotential(luccMEModel, luIndex, event)
  end -- function modifyPotential

	--- Handles with the constants regression method of a SpatialLagRegression component.
	-- @arg self A SpatialLagRegression component.
	-- @arg demand A demand to calculate the potential.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage self:adaptRegressionConstants(demand, event)
  component.adaptRegressionConstants = function(self, demand, event)
    for j, luDataRegion in pairs (self.regressionData) do
      for i, luData in pairs (luDataRegion) do
        local currentDemand = demand:getCurrentLuDemand(j)
        local previousDemand = demand:getPreviousLuDemand(j)
        local plus = 0.01 * ((currentDemand - previousDemand) / previousDemand)

        luData.newconst = luData.const

        if (luData.isLog) then
          local const_unlog = math.pow(10, luData.newconst) + plus
          if (const_unlog ~= 0) then
            luData.newconst = math.log(10, const_unlog)
          end
        else
          luData.newconst = luData.newconst + plus
        end

        luData.newminReg = luData.newminReg + plus
        luData.newmaxReg = luData.newmaxReg + plus
        luData.const = luData.newconst
      end
    end
  end -- function adaptRegressionConstants
	
	--- Handles with the compute potential method of a SpatialLagRegression component.
	-- @arg self A SpatialLagRegression component.
	-- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
	-- @arg luIndex A land use index (an specific luIndex of a list of possible land uses).
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage self:computePotential(luccMEModel, luIndex, event)
	component.computePotential = function(self, luccMEModel, luIndex, event)
		local cs = luccMEModel.cs	
		local luTypes = luccMEModel.landUseTypes
		local lu = luTypes[luIndex]
		local luDataRegion = self.regressionData
		local pot = lu.."_pot"

		for k, cell in pairs (cs.cells) do
	    local regressionX = 0
      local region = cell[self.regionAttr]
  
      if (region == nil or region == 0) then
        region = 1
      end

      local luData = luDataRegion[region] 
		
			local regressionX = 0
			local regresY = 0   
			local neighSum = 0
			local count = 0
			
			for var, beta in pairs (luData[luIndex].betas) do
				regressionX = regressionX + beta * cell[var]
			end
			
			regresDrivers = regressionX
			
			forEachNeighbor (cell, function(cell, neigh, weight)
          										Y = cell.past[lu]
          										neighY = neigh.past[lu]
          
          										if (cell[luccMEModel.landUseNoData] ~= 1) then
          											Y = Y / (1 - cell[luccMEModel.landUseNoData])
          										end
          										if (neigh[luccMEModel.landUseNoData] ~= 1) then
          											neighY = neighY / (1 - neigh[luccMEModel.landUseNoData])
          										end
          
          										if (neigh[luccMEModel.landUseNoData] < 1) then
          											count = count + 1
          											neighSum = neighSum + neighY
          										end
          									end
          							)
		
			if (count > 0) then
				regresY = ((Y + neighSum) / (count + 1)) * luData[luIndex].ro  
			else
				regresY = Y * luData[luIndex].ro
			end	
			
			if (luData[luIndex].isLog) then -- if the land use is log transformed
				regresY = math.log(10, regresY + 0.0001)  
			end

	        local regression = luData[luIndex].newconst + regressionX + regresY		
			local regressionLimit = luData[luIndex].const + regressionX + regresY   		

			if (luData[luIndex].isLog) then -- if the land use is log transformed
				regression = math.pow(10, regression) - 0.0001			
				regressionLimit = math.pow(10, (regressionLimit)) - 0.0001
			end

			if (regressionLimit > luData[luIndex].maxReg) then
				regression = 1
			end
				
			if (regressionLimit < luData[luIndex].minReg) then
				regression = 0
			end

			if (regression > 1) then
				regression = 1
			end

			if (regression < 0) then
				regression = 0
			end

			regression = regression * (1 - cell[luccMEModel.landUseNoData])
			cell[pot] = regression - cell.past[lu]
		end
	end  -- function computePotential

   return component
end -- component definition
