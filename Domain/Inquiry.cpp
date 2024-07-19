////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
#include "Inquiry.h"

/// User Class Exception
// Object Constructor
InquiryException::InquiryException(std::string message): exceptionMessage(std::move(message)){}

// Object Method Overrides
const char *InquiryException::what() const noexcept { return exceptionMessage.c_str();}