-- @example LuccME Discrete Model using the following components.
-- DemandPreComputedValues.
-- PotentialDNeighInverseDistanceRule.
-- AllocationDSimpleOrdering.

import("luccme")

-- LuccME APPLICATION MODEL DEFINITION
Lab13 = LuccMEModel
{
	name = "Lab13",

	-- Temporal dimension definition
	startTime = 1999,
	endTime = 2004,

	-- Spatial dimension definition
	cs = CellularSpace
	{
		project = "C:\\TerraME\\bin\\packages\\luccme\\data\\test\\cs_discrete.tview",
		layer = "layer",
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
	
	potential = PotentialDNeighInverseDistanceRule
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
		outputTheme = "Lab13_",
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
		start = Lab13.startTime,
		action = function(event)
						Lab13:run(event)
				  end
	}
}

env_Lab13 = Environment{}
env_Lab13:add(timer)

-- ENVIROMMENT EXECUTION
if Lab13.isCoupled == false then
	tsave = databaseSave(Lab13)
	env_Lab13:add(tsave)
	env_Lab13:run(Lab13.endTime)
	saveSingleTheme (Lab13, true)
end
