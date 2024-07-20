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

#endif
