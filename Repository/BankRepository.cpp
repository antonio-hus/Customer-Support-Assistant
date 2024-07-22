///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <limits>
#include <utility>
#include <algorithm>
// Project Libraries
#include "BankRepository.h"


////////////////////////
/// STATIC VARIABLES ///
////////////////////////
unsigned long long BankRepository::noInquiries = 0;


////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
/// BankRepository Constructor
BankRepository::BankRepository(const std::unordered_map<Department, int>& departmentsMap) {

    // Iterate Bank Configuration
    int counter = 0;
    for (const auto& [department, agentCount] : departmentsMap) {

        // Initialize Agents
        for (int i = 1; i <= agentCount; ++i) {
            counter ++;
            this->departmentsMap.emplace(department, Agent(counter, department));
        }
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

    // Get Department Range
    auto deptIt = this->processingList.find(agent.getDepartment());
    if (deptIt == this->processingList.end()) {
        return 0;
    }

    // Get Agent range
    auto agentRange = deptIt->second.equal_range(agent);
    return std::distance(agentRange.first, agentRange.second);
}

unsigned long long BankRepository::getCompletedSize() {
    return this->completedList.size();
}

// Get Constant Iterators over the lists
std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator> BankRepository::getPending() {
    return { this->pendingList.begin(), this->pendingList.end() };
}

std::pair<std::unordered_map<Department, std::unordered_multimap<Agent, Inquiry>>::const_iterator, std::unordered_map<Department, std::unordered_multimap<Agent, Inquiry>>::const_iterator> BankRepository::getProcessing() {
    return { this->processingList.begin(), this->processingList.end() };
}

std::pair<std::unordered_multimap<Agent, Inquiry>::const_iterator, std::unordered_multimap<Agent, Inquiry>::const_iterator>
BankRepository::getProcessingByDepartment(const Department& department) {

    // Get department Range
    auto deptIt = this->processingList.find(department);

    // If department exists - return department range
    auto& deptRange = deptIt->second;
    return { deptRange.begin(), deptRange.end() };
}

std::pair<std::unordered_multimap<Agent, Inquiry>::const_iterator, std::unordered_multimap<Agent, Inquiry>::const_iterator>
BankRepository::getProcessingByAgent(const Agent& agent) {

    // Get department range
    auto deptIt = this->processingList.find(agent.getDepartment());

    // If department exists - return agent range
    return deptIt->second.equal_range(agent);
}

std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator> BankRepository::getCompleted() {
    return { this->completedList.begin(), this->completedList.end() };
}

/// BankRepository Class - POST/PUT Operations
// Inquiry Handlers
void BankRepository::addInquiry(Inquiry& inquiry) {
    inquiry.setStatus(InquiryStatus::Pending);
    this->pendingList.push_back(inquiry);
    this->notify();
}

void BankRepository::classifyInquiry(Inquiry& inquiry) {

    // Remove from pendingList
    auto it = std::find(this->pendingList.begin(), this->pendingList.end(), inquiry);
    if (it != this->pendingList.end()) {
        this->pendingList.erase(it);
    }

    // Set the Inquiry Status
    inquiry.process();

    // Set the Inquiry Urgency
    inquiry.setUrgencyLevel(UrgencyLevel::Low); // TODO: Change with AI Classification

    // Set the Department
    Department DEPARTMENT = this->departmentsMap.begin()->first; // TODO: Change with AI Classification
    inquiry.assignDepartment(DEPARTMENT);

    // Set the Agent
    // Assign Inquiry to Agent with the least inquiries
    auto& deptRange = this->processingList[DEPARTMENT];
    auto agents = this->departmentsMap.equal_range(DEPARTMENT);

    unsigned long long minInquiries = std::numeric_limits<unsigned long long>::max();
    Agent minAgent = Agent(-1, Department::Unclassified);
    for (auto itr = agents.first; itr != agents.second; ++itr) {
        unsigned long long count = deptRange.count(itr->second);
        if (count < minInquiries) {
            minInquiries = count;
            minAgent = itr->second;
        }
    }
    inquiry.assignAgent(minAgent);
    deptRange.emplace(minAgent, inquiry);

    // Notify about the change
    this->notify();
}

void BankRepository::processInquiry(Inquiry &inquiry) {

    // Find the department in the processingList
    auto deptIt = this->processingList.find(inquiry.getAssignedDepartment());
    if (deptIt == this->processingList.end()) {
        throw std::invalid_argument("Department not found in processing list.");
    }
    auto& deptRange = deptIt->second;

    // Find the range of inquiries for the assigned agent
    auto agentRange = deptRange.equal_range(inquiry.getAssignedAgent());
    auto itToRemove = agentRange.first;

    // Iterate over the range to find the specific inquiry to remove
    while (itToRemove != agentRange.second) {
        if (itToRemove->second == inquiry) {

            // Remove the inquiry from the unordered_multimap
            deptRange.erase(itToRemove);
            break;
        }
        ++itToRemove;
    }

    // If the unordered_multimap is empty, remove the department
    if (deptRange.empty()) {
        this->processingList.erase(deptIt);
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



