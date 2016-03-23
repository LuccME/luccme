--- Simple model developed as teaching material. Not to be used in real applications. Instead of using the iterative process employed in the CLUE family, 
-- the component implements a simple ordering approach. A more elaborate ordering approch is under construction.
-- @arg component A AllocationBySimpleOrdering component.
-- @arg component.run Handles with the rules of the component execution.
-- @arg component.verify Handles with the parameters verification.
-- @usage allocation = AllocationBySimpleOrdering
--                     {	
--                          maxDifference = 0.001
--					           }   
function AllocationBySimpleOrdering(component)
	--- Handles with the rules of the component execution.
	-- @arg self A allocationClueLike component.
	-- @arg event A representation of a time instant when the simulation engine must run.
	-- @arg model AllocationBySimpleOrdering model.
	-- @usage self.allocation:run(event, model)
	component.run = function(self, event, model)
		local useLog = model.useLog
		local cs = model.cs
		local potential = model.potential		
		local cellarea = cs.cellArea
		local step = event:getTime() - model.startTime + 1	
		local start = model.startTime		
		local demand = model.demand
		local nIter = 0
		local allocation_ok = false
		local numofcells  = #cs.cells
		local luTypes = model.landUseTypes
		local dem = {}
		local differences = {}
		
		--Inicialização das demandas
		for ind, lu in  pairs (luTypes) do	
 			dem[lu] = -1
 		end
  		
		print("\nTime : ", event:getTime())
		print("Step : ", step)

		if (useLog == true) then
			print("-------------------------------------------------------------------------------")
			print("Cell Area "..cellarea)
			print("Num of cells "..numofcells)
			print("Max diff area "..self.maxDifference)

			for landuse, ivalues in pairs (luTypes) do        
				area = self:areaAllocated(cs, cellarea, luTypes[landuse], 1)
				print("Initial area for land use : "..luTypes[landuse].." -> "..area)
			end		
			print("-------------------------------------------------------------------------------")
		end
	   	
		for k, cell in pairs (cs.cells) do
			for luind, lu in  pairs (luTypes) do
				cell[lu.."_change"] = 0
				cell[lu.."_out"] = cell[lu]
			end
			cell.alloc = 0
			cell.simUse = self:currentUse(cell, luTypes)
		end

		local diff = 0
		local ord = {}

		-- Ordenação dos vetores de uso de acordo com as maiores probabilidades
		for ind, lu in  pairs (luTypes) do	
			if (lu ~= model.landUseNoData) then 
				ord = Trajectory { target = cs,
        								   select = function(cell)
														return (cell.alloc ~= 1 and cell.simUse ~= model.landUseNoData)
													end,
        								   greater = function(c, d)
														return c[lu.."_pot"] > d[lu.."_pot"]
													 end
								 }

				--Seleção de tantas células quanto forem necessárias na demanda
				local j = 1
				if (dem[lu] == -1) then
					--dem[lu] = demand:getCurrentDemand(model)
					dem[lu] = demand.currentDemand
					dem[lu] = dem[lu][ind]
				end
				local cs_size = #cs.cells
				local trj_size = #ord.cells	
				print("demand", lu, dem[lu], "trajectory size", trj_size)
		
				while (j <= dem[lu]) and (j <= (trj_size * cellarea))  do 
					-- Este atributo irá me indicar se a célula já teve seu uso alocado ou não
					ord.cells[j].alloc = 1
					ord.cells[j].simUse = lu
					j = j + 1
				end

				-- Quantidade alocada do uso neste passo de tempo
				local areaAlloc = self:areaAllocated(ord, cellarea, "alloc", 1)
				print("areaAlloc", lu, areaAlloc)
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
		
		if (diff < self.maxDifference) then
			allocation_ok = true
		end
 		
		if (allocation_ok == true) then 
 			--Atualizando os status de uso de cada uma das células se a demanda foi alocada corretamente
			for k, cell in pairs (cs.cells) do			
 				self:changeUse(cell, self:currentUse(cell, luTypes), cell.simUse)
 				cell.alloc = 0
 			end
			print("Demand allocated correctly in this time step:", step)
 			-- If the number of iterations is larger than or equal to the maximum number of iterations allowed
		else
			error("Demand not allocated correctly in this time step: "..step)
		end      	
 	end -- end of 'run' function
 	
	--- Handles with the parameters verification.
	-- @arg self An AllocationBySimpleOrdering component.
	-- @arg event A representation of a time instant when the simulation engine must run.
	-- @usage self.allocation:verify(event, self)
	component.verify = function(self, event)
		print("Verifying Allocation parameters")
		if (self.maxDifference == nil) then
		  error("maxDifference variable is missing", 2)
		end
	end

	--- Count the number of allocated areas.
	-- @arg cs A multivalued set of Cells (Cell Space).
	-- @arg cellarea A cell area.
	-- @arg field The field to be checked (Columns name).
	-- @arg attr The attribute to be checked.
	-- @usage areaAlloc = areaAllocated(ord, cellarea, "alloc", 1)
	component.areaAllocated = function(self, cs, cellarea, field, attr)
		local c = 0
		forEachCell(cs, function(cell)
						  if (cell[field] == attr) then
							c = c + 1   
						  end
						end
					)
					
		return (c * cellarea)
	end

	--- Handles with the change of an use for a cell area.
	-- @arg cell A cell area.
	-- @arg cur_use The current use.
	-- @arg higher_use The biggest cell value
	-- @usage self:changeUse(cell, currentUse(cell, luTypes), cell.simUse))
	component.changeUse = function(self, cell, cur_use, higher_use)
		cell[cur_use] = 0
		cell[cur_use.."_out"] = 0
		cell[higher_use] = 1
		cell[higher_use.."_out"] = 1
	  
		cell[higher_use.."_change"] = 0
		cell[cur_use.."_change"] = 0  
		if (cur_use ~= higher_use) then
		  cell[higher_use.."_change"] = 1
		  cell[cur_use.."_change"] = -1 
		 end
	end

	--- Return the current use for a cell area.
	-- @arg cell A cell area.
	-- @arg landuses A set of land use types.
	-- @usage self:currentUse(cell, luTypes)
	component.currentUse = function(self, cell, landuses)
		for i, land  in pairs (landuses) do
		  if (cell[land] == 1) then
			return land
		  end
		end
	end

	return component
end -- end of AllocationCluesLike
