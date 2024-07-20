#ifndef CUSTOMER_SUPPORT_ASSISTANT_USER_H
#define CUSTOMER_SUPPORT_ASSISTANT_USER_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
#include <exception>


////////////////////////
/// CLASS DEFINITION ///
///////////////////////
// User Class
class User {
private:
    std::string username;
    std::string email;
    std::string phoneNumber;
    std::string firstName, lastName;

public:
    explicit User(std::string username, std::string email, std::string phoneNumber, std::string firstName, std::string lastName);
    [[nodiscard]] std::string getUsername() const;
    [[nodiscard]] std::string getFirstName() const;
    [[nodiscard]] std::string getLastName() const;
    [[nodiscard]] std::string getEmail() const;
    [[nodiscard]] std::string getPhoneNumber() const;

};


// User Class Exception
class UserException: public std::exception{
private:
    std::string exceptionMessage;

public:
    explicit UserException(std::string message);
    [[nodiscard]] const char* what() const noexcept override;

};


// User Class Validator
class UserValidator {
private:
    static void validateUsername(const std::string& username);
    static void validateFirstName(const std::string& firstName);
    static void validateLastName(const std::string& lastName);
    static void validateEmail(const std::string& email);
    static void validatePhoneNumber(const std::string& phoneNumber);

public:
    static void checkUser(User& user);

};


#endif
