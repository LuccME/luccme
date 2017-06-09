-- @example LuccME Discrete Model using the following components: 
-- DemandPreComputedValues, 
-- PotentialDInverseDistanceRule, 
-- AllocationDSimpleOrdering.

import("terralib")

local projFile = File("t3mp.tview")
if(projFile:exists()) then
	projFile:delete()
end

proj = Project {
	file = "t3mp.tview",
	clean = true
}

l1 = Layer{
	project = proj,
	name = "layer",
	file = filePath("test/cs_moju.shp", "luccme")
}

import("luccme")

-- LuccME APPLICATION MODEL DEFINITION
Lab11 = LuccMEModel
{
	name = "Lab11",

	-- Temporal dimension definition
	startTime = 1999,
	endTime = 2004,

	-- Spatial dimension definition
	cs = CellularSpace
	{
		project = proj,
		layer = l1.name,
		cellArea = 1,
	},

	-- Land use variables definition
	landUseTypes =
	{
		"f", "d", "o"
	},

	landUseNoData	= "o",

	-- Behaviour dimension definition:
	-- DEMAND, POTENTIAL AND ALLOCATION COMPONENTS
	demand = DemandPreComputedValues
	{
		annualDemand =
		{
			-- "f", "d", "o"
			{5706, 205, 3}, 	-- 1999
			{5658, 253, 3}, 	-- 2000
			{5611, 300, 3}, 	-- 2001
			{5563, 348, 3}, 	-- 2002
			{5516, 395, 3}, 	-- 2003
			{5468, 443, 3} 		-- 2004
		}
	},
	
	potential = PotentialDInverseDistanceRule
	{
		potentialData =
		{
			-- Region 1
			{
				-- f
				{
					const = 0.01,

					betas =
					{
						dist_estra = -0.3,
						dist_br = -0.3
					}
				},

				-- d
				{
					const = 0.01,

					betas =
					{
						dist_estra = 0.3,
						dist_br = 0.3
					}
				},

				-- o
				{
					const = 0.01,

					betas =
					{
						
					}
				}
			}
		}
	},
	
	allocation = AllocationDSimpleOrdering
	{
		maxDifference = 106
	},

	save  =
	{
		outputTheme = "Lab11_",
		mode = "multiple",
		saveYears = {2004},
		saveAttrs = 
		{
			"d_out",
		},
	},

	isCoupled = false
}  -- END LuccME application model definition

-- ENVIROMMENT DEFINITION
timer = Timer
{
	Event
	{
		start = Lab11.startTime,
		action = function(event)
						Lab11:run(event)
				  end
	}
}

env_Lab11 = Environment{}
env_Lab11:add(timer)

-- ENVIROMMENT EXECUTION
if Lab11.isCoupled == false then
	tsave = databaseSave(Lab11)
	env_Lab11:add(tsave)
	env_Lab11:run(Lab11.endTime)
	saveSingleTheme(Lab11, true)
end

-- Creating Map for test compare
local cs2 = CellularSpace{
				file = filePath("test/Lab11_2004.shp", "luccme"),
				zero = "top"
			}
	
mapsResult = Map{
			target = cs2,
			select = "d_out",
			slices = 10,
			min = 0,
			max = 1,
			color = "RdYlGn",
			invert = true,
		}

-- Removing generated files		
projFile = File("t3mp.tview")
if(projFile:exists()) then
	projFile:delete()
end

projFile = filePath("test/Lab11_2004.shp", "luccme")
if(projFile:exists()) then
	projFile:delete()
end
