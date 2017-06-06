-- @example LuccME Discrete Model using the following components.
-- DemandPreComputedValues.
-- PotentialDNeighSimpleRule.
-- AllocationDSimpleOrdering.

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
		project = "C:\\TerraME\\bin\\packages\\luccme\\data\\test\\cs_discrete.tview",
		layer = "csrb",
		cellArea = 1,
	},

	-- Land use variables definition
	landUseTypes =
	{
		"f", "d", "outros"
	},

	landUseNoData	= "outros",

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
	
	potential = PotentialDNeighSimpleRule{},
	
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
