--- Simple component developed as teaching material. Not to be used in real applications. Estimates cell potential combining above two methods.
-- @arg component A NeighInverseDistanceRule component.
-- @arg component.potentialData A table with the potential parameters for each attribute.
-- @arg component.execute Handles with the execution method of a NeighInverseDistanceRule component.
-- @arg component.verify Handles with the verify method of a LogisticRegression component.
-- @return The modified component.
-- @usage potential = NeighInverseDistanceRule{
--  potentialData = { {factor = 0.01, multipliers = {dist_estradas = 0.5, dist_br = 0.3}},  --D
--					  {factor = 0.01, multipliers = {dist_estradas = -0.5}},  				--F
--					  {factor = 0.000, multipliers = {dist_estradas = 0}}					--O
--					}}  					
function NeighInverseDistanceRule(component)
	--- Handles with the execution method of a NeighInverseDistanceRule component.
	-- @arg self A NeighInverseDistanceRule component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg modelParameters A parameter model.
	-- @usage self.potential:execute(event, model)
	component.execute = function(self, event, modelParameters)
		local cs = modelParameters.cs
		local luTypes = modelParameters.landUseTypes
		local potentialData = self.potentialData
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
			
				local luData = self.potentialData[i]
				local potDrivers = 0
				
				for var, coef in pairs (luData.multipliers) do
					if (cell[var] > 0) then
						potDrivers = potDrivers + coef * 1 / cell[var] * luData.factor
					else
						potDrivers = potDrivers + luData.factor
					end
				end

				if (potDrivers > 1) then potDrivers = 1 end

				cell[lu.."_pot"] = cell[lu.."_pot"] + potDrivers
			end
		end
	end -- end execute
	
	--- Handles with the verify method of a LogisticRegression component.
	-- @arg self A NeighInverseDistanceRule component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage self.potential:verify(event, self)
	component.verify = function(self, event)
	end

	return component
end --close RegressionLogistcModelNeighbourhood
