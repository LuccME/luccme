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
function PreComputedValuesINPE (component)
-- External interface:
--      execute
--      verify
--      getCurrentDemand, getPreviousDemand
--      getCurrentLuDemand, getPreviousLuDemand
--      computeDemandDirection
-- Internal structures
--      annualDemand [year][lu]
--      currentDemand [lu]
--      previousDemand [lu]
--      demandDirection [lu]

----------------------------------------------------------------
component.execute = function (self, event, luccMEModel)	
----------------------------------------------------------------
		step = event:getTime() - luccMEModel.startTime + 1

		if (#self.annualDemand < step) then	
		        error ("Time required exceeds the demand set", 5) 
		end
		self.currentDemand = self.annualDemand[step]
			
		if (event:getTime() == luccMEModel.startTime) then
		   self.previousDemand =self.currentDemand
		else
		   self.previousDemand = self.annualDemand[step-1]	 
		end
		   
		   
		self.demandDirection = { }  --increasing (1), decreasing (-1) or static (0).
		
		for i, lu in pairs( luTypes ) do
		    self.demandDirection[ i] = 0 
			if ( step > 1 ) then
					if( self.previousDemand[i] < self.currentDemand[i] ) then
						self.demandDirection [ i ]  = 1
				    end
					if(  self.previousDemand[i] > self.currentDemand[i] ) then 
						self.demandDirection [ i ] = -1
				    end
				
			end
		end 
	end	    
	
---------------------------------------------------------------	
component.verify = function  (self, event, luccMEModel)
--------------------------------------------------------------- 
		yearsSimulated = (luccMEModel.endTime - luccMEModel.startTime) + 1

		if (#self.annualDemand < yearsSimulated) then
			error ("The simulation time exceeds the demand set", 5) 
		end	
		
		if (yearsSimulated == 0) then
			error ("The simulation time is zero", 5) 
	    end
	    
	    self.demandDirection = { } 
		luTypes = luccMEModel.landUseTypes
		self.numLU = 0
		 
	    for k,lu in pairs( luTypes ) do
	        self.demandDirection[k] = 0
	        if (self.annualDemand[1][k] == nil) then
	             error ("Invalid number of land use in the demand table", 5) 
	         end
	         self.numLU = self.numLU + 1
	    end
	    self.currentDemand = self.annualDemand[1]
		self.previousDemand =self.annualDemand[1]
	end	    
    
	component.getCurrentDemand = function (self)	
		 return (self.currentDemand) 
    end
    
    component.getPreviousDemand = function (self)	
		 return (self.previousDemand) 
    end
    
    component.getCurrentLuDemand = function (self, luIndex)		
         if (luIndex > self.numLU) then
           	error ("Invalid land use index", 5) 
	     end
		 return (self.currentDemand[luIndex]) 
    end
    
    component.getPreviousLuDemand = function (self, luIndex)	
         if (luIndex > self.numLU) then
           	error ("Invalid land use index", 5) 
	     end	
		 return (self.previousDemand[luIndex]) 
    end
    
	component.getCurrentLuDirection = function (self, luIndex)	
	     if (luIndex > self.numLU) then
           	error ("Invalid land use index", 5) 
	     end	
		 return (self.demandDirection[luIndex]) 
    end	
    
    component.changeLuDirection = function (self, luIndex)	
	     if (luIndex > self.numLU) then
           	error ("Invalid land use index", 5) 
	     end	
	     self.demandDirection[luIndex] = self.demandDirection[luIndex]*(-1)
		 return (self.demandDirection[luIndex]) 
    end		
    
	return component   
end 
