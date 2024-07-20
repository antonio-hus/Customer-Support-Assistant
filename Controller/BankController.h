#ifndef CUSTOMER_SUPPORT_ASSISTANT_BANKCONTROLLER_H
#define CUSTOMER_SUPPORT_ASSISTANT_BANKCONTROLLER_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
#include <vector>
#include <unordered_map>
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
    std::vector<User> users;
    std::vector<Inquiry> inquiries;

public:

    /// Constructor
    explicit BankController(BankRepository* repository);

    /// Object Builder Methods
    Inquiry createInquiry(const std::string& username, const std::string& firstname, const std::string& lastname, const std::string& email, const std::string& phonenumber, const std::string& message);

    /// GET Operations
    std::vector<Inquiry> getInquiries();
    std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator> getPending();
    std::pair<std::unordered_map<Department, std::unordered_multimap<Agent, Inquiry>>::const_iterator, std::unordered_map<Department, std::unordered_multimap<Agent, Inquiry>>::const_iterator> getProcessing();
    std::pair<std::unordered_multimap<Agent, Inquiry>::const_iterator, std::unordered_multimap<Agent, Inquiry>::const_iterator> getProcessingByDepartment(const Department& department);
    std::pair<std::unordered_multimap<Agent, Inquiry>::const_iterator, std::unordered_multimap<Agent, Inquiry>::const_iterator> getProcessingByAgent(const Agent& agent);
    std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator> getCompleted();

    /// POST/PUT Operations
    // Inquiry Handlers
    void addInquiry(Inquiry& inquiry);
    void classifyInquiry(Inquiry& inquiry);
    void processInquiry(Inquiry& inquiry);
};


#endif
