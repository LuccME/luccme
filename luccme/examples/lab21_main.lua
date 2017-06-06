-- @example LuccME Model using the following components.
-- DemandComputeTwoDates.
-- PotentialDLogisticRegressionNeighAttractRepulsion.
-- AllocationCClueLike.

import("luccme")

-- LuccME APPLICATION MODEL DEFINITION
Lab21 = LuccMEModel
{
	name = "Lab21",

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
	demand = DemandComputeTwoDates
	{
		finalYearForInterpolation = 2004,
		finalLandUseTypesForInterpolation = {"f04", "d04", "o"},
	},
	
	potential = PotentialDLogisticRegressionNeighAttractRepulsion
	{
		potentialData =
		{
			-- Region 1
			{
				-- f
				{
					const = -2.34187976925989,
					elasticity = 0.0,
					percNeighborsUse = 0.5,

					betas =
					{
						media_decl = -0.0272710076327129,
						dist_area_ = 4.30977432375496,
						dist_br = 3.10319957497883,
						dist_curua = 0.445414024051873,
						dist_rios_ = 47.3556329553235,
						dist_estra = 38.4966894254506
					}
				},

				-- d
				{
					const = -0.100351497277102,
					elasticity = 0.6,
					percNeighborsUse = 0.5,

					betas =
					{
						media_decl = 0.0581358851690861,
						dist_area_ = -0.974998890251365,
						dist_br = -2.51650696123426,
						dist_curua = -1.26742746441679,
						dist_rios_ = -40.3646901047482,
						dist_estra = -23.0841140199094
					}
				},

				-- o
				{
					const = 0.01,
					elasticity = 0.5,
					percNeighborsUse = 0.5,

					betas =
					{
						
					}
				}
			}
		},

		affinityMatrix = 
		{
			-- Region 1
			{
				{1, -1, 0},
				{-1, 1, 0},
				{0, 0, 0}
			}
		}
	},
	
	allocation = AllocationDClueSLike
	{
		maxIteration = 1000,
		factorIteration = 0.0001,
		maxDifference = 15,
		transitionMatrix =
		{
			--Region 1
			{
				{1, 1, 0},
				{0, 1, 0},
				{0, 0, 1}
			}
		}
	},

	save  =
	{
		outputTheme = "Lab21_",
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
