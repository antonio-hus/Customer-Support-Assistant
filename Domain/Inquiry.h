#ifndef CUSTOMER_SUPPORT_ASSISTANT_INQUIRY_H
#define CUSTOMER_SUPPORT_ASSISTANT_INQUIRY_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
#include <exception>
#include <ctime>
// Project Libraries
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

    // Provided Inquiry Information
    User user;
    std::string message;

    // Determined Inquiry Information
    std::string inquiryID;
    std::tm timestamp;
    Department department;
    UrgencyLevel urgencyLevel;
    InquiryStatus inquiryStatus;

public:

    // Inquiry Constructor
    Inquiry(const User& user, const std::string& message, const std::string& inquiryID="-1",
            const Department& departament=Department("Unclassified"), UrgencyLevel urgencyLevel=UrgencyLevel::Low,
            InquiryStatus inquiryStatus=InquiryStatus::Pending, std::tm timestamp = get_current_date());

    // Inquiry Operator Overload
    bool operator==(const Inquiry& other) const;

    // Inquiry Attribute Getters
    [[nodiscard]] User getUser() const;
    [[nodiscard]] std::string getMessage() const;
    [[nodiscard]] std::string getID() const;
    [[nodiscard]] Department getDepartament() const;
    [[nodiscard]] UrgencyLevel getUrgencyLevel() const;
    [[nodiscard]] InquiryStatus getInquiryStatus() const;
    [[nodiscard]] bool canBeDeleted() const;

    // Inquiry Attribute Setters
    void setID(const std::string& inquiryID);
    void setDepartment(const Department& department);
    void setUrgencyLevel(UrgencyLevel urgencyLevel);
    void setStatus(InquiryStatus status);

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
    static void validateTimestamp(const std::string& timestamp);

public:
    static void checkInquiry(Inquiry& inquiry);

};

#endif
