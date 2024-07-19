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

public:
    explicit User(std::string  username);
    [[nodiscard]] std::string getUsername() const;

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

public:
    static void checkUser(User& user);

};


#endif
