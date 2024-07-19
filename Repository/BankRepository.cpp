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
/// BankRepository Class - GET Operations
int BankRepository::getPendingSize() {return this->pendingList.size(); }
int BankRepository::getProcessingSize() { return this->processingList.size(); }
int BankRepository::getProcessingByDepartmentSize(const Department &department) {
    auto range = this->processingList.equal_range(department);
    return std::distance(range.first, range.second);
}
int BankRepository::getCompletedSize() { return this->completedList.size(); }
int BankRepository::getDepartmentsSize() { return this->departmentsList.size(); }

std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator>
BankRepository::getPending() {
    return { this->pendingList.begin(), this->pendingList.end() };
}

std::pair<std::multimap<Department, Inquiry>::const_iterator, std::multimap<Department, Inquiry>::const_iterator>
BankRepository::getProcessing() {
    return { this->processingList.begin(), this->processingList.end() };
}

std::pair<std::multimap<Department, Inquiry>::const_iterator, std::multimap<Department, Inquiry>::const_iterator>
BankRepository::getProcessingByDepartment(const Department &department) {
    return this->processingList.equal_range(department);
}

std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator>
BankRepository::getCompleted() {
    return { this->completedList.begin(), this->completedList.end() };
}

std::pair<std::vector<Department>::const_iterator, std::vector<Department>::const_iterator> BankRepository::getDepartments() {
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
    Department DEPARTMENT = this->departmentsList[0]; // TODO: Change with AI Classification
    inquiry.setDepartment(DEPARTMENT);

    // Add in the processingList to the correct department
    this->processingList.insert(std::make_pair(DEPARTMENT, inquiry));
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

// Department Handlers
void BankRepository::addDepartament(const Department &department) {

    // Add in the Departments List
    this->departmentsList.push_back(department);
    this->notify();
}

void BankRepository::removeDepartament(const Department &department) {

    // Remove from the Departments List
    this->departmentsList.erase(std::find(this->departmentsList.begin(), this->departmentsList.end(), department));

    // Retrieve all inquiries associated with the department
    auto [begin, end] = this->processingList.equal_range(department);

    // Move all inquiries to the pending list
    for (auto it = begin; it != end; ++it) {
        it->second.setStatus(InquiryStatus::Pending);
        this->pendingList.push_back(it->second);
    }

    // Erase all inquiries from the processing list
    this->processingList.erase(begin, end);
    this->notify();
}



