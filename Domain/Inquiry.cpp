///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <utility>
// Project Libraries
#include "Inquiry.h"

////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
/// Inquiry Class
// Object Constructor
Inquiry::Inquiry(const User& user, const std::string& message, const std::string& inquiryID, const Department& departament,
                 UrgencyLevel urgencyLevel, InquiryStatus inquiryStatus):
user{user}, message{message}, inquiryID{inquiryID}, department{departament}, urgencyLevel{urgencyLevel}, inquiryStatus{inquiryStatus} {}

// Object Attribute Getter
User Inquiry::getUser() { return this->user; }
std::string Inquiry::getMessage() { return this->message; }
std::string Inquiry::getID() { return this->inquiryID; }
Department Inquiry::getDepartament() { return this->department; }
UrgencyLevel Inquiry::getUrgencyLevel() { return this->urgencyLevel; }
InquiryStatus Inquiry::getInquiryStatus() { return this->inquiryStatus; }

// Object Attribute Setter
void Inquiry::setID(const std::string& _inquiryID) { this->inquiryID = _inquiryID; }
void Inquiry::setDepartment(const Department& _department) { this->department = _department; }
void Inquiry::setUrgencyLevel(UrgencyLevel _urgencyLevel) { this->urgencyLevel = _urgencyLevel; }
void Inquiry::setStatus(InquiryStatus _inquiryStatus) { this->inquiryStatus = _inquiryStatus; }

/// Inquiry Class Exception
// Object Constructor
InquiryException::InquiryException(std::string message): exceptionMessage(std::move(message)){}

// Object Method Overrides
const char *InquiryException::what() const noexcept { return exceptionMessage.c_str();}

/// Inquiry Class Validator
// Object Methods Private
void InquiryValidator::validateMessage(const std::string &message) {
    // Message length shall be greater or equal to 3
    if (message.length() < 3) {
        throw InquiryException("Message must be at least 3 characters long");
    }
}

// Object Methods Public
void InquiryValidator::checkInquiry(Inquiry &inquiry) {
    validateMessage(inquiry.getMessage());
}