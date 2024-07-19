#ifndef CUSTOMER_SUPPORT_ASSISTANT_INQUIRYSTATUS_H
#define CUSTOMER_SUPPORT_ASSISTANT_INQUIRYSTATUS_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
#include <stdexcept>

////////////////////////
/// CLASS DEFINITION ///
///////////////////////
// InquiryStatus Class
enum class InquiryStatus {
    Pending,
    InProgress,
    Completed
};

/////////////////////
/// CLASS METHODS ///
/////////////////////
// Gets a string status of the InquiryStatus
std::string toString(InquiryStatus status) {
    switch (status) {
        case InquiryStatus::Pending:
            return "Pending";
        case InquiryStatus::InProgress:
            return "InProgress";
        case InquiryStatus::Completed:
            return "Completed";
        default:
            return "Unknown";
    }
}

#endif
