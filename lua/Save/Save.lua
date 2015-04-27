--- Save the generated data after the simulation into the database for each year a theme will be created.
-- @arg luccmemodel A LuccMe model.
-- @usage saveToDatabase = databaseSave(luccMeModel)
function databaseSave(luccmemodel)
	local saveYears = {}
	tsave = Timer{}
	
	-- Verifies whether the years be to be saved were correctly chosen
	if ((luccmemodel.save.yearly == false) and ((luccmemodel.save.saveYears == nil) or (luccmemodel.save.saveYears[1] == nil))) then
		error("Please set which year of the simulation will be saved", 2)
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
		-- for year = 2005, luccmemodel.endTime, 5 do
		e2 = Event {	time = year,
						priority = 21,
						action = function(event)
									forEachCell(luccmemodel.cs, function(cell)
																	for j, lu in pairs (luccmemodel.landUseTypes) do
																			--if (lu ~= luccmemodel.allocation.landUseNoData and lu ~= luccmemodel.allocation.complementarLU) then
																			if (lu ~= luccmemodel.allocation.landUseNoData) then
																				cell[lu.."_Ext"..year] = cell[lu] * luccmemodel.cs.cellArea     -- ANAP: concatenate all saveAttrs instead
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
				--for year = luccmemodel.scenarioStartTime, luccmemodel.endTime, 1 do
				for year = luccmemodel.startTime + 1, luccmemodel.endTime, 1 do --ANAP
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
end

--- Save the generated data after the simulation into the database all the data for each year will be created in a single theme.
-- @arg luccmemodel A LuccMe model.
-- @arg flagArea A flag used to indicate if the simulated area will be recorded or not.
-- @usage saveToDatabase = saveSingleTheme_v1(luccMeModel, true)
function saveSingleTheme_v1(luccmemodel, flagArea)	
	local n = 1
	local attrs = {}
	local attrsinc = {}
	local attrs_out = {}
	
	if (luccmemodel.potential.landUseNoData ~= nil) then
		  attrs[n] = "result_nodata"
		  attrsinc[n] = "result_nodata"
		  attrs_out[n] = "result_nodata"
		  n = n + 1
		  forEachCell(luccmemodel.cs, function(cell)
											cell["result_nodata"] = cell[luccmemodel.potential.landUseNoData]
									  end
					 )
	end

	print ("\n-------------------------------------------------------------")
	print (luccmemodel.name.." - Actual allocated area in each year:")
	print ("-------------------------------------------------------------\n")

	for j, lu in pairs (luccmemodel.landUseTypes) do
		--print ("\n"..lu)
		local tot = {}

		for year = luccmemodel.startTime + 1, luccmemodel.endTime, 1 do
			out = lu.."ext"..year
			change = lu.."inc"..year

			out_area = lu.."ext_area"..year
			change_area = lu.."inc_area"..year

			tot[year] = 0
			
			forEachCell(luccmemodel.cs, function(cell)
											tot[year] = tot[year] + cell[out] * luccmemodel.cs.cellArea
											if (flagArea == true) then
												cell[out_area] = cell[out] * luccmemodel.cs.cellArea
												cell[change_area] = cell[change] * luccmemodel.cs.cellArea
											end
										end
						)
			print ("       ", year, math.floor(tot[year]))

			--if (lu == "luDeforest") then
			if (lu ~= luccmemodel.potential.landUseNoData) then
				if (flagArea == true) then
					attrs_out[n] = out_area
					attrsinc[n] = change_area
				end
				attrs[n] = out
				n = n + 1
			end
		end
	end
	
	io.flush()
	if (flagArea == true) then
		luccmemodel.cs:save(luccmemodel.endTime, luccmemodel.save.outputTheme.."single_inc_area_", attrsinc)
	end
	if (flagArea == true) then
		luccmemodel.cs:save(luccmemodel.endTime, luccmemodel.save.outputTheme.."single_ext_area_", attrs_out)
	end
	if (flagArea == true) then
		luccmemodel.cs:save(luccmemodel.endTime, luccmemodel.save.outputTheme.."single_ext_perc_", attrs)
	end
end

--- Save the generated data after the simulation into the database all the data for each year will be created in a single theme.
-- @arg luccmemodel A LuccMe model.
-- @arg flagArea A flag used to indicate if the simulated area will be recorded or not.
-- @usage saveToDatabase = saveSingleTheme_v0(luccMeModel, true)
function saveSingleTheme_v0(luccmemodel, flagArea)	
	local n = 1
	local attrs = {}

	print ("\n-------------------------------------------------------------")
	print (luccmemodel.name.." - Actual allocated area in each year:")
	print ("-------------------------------------------------------------\n")

	for j, lu in pairs (luccmemodel.landUseTypes) do
		--print ("\n"..lu)
		local tot = {}
		for year = luccmemodel.startTime, luccmemodel.endTime, 1 do
			out = lu..year
			change = lu.."inc"..year

			out_area = lu.."ext_area"..year
			change_area = lu.."inc_area"..year

			tot[year] = 0
			forEachCell(luccmemodel.cs, function(cell)
											tot[year] = tot[year] + cell[out] * luccmemodel.cs.cellArea
											if (flagArea == true) then
												cell[out_area] = cell[out] * luccmemodel.cs.cellArea
												cell[change_area] = cell[change] * luccmemodel.cs.cellArea
											end
										end
						)
			print ("       ", year, math.floor(tot[year]))
			attrs[n] = out
			n = n + 1
			attrs[n] = change
			n = n + 1
			if (flagArea == true) then
				attrs[n] = out_area
				n = n + 1
				attrs[n] = change_area
				n = n + 1
			end
		end
	end
	
	io.flush()
	luccmemodel.cs:save(luccmemodel.endTime, luccmemodel.save.outputTheme.."single_", attrs)
end
