#ifndef CUSTOMER_SUPPORT_ASSISTANT_DEPARTMENTVIEW_H
#define CUSTOMER_SUPPORT_ASSISTANT_DEPARTMENTVIEW_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
// Qt Libraries
#include <QWidget>
// Project Libraries
#include "../Controller/BankController.h"
#include "../Utils/ObserverPattern.h"


////////////////////////////
/// NAMESPACE DEFINITION ///
////////////////////////////
QT_BEGIN_NAMESPACE
namespace Ui { class DepartmentView; }
QT_END_NAMESPACE


////////////////////////
/// CLASS DEFINITION ///
////////////////////////
class DepartmentView : public QWidget, public Observer {
Q_OBJECT
private:
    BankController* controller;
    Department* department;
    Ui::DepartmentView *ui;

public:
    explicit DepartmentView(BankController* controller, const std::string& departmentName, QWidget *parent = nullptr);
    void notify() override {};
    ~DepartmentView() override;
};


#endif
