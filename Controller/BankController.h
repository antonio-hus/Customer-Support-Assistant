#ifndef CUSTOMER_SUPPORT_ASSISTANT_BANKCONTROLLER_H
#define CUSTOMER_SUPPORT_ASSISTANT_BANKCONTROLLER_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
#include <vector>
#include <map>
#include <exception>
// Project Libraries
#include "../Domain/User.h"
#include "../Domain/Department.h"
#include "../Domain/Inquiry.h"
#include "../Domain/InquiryStatus.h"
#include "../Domain/UrgencyLevel.h"
#include "../Repository/BankRepository.h"


////////////////////////
/// CLASS DEFINITION ///
///////////////////////
// BankController
class BankController {
private:

    // Persistent Data
    BankRepository* repository;

    // Runtime Data
    std::vector<User*> users;
    std::vector<Department*> departments;
    std::vector<Inquiry*> inquiries;

public:

    /// Constructor
    explicit BankController(BankRepository* repository);
    ~BankController();

    /// Object Builder Methods
    User* createUser(const std::string& username);
    Inquiry* createInquiry(const std::string& username, const std::string& message);
    Department* createDepartment(const std::string& departamentName="None");

    /// GET Operations
    std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator> getPending();
    std::pair<std::multimap<Department, Inquiry>::const_iterator, std::multimap<Department, Inquiry>::const_iterator> getProcessing();
    std::pair<std::multimap<Department, Inquiry>::const_iterator, std::multimap<Department, Inquiry>::const_iterator> getProcessingByDepartment(const Department& department);
    std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator> getCompleted();
    std::pair<std::vector<Department>::const_iterator, std::vector<Department>::const_iterator> getDepartments();

    /// POST/PUT Operations
    // Inquiry Handlers
    void addInquiry(Inquiry& inquiry);
    void classifyInquiry(Inquiry& inquiry);
    void processInquiry(Inquiry& inquiry);

    // Departament Handlers
    // Adds a departament to the department list
    void addDepartament(const Department& department);
    // Removes a departament from the list and multimap
    // All inquiries are set back to pending for reclassification
    void removeDepartament(const Department& department);
};


#endif
