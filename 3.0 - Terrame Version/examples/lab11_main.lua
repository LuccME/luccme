-- @example LuccME Discrete Model using the following components.
-- PreComputedValuesINPE.
-- NeighSimpleRule.
-- AllocationBySimpleOrdering.

import("luccme")

-- LuccME APPLICATION MODEL DEFINITION
Lab11 = LuccMEModel
{
	name = "Lab11",

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
	
	potential = NeighSimpleRule{},
	
	allocation = AllocationBySimpleOrdering
	{
		maxDifference = 106
	},

	save  =
	{
		outputTheme = "Lab11_",
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
		start = Lab11.startTime,
		action = function(event)
						Lab11:run(event)
				  end
	}
}

env_Lab11 = Environment{}
env_Lab11:add(timer)

-- ENVIROMMENT EXECUTION
if Lab11.isCoupled == false then
	tsave = databaseSave(Lab11)
	env_Lab11:add(tsave)
	env_Lab11:run(Lab11.endTime)
	saveSingleTheme (Lab11, true)
end
