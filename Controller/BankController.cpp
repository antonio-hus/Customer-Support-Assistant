///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
#include <iterator>
#include <algorithm>
// Project Libraries
#include "BankController.h"

////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
/// BankController Class
// Object Constructor
BankController::BankController(BankRepository *repository, AIModel* aiModel): repository{repository}, aiModel{aiModel} {

    // Connecting Signals & Slots
    connect(this->aiModel, &AIModel::isClassified, this, &BankController::handleClassification);
}

/// BankController Class - Signals & Slots
// Slots
void BankController::handleClassification(const std::pair<Inquiry, std::pair<UrgencyLevel, Department>>& classification) {
    Inquiry inquiry = classification.first;
    UrgencyLevel level = classification.second.first;
    Department department = classification.second.second;
    this->classifyInquiry(inquiry, level, department);
}

/// BankController Class - Builder Operations
Inquiry BankController::createInquiry(const std::string &username, const std::string &firstname, const std::string &lastname,
                              const std::string &email, const std::string &phonenumber, const std::string &message) {

    // Creating User
    auto newUser = User(username, email, phonenumber, firstname, lastname);
    this->users.push_back(newUser);

    // Creating new ID
    unsigned long long newID = BankRepository::noInquiries;
    BankRepository::noInquiries ++;

    // Creating and storing new Inquiry
    auto newInquiry = Inquiry(newID, message, newUser, Agent(0, Department::BusinessBanking));
    this->addInquiry(newInquiry);

    // Returning new Inquiry
    return newInquiry;
}


/// BankController Class - GET Operations
unsigned long long BankController::getPendingSize() { return this->repository->getPendingSize(); }
unsigned long long BankController::getProcessingSize() { return this->repository->getProcessingSize(); }
unsigned long long BankController::getProcessingByDepartmentSize(const Department &department) { return this->repository->getProcessingByDepartmentSize(department); }
unsigned long long BankController::getProcessingByAgentSize(const Agent &agent) { return this->repository->getProcessingByAgentSize(agent); }
unsigned long long BankController::getCompletedSize() { return this->repository->getCompletedSize(); }

std::vector<Inquiry> BankController::getInquiries() { return this->inquiries; }

std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator>
BankController::getPending() {
    return this->repository->getPending();
}

std::pair<std::unordered_map<Department, std::unordered_multimap<Agent, Inquiry>>::const_iterator, std::unordered_map<Department, std::unordered_multimap<Agent, Inquiry>>::const_iterator>
BankController::getProcessing() {
    return this->repository->getProcessing();
}

std::pair<std::unordered_multimap<Agent, Inquiry>::const_iterator, std::unordered_multimap<Agent, Inquiry>::const_iterator>
BankController::getProcessingByDepartment(const Department &department) {
    return this->repository->getProcessingByDepartment(department);
}

std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator>
BankController::getProcessingByAgent(const Agent &agent) {
    // Get the range of inquiries for the agent
    auto range = this->repository->getProcessingByAgent(agent);

    // Create a vector to store the Inquiry objects
    std::vector<Inquiry> agentInquiries;

    // Transform the range of pairs into a vector of Inquiries
    std::transform(range.first, range.second, std::back_inserter(agentInquiries),
                   [](const std::pair<const Agent, Inquiry>& pair) {
                       return pair.second;
                   });

    // Sort the inquiries by urgency level
    std::sort(agentInquiries.begin(), agentInquiries.end(), [](const Inquiry& a, const Inquiry& b) {
        return a.getUrgencyLevel() < b.getUrgencyLevel();
    });

    return {agentInquiries.begin(), agentInquiries.end()};
}

std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator>
BankController::getCompleted() {
    return this->repository->getCompleted();
}

/// BankController Class - POST/PUT Operations
void BankController::addInquiry(Inquiry &inquiry) {
    this->repository->addInquiry(inquiry);
    emit this->pendingDataChanged();

    // Send inquiry to be classified
    this->aiModel->sendRequest(inquiry);
}

void BankController::classifyInquiry(Inquiry &inquiry, UrgencyLevel urgencyLevel, Department department) {
    this->repository->classifyInquiry(inquiry, urgencyLevel, department);
    emit this->pendingDataChanged();
    emit this->processingDataChanged();
    emit this->agentDataChanged(inquiry.getAssignedAgent());
}

void BankController::processInquiry(Inquiry &inquiry) {
    this->repository->processInquiry(inquiry);
    emit this->processingDataChanged();
    emit this->completedDataChanged();
    emit this->agentDataChanged(inquiry.getAssignedAgent());
}