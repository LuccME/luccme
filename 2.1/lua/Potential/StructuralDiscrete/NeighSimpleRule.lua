--- XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx
-- @arg model A NeighSimpleRule model.
-- @arg model.execute Handles with the execution method of a NeighSimpleRule model.
-- @arg model.verify Handles with the verify method of a NeighSimpleRule model.
-- @return The modified model.
-- @usage potential = NeighSimpleRule{}
function NeighSimpleRule(model)
	--- Handles with the execution method of a NeighSimpleRule model.
	-- @arg self A NeighSimpleRule model.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg modelParameters A parameter model.
	-- @usage self.potential:execute(event, model)
	model.execute = function(self, event, modelParameters)
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
  		 	if (model.region == nil) then
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
			end
		end
	end -- end execute
	
	--- Handles with the verify method of a NeighSimpleRule model.
	-- @arg self A NeighSimpleRule model.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage self.potential:verify(event, self)
	model.verify = function(self, event)
	end

	return model
end --close RegressionLogistcModelNeighbourhood
