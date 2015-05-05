--- Simple component developed as teaching material. Not to be used in real applications. Estimates cell potential for a given 
-- use according to the inverse of the distance to given attributes.
-- @arg component A InverseDistanceRule component.
-- @arg component.potentialData A table with the potential parameters for each attribute.
-- @arg component.execute Handles with the execution method of a InverseDistanceRule component.
-- @arg component.verify Handles with the verify method of a InverseDistanceRule component.
-- @return The modified component.
-- @usage potential = InverseDistanceRule {
--  potentialData = { {factor = 0.01, multipliers = {dist_estradas = 0.5, dist_br = 0.3}},  --D
--					  {factor = 0.01, multipliers = {dist_estradas = -0.5}},  				--F
--					  {factor = 0.000, multipliers = {dist_estradas = 0}}					--O
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
 		
  		for k, cell in pairs (cs.cells) do
			for i, lu in pairs (luTypes) do
				cell[lu.."_pot"] = 0
				local luData = self.potentialData[i]
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
			end
		end
	end -- end execute
	
	--- Handles with the verify method of a InverseDistanceRule component.
	-- @arg self A InverseDistanceRule component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage self.potential:verify(event, self)
	component.verify = function(self, event)
	end
	
	return component
end --close InverseDistanceRule
