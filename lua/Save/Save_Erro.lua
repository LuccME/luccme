--- Save the data generated in the database for a set of years for all themes with allocation errors.
-- @arg luccmemodel A LuccMe model.
-- @usage saveToDatabase = databaseSave(luccMeModel)
function databaseSave(luccmemodel)
	local saveYears = {}
	tsave = Timer{}

	--INIT ATTRIBUTE NAMES
	if (luccmemodel.save.saveAttrs == nil) then   
		n = 1
		luccmemodel.save.saveAttrs = {}      
		for j, lu in pairs (luccmemodel.landUseTypes) do
			if (lu ~= luccmemodel.landUseNoData and lu ~= luccmemodel.complementarLU) then
					luccmemodel.save.saveAttrs[n] = lu.."_out" 
					n = n + 1
					luccmemodel.save.saveAttrs[n] = lu.."_pot" 
					n = n + 1
					luccmemodel.save.saveAttrs[n] = lu.."_change" 
					n = n + 1
					print ("n", n)
			end
		end
	--[[else 
	   for j, lu in pairs (luccmemodel.landUseTypes) do

			  local equal=0
			  for i, attr in pairs (self.save.saveAttrs) do
					if (lu == attr) then
						equal = 1
						break
					end
			 end 
			 if (equal == 0) then
				error("Attributes to be saved must be calculated as land use type in the model", 2)
			end
	  end--]]
	end
	
	--INIT ANNUAL SAVE
	print(luccmemodel.save.mode)

	if (luccmemodel.save.mode == nil) then
		luccmemodel.save.mode = "multiple" 
	end

	if (luccmemodel.save.mode == "multiple") then
		--Verifies whether the years be to be saved were correctly chosen
		if ((luccmemodel.save.yearly == false) and ((luccmemodel.save.saveYears == nil) or (luccmemodel.save.saveYears[1] == nil))) then
			error("Please set which year of the simulation will be saved", 2)
		elseif (luccmemodel.save.yearly == true) then
			for i = 0, (luccmemodel.endTime - luccmemodel.startTime) do
				saveYears[i + 1] = luccmemodel.startTime + i 
			end
		else
			saveYears = luccmemodel.save.saveYears
		end

		--Save
		for i, year in pairs (saveYears) do
			e1 = Event {	time = year, 
							priority = 20, 
							action = function(event) 
										luccmemodel.cs:save(event:getTime(), luccmemodel.save.outputTheme, luccmemodel.save.saveAttrs) 
										return false 
									 end
						}
			tsave:add(e1)
		end
	end
	
	--INIT SINGLE
	print ("SINGLE") --@todo Apagar?
	--[[
		for year = luccmemodel.startTime, luccmemodel.endTime, 1 do
			   print("ext", year)

				e2 = Event
				{
					time = year, 
					priority = 21,
					action = function(event) 
						forEachCell (luccmemodel.cs, function(cell) 
							print ("HERE")
							io.flush()
							 for j, lu in pairs (luccmemodel.landUseTypes) do
									 if (lu ~= luccmemodel.allocation.landUseNoData and lu ~= luccmemodel.allocation.complementarLU) then
											print ("change", cell [lu.."_change"])
											cell[lu.."ext"..year] = cell[ lu]*luccmemodel.cs.cellArea     -- ANAP: concatenate all saveAttrs instead
											cell[lu.."inc"..year] = cell [lu.."_change"]*luccmemodel.cs.cellArea
									 end
							 end
						 end) 
					return false 
				end
				}
				tsave:add(e2)
			end
	--]]		
	return tsave
end

--- Save the data generated in the database for a set of years for a single theme with allocation error.
-- @arg luccmemodel A LuccMe model.
-- @arg flagArea A flag used to indicate if the simulated area will be recorded or not.
-- @usage saveToDatabase = saveSingleTheme(luccMeModel)
function saveSingleTheme(luccmemodel, flagArea)	-- @todo Apagar flagArea?
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
			for year = luccmemodel.startTime, luccmemodel.endTime, 1 do
				out = lu.."ext"..year
				change = lu.."inc"..year
				attrs_ext[n] = out
				attrs_inc[n] = change
				n = n + 1  
			end  
		end
	end

	io.flush ()       
	luccmemodel.cs:save(luccmemodel.endTime, luccmemodel.save.outputTheme.."inc_area_", attrs_inc)  
	luccmemodel.cs:save(luccmemodel.endTime, luccmemodel.save.outputTheme.."ext_area_", attrs_ext)  
end

--- Save the data generated in the database for a set of years for a single theme with allocation error.
-- @arg luccmemodel A LuccMe model.
-- @arg flagArea A flag used to indicate if the simulated area will be recorded or not.
-- @usage saveToDatabase = saveSingleTheme_v1(luccMeModel)
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
	--if (flagArea == true) then luccmemodel.cs:save(luccmemodel.endTime, luccmemodel.save.outputTheme.."single_inc_area_", attrsinc) end 
	--if (flagArea == true) then luccmemodel.cs:save(luccmemodel.endTime, luccmemodel.save.outputTheme.."single_ext_area_", attrs_out) end 
	if (flagArea == true) then 
		luccmemodel.cs:save(luccmemodel.endTime, luccmemodel.save.outputTheme.."single_ext_perc_", attrs)
	end 
 end

--- Save the data generated in the database for a set of years for a single theme with allocation error.
-- @arg luccmemodel A LuccMe model.
-- @arg flagArea A flag used to indicate if the simulated area will be recorded or not.
-- @usage saveToDatabase = saveSingleTheme_v0(luccMeModel)
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
											tot[year] = tot [year] + cell[out] * luccmemodel.cs.cellArea
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
