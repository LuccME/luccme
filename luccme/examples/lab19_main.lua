-- @example LuccME Discrete Model using the following components and Dynamic Variables.
-- DemandComputeThreeDates.
-- PotentialDLogisticRegression.
-- AllocationDClueSLike.
-- Dynamic Variables update in 2009.

import("luccme")

-- LuccME APPLICATION MODEL DEFINITION
Lab19 = LuccMEModel
{
	name = "Lab19",

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
	demand = DemandComputeThreeDates
	{
		middleYearForInterpolation = 2011,
		middleLandUseTypesForInterpolation = {"f2011", "d2011", "outros"},
		finalYearForInterpolation = 2014,
		finalLandUseTypesForInterpolation = {"f2014", "d2014", "outros"},
	},
	
	potential = PotentialDLogisticRegression
	{
		potentialData =
		{
			-- Region 1
			{
				-- f
				{
					const = -1.961,
					elasticity = 0.6,

					betas =
					{
						dist_rodov = 0.00008578,
						assentamen = -0.2604,
						uc_us = 0.6064,
						fertilidad = 0.4393
					}
				},

				-- dto
				{
					const = 1.978,
					elasticity = 0.6,

					betas =
					{
						dist_rodov = -0.00008651,
						assentamen = 0.2676,
						uc_us = -0.6376,
						fertilidad = -0.4565
					}
				},

				-- outros
				{
					const = 0,
					elasticity = 1,

					betas =
					{
						
					}
				}
			}
		}
	},
	
	allocation = AllocationDClueSLike
	{
		maxIteration = 1000,
		factorIteration = 0.000001,
		maxDifference = 106,
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
		outputTheme = "Lab19_",
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
	saveSingleTheme (Lab19, true)
end
