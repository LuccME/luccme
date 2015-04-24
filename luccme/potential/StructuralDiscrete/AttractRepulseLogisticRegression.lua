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

function AttractRepulseLogisticRegression (model)
	
	model.execute = function (self,event,modelParameters)
	
		local cs = modelParameters.cs 
		local luTypes = modelParameters.landUseTypes 
		local regressionData = self.regressionData 
 		local landUseDrivers = self.landUseDrivers 
  		local filename = self.filename 
		
		if filename ~= nil then
			loadGALNeighborhood (filename)
		else
			createMooreNeighborhood(cs)	
		end
 		
		local totalNeigh = 0 
  		
  		for k, cell in pairs( cs.cells ) do

  		 	if (model.region == nil) then cell.region = 1 end


			-- Initialization
			totalNeigh = cell:getNeighborhood():size() - 1
			for i, inputValues in  pairs( regressionData[cell.region]) do
				local lu = luTypes[i]
				if ( cell[lu] == 1 )  then		
					cellType = toIndex(lu ,luTypes)
				end
				cell["tau_"..lu] = 0.0
			end

			-- "TAU": ATTRACTION/REPULSION FACTOR			
			for luind, inputValues in  pairs( regressionData[cell.region]) do
				local lu = luTypes[luind]
				-- Step 1: Count neighbgours		
				local numNeigh = 0;
				forEachNeighbor(cell,function(cell,neigh)			
						if ( neigh[lu] == 1 and neigh ~= cell )  then		
							numNeigh = numNeigh + 1
						end						
				end)
				-- Step 2: Compute weight 
				d = inputValues.percNeighborsUse * totalNeigh
				if numNeigh < d then 
					w = 0.0
				elseif numNeigh >= d then 
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
				local regrProb = model.calcRegressionLogistic(cell,inputValues,landUseDrivers,self)
				-- Step 6: Compute the potential
				cell["suit_"..lu] = regrProb + elas

			end -- use type
		end -- end cells
	end -- end execute

	function toIndex (lu, usetypes )
	local index = 0 
			for i, value in  pairs( usetypes ) do
			
				if ( value == lu ) then
					index = i
					break
				end
				
			end
	return index
	end
	
	model.verify = function (self,event)
		local range_drivers = table.getn(self.landUseDrivers)
		
		for i, inputValues in  pairs( self.regressionData[1] ) do
			if(table.getn(inputValues.betas) ~= table.getn(inputValues.attributes)) then
				error("Betas and attributes must have the same size", 3)
			end
			for i, attr in pairs (inputValues.attributes) do
				if (attr < 1) or (attr > range_drivers) then
					error ("Invalid attribute index", 3)
				end
			end
		end
	end
	
	model.calcRegressionLogistic = function(cell,inputValues,luDrivers,model) 
			
		local regrLogit = inputValues.const
		local betas = inputValues.betas
		local attrs = inputValues.attributes
		
		for i, coef in pairs (betas) do
			local driverIndex = attrs[i]
			local driver = cell[luDrivers[driverIndex]]
			if ( driver == nil) then 
				print ("Atribute "..driver.." not found in database")
				os.exit() 
			end
			regrLogit = regrLogit + coef * driver
		end
		return (model.probability(regrLogit))
	end	
	-- Computing the probability 
	
	model.probability = function (z)
	
		local euler  = 2.718281828459045235360287
		local zEuler = math.pow(euler,z)
		local prob = zEuler/(1+zEuler)
			
		return (prob)
	end
	
	return model
end --close RegressionLogistcModelNeighbourhood
