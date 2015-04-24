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

function NeighInverseDistanceRule (model)
	
	model.execute = function (self,event,modelParameters)
										 
		local cs = modelParameters.cs 
		local luTypes = modelParameters.landUseTypes 
		local potentialData = self.potentialData 
 		local landUseDrivers = self.landUseDrivers 
  		local filename = self.filename 
		
		if filename ~= nil then
			loadGALNeighborhood (filename)
		else
			cs:createNeighborhood()		
		end
 		
		local totalNeigh = 0 
  		
  		for k, cell in pairs( cs.cells ) do
			totalNeigh = cell:getNeighborhood():size()
  		 	if (model.region == nil) then cell.region = 1 end 	
  		 			
			for i, lu in pairs( luTypes ) do  
			
			     
					    cell[lu.."_pot"] = 0
					local numNeigh = 0;
					forEachNeighbor(cell,function(cell,neigh)				
						if (neigh[lu] == 1)  then					
							numNeigh = numNeigh + 1
						end
				    end)
				-- Step 4: Compute potencial
				--if (numNeigh > 0) then print (numNeigh, totalNeigh)end
				if totalNeigh > 0 then cell[lu.."_pot"] = numNeigh/totalNeigh 	
				                  else 	cell[lu.."_pot"] = 0 
				end	
			--	print ("pot"..lu.."->"..cell[lu.."_pot"])
			
					 local luData 	= self.potentialData[i]
					-- print (luData.factor)
					 local potDrivers = 0
					 for var, coef in pairs( luData.multipliers ) do 
						if (cell[var] > 0) then potDrivers = potDrivers + coef*1/cell[var]*luData.factor
						                    else potDrivers = potDrivers + luData.factor end
					 end
					 
					 if (potDrivers > 1) then potDrivers = 1 end
					 
					-- print ("potDrivers", potDrivers)
					 cell[lu.."_pot"] = cell[lu.."_pot"] + potDrivers

			end
		end
	end -- end execute
	
	model.verify = function (self,event)
	end
	
	
	return model
end --close RegressionLogistcModelNeighbourhood