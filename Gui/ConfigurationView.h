#ifndef CUSTOMER_SUPPORT_ASSISTANT_CONFIGURATIONVIEW_H
#define CUSTOMER_SUPPORT_ASSISTANT_CONFIGURATIONVIEW_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <unordered_map>
#include <vector>
// Qt Libraries
#include <QMessageBox>
#include <QWidget>
// Project Libraries
#include "../Domain/Department.h"
#include "../Repository/BankRepository.h"
#include "../Controller/BankController.h"
#include "ControllerView.h"
#include "DepartmentView.h"
#include "ClientView.h"


////////////////////////////
/// NAMESPACE DEFINITION ///
////////////////////////////
QT_BEGIN_NAMESPACE
namespace Ui { class ConfigurationView; }
QT_END_NAMESPACE


////////////////////////
/// CLASS DEFINITION ///
////////////////////////
class ConfigurationView : public QWidget {
Q_OBJECT
private:
    BankRepository* repository;
    BankController* controller;
    std::vector<QWidget*> allocatedViews;
    Ui::ConfigurationView *ui;

public:
    explicit ConfigurationView(BankRepository* bankRepository, BankController* controller, QWidget *parent = nullptr);
    ~ConfigurationView() override;

};


#endif
