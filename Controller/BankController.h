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
// Qt Libraries
#include <QObject>
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
class BankController: public QObject {
Q_OBJECT
signals:
    void pendingDataChanged();
    void processingDataChanged();
    void completedDataChanged();
    void agentDataChanged(Agent agent);

private:

    // AI Model
    AIModel* aiModel;

    // Persistent Data
    BankRepository* repository;

    // Runtime Data
    std::vector<User> users;
    std::vector<Inquiry> inquiries;

private slots:
    void handleClassification(const std::pair<Inquiry, std::pair<UrgencyLevel, Department>>& classification);

public:

    /// Constructor
    explicit BankController(BankRepository* repository, AIModel* aiModel);

    /// Object Builder Methods
    Inquiry createInquiry(const std::string& username, const std::string& firstname, const std::string& lastname, const std::string& email, const std::string& phonenumber, const std::string& message);

    /// GET Operations
    unsigned long long getPendingSize();
    unsigned long long getProcessingSize();
    unsigned long long getProcessingByDepartmentSize(const Department &department);
    unsigned long long getProcessingByAgentSize(const Agent &agent);
    unsigned long long getCompletedSize();
    std::vector<Inquiry> getInquiries();
    std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator> getPending();
    std::pair<std::unordered_map<Department, std::unordered_multimap<Agent, Inquiry>>::const_iterator, std::unordered_map<Department, std::unordered_multimap<Agent, Inquiry>>::const_iterator> getProcessing();
    std::pair<std::unordered_multimap<Agent, Inquiry>::const_iterator, std::unordered_multimap<Agent, Inquiry>::const_iterator> getProcessingByDepartment(const Department& department);
    std::pair<std::unordered_multimap<Agent, Inquiry>::const_iterator, std::unordered_multimap<Agent, Inquiry>::const_iterator> getProcessingByAgent(const Agent& agent);
    std::pair<std::vector<Inquiry>::const_iterator, std::vector<Inquiry>::const_iterator> getCompleted();

    /// POST/PUT Operations
    // Inquiry Handlers
    void addInquiry(Inquiry& inquiry);
    void classifyInquiry(Inquiry& inquiry, UrgencyLevel urgencyLevel, Department department);
    void processInquiry(Inquiry& inquiry);
};


#endif
