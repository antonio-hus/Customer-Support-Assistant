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

    int inquiryID;
    User user;
    std::string description;
    UrgencyLevel urgencyLevel;
    InquiryStatus status;
    std::optional<Agent> assignedAgent;
    std::optional<Department> assignedDepartment;
    std::tm timestamp;

public:

    // Constructor
    explicit Inquiry(int id, const std::string &desc, const User& user);

    // Operator Overload
    bool operator==(const Inquiry& other) const;

    // Getters
    [[nodiscard]] int getInquiryID() const;
    [[nodiscard]] std::string getDescription() const;
    [[nodiscard]] UrgencyLevel getUrgencyLevel() const;
    [[nodiscard]] InquiryStatus getStatus() const;
    [[nodiscard]] std::optional<Agent> getAssignedAgent() const;
    [[nodiscard]] std::optional<Department> getAssignedDepartment() const;
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
