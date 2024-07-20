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
Inquiry::Inquiry(int id, const std::string &desc, const User& user)
        : inquiryID(id), description(desc), urgencyLevel(UrgencyLevel::High), status(InquiryStatus::Pending), user(user), timestamp(get_current_date()) {
    // By default, urgencyLevel is high, the inquiry is unclassified and in pending status. Timestamp is today
}

// Object Operator Overload
bool Inquiry::operator==(const Inquiry& other) const { return this->inquiryID == other.getInquiryID(); }

// Object Attribute Getter
int Inquiry::getInquiryID() const { return inquiryID; }
std::string Inquiry::getDescription() const { return description; }
UrgencyLevel Inquiry::getUrgencyLevel() const { return urgencyLevel; }
InquiryStatus Inquiry::getStatus() const { return status; }
std::optional<Agent> Inquiry::getAssignedAgent() const { return assignedAgent; }
std::optional<Department> Inquiry::getAssignedDepartment() const { return assignedDepartment; }
std::optional<User> Inquiry::getUser() const { return user; }
std::string Inquiry::getTimeStamp() const { return to_string(this->timestamp); }
bool Inquiry::canBeDeleted() const {
    std::tm currentDate = get_current_date();
    std::tm inquiryDate = this->timestamp;

    // Inquiry can be deleted if it is completed and older than 7 days
    return (this->status == InquiryStatus::Completed && difference(inquiryDate, currentDate) > 7);
}

// Object Attribute Setter
void Inquiry::setUrgencyLevel(UrgencyLevel urgency) { urgencyLevel = urgency; }
void Inquiry::setStatus(InquiryStatus status) { this->status = status; }
void Inquiry::assignAgent(const Agent &agent) { assignedAgent = agent; }
void Inquiry::assignDepartment(Department dept) { assignedDepartment = dept; }

void Inquiry::process() {
    if (status == InquiryStatus::Pending) {
        status = InquiryStatus::Processing;
    } else {
        throw std::runtime_error("Inquiry cannot be processed from the current state.");
    }
}

void Inquiry::complete() {
    if (status == InquiryStatus::Processing) {
        status = InquiryStatus::Completed;
    } else {
        throw std::runtime_error("Inquiry cannot be completed from the current state.");
    }
}


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
    validateMessage(inquiry.getDescription());
}