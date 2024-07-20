#ifndef CUSTOMER_SUPPORT_ASSISTANT_INQUIRY_H
#define CUSTOMER_SUPPORT_ASSISTANT_INQUIRY_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
#include <exception>
#include <optional>
#include <ctime>
// Project Libraries
#include "Agent.h"
#include "Department.h"
#include "User.h"
#include "InquiryStatus.h"
#include "UrgencyLevel.h"
#include "../Utils/time.h"


////////////////////////
/// CLASS DEFINITION ///
///////////////////////
// Inquiry Class
class Inquiry {
private:

    unsigned long long inquiryID;
    User user;
    std::string description;
    UrgencyLevel urgencyLevel;
    InquiryStatus status;
    Agent assignedAgent;
    Department assignedDepartment;
    std::tm timestamp;

public:

    // Constructor
    explicit Inquiry(unsigned long long id, const std::string &desc, const User &user, Agent assignedAgent=Agent(-1, Department::Unclassified));

    // Operator Overload
    bool operator==(const Inquiry& other) const;

    // Getters
    [[nodiscard]] unsigned long long getInquiryID() const;
    [[nodiscard]] std::string getDescription() const;
    [[nodiscard]] UrgencyLevel getUrgencyLevel() const;
    [[nodiscard]] InquiryStatus getStatus() const;
    [[nodiscard]] const Agent getAssignedAgent() const;
    [[nodiscard]] const Department getAssignedDepartment() const;
    [[nodiscard]] std::optional<User> getUser() const;
    [[nodiscard]] std::string getTimeStamp() const;
    [[nodiscard]] bool canBeDeleted() const;

    // Setters
    void setUrgencyLevel(UrgencyLevel urgency);
    void setStatus(InquiryStatus status);
    void assignAgent(const Agent &agent);
    void assignDepartment(Department dept);

    // Method to transition status
    void process();
    void complete();
};

// Inquiry Class Exception
class InquiryException: public std::exception{
private:
    std::string exceptionMessage;

public:
    explicit InquiryException(std::string message);
    [[nodiscard]] const char* what() const noexcept override;

};

// Inquiry Class Validator
class InquiryValidator {
private:
    static void validateMessage(const std::string& message);

public:
    static void checkInquiry(Inquiry& inquiry);

};

#endif
