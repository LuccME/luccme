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

function databaseSave(luccmemodel)
 
	
	local saveYears = {}
	
	tsave = Timer{}
	
	--Verifies whether the years be to be saved were correctly chosen
	if (luccmemodel.save.yearly == false) and ((luccmemodel.save.saveYears == nil) or (luccmemodel.save.saveYears[1] == nil)) then
		error("Please set which year of the simulation will be saved", 2)
	elseif luccmemodel.save.yearly== true then
		for i = 0, (luccmemodel.endTime - luccmemodel.startTime)  do
			saveYears[i+1] = luccmemodel.startTime + i 
		end
	else
		saveYears = luccmemodel.save.saveYears
	end
   
			--Save
			for i, year in pairs (saveYears) do
		
				e1 = Event
				{
					time = year, 
					priority = 20, 
					action = function(event) 
				    if (luccmemodel.save.mode == "multiple") then
						luccmemodel.cs:save(event:getTime(),luccmemodel.save.outputTheme,luccmemodel.save.saveAttrs) 
					end
					return false 
				end
				}
				tsave:add(e1)
			end
		    for year = luccmemodel.startTime+1, luccmemodel.endTime, 1 do

            	e2 = Event
				{
					time = year, 
					priority = 21, 
					action = function(event) 

					forEachCell (luccmemodel.cs, function (cell) 
					         for j, lu in pairs( luccmemodel.landUseTypes ) do
					                 if (lu ~= luccmemodel.allocation.landUseNoData) then
					           				cell[lu.."_Ext"..year] = cell[ lu]*luccmemodel.cs.cellArea    
					           				cell[lu.."_Area"..year] = cell [lu.."_change"]*luccmemodel.cs.cellArea
					                 end
					         end
					end) 
					
					return false 
				end
				}
				tsave:add(e2)
			end
			

	return tsave
end

function saveSingleTheme (luccmemodel, flagArea)	
  local n = 1
  local attrs_inc = {}
  local attrs_ext = {}
	     
  if (luccmemodel.potential.landUseNoData ~= nil) then
		  attrs_inc [n] = "result_nodata"
		  attrs_ext [n] = "result_nodata"
		  n = n + 1
		  forEachCell (luccmemodel.cs, function (cell)
  		              cell["result_nodata"] = cell[luccmemodel.potential.landUseNoData]
  		  end)
  end 
  

  for j, lu in pairs( luccmemodel.landUseTypes ) do
      if (lu ~= luccmemodel.allocation.landUseNoData and lu ~= luccmemodel.allocation.complementarLU) then

        		for year = luccmemodel.startTime+1, luccmemodel.endTime, 1 do
	     		out = lu.."_Ext"..year
	     		change = lu.."_Area"..year
	     		attrs_ext [n] = out
		 	    attrs_inc [n] = change
			    n = n + 1  
		  end  
	end
 end
 io.flush ()       
 luccmemodel.cs:save(luccmemodel.endTime,luccmemodel.save.outputTheme.."inc_area_",attrs_inc)  
 luccmemodel.cs:save(luccmemodel.endTime,luccmemodel.save.outputTheme.."ext_area_",attrs_ext)  

end
