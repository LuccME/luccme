-- @example LuccME Model using the following components.
-- DemandPreComputedValues.
-- PotentialDMaximumEntropyLike.
-- AllocationCClueLike.

import("luccme")

-- LuccME APPLICATION MODEL DEFINITION
Lab21 = LuccMEModel
{
	name = "Lab21",

	-- Temporal dimension definition
	startTime = 2008,
	endTime = 2014,

	-- Spatial dimension definition
	cs = CellularSpace
	{
		project = "C:\\TerraME\\bin\\packages\\luccme\\data\\cs_discrete.tview",
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
			-- "f", "d", "outros"
			{7771, 2829, 12}, 	-- 2008
			{7766, 2834, 12}, 	-- 2009
			{7762, 2838, 12}, 	-- 2010
			{7757, 2843, 12}, 	-- 2011
			{7754, 2846, 12}, 	-- 2012
			{7751, 2849, 12}, 	-- 2013
			{7748, 2852, 12}	-- 2014
		}
	},
	
	potential = PotentialDMaximumEntropyLike
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
						"dist_rodov",
						"dist_centr",
						 
					},

					attributesClass = 
					{
						"uc_us",
						"fertilidad",
						"assentamen",
						"ti",
						"d"
					}
				},

				-- d
				{
					cellUsePercentage = 100, 

					attributesPerc = 
					{
						"dist_rodov",
						"dist_centr",
						 
					},

					attributesClass = 
					{
						"uc_us",
						"fertilidad",
						"assentamen",
						"ti",
						 
					}
				},

				-- outros
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
		maxIteration = 5000,
		factorIteration = 0.000001,
		maxDifference = 2500,
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
		outputTheme = "Lab21_",
		mode = "multiple",
		saveYears = {2014},
		saveAttrs = 
		{
			"d_out",
			"d_change",
			"d_pot",
		},

	},

	isCoupled = false
}  -- END LuccME application model definition

-- ENVIROMMENT DEFINITION
timer = Timer
{
	Event
	{
		start = Lab21.startTime,
		action = function(event)
						Lab21:run(event)
				  end
	}
}

env_Lab21 = Environment{}
env_Lab21:add(timer)

-- ENVIROMMENT EXECUTION
if Lab21.isCoupled == false then
	tsave = databaseSave(Lab21)
	env_Lab21:add(tsave)
	env_Lab21:run(Lab21.endTime)
	saveSingleTheme (Lab21, true)
end
