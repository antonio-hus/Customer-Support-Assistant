///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <utility>
#include <algorithm>
// Project Libraries
#include "BankRepository.h"

////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
/// BankRepository Constructor
BankRepository::BankRepository(const std::map<Department, int>& departmentsList) {
    this->departmentsList = departmentsList;
}

/// BankRepository Class - GET Operations
int BankRepository::getPendingSize() {return this->pendingList.size(); }
int BankRepository::getProcessingSize() { return this->processingList.size(); }
int BankRepository::getProcessingByDepartmentSize(const Department &department) {
    auto range = this->processingList.equal_range(department);
    return std::distance(range.first, range.second);
}

int BankRepository::getProcessingByAgentSize(const Agent &agent) {
    auto deptRange = this->processingList.equal_range(*agent.getDepartment());
    auto agentRange = deptRange.first->second.equal_range(agent);
    return std::distance(agentRange.first, agentRange.second);
}
int BankRepository::getCompletedSize() { return this->completedList.size(); }
int BankRepository::getDepartmentsSize() { return this->departmentsList.size(); }

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
    auto deptRange = this->processingList.equal_range(*agent.getDepartment());
    auto agentRange = deptRange.first->second.equal_range(agent);
    return agentRange;
}

std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator>
BankRepository::getCompleted() {
    return { this->completedList.begin(), this->completedList.end() };
}

std::pair<std::map<Department, int>::const_iterator, std::map<Department, int>::const_iterator>
BankRepository::getDepartments() {
    return { this->departmentsList.begin(), this->departmentsList.end() };
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
    inquiry.setStatus(InquiryStatus::InProgress);

    // Set the Inquiry Urgency
    inquiry.setUrgencyLevel(UrgencyLevel::Low); // TODO: Change with AI Classification

    // Set the Department
    Department DEPARTMENT = this->departmentsList.begin()->first; // TODO: Change with AI Classification
    inquiry.setDepartment(DEPARTMENT);

    // Set the Agent
    // Assign Inquiry to Agent with the least inquiries

    // Add in the processingList to the correct department
    this->notify();
}

void BankRepository::processInquiry(Inquiry &inquiry) {

    // Remove from multimap
    auto range = this->processingList.equal_range(inquiry.getDepartament());
    auto it = std::find_if(range.first, range.second, [&inquiry](const std::pair<const Department, Inquiry>& pair) {return pair.second == inquiry; });

    // Set the Inquiry Status
    inquiry.setStatus(InquiryStatus::Completed);

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



