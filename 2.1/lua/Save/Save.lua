--- Save the generated data after the simulation into the database for each year a theme will be created.
-- @arg luccmemodel A LuccMe model.
-- @usage saveToDatabase = databaseSave(luccMeModel)
function databaseSave(luccmemodel)
	local saveYears = {}
	local e1 = {}
	local e2 = {}
	local tsave = Timer{}
	
	-- Verify the outputTheme variable
	if (luccmemodel.save.outputTheme == nil) then
	  error("outputTheme variable is missing on save parameters", 2)
	end

  -- Verify the dates to be saved
  if (luccmemodel.save.saveYears ~= nil) then
    for i = 1, #luccmemodel.save.saveYears, 1 do
      if (luccmemodel.save.saveYears[i] < luccmemodel.startTime or luccmemodel.save.saveYears[i] > luccmemodel.endTime) then
        error(luccmemodel.save.saveYears[i].." is selected to be saved, but it is out of the simulation range. From "..luccmemodel.startTime.." to "..luccmemodel.endTime..".", 2)
      end
    end
  end
	
	-- Check if one of the save year variable is declared 
	if (luccmemodel.save.saveYears == nil and luccmemodel.save.yearly == nil) then
	  error("saveYears or yearly variable must be used on save parameters.", 2)
	end
	
	-- Verifies whether the years be to be saved were correctly chosen
	if ((luccmemodel.save.yearly == false) and ((luccmemodel.save.saveYears == nil) or (luccmemodel.save.saveYears[1] == nil))) then
		error("Please set which year of the simulation will be saved. (saveYears variable on save parameters)", 2)
	elseif (luccmemodel.save.yearly == true) then
		for i = 0, (luccmemodel.endTime - luccmemodel.startTime) do
			saveYears[i + 1] = luccmemodel.startTime + i
		end
	else
		saveYears = luccmemodel.save.saveYears
	end

	-- Save
	for i, year in pairs (saveYears) do
		e1 = Event {	time = year,
						      priority = 20,
						      action = function(event)
            								  if (luccmemodel.save.mode == "multiple") then
            									 luccmemodel.cs:save(event:getTime(), luccmemodel.save.outputTheme, luccmemodel.save.saveAttrs)
            									end
            									return false
          								 end
					     }
		tsave:add(e1)
	end
	
	for year = luccmemodel.startTime + 1, luccmemodel.endTime, 1 do
		e2 = Event {  time = year,
						      priority = 21,
						      action = function(event)
            									forEachCell(luccmemodel.cs, function(cell)
            																	for j, lu in pairs (luccmemodel.landUseTypes) do
            																			if (lu ~= luccmemodel.allocation.landUseNoData) then
            																				cell[lu.."_Ext"..year] = cell[lu] * luccmemodel.cs.cellArea
            																				cell[lu.."_Area"..year] = cell[lu.."_change"] * luccmemodel.cs.cellArea
            																			end
            																	end
            															end
            												      )
            									return false
            								 end
					     }
		tsave:add(e2)
	end
	
	return tsave
end

--- Save the generated data after the simulation into the database all the data for each year will be created in a single theme.
-- @arg luccmemodel A LuccMe model.
-- @usage saveToDatabase = saveSingleTheme(luccMeModel)
function saveSingleTheme(luccmemodel)
	local n = 1
	local attrs_inc = {}
	local attrs_ext = {}
	local out = ""
	local change = ""
	
	if (luccmemodel.potential.landUseNoData ~= nil) then
		  attrs_inc[n] = "result_nodata"
		  attrs_ext[n] = "result_nodata"
		  n = n + 1
		  forEachCell(luccmemodel.cs, function(cell)
											cell["result_nodata"] = cell[luccmemodel.potential.landUseNoData]
									  end
					       )
	end

	for j, lu in pairs (luccmemodel.landUseTypes) do
		if (lu ~= luccmemodel.allocation.landUseNoData and lu ~= luccmemodel.allocation.complementarLU) then
				for year = luccmemodel.startTime + 1, luccmemodel.endTime, 1 do
					out = lu.."_Ext"..year
					change = lu.."_Area"..year
					attrs_ext[n] = out
					attrs_inc[n] = change
					n = n + 1
				end
		end
	end

	io.flush()
	luccmemodel.cs:save(luccmemodel.endTime, luccmemodel.save.outputTheme.."inc_area_", attrs_inc)
	luccmemodel.cs:save(luccmemodel.endTime, luccmemodel.save.outputTheme.."ext_area_", attrs_ext)
	print("\nEnd of Simulation")
	local answer
  repeat
     io.write("\nPress any key to exit...")
     io.flush()
     answer = io.read()
  until answer ~= "`"
end
