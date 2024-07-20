///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <limits>
#include <utility>
#include <algorithm>
// Project Libraries
#include "BankRepository.h"

////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
/// BankRepository Constructor
BankRepository::BankRepository(const std::map<Department, int>& departmentsList) {

    // Iterate Bank Configuration
    auto it = departmentsList.begin();
    while(it != departmentsList.end()){

        // Get department data
        Department department = it->first;
        int agentCount = it->second;

        // Initialize Agents
        for(int i=1; i<=agentCount; ++i){
            this->departmentsMap.insert(std::make_pair(department, Agent(i, department)));
        }

        // Get the next element
        ++it;
    }
}

/// BankRepository Class - GET Operations
// Inquiry Lists Sizes
unsigned long long BankRepository::getPendingSize() {
    return this->pendingList.size();
}

unsigned long long BankRepository::getProcessingSize() {
    return this->processingList.size();
}

unsigned long long BankRepository::getProcessingByDepartmentSize(const Department &department) {
    auto range = this->processingList.equal_range(department);
    return std::distance(range.first, range.second);
}

unsigned long long BankRepository::getProcessingByAgentSize(const Agent &agent) {
    auto deptRange = this->processingList.find(agent.getDepartment());
    auto agentRange = deptRange->second.equal_range(agent);
    return std::distance(agentRange.first, agentRange.second);
}

unsigned long long BankRepository::getCompletedSize() {
    return this->completedList.size();
}

// Get Constant Iterators over the lists
std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator>
BankRepository::getPending() {
    return { this->pendingList.begin(), this->pendingList.end() };
}

std::pair<std::map<Department, std::multimap<Agent, Inquiry>>::const_iterator, std::map<Department, std::multimap<Agent, Inquiry>>::const_iterator>
BankRepository::getProcessing() {
    return { this->processingList.begin(), this->processingList.end() };
}

std::pair<std::map<Department, std::multimap<Agent, Inquiry>>::const_iterator, std::map<Department, std::multimap<Agent, Inquiry>>::const_iterator>
BankRepository::getProcessingByDepartment(const Department &department) {
    return this->processingList.equal_range(department);
}

std::pair<std::multimap<Agent, Inquiry>::const_iterator, std::multimap<Agent, Inquiry>::const_iterator>
BankRepository::getProcessingByAgent(const Agent &agent) {
    auto deptRange = this->processingList.find(agent.getDepartment());
    auto agentRange = deptRange->second.equal_range(agent);
    return agentRange;
}

std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator>
BankRepository::getCompleted() {
    return { this->completedList.begin(), this->completedList.end() };
}

/// BankRepository Class - POST/PUT Operations
// Inquiry Handlers
void BankRepository::addInquiry(Inquiry &inquiry) {
    inquiry.setStatus(InquiryStatus::Pending);
    this->pendingList.push_back(inquiry);
    this->notify();
}

void BankRepository::classifyInquiry(Inquiry &inquiry) {

    // Remove from pendingList
    this->pendingList.erase(std::find(this->pendingList.begin(), this->pendingList.end(), inquiry));

    // Set the Inquiry Status
    inquiry.process();

    // Set the Inquiry Urgency
    inquiry.setUrgencyLevel(UrgencyLevel::Low); // TODO: Change with AI Classification

    // Set the Department
    Department DEPARTMENT = this->departmentsMap.begin()->first; // TODO: Change with AI Classification
    inquiry.assignDepartment(DEPARTMENT);

    // Set the Agent
    // Assign Inquiry to Agent with the least inquiries
    auto& deptRange = this->processingList.find(DEPARTMENT)->second;
    auto agents = this->departmentsMap.equal_range(DEPARTMENT);

    unsigned long long minInquiries = std::numeric_limits<unsigned long long>::max();
    Agent minAgent = Agent(-1, Department::Unclassified);
    for(auto& it = agents.first; it != agents.second; ++it){
        unsigned long long count = deptRange.count(it->second);
        if (count < minInquiries){
            minInquiries = count;
            minAgent = it->second;
        }
    }
    inquiry.assignAgent(minAgent);
    deptRange.insert(std::make_pair(minAgent, inquiry));

    // Add in the processingList to the correct department
    this->notify();
}

void BankRepository::processInquiry(Inquiry &inquiry) {

    // Find the department in the processingList
    auto deptIt = this->processingList.find(inquiry.getAssignedDepartment());
    if (deptIt == this->processingList.end()) {
        throw std::invalid_argument("Department not found in processing list.");
    }

    auto& deptRange = deptIt->second; // This is a multimap<Agent, Inquiry>

    // Find the range of inquiries for the assigned agent
    auto agentRange = deptRange.equal_range(inquiry.getAssignedAgent());
    auto itToRemove = agentRange.first;

    // Iterate over the range to find the specific inquiry to remove
    while (itToRemove != agentRange.second) {
        if (&itToRemove->second == &inquiry) {
            // Remove the inquiry from the multimap
            deptRange.erase(itToRemove);
            break;
        }
        ++itToRemove;
    }

    // Set the Inquiry Status
    inquiry.complete();

    // Add in the completedList
    this->completedList.push_back(inquiry);
    this->notify();
}

void BankRepository::deleteOldInquiries() {
    for(auto it = this->completedList.begin(); it != this->completedList.end(); ++it){
        if(it->canBeDeleted()) {
            this->completedList.erase(it);
        }
    }
}



