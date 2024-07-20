#ifndef CUSTOMER_SUPPORT_ASSISTANT_AGENT_H
#define CUSTOMER_SUPPORT_ASSISTANT_AGENT_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
#include <exception>


////////////////////////
/// CLASS DEFINITION ///
///////////////////////
// Agent Class
class Agent {
private:
    int agentID;

public:
    explicit Agent(int agentID);
    [[nodiscard]] int getAgentID() const;

};


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
