-- RAIN AND WATER DRAINAGE MODEL
-- (C) 2010 INPE AND UFOP

print(">> Database type: MySQL")io.flush()
print(">> MySQL password: ")io.flush()
pwd=io.read()

-- attributes name can differ in differents DBMS's
HEIGHT= "height_"

-- model parameters
C = 200 -- a single shot rain 
MINIMUM_HEIGHT_TO_RAIN = 255
K = 0.04 -- absorbing coefficient
FINAL_TIME = 30

soilWaterLeg = Legend{
	-- Attribute: soilWater
	type = "number",
	grouping = "equalsteps",
	slices = 40,
	precision = 1,
	stdDeviation = "none",
	maximum = 300,
	minimum = 0, 
	colorBar = {
		{ 
			color = "white",
			value = 0
		},
		{
			color = "blue",
			value = 1
		}
	}
}

heightLeg = Legend{
	-- Attribute: soilWater
	type = "number",
	grouping = "equalsteps",
	slices = 40,
	precision = 1,
	stdDeviation = "none",
	maximum = 255,
	minimum = 0,
	colorBar = {
		{
			color = "black", 
			value = 0
		},
		{
			color = "white",
			value = 255
		}
	}
}

cs = nil

cs = CellularSpace{
	dbType = "mysql",
	host = "127.0.0.1",
	database = "cabeca",
	user = "root",
	password = pwd,
	theme = "cells90x90"
}

cs:load();

-- Create a Observer Map
obs = Observer{
	subject = cs,
	type = "map",
	attributes={HEIGHT, "soilWater"},
	legends= { heightLeg, soilWaterLeg}
}

function isNeighbor(cell1, cell2)
	return cell1 ~= cell2 and cell1[HEIGHT] >= cell2[HEIGHT]
end

cs:createNeighborhood{strategy = "3x3", filter = isNeighbor}

-------------------------------------------------------------------------------
rain = function(cs)
	forEachCell(cs, function(cell)
		if(cell[ HEIGHT ] >= MINIMUM_HEIGHT_TO_RAIN) then
			cell.soilWater = cell.soilWater + C
		end
	end)
end

absorb = function(cell)
	cell.soilWater = cell.soilWater - K*cell.soilWater
end

superficial_flow = function(cell)
	countNeigh = #cell:getNeighborhood()
	if(countNeigh > 0 ) then
		local qflow = cell.past.soilWater/countNeigh

		total = 0
		forEachNeighbor(cell, function(cell, neigh)
			neigh.soilWater = neigh.soilWater + qflow
			total = total + qflow
		end)

		if total ~= cell.past.soilWater then
			local rn = cell:getNeighborhood():sample()
			rn.soilWater = rn.soilWater + cell.past.soilWater - total
		end

	else
		cell.soilWater = cell.soilWater + cell.past.soilWater
	end
end

totalWater = function(cs)
	total = 0
	forEachCell(cs, function(cell)
		total = total + cell.soilWater
	end)
	return total
end

t = Timer{
	Event{ priority = 0, action = function(event)
		rain(cs)
		return false
	end},
	Event{ priority = 2, action = function(event)
		forEachCell(cs, absorb)
		cs:synchronize()
		forEachCell(cs, function(cell) cell.soilWater = 0 end)
		forEachCell(cs, superficial_flow)
	end},
	Event{ priority = 1, period = 1, action = function(event)
		print(event:getTime())
		cs:notify()
	end}
}

print("Simulating until step ".. FINAL_TIME .. "...") 
t:execute(FINAL_TIME)
print("READY!")
io.flush()
os.exit(1)