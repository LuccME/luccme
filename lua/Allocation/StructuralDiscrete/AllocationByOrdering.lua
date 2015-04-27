--- XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
-- @arg model A AllocationByOrdering model.
-- @arg model.execute Handles with the rules of the component execution.
-- @arg model.verify Handles with the parameters verification.
-- @usage allocation = AllocationByOrdering
--                   {	
--                       maxDifference = 0.001
--						
--					 }   
function AllocationByOrdering(model)
	--- Handles with the rules of the component execution.
	-- @arg self A allocationClueLike component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @arg model AllocationByOrdering model.
	-- @usage self.allocation:execute(event, model)
	model.execute = function(self, event, model)
	------Global and Local Variables and Constants------
		local useLog = self.useLog
		local cs = model.cs
		local potential = model.potential		
		local cellarea = cs.cellArea
		local step = event:getTime() - (model.startTime + 1)
		local start = model.startTime		
  		local demand = model.demand
		local nIter = 0
  		local allocation_ok = false
  		local numofcells  = #cs.cells
  		local totarea = (numofcells * cellarea)
  		local maxdiffarea = (self.maxDifference * totarea)
  		local luTypes = model.landUseTypes
  		local dem = {}
  		local differences = {}
  		
		--Inicialização das demandas
	   	for ind, lu in  pairs (luTypes) do	
 			dem[lu] = -1
 		end
  		
  		print ("Time : ", event:getTime())
    	print ("Step : ", step)
		if (useLog == true) then
			print ("----------------------------------------------------------------------------------------")
			print ("Cell Area "..cellarea)
			print ("Num of cells "..numofcells)
			print ("Max diff area "..maxdiffarea)	 		
			----------------------------------------------------
			for landuse, ivalues in pairs (luTypes) do        
				area = areaAllocated(cs, cellarea, luTypes[landuse], 1)
				print ("Initial area for land use : "..luTypes[landuse].." -> " ..area)
			end		
			print ("----------------------------------------------------------------------------------------")
	   	end
	   	
		for k, cell in pairs (cs.cells) do
			for luind, lu in  pairs (luTypes) do
				cell[lu.."_change"] = 0
				cell[lu.."_out"] = cell[lu]
			end
			cell.alloc = 0
			cell.simUse = currentUse(cell, luTypes)
        end

		diff = 0
		-- Crio o mapa de maiores probabilidades: simUse

		
		-- Ordenação dos vetores de uso de acordo com as maiores probabilidades
		for ind, lu in  pairs (luTypes) do	
			if (lu ~= model.landUseNoData) then --ANAP
				ord = Trajectory { target = cs,
								   select = function(cell)
												return (cell.alloc ~= 1 and cell.simUse ~= model.landUseNoData)
											end, -- ANAP
								   greater = function(c, d)
												return c[lu.."_pot"] > d[lu.."_pot"]
											end
								}

			 --Seleção de tantas células quanto forem necessárias na demanda
				local j = 1
				if (dem[lu] == -1) then
					dem[lu] = demand:getCurrentDemand(model)
					dem[lu] = dem[lu][ind]
				end
				cs_size = #cs.cells
				trj_size = #ord.cells	
				print ("demand", lu, dem[lu], "trajectory size", trj_size)
				--table.foreach(ord.cells, print)
		
				while (j <= dem[lu]) and (j <= (trj_size * cellarea))  do 
					-- Este atributo irá me indicar se a célula já teve seu uso alocado ou não
					ord.cells[j].alloc = 1
					ord.cells[j].simUse = lu
					j = j + 1
				end

				-- Quantidade alocada do uso neste passo de tempo
				areaAlloc = areaAllocated(ord, cellarea, "alloc", 1)
				print ("areaAlloc", lu, areaAlloc)
				differences[lu] = (dem[lu] - areaAlloc)

				if (differences[lu]> 0) then
					dem[lu] = differences[lu]
				else
					dem[lu] = 0
				end
				-- Diferença total
				diff = diff + math.abs(differences[lu])
			end
		end
		
		if (diff < maxdiffarea) then
			allocation_ok = true
		end
 		
		if (allocation_ok == true) then 
 			--Atualizando os status de uso de cada uma das células se a demanda foi alocada corretamente
			for k, cell in pairs (cs.cells) do			
 				--changeUse (cell, currentUse(cell, luTypes), toLU(cell.simUse, luTypes))
 				changeUse(cell, currentUse(cell, luTypes), cell.simUse)
 				cell.alloc = 0
 			end
      		print ("Demand allocated correctly in this time step:", step)
 			-- If the number of iterations is larger than or equal to the maximum number of iterations allowed
        else
        	print ("Demand not allocated correctly in this time step:", step)
        	os.exit();
        end      	
       
 	end -- end of 'execute' function
 	
	--- Handles with the parameters verification.
	-- @arg self An AllocationByOrdering component.
	-- @arg event A representation of a time instant when the simulation engine must execute.
	-- @usage self.allocation:verify(event, self)
    model.verify = function(self, event)
	end

	return model
end -- end of AllocationCluesLike

-- ____________________________________
--			AUXILIARY FUNCTIONS
--_____________________________________
--- Count the number of allocated areas.
-- @arg cs A multivalued set of Cells (Cell Space).
-- @arg cellarea A cell area.
-- @arg field The field to be checked (Columns name).
-- @arg attr The attribute to be checked.
-- @usage areaAlloc = areaAllocated(ord, cellarea, "alloc", 1)
function areaAllocated(cs, cellarea, field, attr)
	c = 0
	forEachCell(cs, function(cell)
						if (cell[field] == attr) then
							c = c + 1 	
						end
					end
				)
				
	return (c * cellarea)
end

--- Return an Index for a land use type in a set of land use types.
-- @arg lu A land use type.
-- @arg usetypes A set of land use type.
-- @usage toIndex(lu , luTypes)
function toIndex(lu, usetypes)
	local index = 0
	for i, value in  pairs (usetypes) do
	
		if (value == lu) then
			index = i
			break
		end
	end

	return index
end

--- Return a land use type in a set of land use types.
-- @arg lu A land use type.
-- @arg usetypes A set of land use type.
-- @usage toLU(cell.simUse, luTypes)
function toLU (lu, usetypes) -- @TODO FUNCIONA?????????
	for i, value in  pairs (usetypes) do	
		if (i == lu) then
			return value
		end
	end

	return index
end

--- Initialise the iteration vector for each land use type.
-- @arg lutype A set of land uses type.
-- @usage iteration = initIteration(luTypes)
function initIteration(lutypes)
	local iteration = {}	
	for k, lu in pairs (lutypes) do
		iteration[lu] = 0
	end
	
	return iteration
end

--- Handles with the change of an use for a cell area.
-- @arg cell A cell area.
-- @arg cur_use The current use.
-- @arg great_use The new use XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
-- @usage changeUse(cell, currentUse(cell, luTypes), cell.simUse)
function changeUse(cell, cur_use, great_use)
	cell[cur_use] = 0
	cell[cur_use.."_out"] = 0
	cell[great_use] = 1
	cell[great_use.."_out"] = 1

	cell[great_use.."_change"] = 0
	cell[cur_use.."_change"] = 0  --ANAP
	if (cur_use ~= great_use) then
	       cell[great_use.."_change"] = 1
	       cell[cur_use.."_change"] = -1 --ANAP
	      -- print ("change ok  ", cur_use, great_use)
	 end
end

--- Return the current use for a cell area.
-- @arg cell A cell area.
-- @arg landuses A set of land use types.
-- @usage currentUse(cell, luTypes)
function currentUse(cell, landuses)
	for i, land  in pairs (landuses) do
		if (cell[land] == 1) then
			return land
		end
	end
end
