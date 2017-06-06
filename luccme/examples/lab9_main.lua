-- @example LuccME Continuous Model using the following components.
-- DemandPreComputedValues.
-- PotentialCMaximumEntropyLike.
-- AllocationCClueLike.

import("luccme")

-- LuccME APPLICATION MODEL DEFINITION
Lab9 = LuccMEModel
{
	name = "Lab9",

	-- Temporal dimension definition
	startTime = 2008,
	endTime = 2014,

	-- Spatial dimension definition
	cs = CellularSpace
	{
		project = "C:\\TerraME\\bin\\packages\\luccme\\data\\test\\cs_continuous.tview",
		layer = "csAC",
		cellArea = 25,
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
			-- "f", "d", "outros"
			{137878.1691, 19982.62882, 6489.202049}, 	-- 2008
			{137622.2199, 20238.57805, 6489.202049}, 	-- 2009
			{137366.2707, 20494.52729, 6489.202049}, 	-- 2010
			{137110.3214, 20750.47652, 6489.202049}, 	-- 2011
			{136824.6853, 21036.11265, 6489.202049}, 	-- 2012
			{136539.0492, 21321.74879, 6489.202049}, 	-- 2013
			{136253.4130, 21607.38493, 6489.202049}		-- 2014
		}
	},
	
	potential = PotentialCMaximumEntropyLike
	{
		potentialData =
		{
			-- Region 1
			{
				-- f
				{
					cellUsePercentage = 75, 

					attributesPerc = 
					{
						"assentamen",
						"rodovias",
						"dist_riobr",
						"rios_todos",
						"uc_us",
						"ti",
						"ap",
						"uc_pi",
						"fertilidad"
					},

					attributesClass = 
					{
					}
				},

				-- dto
				{
					cellUsePercentage = 75, 

					attributesPerc = 
					{
						"assentamen",
						"rodovias",
						"dist_riobr",
						"rios_todos",
						"uc_us",
						"ti",
						"ap",
						"uc_pi",
						"fertilidad"
					},

					attributesClass = 
					{
					}
				},

				-- outros
				{
					cellUsePercentage = 75, 

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
	
	allocation = AllocationCClueLike
	{
		maxDifference = 2500,
		maxIteration = 1000,
		initialElasticity = 0.1,
		minElasticity = 0.001,
		maxElasticity = 1.5,
		complementarLU = "f",
		allocationData =
		{
			-- Region 1
			{
				{static = 0, minValue = 0, maxValue = 1, minChange = 0, maxChange = 1, changeLimiarValue = 1, maxChangeAboveLimiar = 0},	-- f
				{static = 0, minValue = 0, maxValue = 1, minChange = 0, maxChange = 1, changeLimiarValue = 1, maxChangeAboveLimiar = 0},	-- d
				{static = 1, minValue = 0, maxValue = 1, minChange = 0, maxChange = 1, changeLimiarValue = 1, maxChangeAboveLimiar = 0},	-- outros
			}
		}
	},

	save  =
	{
		outputTheme = "Lab9_",
		mode = "multiple",
		saveYears = {2014},
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
		start = Lab9.startTime,
		action = function(event)
						Lab9:run(event)
				  end
	}
}

env_Lab9 = Environment{}
env_Lab9:add(timer)

-- ENVIROMMENT EXECUTION
if Lab9.isCoupled == false then
	tsave = databaseSave(Lab9)
	env_Lab9:add(tsave)
	env_Lab9:run(Lab9.endTime)
	saveSingleTheme (Lab9, true)
end
