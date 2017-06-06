-- @example LuccME Discrete Model using the following components and Dynamic Variables.
-- DemandComputeThreeDates.
-- PotentialDSampleBased.
-- AllocationDClueSLike.
-- Dynamic Variables update in 2009.

import("luccme")

-- LuccME APPLICATION MODEL DEFINITION
Lab19 = LuccMEModel
{
	name = "Lab19",

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

	-- Dynamic variables definition
	updateYears = {2009},

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
	
	potential = PotentialDSampleBased
	{
		potentialData =
		{
			-- Region 1
			{
				-- f
				{
					cellUsePercentage = 100, 

					attributesPerc = 
					{
						"media_decl",
						"dist_area_",
						"dist_br",
						"dist_curua",
						"dist_rios_",
						"dist_estra"
					},

					attributesClass = 
					{
					}
				},

				-- d
				{
					cellUsePercentage = 100, 

					attributesPerc = 
					{
						"media_decl",
						"dist_area_",
						"dist_curua"
					},

					attributesClass = 
					{
					}
				},

				-- o
				{
					cellUsePercentage = 100, 

					attributesPerc = 
					{
					},

					attributesClass = 
					{
					}
				}
			}
		}
	},
	
	allocation = AllocationDClueSLike
	{
		maxIteration = 1000,
		factorIteration = 0.00001,
		maxDifference = 100,
		transitionMatrix =
		{
			--Region 1
			{
				{1, 1, 0},
				{1, 1, 0},
				{0, 0, 1}
			}
		}
	},

	save  =
	{
		outputTheme = "Lab19_",
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
		start = Lab19.startTime,
		action = function(event)
						Lab19:run(event)
				  end
	}
}

env_Lab19 = Environment{}
env_Lab19:add(timer)

-- ENVIROMMENT EXECUTION
if Lab19.isCoupled == false then
	tsave = databaseSave(Lab19)
	env_Lab19:add(tsave)
	env_Lab19:run(Lab19.endTime)
	saveSingleTheme(Lab19, true)
end
