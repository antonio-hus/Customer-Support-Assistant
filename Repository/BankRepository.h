#ifndef CUSTOMER_SUPPORT_ASSISTANT_BANKREPOSITORY_H
#define CUSTOMER_SUPPORT_ASSISTANT_BANKREPOSITORY_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
#include <vector>
#include <map>
// Project Libraries
#include "../Domain/User.h"
#include "../Domain/Department.h"
#include "../Domain/Inquiry.h"
#include "../Domain/InquiryStatus.h"
#include "../Domain/UrgencyLevel.h"
#include "../Utils/ObserverPattern.h"

////////////////////////
/// CLASS DEFINITION ///
///////////////////////
// Bank Repository - Local Storage
class BankRepository: public Subject {
protected:

    // Pending Inquiries List
    std::vector<Inquiry> pendingList;

    // Processing Inquiries List
    // MultiMap - Key, Values Pairs - Department & Processing Inquiries
    std::multimap<Department, Inquiry> processingList;

    // Completed Inquiries List
    std::vector<Inquiry> completedList;

    // Departments List
    std::vector<Department> departmentsList;

public:
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

//////////////////////////
/// DERIVED DEFINITION ///
//////////////////////////
// Bank Repository - Cloud Storage - MongoDB
class CloudBankRepository: public BankRepository {
public:

};


#endif
