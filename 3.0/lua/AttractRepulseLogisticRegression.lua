-------------------------------------------------------------------------------------------
--LuccME - a framework for topdown land use change modeling.
--Copyright © 2009 - 2011 INPE.
--
--This code is part of the LuccME framework.
--This framework is a free software; you can redistribute and/or
--modify it under the terms of the GNU Lesser General Public
--License as published by the Free Software Foundation; either
--version 3 of the License, or (at your option) any later version.
--
--You should have received a copy of the GNU Lesser General Public
--License along with this library.
--
--The authors reassure the license terms regarding the warranties.
--They specifically disclaim any warranties, including, but not limited to,
--the implied warranties of merchantability and fitness for a particular purpose.
--The framework provided hereunder is on an "as is" basis, and the authors have no
--obligation to provide maintenance, support, updates, enhancements, or modifications.
--In no event shall INPE be held liable to any part for direct,
--indirect, special, incidental, or consequential damages arising out of the use
--of this library and its documentation.
--
-------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------

function AttractRepulseLogisticRegression(component)
	--- Handles with the execution method of a NeighAttractionLogisticRegression component.
	-- @arg event A representation of a time instant when the simulation engine must run.
	-- @arg luccMEModel A luccME Model.
	-- @usage --DONTRUN
	-- component.run(event, model)
	component.run = function(self, event, luccMEModel)
		local cs = luccMEModel.cs 
		local luTypes = luccMEModel.landUseTypes 
		local regressionData = self.regressionData 
 		local landUseDrivers = self.landUseDrivers 
  		local filename = self.filename 
		
		if (filename ~= nil) then
			loadGALNeighborhood(filename)
		else
		  if(event:getTime() == luccMEModel.startTime) then
			cs:createNeighborhood()   
		  end
		end
 		
		local totalNeigh = 0 
  		
  		for k, cell in pairs (cs.cells) do
			-- Initialization
			totalNeigh = #cell:getNeighborhood() - 1
			
			for i, inputValues in  pairs (regressionData[cell.region]) do
				local lu = luTypes[i]
				if (cell[lu] == 1)  then		
					cellType = toIndex(lu ,luTypes)
				end
				cell["tau_"..lu] = 0.0
			end

			-- "TAU": ATTRACTION/REPULSION FACTOR			
			for luind, inputValues in  pairs( regressionData[cell.region]) do
				local lu = luTypes[luind]
				-- Step 1: Count neighbgours		
				local numNeigh = 0;
				forEachNeighbor(cell, function(cell, neigh)			
										if (neigh[lu] == 1 and neigh ~= cell)  then		
											numNeigh = numNeigh + 1
										end						
									 end
								)
				
				-- Step 2: Compute weight 
				d = inputValues.percNeighborsUse * totalNeigh
				
				if (numNeigh < d) then 
					w = 0.0
				elseif (numNeigh >= d) then 
					w = (numNeigh - d) / (totalNeigh - d)
				end
				
				-- Step 3: Compute Attraction/Repulsion factor
				cell["tau_"..lu] = cell["tau_"..lu] + self.affinityMatrix[cell.region][cellType][luind] * w
				
				-- Step 4: Elasticity
				local elas = 0				
				if (cell[lu] == 1) then
					elas = inputValues.elasticity
				end
				
				-- Step 5: Calculates the regression estimates 
				local regrProb = model.calcRegressionLogistic(cell, inputValues, landUseDrivers, self)
				
				-- Step 6: Compute the potential
				cell[lu.."_pot"] = regrProb + elas

			end -- use type
		end -- end cells
	end -- end execute

	--- Handles with the verify method of a NeighAttractionLogisticRegression component.
	-- @arg event A representation of a time instant when the simulation engine must run.
	-- @arg luccMEModel A luccME Model.
	-- @usage --DONTRUN
	-- component.verify(event, self)
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
			  
			  -- check percNeighborsUse variable
			  if (self.potentialData[i][j].percNeighborsUse == nil) then
				error("percNeighborsUse variable is missing on Region "..i.." LandUseType number "..j, 2)
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
	
	--- Return an Index for a land use type in a set of land use types.
	-- @arg lu A land use type.
	-- @arg usetypes A set of land use type.
	-- @usage --DONTRUN
	-- component.toIndex(lu, luTypes)
	component.toIndex = function(self, lu, usetypes)
		local index = 0
		for i, value in  pairs (usetypes) do
		  if (value == lu) then
			index = i
			break
		  end   
		end
		
		return index
	end
	
	--- Handles with the calculation of the regression logistic method of a NeighAttractionLogisticRegression component.
	-- @arg cell A spatial location with homogeneous internal content.
	-- @arg inputValues A parameter component.
	-- @arg component A NeighAttractionLogisticRegression component.
	-- @usage --DONTRUN
	-- component.calcRegressionLogistic(cell, inputValues, self)
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
	-- @usage --DONTRUN
	-- component.probability(regrLogit)
	component.probability = function(z)
		local euler  = 2.718281828459045235360287
		local zEuler = math.pow(euler, z)
		local prob = zEuler/(1 + zEuler)
			
		return prob
	end
	
	collectgarbage("collect")
	return component
end --close NeighAttractionLogisticRegression
