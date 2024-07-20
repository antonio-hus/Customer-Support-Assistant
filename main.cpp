///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <vector>
#include <unordered_map>
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
#include "Gui/ConfigurationView.h"


////////////////////
/// APP HANDLER ///
///////////////////
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Configuration View
    auto* configurationView = new ConfigurationView();
    configurationView->show();

    // Execute the application
    int result = QApplication::exec();

    // Return execution result
    return result;
}
