-- @example LuccME Model using the following components.
-- DemandComputeTwoDates.
-- PotentialDLogisticRegression.
-- AllocationDClueSNeighOrdering.

import("luccme")

-- LuccME APPLICATION MODEL DEFINITION
Lab23 = LuccMEModel
{
	name = "Lab23",

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
	demand = DemandComputeTwoDates
	{
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
					elasticity = 0,

					betas =
					{
						
					}
				}
			}
		}
	},
	
	allocation = AllocationDClueSNeighOrdering
	{
		maxIteration = 1000,
		factorIteration = 0.000001,
		maxDifference = 200,
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
		outputTheme = "Lab23_",
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
		start = Lab23.startTime,
		action = function(event)
						Lab23:run(event)
				  end
	}
}

env_Lab23 = Environment{}
env_Lab23:add(timer)

-- ENVIROMMENT EXECUTION
if Lab23.isCoupled == false then
	tsave = databaseSave(Lab23)
	env_Lab23:add(tsave)
	env_Lab23:run(Lab23.endTime)
	saveSingleTheme (Lab23, true)
end
