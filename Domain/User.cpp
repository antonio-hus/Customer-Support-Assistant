///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <utility>
#include <algorithm>
#include <cctype>
// Project Libraries
#include "User.h"


////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
/// User Class
// Object Constructor
User::User(std::string username, std::string email, std::string phoneNumber, std::string firstName, std::string lastName):
username{std::move(username)}, firstName{std::move(firstName)}, lastName{std::move(lastName)}, email{std::move(email)}, phoneNumber{std::move(phoneNumber)} { UserValidator::checkUser(*this); }

// Object Attribute Getters
std::string User::getUsername() const { return this->username; }
std::string User::getFirstName() const { return this->firstName; }
std::string User::getLastName() const { return this->lastName; }
std::string User::getEmail() const { return this->email; }
std::string User::getPhoneNumber() const { return this->phoneNumber; }

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

void UserValidator::validateFirstName(const std::string &firstName) {
    // First Name length shall be greater or equal to 3
    if (firstName.length() < 3) {
        throw UserException("First Name must be at least 3 characters long");
    }
}

void UserValidator::validateLastName(const std::string &lastName) {
    // Last Name length shall be greater or equal to 3
    if (lastName.length() < 3) {
        throw UserException("Last Name must be at least 3 characters long");
    }
}

void UserValidator::validateEmail(const std::string &email) {

    // Finding the @ sign
    auto atPos = email.find('@');
    if (atPos == std::string::npos || atPos == 0 || atPos == email.length() - 1) {
        throw UserException("Invalid e-mail format - did you include @example ?");
    }

    // Finding the . sign
    auto dotPos = email.find('.', atPos);
    if(dotPos == std::string::npos){
        throw UserException("Invalid e-mail format - did you include .com ?");
    }
}

void UserValidator::validatePhoneNumber(const std::string &phoneNumber) {

    // Check if all characters are digits, dashes, or spaces
    for (char ch : phoneNumber) {
        if (!std::isdigit(ch) && ch != '-' && ch != ' ') {
            throw UserException("Invalid Phone Number format - Invalid Characters");
        }
    }
}

// Object Methods Public
void UserValidator::checkUser(User &user) {
    validateUsername(user.getUsername());
    validateFirstName(user.getFirstName());
    validateLastName(user.getLastName());
    validateEmail(user.getEmail());
    validatePhoneNumber(user.getPhoneNumber());
}