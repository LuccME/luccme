-------------------------------------------------------------------------------------------
--LuccME - a framework for topdown land use change modelling.
--Copyright � 2009 - 2015 INPE.
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
function allocationClueLike (component)
-- external interface
	-- execute
	-- verify 
-- internal	
	-- computeDemandDirection
	-- initElasticity
	-- computeChange
	-- correctCellChange
 
	----------------------------------------------------------------   	 
	component.execute = function (self,event,luccMEModel) 
	----------------------------------------------------------------   	 
	-- Synchronize cellular space in the first year
		   local luTypes 	= luccMEModel.landUseTypes
		   local cs 		= luccMEModel.cs
		
			--Init demandDirection and elasticity (internal component variables)
		    self:initElasticity        (luccMEModel, self.initialElasticity)  

			-- Define iteration loop variables
		    local nIter= 0
			local allocation_ok = false
			local maxAdjust = self.maxDifference  
			local maxdiff = self.maxDifference*1000 -- Initializing for a large number of iteration
			local flagFlex = false
			 		
		    -- Loop until maxdiff is achieved
			repeat
			    -- compute tentative allocation
				self:computeChange (luccMEModel)
				self:correctCellChange (luccMEModel)
				
				if luccMEModel.useLog == true then
					self:printAllocatedArea(event, luccMEModel, nIter)
				end
				
				-- verify if allocation reaches demand
				maxdiff = self:compareAllocationToDemand(event, luccMEModel)		
				if (maxdiff <= maxAdjust) then
					allocation_ok = true
					if luccMEModel.useLog == true then
						print ("Demand allocated correctly in ", event:getTime(),"number of iterations", niter, "maximum error: ", maxdiff )
			        end
				else  
					nIter = nIter + 1
		 	    end
			until ((nIter >= self.maxIteration) or (allocation_ok == true) )
	        
			if (nIter == self.maxIteration)then
				print ("Demand not allocated correctly in this time step:", nIter)
				os.exit()
            end				
            
            forEachCell(cs, function(cell)
               local total = 0 
               for i, lu in pairs( luTypes ) do
            	   if (lu ~= luccMEModel.complementarLU) then
            	      total = total + cell[lu]
            	    end
               end
		       if (luccMEModel.complementarLU ~= nil) then
		              cell[luccMEModel.complementarLU] = 1 - total
		       end
		    end)
		    
            for i, lu in pairs( luTypes ) do
            	local out = lu.."_out"
            	local diff = lu.."_change"
				for k, cell in pairs( cs.cells ) do
					cell[out] = cell[lu]
				    cell[diff] = cell[ lu ] - cell.past[lu]
				end
		     end
				
		     cs:synchronize()
		end
		
----------------------------------------------------------------   	 
	component.verify = function (self,event,luccMEModel) 
	---------------------------------------------------------------- 
	end
	 
	----------------------------------------------------------------   	 
	component.initElasticity = function(self, luccMEModel, value)
	----------------------------------------------------------------   	 
	-- Init elasticity. In this version of the component, a single elasticity for each land use (all cells).
	-- Similar to the coarse scale old clue
			local luTypes = luccMEModel.landUseTypes
			self.elasticity = {}	
			for k,lu in pairs( luTypes ) do
				self.elasticity[k] = value
			end
		end

	----------------------------------------------------------------   	 
	component.computeChange = function ( self, luccMEModel)
	----------------------------------------------------------------   	 

		local cs      = luccMEModel.cs
		local luTypes = luccMEModel.landUseTypes
	
	
		for i, luAllocData in pairs( self.allocationData ) do
				local lu = luTypes[i]
				local attr_pot = lu.."_pot"
				
				local luDirect = luccMEModel.demand:getCurrentLuDirection (i)
				for k, cell in pairs( cs.cells ) do				
					local pot = cell[attr_pot]
					local luStatic = luAllocData.static
						
					local change = pot* self.elasticity[i]
						        
					if (math.abs(change) < luAllocData.minChange) then 
					    pot = 0
					    change = 0
					end
					
					
					if (math.abs(change) >= luAllocData.maxChange) then 
					      change = luAllocData.maxChange*(pot/math.abs(pot)) 
					end
					
					if (( pot >= 0 ) and ( luDirect == 1 )  and ( luStatic< 1)) or
					   (( pot <= 0 ) and ( luDirect == -1 ) and ( luStatic < 1)) then
					
							cell[ lu ] = cell.past[lu] + change  
					elseif ( luStatic ~= 0 ) then
						   cell[ lu ] = cell.past[ lu ]
					end
		
				   if ( cell[ lu ] < 0 ) then 
				            cell[ lu ] = 0 
				   end
				   
				    if ( cell[ lu ] > 1 ) then 
				            cell[ lu ] = 1 
				   end
				   

			    if (cell[lu] <= luAllocData.minValue) then	
							if (cell.past[lu] >= luAllocData.minValue) then 
						       cell[lu] = luAllocData.minValue
						else
						      cell[lu] = cell.past[lu]
						end 
		 			end
		 			
				if (cell[lu] > luAllocData.maxValue) then	
					     print ("ERRO MAX 1", cell[lu], luAllocData.maxValue)
			
						if (cell.past[lu] <= luAllocData.maxValue) then  
						       cell[lu] = luAllocData.maxValue
						else
						      cell[lu] = cell.past[lu]
						end 
				end
			end  -- for cell
		end -- for lu
	end

	----------------------------------------------------------------   	 
	component.compareAllocationToDemand = function (self, event, luccMEModel)
	----------------------------------------------------------------   	 
	-- Compares the demand to the amount of allocated land use/cover, then adapts elasticity
			local cs 				= luccMEModel.cs
			local luTypes 			= luccMEModel.landUseTypes
		
			local cellarea = cs.cellArea
			local areas = self:countAllocatedLandUseArea(cs, luTypes)
			
			local max = 0
			local tot = 0
		
			for i, lu in  pairs( luTypes) do
			    local luDirect 		 = luccMEModel.demand:getCurrentLuDirection(i)
			    local currentDemand  = luccMEModel.demand:getCurrentLuDemand(i) 
			    
				if ( luDirect == 0) and (event:getTime() == luccMEModel.startTime) then 
					if ( currentDemand  >= areas[i]) then
						luDirect = 1
					else
						luDirect = -1
					end
				end
				if (luDirect == 1) then
						self.elasticity[i] = self.elasticity[i]  * (currentDemand / areas[i])
				else
						self.elasticity[i]  = self.elasticity[i]  * (areas[i] / currentDemand )
				end
				local flag = false
				
				if (self.elasticity[i] > self.maxElasticity) then  
				        flag = true
						self.elasticity[i] = self.maxElasticity
						luccMEModel.potential:modify (luccMEModel, i, luDirect)			
				end
				
				if (self.elasticity[i] < self.minElasticity) then
				    flag = true
					if (self.allocationData[i].static < 0) then  
						  self.elasticity[i] = self.minElasticity
						  luccMEModel.potential:modify (luccMEModel, i, luDirect*(-1)) -- original clue does not modify in this case, but AMAZALERT results are like this
						  
					else
						  luccMEModel.demand:changeLuDirection (i)
					end
				end
				if (luccMEModel.useLog == true and flag == true) then
					   print (lu, "elas: ", self.elasticity[i],"dir: ",luDirect,"const :",luccMEModel.potential.regressionData[i].const,"->", luccMEModel.potential.regressionData[i].newconst, luccMEModel.potential.regressionData[i].newminReg, luccMEModel.potential.regressionData[i].newmaxReg    )  
		        end
		
				local  diff = math.abs((areas[i] - currentDemand)) 
				if ( diff > max) then 
					max =  diff
				end
				tot =  tot + math.abs(areas[i] - currentDemand )
			end
			
			return max
		end
		
	----------------------------------------------------------------   
	component.correctCellChange = function (self, luccMEModel)
	----------------------------------------------------------------   
	-- corrects total land use/cover types to 100 percent
			local cs      = luccMEModel.cs
			local luTypes = luccMEModel.landUseTypes
		
			local NCOV = #luTypes 
			local BACKP = 0.5
			for k, cell in pairs( cs.cells ) do
				local nostatic = 0
				local decr = 0
				local incr = 0
				local totcov = 0
				local totchange = 0
				local amin = cell[ luTypes[1] ] - cell.past[ luTypes[1] ]
				local amax = amin
				local max  = math.abs( amax )
				local l=0
				
				-- checks if total land use/cover ers from 100 percent
				for i, lu in pairs( luTypes ) do
					totcov = totcov + cell[ lu ] 
				end
	
				if( math.abs( totcov - 1 ) > 0.005 )then
					for i, lu in pairs( luTypes ) do
						local dif = cell[ lu ] - cell.past[ lu ]
						totchange = totchange + math.abs( dif )
						if( math.abs( dif ) > max ) then max = math.abs( dif ) end
						if( dif > amax ) then amax = dif end
						if( dif < amin ) then amin = dif end
					end
	
					-- adapts land use/cover types if all of them change into the same direction
					if (totchange > 0) then
						if ((BACKP * totchange) > (max * 0.5))then  
							BACKP = (max / (2*totchange))
						end
					end
	
					for i, luAllocData in pairs( self.allocationData ) do
						local lu = luTypes[i]
						local luStatic = luAllocData.static
					    if ((cell[lu] <= luAllocData.minValue) or cell[lu] >= luAllocData.maxValue)then 
										luStatic =1
					     end		
					   if (luStatic < 1) then
							local dif = cell[ lu ] - cell.past[ lu ]
							if ( dif > (-1 * BACKP * totchange)) then incr = incr + 1 end
							if ( dif < (BACKP * totchange)) then decr = decr + 1 end
						else 
							nostatic = nostatic + 1 
						end
					end
	
					if (decr == (NCOV-nostatic)) or (incr == (NCOV-nostatic)) then
						for i, luAllocData in pairs( self.allocationData ) do
							local lu = luTypes[i]
							
							local luStatic = luAllocData.static
						    if ((cell[lu] <= luAllocData.minValue) or cell[lu] >= luAllocData.maxValue)then
										luStatic =1
							end		
							 if (luStatic < 1) then
							 
								if (incr == (NCOV-nostatic)) then
									cell[ lu ] =  cell[ lu ] - (amin + (BACKP * totchange))
								end
								if (decr == (NCOV-nostatic)) then
									 cell[ lu ] = cell[ lu ] + ((BACKP * totchange) - amax)
								end
								if ( cell[ lu ] < 0) then 
									cell[ lu ] = 0 
								end
							end
							if (luDirect == 1) and (cell[lu] < cell.past[lu]) and (luAllocData.static == -1) then
								cell[lu] = cell.past[lu]
							end
							if (luDirect == -1) and (cell[lu] > cell.past[lu]) and (luAllocData.static == -1) then
								cell[lu] = cell.past[ lu ]
							end
						end
					end
					-- perform the corrections
					repeat
						l = l + 1
						totcov = 0
						totchange = 0
						totstatic = 0
						for i, luAllocData in pairs( self.allocationData ) do
							local lu = luTypes[i]
							local luStatic = luAllocData.static
							 if ((cell[lu] <= luAllocData.minValue) or cell[lu] >= luAllocData.maxValue)then
										luStatic =1
							end		
							if (luStatic < 1) then
								totcov = totcov + cell[ lu ]
							else
								totstatic = totstatic +  cell[ lu ]
							end
							totchange = totchange + math.abs(cell[lu] - cell.past[lu])
						end
						if ( math.abs(totcov - (1-totstatic)) > 0.005) then
							if (totchange == 0) then
								for i, luAllocData in pairs( self.allocationData ) do
									local lu = luTypes[i]
	                                local luStatic = luAllocData.static
							        if ((cell[lu] <= luAllocData.minValue) or cell[lu] >= luAllocData.maxValue)then
										luStatic =1
									end		
							        if (luStatic < 1) then
								
							             cell[ lu ] = cell[ lu ] * ((1-totstatic)/totcov)
									end
								end
							else
								for i, luAllocData in pairs( self.allocationData ) do
									local lu = luTypes[i]
									local aux = cell[ lu ]
									cell[ lu ] = cell[ lu ] - (math.abs(cell[lu] - cell.past[lu]) * ((totcov - (1-totstatic))/totchange))
									if (cell[lu] < 0) then 
										cell[lu] = 0 
									end
									
								end
							end
						end
					until (math.abs(totcov - (1-totstatic)) <= 0.005) or (l >= 25)
	
					if (l == 25) then
						totcov = 0
						totstatic = 0
						for i, luAllocData in pairs( self.allocationData ) do
							local lu = luTypes[i]
							 local luStatic = luAllocData.static
							  if ((cell[lu] <= luAllocData.minValue) or cell[lu] >= luAllocData.maxValue)then
										luStatic =1
							end			
							 if (luStatic < 1) then
								totcov = totcov + cell[ lu ]
							else
								totstatic = totstatic + cell[lu]
							end
						end
						for i, luAllocData in pairs( self.allocationData ) do
							local lu = luTypes[i]
							local luStatic = luAllocData.static
							if ((cell[lu] <= luAllocData.minValue) or cell[lu] >= luAllocData.maxValue)then
										luStatic =1
							end			
							 if (luStatic < 1) then
								cell[ lu ] = cell[ lu ] * ((1-totstatic)/totcov)
							end
						end
					end
				end
		
		  end -- for each cell
	end -- correct100
	
	
	----------------------------------------------------------------   
	component.countAllocatedLandUseArea = function (self, cs, luTypes)
	-- Calculates total area allocated by the regression equations for each land use/cover type

		local areas = {}
		local cellarea = cs.cellArea
		for i, lu in pairs( luTypes ) do
			local area = 0
			for k,cell in pairs( cs.cells ) do
				local temp = cell[ lu ] 
				if( temp > 0 ) then
						area = area + temp 
				end
			end
			areas[ i ] = area * cellarea
		end
		return areas
	end

	----------------------------------------------------------------   
	component.printAllocatedArea = function ( self, event, luccMEModel, nIter)
	----------------------------------------------------------------   
	-- calculates and prints the allocated by the regression equations for each land use/cover type

		local cs      = luccMEModel.cs
		local luTypes = luccMEModel.landUseTypes
		local areas, total = {}, 0
		local idx = 1
		areas = self:countAllocatedLandUseArea( cs, luTypes )
		
		print("\nYear:"..event:getTime()," Step: "..nIter )   
		for i, lu in pairs( luTypes ) do
		    local currentDemand  = luccMEModel.demand:getCurrentLuDemand(i) 
		    print (lu.." area: \t"..math.floor (areas[i]),  "Difference: ", math.floor (areas[i]- currentDemand))  
		end
		io.flush()
	end

	----------------------------------------------------------------   
	return component
	
end -- close Allocation Component
-------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------


-------------------------------------------------------------------------------------
-- SUBROUTINES
-------------------------------------------------------------------------------------
