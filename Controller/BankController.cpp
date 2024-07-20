///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
// Project Libraries
#include "BankController.h"

////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
/// BankController Class
// Object Constructor
BankController::BankController(BankRepository *repository): repository{repository} {}

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
    this->repository->addInquiry(newInquiry);

    // Returning new Inquiry
    return newInquiry;
}


/// BankController Class - GET Operations
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

std::pair<std::unordered_multimap<Agent, Inquiry>::const_iterator, std::unordered_multimap<Agent, Inquiry>::const_iterator>
BankController::getProcessingByAgent(const Agent &agent) {
    return this->repository->getProcessingByAgent(agent);
}

std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator>
BankController::getCompleted() {
    return this->repository->getCompleted();
}

/// BankController Class - POST/PUT Operations
void BankController::addInquiry(Inquiry &inquiry) { this->repository->addInquiry(inquiry); }
void BankController::classifyInquiry(Inquiry &inquiry) { this->repository->classifyInquiry(inquiry); }
void BankController::processInquiry(Inquiry &inquiry) { this->repository->processInquiry(inquiry); }