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

function SpatialLagRegressionINPE (component) 
-- component.execute
-- component.verify
-- component.modify

---------------------------------------------------------------------- 	
component.execute = function (self,event,luccMEModel)
---------------------------------------------------------------------- 
		local cs 		= luccMEModel.cs
		local luDrivers = self.landUseDrivers
		local luTypes 	= luccMEModel.landUseTypes
        local demand 	= luccMEModel.demand
		
        -- create an internal const that can be modified during allocation
		for i, luData in pairs(self.regressionData) do
			if luData.const  == nil then luData.const = 0 end
			luData.newconst = luData.const
		end
		
        if (event:getTime() > luccMEModel.startTime) then 
			self:adaptRegressionConstants(demand, event )
        end
	
		for i, luData in  pairs( self.regressionData ) do	                      
		    self:computePotential (luccMEModel, i)
	    end

    end  -- function execute
----------------------------------------------------------------------
component.verify = function (self, event, luccmeModel)
----------------------------------------------------------------------
     
      cs = luccmeModel.cs
	  for i, luData in pairs (self.regressionData) do 
	        if (luccmeModel.landUseTypes[i] == nil) then
			 	error("Invalid number of regressions", 2)
			end 
	        for var, beta in pairs (luData.betas) do
				if luccmeModel.cs.cells[1][var]== nil then
					error("Invalid land use driver", 2)
			    end
		    end
		    if (luData.ro == nil) then
	           error("ro parameter must be defined", 2)
    end	
	  end
	  
	  local find = false	
      
	  if (self.landUseNoData == nil) then find = true end			
	     
     for j, lu in pairs (luccmeModel.landUseTypes) do 
		   if (self.regressionData[j] == nil) then 
		    	error("Invalid number of regressions", 2)
		   end
     
           if (self.landUseNoData == lu) then find = true end
  
	 end
             
     if (find == false) then	
            error("Invalid land use no data variable", 2)
	 end
	 
	 local filename = self.filename 
	 	if (filename ~= nil) then
			loadGALNeighborhood (filename)
	else
			cs:createNeighborhood()	
	end
	

	

		         
end
 
---------------------------------------------------------------------- 
component.modify = function (self, luccMEModel, luIndex, direction)
---------------------------------------------------------------------- 

	
    luData = self.regressionData[luIndex] 
	     
	if luData.newconst == nil then luData.newconst = 0 end	
	 
    if( luData.isLog ) then 
	        luData.newconst = luData.newconst - math.log10(0.1)* direction
	else
		    luData.newconst = luData.newconst + 0.1 * direction
	end

    self:computePotential (luccMEModel, luIndex)

end	-- function	modifyPotential	
	

 


-------------------------------------------------------------------
-- SUBROUTINES FOR THIS COMPONENT
-------------------------------------------------------------------
 		

-------------------------------------------------------------------
-------------------------------------------------------------------
component.adaptRegressionConstants = function(self, demand, event)
			
   for i, luData in pairs(self.regressionData) do			
			
  		local currentDemand = demand:getCurrentLuDemand (i)
        local previousDemand = demand:getPreviousLuDemand(i) 
	    local plus =  ((currentDemand - previousDemand ) / previousDemand)
	                       
        luData.newconst = luData .const
				
        if( luData.isLog ) then
		 	if (plus > 0) then 
				luData.newconst = luData.newconst - math.log10(plus)*0.01 --0.1
		  	end
		  	if (plus < 0) then 
		        luData.newconst = luData.newconst + math.log10((-1)*plus)*0.01 --0.1
		  	end
       else luData.newconst = luData.newconst + plus*0.01  end 
    end
end	-- function adaptRegressionConstants
		

-------------------------------------------------------------------
-------------------------------------------------------------------				
 component.computePotential = function(self, luccMEModel, luIndex)
     local cs 		= luccMEModel.cs	
     local luTypes 	= luccMEModel.landUseTypes
     local lu 		= luTypes[luIndex]
     local luData 	= self.regressionData[luIndex]

     local pot 		= lu.."_pot"
     local reg 		= lu.."_reg"

     for k,cell in pairs( cs.cells ) do
			local regression = luData.newconst
				
			for var, beta in pairs( luData.betas ) do 
				regression = regression + beta * cell[var]
			end
				
			local regresY = 0
			forEachNeighbor (cell, function (cell, neigh, weight)
				    regresY = regresY + weight * neigh[lu]
				    	--print (lu, regresY, weight, neigh[lu])
			end)
		
			regression = regression + regresY * luData.ro
			
			if( luData.isLog ) then -- if the land use is log tranformed
				regression = math.pow( 10, (regression))
			end 

			if(regression > 1)then
				regression = 1
			end
				
			if(regression <0)then
				regression = 0
			end
				
			if (self.landUseNoData ~= nil) then  
				regression = regression*(1-cell[self.landUseNoData])
			end
			        
			cell[pot] = regression - cell.past[lu]  
			cell[reg] = regression -- optional to save and analyze
			
		end
	end  -- function computePotential
	
	
	 

   return component

end -- component definition
