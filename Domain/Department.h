#ifndef CUSTOMER_SUPPORT_ASSISTANT_DEPARTMENT_H
#define CUSTOMER_SUPPORT_ASSISTANT_DEPARTMENT_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
#include <stdexcept>
#include <functional>


////////////////////////
/// CLASS DEFINITION ///
///////////////////////
// Department Class
enum class Department {
    Unclassified,
    CustomerService,       // Customer Service
    PersonalBanking,       // Personal Banking
    BusinessBanking,        // Business Banking
    InvestmentServices,    // Investment Services
    LoansMortgages,    // Loans and Mortgages
    RiskManagement,          // Risk Management
    ITSupport,         // IT Support
    HR,                // Human Resources
    FinanceAccounting        // Finance and Accounting
};

/////////////////////
/// CLASS METHODS ///
/////////////////////
// Converts Department enum to string
inline std::string toString(Department dept) {
    switch (dept) {
        case Department::CustomerService:
            return "Customer Service";
        case Department::PersonalBanking:
            return "Personal Banking";
        case Department::BusinessBanking:
            return "Business Banking";
        case Department::InvestmentServices:
            return "Investment Services";
        case Department::LoansMortgages:
            return "Loans and Mortgages";
        case Department::RiskManagement:
            return "Risk Management";
        case Department::ITSupport:
            return "IT Support";
        case Department::HR:
            return "Human Resources";
        case Department::FinanceAccounting:
            return "Finance and Accounting";
        default:
            return "Unknown Department";
    }
}

inline Department departmentFromString(const std::string& department) {

    // Strings Match
    if(department == "Customer Service") return Department::CustomerService;
    else if(department == "Personal Banking") return Department::PersonalBanking;
    else if(department == "Business Banking") return Department::BusinessBanking;
    else if(department == "Investment Services") return Department::InvestmentServices;
    else if(department == "Loans and Mortgages") return Department::LoansMortgages;
    else if(department == "Risk Management") return Department::RiskManagement;
    else if(department == "IT Support") return Department::ITSupport;
    else if(department == "Human Resources") return Department::HR;
    else if(department == "Finance and Accounting") return Department::FinanceAccounting;

    // Default Case
    else return Department::CustomerService;
}

#endif
