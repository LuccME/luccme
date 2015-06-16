-------------------------------------------------------------------------------------------
--LuccME - a framework for top-down land use change modelling.
--Copyright © 2009 - 2015 INPE.
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
function LogisticRegression (component)

	component.execute = function (self,event,modelParameters)
		local cs = modelParameters.cs 
		local regressionData = self.regressionData
 		local luTypes = modelParameters.landUseTypes 
 		local landUseDrivers = self.landUseDrivers 
  		
  		for k,cell in pairs( cs.cells ) do
				 
			if (cell.region == nil) then cell.region = 1 end 
  				 
 			for luind, inputValues in  pairs(regressionData[cell.region]) do
				local lu = luTypes[luind]
  				
  				-- Step 1: Calculates the regression estimates 
   				local regrLogit = self.calcRegressionLogistic(cell,inputValues,landUseDrivers,self) 
				
   				-- Step 2: Calculates the elasticity
				local elas = 0				
				if (cell[lu] == 1) then 
					elas = inputValues.elasticity
				end	
				
				-- Step 3 : Computes the total probability
				cell[lu.."_pot"] = regrLogit + elas 
				
			end	--close for region
		end -- close for cell
	end
	
	component.verify = function (self,event)
	end
	
	component.calcRegressionLogistic = function (cell,inputValues,luDrivers,component) 
			local regrLogit = inputValues.const
			local betas = inputValues.betas
			local attrs = inputValues.attributes
		
			for var, beta in pairs (betas) do
				regrLogit = regrLogit + beta * cell[var]
			end
			
		return component.probability(regrLogit)
	end	--end calcRegressionLogistic
	
	-- Computing the probability  
	component.probability = function (z)
		local euler  = 2.718281828459045235360287
		local zEuler = math.pow(euler,z)
		local prob = zEuler/(1+zEuler)
		
		return prob
	end
	
	return component
 end --close LogisticRegression	
