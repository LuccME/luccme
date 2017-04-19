-- @example LuccME Continuous Model using the following components.
-- DemandPreComputedValues.
-- PotentialCSpatialLagRegression.
-- AllocationCClueLike.

import("luccme")

-- LuccME APPLICATION MODEL DEFINITION
Lab2 = LuccMEModel
{
	name = "Lab2",

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
	demand = DemandPreComputedValues
	{
		annualDemand =
		{
			-- "f", "den", "outros"
			{137878.1691, 19982.62882, 6489.202049}, 	-- 2008
			{137622.2199, 20238.57805, 6489.202049}, 	-- 2009
			{137366.2707, 20494.52729, 6489.202049}, 	-- 2010
			{137110.3214, 20750.47652, 6489.202049}, 	-- 2011
			{136824.6853, 21036.11265, 6489.202049}, 	-- 2012
			{136539.0492, 21321.74879, 6489.202049}, 	-- 2013
			{136253.4130, 21607.38493, 6489.202049}		-- 2014
		}
	},
	
	potential = PotentialCSpatialLagRegression
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
						fertilidad = 0.01701601,
						dist_riobr = -0.00000002262071,
						
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
	
	allocation = AllocationCClueLike
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
		outputTheme = "Lab2_",
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
		start = Lab2.startTime,
		action = function(event)
						Lab2:run(event)
				  end
	}
}

env_Lab2 = Environment{}
env_Lab2:add(timer)

-- ENVIROMMENT EXECUTION
if Lab2.isCoupled == false then
	tsave = databaseSave(Lab2)
	env_Lab2:add(tsave)
	env_Lab2:run(Lab2.endTime)
	saveSingleTheme (Lab2, true)
end
