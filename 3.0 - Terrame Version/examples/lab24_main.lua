-- @example LuccME Model using the following components.
-- PreComputedValuesINPE.
-- AttractRepulseLogisticRegression.
-- AllocationClueSLike.

import("luccme")

-- LuccME APPLICATION MODEL DEFINITION
Lab24 = LuccMEModel
{
	name = "Lab24",

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
	demand = PreComputedValuesINPE
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
	
	potential = AttractRepulseLogisticRegression
	{
		potentialData =
		{
			-- Region 1
			{
				-- f
				{
					const = -1.961,
					elasticity = 0.1,
					percNeighborsUse = 0.5,

					betas =
					{
						dist_rodov = 0.00008578,
						assentamen = -0.2604,
						uc_us = 0.6064,
						fertilidad = 0.4393
					}
				},

				-- d
				{
					const = 1.978,
					elasticity = 0.1,
					percNeighborsUse = 0.5,

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
					percNeighborsUse = 0,

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
	
	allocation = AllocationClueSLike
	{
		maxIteration = 1000,
		factorIteration = 0.0001,
		maxDifference = 6,
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
		outputTheme = "Lab24_",
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
		start = Lab24.startTime,
		action = function(event)
						Lab24:run(event)
				  end
	}
}

env_Lab24 = Environment{}
env_Lab24:add(timer)

-- ENVIROMMENT EXECUTION
if Lab24.isCoupled == false then
	tsave = databaseSave(Lab24)
	env_Lab24:add(tsave)
	env_Lab24:run(Lab24.endTime)
	saveSingleTheme (Lab24, true)
end