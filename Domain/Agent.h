#ifndef CUSTOMER_SUPPORT_ASSISTANT_AGENT_H
#define CUSTOMER_SUPPORT_ASSISTANT_AGENT_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
#include <exception>
#include "Department.h"


////////////////////////
/// CLASS DEFINITION ///
///////////////////////
// Agent Class
class Agent {
private:
    int agentID;
    Department department;

public:
    explicit Agent(int agentID, Department department);
    [[nodiscard]] int getAgentID() const;
    [[nodiscard]] Department getDepartment() const;
    bool operator<(const Agent& other) const;
    bool operator==(const Agent& other) const;
};

// Agent Class Specialized Methods
// Hashing
namespace std {
    template <>
    struct hash<Agent> {
        std::size_t operator()(const Agent& agent) const {
            return std::hash<int>()(agent.getAgentID());
        }
    };
}

// Agent Class Exception
class AgentException: public std::exception{
private:
    std::string exceptionMessage;

public:
    explicit AgentException(std::string  message);
    [[nodiscard]] const char* what() const noexcept override;

};


// Agent Class Validator
class AgentValidator {
private:
    static void validateAgentID(int agentID);

public:
    static void checkAgent(Agent& agent);

};


#endif
