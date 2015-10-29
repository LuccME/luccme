--- Simple component developed as teaching material. Not to be used in real applications. Estimates cell 
-- potential for a given use according to the percentage of cells of the same type in a Moore neighbourhood.
-- @arg component A NeighSimpleRule component.
-- @arg component.execute Handles with the execution method of a NeighSimpleRule component.
-- @arg component.verify Handles with the verify method of a NeighSimpleRule component.
-- @return The modified component.
-- @usage potential = NeighSimpleRule{}
function NeighSimpleRule(component)
	--- Handles with the execution method of a NeighSimpleRule component.
	-- @arg self A NeighSimpleRule component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg luccMeModel A container that encapsulates space, time, behaviour, and other environments.
	-- @usage self.potential:execute(event, model)
	component.execute = function(self, event, luccMEModel)
		local cs = luccMEModel.cs
		local luTypes = luccMEModel.landUseTypes
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
			end -- for i
		end -- for k
	end -- end execute
	
	--- Handles with the verify method of a NeighSimpleRule component.
	-- @arg self A NeighSimpleRule component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage self.potential:verify(self, event)
	component.verify = function(self, event)
	  print("Verifying Potential parameters")
	end

	return component
end --close RegressionLogistcModelNeighbourhood
