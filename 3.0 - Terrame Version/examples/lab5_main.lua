-- @example LuccME Continuous Model using the following components.
-- ComputeInputThreeDateMaps.
-- SpatialLagRegression.
-- AllocationClueLike.

import("luccme")

-- LuccME APPLICATION MODEL DEFINITION
Lab5 = LuccMEModel
{
	name = "Lab5",

	-- Temporal dimension definition
	startTime = 2008,
	endTime = 2014,

	-- Spatial dimension definition
	cs = CellularSpace
	{
		project = "C:\\TerraME\\bin\\packages\\luccme\\data\\cs_continuous.tview",
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
	demand = ComputeInputThreeDateMaps
	{
		middleYearForInterpolation = 2011,
		middleLandUseTypesForInterpolation = {"f2011", "d2011", "outros"},
		finalYearForInterpolation = 2014,
		finalLandUseTypesForInterpolation = {"f2014", "d2014", "outros"},
	},
	
	potential = SpatialLagRegression
	{
		potentialData =
		{
			-- Region 1
			{
				-- f
				{
					isLog = false,
					const = 0.05266679,
					minReg = 0,
					maxReg = 1,
					ro = 0.9124615,

					betas =
					{
						uc_us = 0.03789872,
						uc_pi = 0.04141921,
						ti = 0.04455667
					}
				},

				-- d
				{
					isLog = false,
					const = 0.01431553,
					minReg = 0,
					maxReg = 1,
					ro = 0.9019253,

					betas =
					{
						assentamen = 0.0443537,
						uc_us = -0.01454847,
						dist_riobr = -0.00000002262071,
						fertilidad = 0.01701601
					}
				},

				-- outros
				{
					isLog = false,
					const = 0,
					minReg = 0,
					maxReg = 1,
					ro = 0,

					betas =
					{
						
					}
				}
			}
		}
	},
	
	allocation = AllocationClueLike
	{
		maxDifference = 1643,
		maxIteration = 1000,
		initialElasticity = 0.1,
		minElasticity = 0.001,
		maxElasticity = 1.5,
		complementarLU = "f",
		allocationData =
		{
			{static = -1, minValue = 0, maxValue = 1, minChange = 0, maxChange = 1, changeLimiarValue = 1, maxChangeAboveLimiar = 0},	-- f
			{static = -1, minValue = 0, maxValue = 1, minChange = 0, maxChange = 1, changeLimiarValue = 1, maxChangeAboveLimiar = 0},	-- d
			{static = 1, minValue = 0, maxValue = 1, minChange = 0, maxChange = 1, changeLimiarValue = 1, maxChangeAboveLimiar = 0},	-- outros
		}
	},

	save  =
	{
		outputTheme = "Lab5_",
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
		start = Lab5.startTime,
		action = function(event)
						Lab5:run(event)
				  end
	}
}

env_Lab5 = Environment{}
env_Lab5:add(timer)

-- ENVIROMMENT EXECUTION
if Lab5.isCoupled == false then
	tsave = databaseSave(Lab5)
	env_Lab5:add(tsave)
	env_Lab5:run(Lab5.endTime)
	saveSingleTheme (Lab5, true)
end