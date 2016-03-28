globalAgentIdCounter = 0

local deadAgentMetaTable_ = {__index = function()
		customErrorMsg("Error: Trying to use a function or an attribute of a dead Agent.", 3)
	end}

Agent_ = {
	type_ = "Agent",
	--- Add a Trajectory or State to the Agent.
	-- @param object A State or Trajectory.
	-- @usage agent:add(state)
	--
	-- agent:add(trajectory)
	add = function(self, object)
		--if(type(object) == "State" or type(object) == "Trajectory") then
    -- State esta sendo tratado como userdata!!!!!!!!!!!
    if(type(object) == "userdata" or type(object) == "Trajectory") then
			self.cObj_:add(object)
		else
			incompatibleTypesErrorMsg("#1", "State or Trajectory", type(object), 3)
		end
	end,
	---Add a SocialNetwork to the Agent.
	-- @param set A SocialNetwork.
	-- @param id Name of the relation.
	-- @usage agent:addSocialNetwork(network)
	--
	-- agent:addSocialNetwork(network, "friends")
	addSocialNetwork = function(self, set, id)
		-- verificar o parametro set pode ser uma função!
		if type(set) ~= "SocialNetwork" and type(set) ~= "function" then
			incompatibleTypesErrorMsg("#1", "SocialNetwork", type(set), 3)
		end

		if id == nil then
			if type(set:getId() == "string") then
				id = set:getId()
			else
				id = "sntw1"        
			end
			defaultValueWarningMsg("#2", "string", id, 3)
		elseif type(id) ~= "string" then
			incompatibleTypesErrorMsg("#2", "string", type(id), 3)
		end
		self.socialnetworks[id] = set
	end,
	--- Check if the state machine was correctly defined, verifying
	-- whether the targets of Jump rules match the ids of the States. It is
	-- useful only when the Agent is described as a state machine.
	-- @usage agent:build()
	build = function(self)
		self.cObj_:build()
	end,
	---Kill the agent and remove it from the Society it belongs. The methods execute() and on_message() of the Agent are set to do nothing.
	-- @param remove_placements A boolean value indicating whether the 
	-- relations of the Agent should be removed. Default is true, but it 
	-- only works with simple placements, where one Agent is connected to 
	-- a single Cell in each placement. If more complex relations are used 
	-- in the model, then the modeler should set this parameter as false
	-- and remove the relations by himself/herself.
	-- @usage agent:die()
	die = function(self, remove_placements)
		if remove_placements == true and not self.parent then
			customErrorMsg("Error: Cannot remove the placements of an Agent that does not belong to a Society.", 3)
		end

		if remove_placements == nil then
			remove_placements = true
			defaultValueWarningMsg("#1", "boolean", remove_placements, 3)
		end

		-- remove all the placements
		if remove_placements and self.parent then
			forEachElement(self.parent.placements, function(placement)
        flagLeaveNil = true
				self:leave(nil, placement)
        flagLeaveNil = false
			end)
		end
		self.execute = function() customWarningMsg("Warning: Trying to execute a dead agent.", 3) end
		-- remove all the possible ways of getting delayed messages
		forEachElement(self, function(idx, _, mtype)
			if mtype == "function" and idx:sub(1, 3) == "on_" then
				self[idx] = function() customWarningMsg("Warning: Trying to send a message to a dead Agent.", 3) end
			end
		end)
		self.on_message = function() customWarningMsg("Warning: Trying to send a message to a dead Agent.", 3) end
		self.parent:remove(self)
		setmetatable(self, deadAgentMetaTable_)
	end,
	--- Put the Agent into a Cell, using their placements. If the Agent is already inside of a Cell, use Agent:move() instead.
	--The agent needs to have a placement to be able to use Agent:enter(), Agent:leave(), or Agent:move() (see Environment:createPlacement()).
	-- @param cell A Cell.
	-- @param placement A string representing the index to be used. Default is "placement".
	-- @usage agent:enter(newcell)
	-- agent:enter(newcell, "renting")
	enter = function(self, cell, placement)
		if type(cell)~="Cell" then
			incompatibleTypesErrorMsg("#1", "Cell", type(cell), 3)
		end

    	if placement == nil then
          placement = "placement"
          defaultValueWarningMsg("#2", "string", placement, 3)
		elseif type(placement) ~= "string" then
			incompatibleTypesErrorMsg("#2", "string", type(placement), 3) 
		end


		if (self[placement]) then 
			self[placement].cells[1] = cell
		end
		if (cell[placement]) then
			cell[placement]:add(self)
		end
		self.cell = cell
	end,
	--- The entry point for executing a given Agent. When the Agent is described as a state machine, execute is automatically defined by TerraME. It activates the Jump of the current State while it jumps from State to State. After that, it   executes all the Flows of the current State. Usually, this function is called within an Event, thus the time of the Event can be got directly from the Timer.
	-- When the Agent is not defined as a composition of States, the modeler should follow a signature to describe this function.
	-- @param event An Event.
	-- @usage agent:execute()
	--
	-- agent:execute(event)
	--
	-- singleFooAgent = Agent { 
  -- execute = function(self) 
  --     self.size = self.size + 1 
  --     self:walk() 
  --end}
	execute = function(self, event)
		if type(event) == "Event" then
			self.cObj_:execute(event)      
		else
			incompatibleTypesErrorMsg("#1", "Event", type(event), 3)
		end
	end,
	--- Return the Cell where the Agent is located according to its placement. It assumes that each Agent belongs to at most one Cell.
	-- @param placement  A string representing the index to be used. Default is "placement".
	-- @usage cell = agent:getCell()
	getCell = function(self, placement)
		if type(placement) ~= "string" then
			if type(placement) == "nil"  then
				placement = "placement"
				defaultValueWarningMsg("#1", "string", placement, 3)
			else
				incompatibleTypesErrorMsg("#1", "string", type(placement), 3)
			end
		end
		if type(self[placement]) ~= "Trajectory" then
			customErrorMsg("Error: Placement '".. placement.. "' should be a Trajectory, got "..type(self[placement])..".", 3)
		end
		return self[placement].cells[1]		
	end,
	--- Return the Cells pointed by the Agent according to its placement.
	-- @param placement A string representing the index to be used. Default is "placement".
	-- @usage cell = agent:getCells()[1]
	getCells = function(self, placement)
		if type(placement) ~= "string" then
			if placement == nil  then
				placement = "placement"
				defaultValueWarningMsg("#1", "string", placement, 3)
			else
				incompatibleTypesErrorMsg("#1", "string", type(placement), 3)
			end
		end

		if type(self[placement]) ~= "Trajectory" then
			customErrorMsg("Error: Placement '".. placement.. "' should be a Trajectory, got "..type(self[placement])..".", 3)
		end

		return self[placement].cells
	end,
	--- Return the unique identifier of the Agent. 
	-- @usage id = agent:getId()
	getId = function(self)
		return self.id
	end,
	--- Return the time when the machine executed the transition to the current state. 
	-- Before executing for the first time, the latency is zero. 
	-- This function is useful only when the Agent is described as a state machine.
	-- @usage latency = agent:getLatency()
	getLatency = function(self)
		return self.cObj_:getLatency()
	end,
	--- Returns a SocialNetwork of the Agent given its name.
	-- @param id Name of the relation.
	-- @usage net = agent:getSocialNetwork("friends")
	-- @see Society:createSocialNetwork
	getSocialNetwork = function(self, id)
		if id == nil then
      id = "sntw1"
			defaultValueWarningMsg("#1", "string", id, 3)
		elseif type(id) ~= "string" then
			incompatibleTypesErrorMsg("#1","string", type(id), 3)
		end

		local s = self.socialnetworks[id] 
		if s == nil then
			valueNotFoundErrorMsg("#1",id, 3)
		end
		if type(s) == "function" then
			s = s(self)
		end
		return s
	end,
	--- Returns a string with the current state name. This function is useful only when the Agent is described as a state machine.
	-- @usage name = agent:getStateName()
	getStateName = function(self)
		return self.cObj_:getControlModeName()
	end,
	--- Return the status of the Trajectories of the Agent. 
	-- This function is useful only when the Agent is described as a state machine.
	-- @see Agent:setTrajectoryStatus
	getTrajectoryStatus = function(self)
		return self.cObj_:getActionRegionStatus()
	end,
	--- A user-defined function that is used to initialize an Agent when it enters in a given Society (e.g. by calling Society:add()).
	-- @usage agent = Agent{
	--     init = function(self)
	--         self.age = math.random(1, 10) -- initial age chosen randomly
	--         self.wealth = math.random(50, 100) -- initial wealth chosen randomly
	--     end,
	--     ...
	-- }
	-- 
	-- agent:init()
	init = function(self) -- virtual function that might be implemented by the modeler
	end,
	--- Remove the Agent from a given Cell. 
	--The agent needs to have a placement to be able to use Agent:enter(), Agent:leave(), or Agent:move() (see Environment:createPlacement()).
	-- @param cell A Cell. Default is the first (or the only) Cell of the placement.
	-- @param placement A string representing the index to be used. Default is "placement".
	-- @usage agent:leave()
	--
	-- agent:leave(cell)
	--
	-- agent:leave(cell, "renting")
	leave = function(self, cell, placement)
		if type(placement) ~= "string" then
			if placement == nil then
				defaultValueWarningMsg("#2", "string", placement, 3) 
				placement = "placement"
			else
				incompatibleTypesErrorMsg("#2", "string", type(placement), 3) 
			end
		end

		if type(cell) ~= "Cell" then
			if cell == nil then
        local level = 3
        if flagLeaveNil then
          level = 6                            
        end
				cell = self[placement].cells[1]
 				defaultValueWarningMsg("#1", "Cell", "agent["..placement .."].cells[1]", level)
			else
				incompatibleTypesErrorMsg("#1", "Cell", type(cell), 3)
			end
		end

		if self[placement] == nil then
			valueNotFoundErrorMsg("#1",placement, 3)
		elseif type(self[placement]) ~= "Trajectory" then
			customErrorMsg("Error: Placement '".. placement.. "' should be a Trajectory, got "..type(self[placement])..".", 3)
		end

		self.cell = nil
		if (self[placement]) then
			self[placement].cells[1] = nil
		end

		if cell and cell[placement] then
			local ags = cell[placement].agents

			if getn(ags) == 0 then
				return true
			end

			for i = 1, #ags do
				if self.id == ags[i].id and self.parent == ags[i].parent then
					table.remove(ags, i)
					return true
				end
			end
		end
	end,
	--- Send a message to another Agent as a table. The receiver will get a message through its Agent:on_message(). Messages can arrive exactly after they are sent (synchronous) or have some delay (asynchronous). In the latter case, it is necessary to call function Society:synchronize() from the Society they belong to activate the messages.
	-- @param data.receiver The Agent that will get the message.
	-- @param data.subject A string describing the function that will be called in the receiver. Given a string x, the receiver will get the message in a function called on_x. Default is "message". The function to receive the message must be implemented by the modeler. See Agent:on_message() for more details.
	-- @param data.delay An integer indicating the number of times synchronize needs to be called before activating this message. Default is zero (no delay, no synchronization required). Whenever a delayed message is received, it comes with the element delay = true.
	-- @param data.... Other arguments are allowed to this function, as the message is a table. The receiver will get all the attributes sent plus a sender value. 
	-- @usage agent:message {
	--     receiver = agent2,
	--     delay = 2,
	--     content = "money",
	--     quantity = 20
	-- }
	message = function(self, data)
		if(type(data) ~= "table")then
			if(data == nil)then
				tableParameterErrorMsg("message", 3)
			else
	 			namedParametersErrorMsg("message", 3)
		end
		end

		data.sender = self
		if type(data.receiver) ~= "Agent" then
			incompatibleTypesErrorMsg("receiver", "Agent", type(data.receiver), 3)
		end

		if data.delay == nil then
			data.delay = 0
			defaultValueWarningMsg("delay", "positive integer number", data.delay, 3)
		elseif type(data.delay) ~= "number" then
			incompatibleTypesErrorMsg("delay", "positive integer number", type(data.delay), 3)
		elseif(data.delay < 0) then
			incompatibleValuesErrorMsg("delay", "positive integer number", data.delay, 3)
		end

		if data.delay == 0 then
			if data.subject then
				if type(data.subject) ~= "string" then
					incompatibleTypesErrorMsg("subject", "string", type(data.subject), 3)
				end
				local call = "on_"..data.subject
				if type(data.receiver[call]) ~= "function" then
					customErrorMsg("Error: Receiver (id = ".. data.receiver:getId() ..") does not implement function "..call ..".", 3)
				else
					data.receiver[call](data.receiver, data)
					return true
				end
			else
				data.receiver:on_message(data)
				return true
			end
		elseif type(self.parent) ~= "Society" then
			customErrorMsg("Error: Agent must be within a Society to send messages with delay.", 3)
		else
			table.insert(self.parent.messages, data)
			return true
		end
	end,
	--- Move the Agent to a new Cell.
	--The agent needs to have a placement to be able to use Agent:enter(), Agent:leave(), or Agent:move() (see Environment:createPlacement()).
	-- @param newcell The new Cell.
	-- @param placement A string representing the index to be used. Default is "placement".
	-- @usage agent:move(newcell)
	-- agent:move(newcell, "renting")
	move = function(self, newcell, placement)
		if type(newcell) ~= "Cell" then
			if newcell == nil then
				mandatoryArgumentErrorMsg("#1", 3)
			else
				incompatibleTypesErrorMsg("#1", "Cell", type(newcell), 3)
			end
		end

		if type(placement) ~= "string" then
			if placement == nil then
				placement = "placement"
				defaultValueWarningMsg("#2", "string", placement, 3)
			else
				incompatibleTypesErrorMsg("#2", "string", type(placement), 3) 
			end
		end

		if self[placement] == nil then
			customErrorMsg("Error: Value '".. placement .."' not found for parameter '#2'.", 3)
		elseif not self[placement].cells[1] then 
			customErrorMsg("Error: Agent is not inside of any Cell.", 3)
		end

		self:leave(self[placement].cells[1], placement)
		self:enter(newcell, placement)
		return true
	end,
	--- Notify the Observers of the Agent.
	-- @param modelTime An integer number representing the notification time.
	-- @usage agent:notify()
	notify = function (self, modelTime)
		if modelTime == nil then
			modelTime = 1
			defaultValueWarningMsg("#1", "positive number", modelTime, 3)
    elseif type(modelTime) ~= "number" then
      incompatibleTypesErrorMsg("#1", "positive number", type(modelTime), 3) 
		elseif modelTime < 0 then
			incompatibleValuesErrorMsg("#1","positive number", modelTime, 3)   
		end
		self.cObj_:notify(modelTime)
	end,
	--- Signature of a function that can be implemented by the modelers when the 
	-- Agents can receive messages from other ones. 
	-- This function receives a message as argument, with the same content of the 
	-- message sent plus the attribute sender, representing the Agent that has 
	-- sent the message. In the case of non-delayed messages, the returning value 
	-- of this function (executed by the receiver) is also returned as the result 
	-- of message (executed by the sender). Note that, although in the description
	-- below on_message has only one argument, the signature has two arguments,
	-- the first one being the agent itself. This function is usually called by
	-- TerraME, as result of calls of Agent:message() by the modeler. Other 
	-- functions on_ can be defined by the modeler, and will be called by 
	-- TerraME according to the subject of the message.
	-- @see Agent:message
	-- @see Society:synchronize
	-- @usage agent = Agent{
	--     on_message = function(self, message)
	--         self.money = self.money + message.quantity
	--         self:message{receiver = message.sender, content = "thanks"}
	--     end,
	--     --...
	--     on_thanks = function(self, message)
	--         self:message{receiver = message.sender, content = "yourewelcome"}
	--     end
	--     --...
	-- }
	-- @param message A table with the received message. It has an attribute called sender with the Agent that sent the message.
	on_message = function(self, message)
		customErrorMsg("Error: Agent "..self:getId().." does not implement 'on_message'.", 3)
	end,
	--- Execute a random walk to a neighbor Cell.
	-- @param placement A string representing the index to be used. Default is "placement".
	-- @param neighborhood A string representing the index of the Neighborhood to be used. Default is "placement".
	-- @param randomObj A Random object. Default is the internal TerraME random number generator.
	-- @usage agent:walk()
	--
	-- agent:walk("moore")
	walk = function(self, placement, neighborhood, randomObj)
		if type(placement) ~= "string" then
			if placement == nil then
				placement = "placement"
				defaultValueWarningMsg("#1", "string", placement, 3) 
			else
				incompatibleTypesErrorMsg("#1", "string", type(placement), 3) 
			end
		end

		if type(neighborhood) ~= "string" then
			if neighborhood == nil then
				neighborhood = "neigh1"
				defaultValueWarningMsg("#2", "string", neighborhood, 3) 
			else
				incompatibleTypesErrorMsg("#2", "string", type(neighborhood), 3) 
			end
		end

		if type(self[placement]) ~= "Trajectory" then
			valueNotFoundErrorMsg("#1",placement, 3)
		end

		local c1 = self:getCell(placement)
		local c2 = c1:getNeighborhood(neighborhood)
		if c2 == nil then
			valueNotFoundErrorMsg("#2",neighborhood, 3)
		end
		self:move(c2:sample(randomObj), placement)
	end,
	--- Create an Agent with the same behavior in the same Cell where the original Agent is (according to its placement). The new Agent is pushed into the same Society the original Agent belongs and placements created using the Society are instantiated with size zero if the only argument of reproduce does not contain such placements. This function returns the new Agent.
	-- @param data An optional table with attributes of the new Agent.
	-- @usage child = agent:reproduce()
	--
	-- child = agent:reproduce{age=0}
	--
	-- child = agent:reproduce{
	--     age = 0,
	--     house = agent.house:clone() -- house is a placement
	-- }
	reproduce = function(self, data)
		if self.parent == nil then
			customErrorMsg("Error: Agent should belong to a Society to be able to reproduce.", 3)
		end
		if type(data) ~= "table" then
		    if data == nil then
		        data = {}
		        defaultValueWarningMsg("#1", "table","{}", 3)
		    else
		        namedParametersErrorMsg("reproduce", 3)
	        end
		end
		ag = self.parent:add(data)

		if self.placement ~= nil then
			ag:enter(self:getCell("placement"),"placement")
		end
		return ag
	end,
	--- Returns a random Agent from a SocialNetwork of this Agent.
	-- @param id Name of the relation.
	-- @param randomObj A random object. As default, TerraME uses its
	-- internal random number generator.
	-- @usage ag_friend = agent:sample("friends")
	sample = function(self, id, randomObj)
		return self:getSocialNetwork(id):sample(randomObj)
	end,
	--- Set the unique identifier of the Agent. 
	-- @param name A string.
	-- @usage agent:setId("newid")
	setId = function(self, name)
		self.id = name
	end,
	--- Activate or not the trajectories defined for a given Agent.
	-- @param status Use or not the trajectories. As default, trajectories are turned off. If status is true, when executed, the Agent that contains States will automatically traverse all trajectories defined within it. This function is useful only when the Agent is described as a state machine.
	-- @usage agent:setTrajectoryStatus(true)
	setTrajectoryStatus = function(self, status)
		if type(status) ~= "boolean" then
			status = false
			defaultValueWarningMsg("#1", "boolean", "false", 3)
		end
		self.cObj_:setActionRegionStatus(status)
	end
}

local metaTableAgent_ = {__index = Agent_, __tostring = tostringTerraME}
--- An autonomous entity that is capable of performing actions as well as interact 
-- with other Agents and the spatial representation of the model. 
-- The Agent constructor gets a table containing the attributes and functions of the 
-- Agent.
-- It can be 
-- described as a simple table or as a hybrid state machine that has a unique 
-- internal state. When the agent has a set of states, the initial State will be the first declared State. 
-- When the agent does not have states, there is a set of signatures that can be implemented by the modeller,
-- such as Agent:init(), Agent:on_message(), and Agent:execute().
-- An Agent can belong to a Society and can have SocialNetworks.
-- @param data.id The unique identifier of the Agent. Default is a string with a numeric auto increment.
-- @param data.init A function to be executed when the Agent enters in a Society (optional, see below).
-- @param data.execute A function describing the behavior of the agent each time step it is executed (optional, see below).
-- @param data.on_message A function describing the behavior of the agent when it receives a message (optional, see below).
-- @output cells A vector of Cells necessary to use Utils:forEachCell(). This value is the same of "agent.placement.cells".
-- @output id The unique identifier of the Agent within the Society (only when the Agent was not loaded from an external source).
-- @output parent The Society it belongs.
-- @output placement A Trajectory representing the default placement of the Agent (only when the Agent belongs to an Environment, be itself directly or belonging to a Society that belongs to an Environment).
-- @output socialnetworks A set of SocialNetworks with the connections of the Agent.
-- @see Environment:createPlacement
-- @see Utils:forEachConnection
-- @usage agent = Agent {
--     id = "MyAgent",
--     State {...},
--     -- ...
--     State {...}
-- }
--
-- singleFooAgent = Agent {
--     size = 10,
--     name = "foo",
--     execute = function(self)
--         self.size = self.size + 1
--         self:walk()
--     end,
--     on_hello = function(self, m)
--         self:message {
--             receiver = m.sender,         
--             content = "hi"
--         }
--     end
-- }
function Agent(data)
	if(type(data) ~= "table")then
		if(data == nil)then
			tableParameterErrorMsg("Agent", 3)
		else
 			namedParametersErrorMsg("Agent", 3)
 		end
	end

	setmetatable(data, metaTableAgent_)

	if type(data.id) ~= "string" then
		if type(data.id) == "nil" then
			globalAgentIdCounter = globalAgentIdCounter +1	
			data.id = "ag".. globalAgentIdCounter	
			defaultValueWarningMsg("id", "string", data.id, 3)
		else
			incompatibleTypesErrorMsg("id", "string", type(data.id), 3)
		end
	end

	local cObj = TeGlobalAutomaton()
	data.cObj_ = cObj
	cObj:setReference(data)

	for i, ud in pairs(data) do
		if type(ud) == "Trajectory" then cObj:add(ud.cObj_) end
		if type(ud) == "userdata" then cObj:add(ud); end
	end

	cObj:build()
	data.socialnetworks = {}
	return data
end
