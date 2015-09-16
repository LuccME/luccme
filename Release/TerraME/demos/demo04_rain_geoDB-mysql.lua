-- RAIN DRAINAGE MODELS
-- (C) 2010 INPE AND UFOP


-- DBMS Type
-- 0 : mysql
-- 1 : msaccess
print("Database type: MySQL")io.flush()
print(">> MySQL password: ")io.flush()
pwd=io.read()

-- attributes name can differ in differents DBMS's
HEIGHT= "height_"

-- model parameters
C = 2 -- rain/t
K = 0.4 -- flow coefficient
FINAL_TIME = 24

-- PART 1 - Retrieve the cell space from the database
csQ = CellularSpace{
	dbType = "mysql",
	host = "127.0.0.1",
	database = "cabeca",
	user = "root",
	password = pwd,
	theme = "cells90x90",
	autoload = true
}

csQ:createNeighborhood()
csQ:synchronize()

forEachCell(csQ, function(cell)
	cell.soilWater = 0
end)

local t = 0
for t = 1, FINAL_TIME do
	print("t: "..t)
	-- PART 2: It's raining in the high areas
	forEachCell(csQ,function(cell)
		if (cell[HEIGHT] > 200) then
			cell.soilWater = cell.past.soilWater + C
		end
	end)
	csQ:synchronize()

	-- PART 3: create a temporary variable to store the flow
	forEachCell(csQ, function(cell)
		cell.flow = 0
	end)

	-- Calculate the drainage and the flow
	forEachCell(csQ, function(cell)
		-- PART 4: calculate the drainage
		cell.soilWater = cell.past.soilWater - K*cell.past.soilWater
		-- count the lower neighbors
		--[ERROR
		countNeigh = 0
		forEachNeighbor(cell, function(cell, neigh)
			if (cell[HEIGHT] >= neigh[HEIGHT]) then 
				countNeigh = countNeigh + 1
			end
		end)
		--]ERROR: Error: neighborhood "1" not found.
		-- PART 5: calculates the flow to neighbors
		if (countNeigh > 0) then
			flow = cell.soilWater / countNeigh
			-- send the water to neighbors
			forEachNeighbor(cell, function(cell, neigh)
				if (cell ~= neigh) 	and (cell[HEIGHT] > neigh[HEIGHT]) then
					neigh.flow = neigh.flow + flow
				end
			end)
		end
	end) --forEachCell
		
	forEachCell(csQ, function(cell)
		cell.soilWater = cell.flow
	end)
		
	csQ:synchronize()
end

csQ:save(t, "water", {"soilWater"})

print("READY!")
print("Press <ENTER> to quit...")io.flush()	
io.read()
os.exit(0)
