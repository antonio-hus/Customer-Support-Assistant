///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <vector>
#include <map>
#include <string>
// Qt Libraries
#include <QApplication>
#include <QPushButton>
// Project Libraries
#include "Domain/AIModel.h"
#include "Domain/Department.h"
#include "Domain/Inquiry.h"
#include "Domain/InquiryStatus.h"
#include "Domain/UrgencyLevel.h"
#include "Domain/User.h"
#include "Repository/BankRepository.h"
#include "Controller/BankController.h"
#include "Gui/ControllerView.h"
#include "Gui/ClientView.h"
#include "Gui/DepartmentView.h"
#include "Gui/InquiriesView.h"


/////////////////////////
/// APP CONFIGURATION ///
/////////////////////////
// Bank Departments and number of Agents
std::map<std::string, int> departments = {
        {"Technical and Account Support", 1},
        {"Billing and Payment Services", 1},
        {"Loan and Investment Services", 1},
        {"Customer and Compliance Services", 1}
};


////////////////////
/// APP HANDLER ///
///////////////////
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Starting Up the Bank Services - Repository & Controller
    BankRepository* repository = new BankRepository();
    BankController controller = BankController(repository);

    // Starting Up Views
    // Client Controller View
    auto* controllerView =  new ControllerView(&controller);
    controllerView->show();

    // Department Views
    // Keeping track of allocated views
    std::vector<DepartmentView*> departmentViews;
    // Looping over all departments
    for (const auto& pair : departments) {

        // Opening as many agents as specified in config
        for (int i = 1; i <= pair.second; ++i) {
            auto* departmentView = new DepartmentView(&controller, pair.first + " - agent " + std::to_string(i));
            departmentViews.push_back(departmentView);
            departmentView->show();
        }
    }

    // Execute the application
    int result = QApplication::exec();

    // Clean up & close Bank Services
    delete controllerView;
    for (auto* view : departmentViews) {
        delete view;
    }
    delete repository;

    // Return execution result
    return result;
}
