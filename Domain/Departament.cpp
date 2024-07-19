///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <utility>
// Project Libraries
#include "Departament.h"

////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
/// Departament Class
// Object Constructor
Departament::Departament(std::string name): departamentName{std::move( name )} {}

// Object Property Getters
std::string Departament::getName() const {
    return this->departamentName;
}

/// User Class Exception
// Object Constructor
DepartamentException::DepartamentException(std::string message): exceptionMessage(std::move(message)){}

// Object Method Overrides
const char *DepartamentException::what() const noexcept { return exceptionMessage.c_str();}

/// Departament Class Validator
// Object Methods Private
void DepartamentValidator::validateName(const std::string& departamentName) {
    // Departament Name length shall be greater or equal to 3
    if (departamentName.length() < 3) {
        throw DepartamentException("Departament Name must be at least 3 characters long");
    }
}

// Object Methods Public
void DepartamentValidator::checkDepartament(const Departament &departament) {
    validateName(departament.getName());
}