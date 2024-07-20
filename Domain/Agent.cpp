///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <utility>
// Project Libraries
#include "Agent.h"


////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
/// Agent Class
// Object Constructor
Agent::Agent(int agentID, Department department): agentID{agentID}, department{department} { AgentValidator::checkAgent(*this); }

// Object Attribute Getters
int Agent::getAgentID() const { return this->agentID; }
Department Agent::getDepartment() const { return this->department; }

// Object Operator Overload Methods
bool Agent::operator==(const Agent &other) const { return this->agentID == other.getAgentID(); }
bool Agent::operator<(const Agent &other) const { return this->agentID < other.getAgentID(); }

/// Agent Class Exception
// Object Constructor
AgentException::AgentException(std::string  message): exceptionMessage(std::move(message)){}

// Object Method Overrides
const char *AgentException::what() const noexcept { return exceptionMessage.c_str();}

/// Agent Class Validator
// Object Methods Private
void AgentValidator::validateAgentID(int agentID) {
    // AgentID length shall be non-negative
    if (agentID < 0) {
        throw AgentException("AgentID cannot be negative");
    }
}

// Object Methods Public
void AgentValidator::checkAgent(Agent &agent) {
    validateAgentID(agent.getAgentID());
}