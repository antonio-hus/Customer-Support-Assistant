#ifndef CUSTOMER_SUPPORT_ASSISTANT_BANKREPOSITORY_H
#define CUSTOMER_SUPPORT_ASSISTANT_BANKREPOSITORY_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
#include <vector>
#include <unordered_map>
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
    // Unordered Map - Key, Value Pairs - Department & Department Processing Inquiries List
    // Unordered Multimap - Key, Values Pairs - Agents & Processing Inquiries
    std::unordered_map<Department, std::unordered_multimap<Agent, Inquiry>> processingList;

    // Completed Inquiries List
    std::vector<Inquiry> completedList;

    // Departments Unordered Multimap - Key: Department, Values: Agents
    std::unordered_multimap<Department, Agent> departmentsMap;

public:

    /// Class Static Variables
    // Number of inquiry instances:
    static unsigned long long noInquiries;

    /// Class Constructor
    BankRepository(const std::unordered_map<Department, int>& departmentsMap);

    /// GET Operations
    unsigned long long getPendingSize();
    unsigned long long getProcessingSize();
    unsigned long long getProcessingByDepartmentSize(const Department &department);
    unsigned long long getProcessingByAgentSize(const Agent &agent);
    unsigned long long getCompletedSize();
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
