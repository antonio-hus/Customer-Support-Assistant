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
#include "../Domain/Agent.h"
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
    // Map - Key , Value Pairs - Department & Department Processing Inquiries List
    // MultiMap - Key, Values Pairs - Agents & Processing Inquiries
    std::map<Department, std::multimap<Agent, Inquiry>> processingList;

    // Completed Inquiries List
    std::vector<Inquiry> completedList;

    // Departments List - with agent count
    std::map<Department, int> departmentsList;

    // Agent List
    std::vector<Agent> agentList;

public:

    /// Class Constructor
    BankRepository(const std::map<Department, int>& departmentsList);

    /// GET Operations
    int getPendingSize();
    int getProcessingSize();
    int getProcessingByDepartmentSize(const Department &department);
    int getProcessingByAgentSize(const Agent &agent);
    int getCompletedSize();
    int getDepartmentsSize();
    std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator> getPending();
    std::pair<std::map<Department, std::multimap<Agent, Inquiry>>::const_iterator, std::map<Department, std::multimap<Agent, Inquiry>>::const_iterator> getProcessing();
    std::pair<std::map<Department, std::multimap<Agent, Inquiry>>::const_iterator, std::map<Department, std::multimap<Agent, Inquiry>>::const_iterator> getProcessingByDepartment(const Department& department);
    std::pair<std::multimap<Agent, Inquiry>::const_iterator, std::multimap<Agent, Inquiry>::const_iterator> getProcessingByAgent(const Agent& agent);
    std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator> getCompleted();
    std::pair<std::map<Department, int>::const_iterator, std::map<Department, int>::const_iterator> getDepartments();

    /// POST/PUT Operations
    // Inquiry Handlers
    void addInquiry(Inquiry& inquiry);
    void classifyInquiry(Inquiry& inquiry);
    void processInquiry(Inquiry& inquiry);
    void deleteOldInquiries();

};

//////////////////////////
/// DERIVED DEFINITION ///
//////////////////////////
// Bank Repository - Cloud Storage - MongoDB
class CloudBankRepository: public BankRepository {
public:

};


#endif
