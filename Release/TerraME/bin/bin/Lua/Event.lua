-- Set type to "Event"
TeEvent.type_ = "Event"

--- An Event represents a time instant when the simulation engine must execute some computation. In order to be executed, Events must belong to a Timer. An Event is usually rescheduled to be executed again according to its period, unless its action returns false.
--- The functions available for Events can be used only along
-- the simulation, when the Event is activated and comes as a parameter of an action.
-- @param data.time A positive integer number representing the first instant of time when the Event will occur. Default is 1.
-- @param data.period A positive integer number representing the periodicity of the Event. Default is 1.
-- @param data.priority A number defining the priority of the Event over other Events. Smaller values have higher priority. Default is 0.
-- @param data.action A function from where, in general, the simulation engine services are invoked. This function has one single argument, the Event itself. If the action returns false, the Event is removed from the Timer and will not be executed again. Action can also be a TerraME object. In this case, each type has its own set of functions that will be activated by the Event.
-- See below how the objects are activated. Arrows indicate the execution order:
-- @tab action
-- Object & Function(s) activated \
-- Agent/Automaton & execute -> notify \
-- CellularSpace/Cell & synchronize -> notify \
-- function & function\
-- Society & execute -> synchronize \
-- Timer & notify \
-- Trajectory/Group & rebuild -> notify \
-- @usage event = Event {time = 1985, period = 2, priority = -1, action = function(event)
--     print(event:getTime())
-- end}
-- 
-- event2 = Event {
--     time = 2000,
--     action = my_society
-- }
function Event(data)
  if data == nil then
    data = {}
    defaultValueWarningMsg("#1", "table", "{}", 3)
  elseif type(data) ~= "table" then
    namedParametersErrorMsg("Event", 3)
  end  
    
	local cObj = TeEvent()
	if data.message ~= nil then customErrorMsg("Error: Parameter 'message' is deprecated, use 'action' instead.", 3) end

	if data.time == nil then
		data.time = 1
		defaultValueWarningMsg("time", "positive number", data.time, 3)
	elseif type(data.time) ~= "number" then
		incompatibleTypesErrorMsg("time", "positive number", type(data.time), 3)
	end

  if data.period == nil then
		data.period = 1
		defaultValueWarningMsg("period", "positive number (except zero)", data.period, 3)    
	elseif type(data.period) ~= "number" then
		incompatibleTypesErrorMsg("period", "positive number (except zero)", type(data.period), 3)
	elseif data.period <= 0 then
		incompatibleValuesErrorMsg("period","positive number (except zero)", data.period, 3)
	end

	--@RAIAN: Alterei aqui para permitir que o priority seja negativo (ticket #977)
	if data.priority == nil then
		data.priority = 0
		defaultValueWarningMsg("priority", "number", data.priority,3)
	elseif type(data.priority) ~= "number" then
		incompatibleTypesErrorMsg("priority", "number", type(data.priority), 3)
	end
	--@RAIAN: FIM

	cObj:config(data.time, data.period, data.priority)
	cObj:setReference(cObj)

	if data.action ~= nil then
		local targettype = type(data.action)
		if targettype == "function" then
			return Pair{cObj, Action{data.action}}
		elseif targettype == "Society" then
			local func = function(event)
				data.action:execute(event)
				data.action:synchronize(event:getPeriod())
			end
			return Pair{cObj, Action{func}}
		elseif targettype == "Cell" then
			local func = function(event)
				data.action:notify(event:getTime())
			end
			return Pair{cObj, Action{func}}
		elseif targettype == "CellularSpace" then
			local func = function(event)
				data.action:synchronize()
				data.action:notify(event:getTime())
			end
			return Pair{cObj, Action{func}}
		elseif targettype == "Agent" or targettype == "Automaton" then
			local func = function(event)
				data.action:execute(event)
				--data.target:synchronize() 
				--data.target:notify(event:getTime())
				--TODO PEDRO: colocar o notify aqui!!
			end
			return Pair{cObj, Action{func}}
		elseif targettype == "Group" or targettype == "Trajectory" then
			local func = function(event)
				data.action:rebuild()
			end
			return Pair{cObj, Action{func}}
		else
			incompatibleTypesErrorMsg("action","one of the types from the set [Agent, Automaton, Cell, CellularSpace, function, Group, Society, Timer, Trajectory]", type(data.action), 3)
		end
	else
		return cObj
	end
end


--- Return the current simulation time, according to the Timer it belongs.
-- @usage event:getTime()
local function getTime(self) end


--- Return the Timer that contains the Event.
-- @usage timer = event:getParent()
local function getParent(self) end

--#- Change the attributes of the Event. It will be rescheduled according to its new attributes.
-- @param time The time instant the Event will occur again (default is the current time of the Timer it will belong).
-- @param period The new periodicity of the Event (default is 1).
-- @param priority The new priority of the Event. The default priority is 0 (zero). Smaller values have higher priority.
-- @usage event:config(1)
-- event:config(1, 0.05)
-- event:config(1, 0.05, -1)
local function config(self, time, period, priority) end

--- Return the period of the Event.
-- @usage period = event:getPeriod()
local function getPeriod(self) end

--- Return the priority of the Event.
-- @usage timer = event:getPriority()
local function getPriority(self) end

--#- Change the priority of the Event. This change will take place as soon as the Event is rescheduled.
-- @param period The new periodicity of the Event (default is 1).
-- @usage event:setPriority(4)
local function setPriority(period) end

--- Notify every Observer connected to the Event.
-- @usage event:notify()
local function notify() end

--- Return "Event".
-- @usage mtype = event:getType()
local function getType() end
