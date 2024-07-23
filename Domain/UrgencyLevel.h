#ifndef CUSTOMER_SUPPORT_ASSISTANT_URGENCYLEVEL_H
#define CUSTOMER_SUPPORT_ASSISTANT_URGENCYLEVEL_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
#include <stdexcept>


////////////////////////
/// CLASS DEFINITION ///
///////////////////////
// UrgencyLevel Class
enum class UrgencyLevel {
    Low,
    Medium,
    High,
    Critical
};


/////////////////////
/// CLASS METHODS ///
/////////////////////
// Gets a string status of the UrgencyLevel
inline std::string toString(UrgencyLevel level) {
    switch (level) {
        case UrgencyLevel::Low:
            return "Low";
        case UrgencyLevel::Medium:
            return "Medium";
        case UrgencyLevel::High:
            return "High";
        case UrgencyLevel::Critical:
            return "Critical";
        default:
            return "Unknown";
    }
}

inline UrgencyLevel urgencyFromString(const std::string& level) {
    if(level == "Low") return UrgencyLevel::Low;
    else if(level == "Medium") return UrgencyLevel::Medium;
    else if(level == "High") return UrgencyLevel::High;
    else if(level == "Critical") return UrgencyLevel::Critical;
    else return UrgencyLevel::Low;
}

#endif
