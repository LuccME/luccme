import("luccme")

--------------------------------------------------------------
--             LuccME APPLICATION MODEL DEFINITION          --
--------------------------------------------------------------
Lab6 = LuccMEModel
{
	name = "Lab6",

	-----------------------------------------------------
	-- Temporal dimension definition                   --
	-----------------------------------------------------
	startTime = 2008,
	endTime = 2014,

	-----------------------------------------------------
	-- Spatial dimension definition                    --
	-----------------------------------------------------
	cs = CellularSpace
	{
		project = "C:\\TerraME\\bin\\packages\\luccme\\data\\cs_continuous.tview",
		layer = "csAC",
		cellArea = 25,
	},

	-----------------------------------------------------
	-- Dynamic variables definition                    --
	-----------------------------------------------------
	updateYears = {2009},

	-----------------------------------------------------
	-- Land use variables definition                   --
	-----------------------------------------------------
	landUseTypes =
	{
		"f", "d", "outros"
	},

	landUseNoData	= "outros",

	-----------------------------------------------------
	-- Behaviour dimension definition:                 --
	-- DEMAND, POTENTIAL AND ALLOCATION COMPONENTS     --
	-----------------------------------------------------
	demand = PreComputedValuesINPE
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
	
	allocation = AllocationClueLikeSaturation
	{
		maxDifference = 1643,
		maxIteration = 1000,
		initialElasticity = 0.1,
		minElasticity = 0.001,
		maxElasticity = 1.5,
		complementarLU = "f",
		saturationIndicator = "saturationLimiar",
		attrProtection = "uc_pi",
		allocationData =
		{
			{static = -1, minValue = 0, maxValue = 1, minChange = 0, maxChange = 1, changeLimiarValue = 1, maxChangeAboveLimiar = 0},	-- f
			{static = -1, minValue = 0, maxValue = 1, minChange = 0, maxChange = 1, changeLimiarValue = 1, maxChangeAboveLimiar = 0},	-- d
			{static = 1, minValue = 0, maxValue = 1, minChange = 0, maxChange = 1, changeLimiarValue = 1, maxChangeAboveLimiar = 0}		-- outros
		}
	},

	save  =
	{
		outputTheme = "Lab6_",
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

-----------------------------------------------------
-- ENVIROMMENT DEFINITION                          --
-----------------------------------------------------
timer = Timer
{
	Event
	{
		start = Lab6.startTime,
		action = function(event)
						Lab6:run(event)
				  end
	}
}

env_Lab6 = Environment{}
env_Lab6:add(timer)

-----------------------------------------------------
-- ENVIROMMENT EXECUTION                           --
-----------------------------------------------------
if Lab6.isCoupled == false then
	tsave = databaseSave(Lab6)
	env_Lab6:add(tsave)
	env_Lab6:run(Lab6.endTime)
	saveSingleTheme (Lab6, true)
end
