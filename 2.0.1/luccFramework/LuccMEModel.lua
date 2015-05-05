-------------------------------------------------------------------------------------------
--LuccME - a framework for topdown land use change modelling.
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

function LuccMEModel (model)
	
	model.execute = function (self,event)
		if (event:getTime() == self.startTime) then
			model:verify(event)
		end
 	        
		if (self.updateYears ~= nil) then model:dinamicVars(event) end
		
		self.demand:execute 	(event, model)
	
	    self.potential:execute	(event, model)

		self.allocation:execute	(event, model) 
					
	end

		
	model.verify = function (self,event)
			if (model.name == nil) then 
				error("Model name not defined", 2) 
			end
		
			if self.scenarioName == nil and self.scenarioStartTime ~= nil then
				error("A scenario name is required", 2)
			end
		
			if self.scenarioName ~= nil and self.scenarioStartTime == nil then
				error("A scenario start time is required", 2)
			end
		
	        self.result = {}
	        

			---Verify whether the attributes to be saved were calculated in the model
			for i, lu in pairs (self.landUseTypes) do
				if self.cs.cells[1][lu] == nil then
					error("Invalid land use type", 2)
				end

				local equal = 1
			end
			
			if equal == 0 then
				error(" Attributes to be saved must be calculated as land use type in the model", 2)
			end

		   local luTypes 	= self.landUseTypes
		   local cs 		= self.cs
		   if (cs.cells[1].past[luTypes[1]] == nil) then
				cs:synchronize()
			end  
	        if self.useLog == nil then  self.useLog = true end 	 -- print model status during its execution 
	        if self.isCoupled == nil then  isCoupled = false end -- inform whether the model is part of a coupling model 
 	        io.flush()
			self.demand:verify(event,self) 
			self.potential:verify(event,self)
		    self.allocation:verify(event,self) 
	end
	
	model.dinamicVars = function (self,event)
		currentTime = event:getTime()
		for i, updtYear in pairs(self.updateYears) do
			-- If current year needs to update variables
			if currentTime == updtYear then
				print("Updating dynamic variables...")
				
				if (self.scenarioStartTime ~= nil) and (currentTime >= self.scenarioStartTime) then  
				      cs_temp = CellularSpace{	    host = self.cs.host, user = self.cs.user, password = self.cs.password,
													database = self.cs.database,
					                         		theme = self.cs.theme.."_"..self.scenarioName.."_"..updtYear}
					                         		print (self.cs.theme.."_"..self.scenarioName.."_"..updtYear)           
				else
				      cs_temp = CellularSpace{	host = self.cs.host, user = self.cs.user, password = self.cs.password,
				      							database = self.cs.database,
					                           theme = self.cs.theme.."_"..updtYear}
					                            print (self.cs.theme.."_"..updtYear)           

				end
				-- for each cell in the original cs, variables are contained in cs_temp is updated
				local flag = false
			       		
			     forEachCellPair(cs,cs_temp,function(cell,cell_temp)
					  		for var, value in pairs(cell_temp) do
								if var~= "cObj_" and var~="objectId_" and 
								   var~="y" and var~="x" and var~="past" and
								   var~="agents" and var~="agents_" and 
								   var~="object_id_" then
						    			if (cell[var]~= nil) then
						    			     cell[var] = cell_temp[var]
						    			     if (flag == false) then
						          				print("          ", var, cell[var])
						          		
						          			 end		          					
							 			end
								end
							end --for var
							flag = true
				   end)
			end
		end				
	end
	
	return model
end