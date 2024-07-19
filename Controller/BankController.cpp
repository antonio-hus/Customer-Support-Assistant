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

// Object Destructor
BankController::~BankController() {

    // Deletes all runtime allocated objects
    for(auto department:this->departments) delete department;
    for(auto inquiry:this->inquiries) delete inquiry;
    for(auto user:this->users) delete user;
}

/// BankController Class - Builder Operations
User *BankController::createUser(const std::string &username) {
    auto* newUser = new User(username);
    this->users.push_back(newUser);
    return newUser;
}

Inquiry *BankController::createInquiry(const std::string &username, const std::string &message) {
    auto* newUser = new User(username);
    this->users.push_back(newUser);
    auto* newInquiry = new Inquiry(*newUser, message);
    this->inquiries.push_back(newInquiry);
    return newInquiry;
}

Department *BankController::createDepartment(const std::string& departamentName) {
    auto* newDepartment = new Department(departamentName);
    this->departments.push_back(newDepartment);
    return newDepartment;
}


/// BankController Class - GET Operations
std::vector<Inquiry *> BankController::getInquiries() { return this->inquiries; }

std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator>
BankController::getPending() { return this->repository->getPending(); }

std::pair<std::multimap<Department, Inquiry>::const_iterator, std::multimap<Department, Inquiry>::const_iterator>
BankController::getProcessing() { return this->repository->getProcessing(); }

std::pair<std::multimap<Department, Inquiry>::const_iterator, std::multimap<Department, Inquiry>::const_iterator>
BankController::getProcessingByDepartment(const Department &department) { return this->repository->getProcessingByDepartment(department); }

std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator>
BankController::getCompleted() { return this->repository->getCompleted(); }

std::pair<std::vector<Department>::const_iterator, std::vector<Department>::const_iterator>
BankController::getDepartments() { return this->repository->getDepartments(); }

/// BankController Class - POST/PUT Operations
void BankController::addInquiry(Inquiry &inquiry) { this->repository->addInquiry(inquiry); }
void BankController::classifyInquiry(Inquiry &inquiry) { this->repository->classifyInquiry(inquiry); }
void BankController::processInquiry(Inquiry &inquiry) { this->repository->processInquiry(inquiry); }
void BankController::addDepartament(const Department &department) { this->repository->addDepartament(department); }
void BankController::removeDepartament(const Department &department) { this->repository->removeDepartament(department); }