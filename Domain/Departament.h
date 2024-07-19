#ifndef CUSTOMER_SUPPORT_ASSISTANT_DEPARTAMENT_H
#define CUSTOMER_SUPPORT_ASSISTANT_DEPARTAMENT_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
#include <exception>

////////////////////////
/// CLASS DEFINITION ///
///////////////////////
// Departament Class
class Departament {
private:
    std::string departamentName;

public:
    explicit Departament(std::string  name);
    [[nodiscard]] std::string getName() const;

};

// Departament Class Exception
class DepartamentException: public std::exception{
private:
    std::string exceptionMessage;

public:
    explicit DepartamentException(std::string message);
    [[nodiscard]] const char* what() const noexcept override;

};

// Departament Class Validator
class DepartamentValidator {
private:
    static void validateName(const std::string& departamentName);

public:
    static void checkDepartament(const Departament& departament);

};

#endif
