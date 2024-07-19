///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <utility>
// Project Libraries
#include "User.h"


////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
/// User Class
// Object Constructor
User::User(std::string  username): username{std::move( username )} { UserValidator::checkUser(*this); }

// Object Attribute Getters
std::string User::getUsername() const {
    return this->username;
}

/// User Class Exception
// Object Constructor
UserException::UserException(std::string message): exceptionMessage(std::move(message)){}

// Object Method Overrides
const char *UserException::what() const noexcept { return exceptionMessage.c_str();}

/// User Class Validator
// Object Methods Private
void UserValidator::validateUsername(const std::string& username) {
    // Username length shall be greater or equal to 3
    if (username.length() < 3) {
        throw UserException("Username must be at least 3 characters long");
    }
}

// Object Methods Public
void UserValidator::checkUser(User &user) {
    validateUsername(user.getUsername());
}