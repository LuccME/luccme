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

function modifyRoads (lu, roadsModel, cell)
        local incr = 0
        --print ("modifyRoads")
        for i, attr in pairs(roadsModel.attrs) do
             local diff = cell[attr] - cell.past[attr]
           --  if (diff ~= 0) then print (attr, diff, cell[attr], cell.past[attr]) end 
             if (roadsModel.change < 0) and (diff < 0) then
                  if diff < roadsModel.change then 
                        incr =  incr + roadsModel.increment 
                        print ("DECREASE", lu, attr, diff,  incr )            

                  end
             end 
             if (roadsModel.change > 0) and (diff > 0) then
                  if diff > roadsModel.change then 
                  			incr =  incr + roadsModel.increment 
                        print ("INCREASE", lu, attr, diff,  incr )            

                  end
             end 

         end    
                
        return incr
end

function SpatialLagRegressionINPE_limReg_RoadModel (component) 
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
			if luData.minReg  == nil then luData.minReg = 0 end
			if luData.maxReg  == nil then luData.maxReg = 1 end
			luData.newconst = luData.const
			luData.newminReg = luData.minReg
			luData.newmaxReg = luData.maxReg
		end
	    if self.constChange  == nil then self.constChange = 0.1 end  -- original clue value

        if (event:getTime() > luccMEModel.startTime) then 
			self:adaptRegressionConstants(demand, event ) -- LOG TIRAR
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
      
	  if (self.landUseNoData == nil) then 
	       find = true 
		   self.landUseNoData = "defaultlandUseNoData"
		   cell[self.landUseNoData] = 0
	 end		
	     
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
			local const_unlog = math.pow (10, luData.newconst) + self.constChange * direction
		    if (const_unlog ~= 0) then luData.newconst = math.log10(const_unlog) end	
	else
	        luData.newconst = luData.newconst + self.constChange * direction
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
	    local plus = 0.01*((currentDemand - previousDemand ) / previousDemand)
	                       
        luData.newconst = luData.const
        
				
        if( luData.isLog ) then
				local const_unlog = math.pow (10, luData.newconst) + plus 
		        if (const_unlog ~= 0) then luData.newconst = math.log10(const_unlog) end
       else 
            luData.newconst = luData.newconst + plus  
       end    
       
      luData.newminReg = luData.newminReg + plus  
      luData.newmaxReg = luData.newmaxReg + plus
      
      luData.const = luData.newconst  -- PS24A8 v3
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
		
			
            local regressionX = 0
            				
			for var, beta in pairs( luData.betas ) do 
				regressionX = regressionX + beta * cell[var]
			end
			
			local regresY = 0
			local neighSum = 0
			local count = 0
			
			forEachNeighbor (cell, function (cell, neigh, weight)
			    Y = cell.past[lu]
			    neighY = neigh.past[lu]
			    --print ("weight", weight)
			    if (cell[self.landUseNoData] ~= 1) then Y = Y/(1-cell[self.landUseNoData]) end
			    if (neigh[self.landUseNoData] ~= 1) then neighY = neighY/(1-neigh[self.landUseNoData]) end
			    
			    if( luData.isLog ) then -- if the land use is log tranformed
				        Y = math.log10 (Y+0.0001)
				        neighY = math.log10 (neighY+0.0001)
				end
				
			
				 if (neigh[self.landUseNoData] < 1) then 
				           count = count + 1
				           neighSum = neighSum + neighY
				 end
				 
			
			end)
		
		    if (count > 0) then
				      regresY = neighSum/count
				 else
				      regresY = Y
			end
			
			
			--regresY = (regresY + Y)/2   SIM: v14   PS24v3  PS25A14 NAO:v22 PS22 PS24v2 PS25A14v2 
			regressionX = regressionX + regresY * luData.ro
			
	        local regression = luData.newconst + regressionX
			local regressionLimit = luData.const+ regressionX		
			
			if( luData.isLog ) then -- if the land use is log tranformed
				regression = math.pow( 10, (regression)) - 0.0001
				regressionLimit = math.pow( 10, (regressionLimit)) - 0.0001
			end 
			
		
			
			
			if (luData.roadsModel ~= nil) then 
			   -- print ("luData.roadsModel.increment", luData.roadsModel.increment)
				regressionLimit = regressionLimit + modifyRoads (lu, luData.roadsModel, cell) 
		    end

		   local oldReg = regressionLimit

			if (regressionLimit > luData.maxReg) then
				regression = 1
			end
				
			if (regressionLimit <luData.minReg) then
				regression = 0
			end
					
			if (regression > 1) then
				regression = 1
			end
				
			if (regression <0) then
				regression = 0
			end
			
			cell[reg] = oldReg -- optional to save and analyze
			
		    regression = regression*(1-cell[self.landUseNoData])
			        
			cell[pot] = regression - cell.past[lu]  
			
			
		end
	end  -- function computePotential
	
	
	 

   return component

end -- component definition
 

