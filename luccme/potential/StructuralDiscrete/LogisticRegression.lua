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

-- This submodel computes the potential change using logistic regression 


function LogisticRegression (model)

	model.execute = function (self,event,modelParameters)

		local cs = modelParameters.cs 
		local regressionData = self.regressionData
 		local luTypes = modelParameters.landUseTypes 
 		local landUseDrivers = self.landUseDrivers 
  		
  		for k,cell in pairs( cs.cells ) do
				 
			if (modelParameters.region == nil) then cell.region = 1 end 
  				 
 			for luind, inputValues in  pairs(regressionData[cell.region]) do
			--print ("regiao",cell.region)
 			--print (inputValues.const,"atributos",inputValues.attributes)
				local lu = luTypes[luind]
  				
  				-- Step 1: Calculates the regression estimates 
   				local regrLogit = model.calcRegressionLogistic(cell,inputValues,landUseDrivers,self) 
				
   				-- Step 2: Calculates the elasticity
				local elas = 0				
				if (cell[lu] == 1) then 
					elas = inputValues.elasticity
				end	
				
				--Step 3 : Computes the total probability
				cell[lu.."_pot"] = regrLogit + elas 
				
			end	--close for region
		end -- close for cell
	end
	
	model.verify = function (self,event)
	end
	
	model.calcRegressionLogistic = function (cell,inputValues,luDrivers,model) 
			
			local regrLogit = inputValues.const
			local betas = inputValues.betas
			local attrs = inputValues.attributes
		
			for var, beta in pairs (betas) do
			    --print (var, beta)
				regrLogit = regrLogit + beta * cell[var]
			end
		return (model.probability(regrLogit))
	end	--end calcRegressionLogistic
	
	-- Computing the probability  
	
	model.probability = function (z)
		local euler  = 2.718281828459045235360287;
		local zEuler = math.pow(euler,z);
		local prob = zEuler/(1+zEuler);
		
		return (prob)
	end
 return model
 
end --close RegressionLogistcModel	