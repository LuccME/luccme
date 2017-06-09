-- @example LuccME Continuous Model using the following components: 
-- DemandComputeTwoDates, 
-- PotentialCSpatialLagRegression, 
-- AllocationCClueLike.

import("terralib")

local projFile = File("t3mp.tview")
if(projFile:exists()) then
	projFile:delete()
end

proj = Project {
	file = "t3mp.tview",
	clean = true
}

l1 = Layer{
	project = proj,
	name = "layer",
	file = filePath("test/csAC.shp", "luccme")
}

import("luccme")

-- LuccME APPLICATION MODEL DEFINITION
Lab04 = LuccMEModel
{
	name = "Lab04",

	-- Temporal dimension definition 
	startTime = 2008,
	endTime = 2014,

	-- Spatial dimension definition  
	cs = CellularSpace
	{
		project = proj,
		layer = l1.name,
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
	demand = DemandComputeTwoDates
	{
		finalYearForInterpolation = 2014,
		finalLandUseTypesForInterpolation = {"f2014", "d2014", "outros"},
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
			-- Region 1
			{
				{static = -1, minValue = 0, maxValue = 1, minChange = 0, maxChange = 1, changeLimiarValue = 1, maxChangeAboveLimiar = 0},	-- f
				{static = -1, minValue = 0, maxValue = 1, minChange = 0, maxChange = 1, changeLimiarValue = 1, maxChangeAboveLimiar = 0},	-- d
				{static = 1, minValue = 0, maxValue = 1, minChange = 0, maxChange = 1, changeLimiarValue = 1, maxChangeAboveLimiar = 0},	-- outros
			}
		}
	},

	save  =
	{
		outputTheme = "Lab04_",
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
		start = Lab04.startTime,
		action = function(event)
						Lab04:run(event)
				  end
	}
}

env_Lab04 = Environment{}
env_Lab04:add(timer)

-- ENVIROMMENT EXECUTION
if Lab04.isCoupled == false then
	tsave = databaseSave(Lab04)
	env_Lab04:add(tsave)
	env_Lab04:run(Lab04.endTime)
	saveSingleTheme(Lab04, true)
end

-- Creating Map for test compare
local cs2 = CellularSpace{
				file = filePath("test/Lab04_2014.shp", "luccme"),
				zero = "top"
			}
	
mapsResult = Map{
			target = cs2,
			select = "d_out",
			slices = 10,
			min = 0,
			max = 1,
			color = "RdYlGn",
			invert = true,
		}

-- Removing generated files		
projFile = File("t3mp.tview")
if(projFile:exists()) then
	projFile:delete()
end

projFile = filePath("test/Lab04_2014.shp", "luccme")
if(projFile:exists()) then
	projFile:delete()
end
