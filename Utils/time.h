#ifndef CUSTOMER_SUPPORT_ASSISTANT_TIME_H
#define CUSTOMER_SUPPORT_ASSISTANT_TIME_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>


/////////////////////////
/// METHOD DEFINITION ///
////////////////////////
// Get the current date
inline std::tm get_current_date() {
    // Get current time
    std::time_t now = std::time(nullptr);

    // Convert to local time
    std::tm* now_tm = std::localtime(&now);
    return *now_tm;
}

// Compute difference of the two dates
inline int difference(const std::tm& timestamp1, const std::tm& timestamp2) {
    // Convert std::tm to std::time_t
    std::time_t time1 = std::mktime(const_cast<std::tm*>(&timestamp1));
    std::time_t time2 = std::mktime(const_cast<std::tm*>(&timestamp2));

    // Calculate the difference in seconds
    double seconds = std::abs(std::difftime(time2, time1));

    // Convert seconds to days (1 day = 86400 seconds)
    int days = static_cast<int>(std::round(seconds / 86400));
    return days;
}

// Get the string format of the current date
inline std::string to_string(const std::tm& timestamp) {

    // Convert to string DD.MM.YYYY format
    std::ostringstream oss;
    oss << std::put_time(&timestamp, "%d.%m.%Y");
    return oss.str();
}

#endif
