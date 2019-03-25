-- @example LuccME Discrete Model using the following components: 
-- DemandComputeThreeDates,
-- PotentialDSampleBased,
-- AllocationDClueSLike.

import("gis")

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
	file = filePath("test/cs_moju.shp", "luccme")
}

import("luccme")

-- LuccME APPLICATION MODEL DEFINITION
Lab18 = LuccMEModel
{
	name = "Lab18",

	-- Temporal dimension definition
	startTime = 1999,
	endTime = 2004,

	-- Spatial dimension definition
	cs = CellularSpace
	{
		project = proj,
		layer = l1.name,
		cellArea = 1,
	},

	-- Dynamic variables definition
	updateYears = {2009},

	-- Land use variables definition
	landUseTypes =
	{
		"f", "d", "o"
	},

	landUseNoData	= "o",

	-- Behaviour dimension definition:
	-- DEMAND, POTENTIAL AND ALLOCATION COMPONENTS
	demand = DemandPreComputedValues
	{
		annualDemand =
		{
			-- "f", "d", "o"
			{5706, 205, 3}, 	-- 1999
			{5658, 253, 3}, 	-- 2000
			{5611, 300, 3}, 	-- 2001
			{5563, 348, 3}, 	-- 2002
			{5516, 395, 3}, 	-- 2003
			{5468, 443, 3} 		-- 2004
		}
	},
	
	potential = PotentialDSampleBased
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
						"media_decl",
						"dist_area_",
						"dist_br",
						"dist_curua",
						"dist_rios_",
						"dist_estra"
					},

					attributesClass = 
					{
					}
				},

				-- d
				{
					cellUsePercentage = 100, 

					attributesPerc = 
					{
						"media_decl",
						"dist_area_",
						"dist_curua"
					},

					attributesClass = 
					{
					}
				},

				-- o
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
		maxIteration = 1000,
		factorIteration = 0.00001,
		maxDifference = 5000,
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
		outputTheme = "Lab18_",
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
		start = Lab18.startTime,
		action = function(event)
						Lab18:run(event)
				  end
	}
}

env_Lab18 = Environment{}
env_Lab18:add(timer)

-- ENVIROMMENT EXECUTION
if Lab18.isCoupled == false then
	tsave = databaseSave(Lab18)
	env_Lab18:add(tsave)
	env_Lab18:run(Lab18.endTime)
	saveSingleTheme(Lab18, true)
end

-- Creating Map for test compare
local cs2 = CellularSpace{
				file = filePath("test/Lab18_2004.shp", "luccme"),
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

projFile = filePath("test/Lab18_2004.shp", "luccme")
if(projFile:exists()) then
	projFile:delete()
end