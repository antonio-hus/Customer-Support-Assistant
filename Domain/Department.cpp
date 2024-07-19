///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <utility>
// Project Libraries
#include "Department.h"


////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
/// Department Class
// Object Constructor
Department::Department(std::string name): departmentName{std::move(name)} {DepartmentValidator::checkDepartment(*this); }

// Object Attribute Getters
std::string Department::getName() const {
    return this->departmentName;
}

// Object Operator Overload
Department &Department::operator=(const Department &other) { this->departmentName = other.getName(); return *this; }
bool Department::operator<(const Department &other) const { return this->departmentName < other.getName(); }
bool Department::operator==(const Department &other) const { return this->departmentName == other.departmentName; }

/// User Class Exception
// Object Constructor
DepartmentException::DepartmentException(std::string message): exceptionMessage(std::move(message)){}

// Object Method Overrides
const char *DepartmentException::what() const noexcept { return exceptionMessage.c_str();}

/// Department Class Validator
// Object Methods Private
void DepartmentValidator::validateName(const std::string& departmentName) {
    // Department Name length shall be greater or equal to 3
    if (departmentName.length() < 3) {
        throw DepartmentException("Department Name must be at least 3 characters long");
    }
}

// Object Methods Public
void DepartmentValidator::checkDepartment(Department &department) {
    validateName(department.getName());
}