#ifndef CUSTOMER_SUPPORT_ASSISTANT_DEPARTMENT_H
#define CUSTOMER_SUPPORT_ASSISTANT_DEPARTMENT_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
#include <exception>


////////////////////////
/// CLASS DEFINITION ///
///////////////////////
// Department Class
class Department {
private:
    std::string departmentName;

public:
    explicit Department(std::string name="Unclassified");
    [[nodiscard]] std::string getName() const;
    Department& operator=(const Department& other);
    bool operator<(const Department& other) const;
    bool operator==(const Department& other) const;

};

// Department Class Exception
class DepartmentException: public std::exception{
private:
    std::string exceptionMessage;

public:
    explicit DepartmentException(std::string message);
    [[nodiscard]] const char* what() const noexcept override;

};

// Department Class Validator
class DepartmentValidator {
private:
    static void validateName(const std::string& departmentName);

public:
    static void checkDepartment(Department& department);

};

#endif
