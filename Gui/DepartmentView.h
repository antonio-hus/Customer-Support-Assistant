#ifndef CUSTOMER_SUPPORT_ASSISTANT_DEPARTMENTVIEW_H
#define CUSTOMER_SUPPORT_ASSISTANT_DEPARTMENTVIEW_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
// Qt Libraries
#include <QWidget>
#include <QMessageBox>
// Project Libraries
#include "../Controller/BankController.h"
#include "../Utils/CustomTables.h"


////////////////////////////
/// NAMESPACE DEFINITION ///
////////////////////////////
QT_BEGIN_NAMESPACE
namespace Ui { class DepartmentView; }
QT_END_NAMESPACE


////////////////////////
/// CLASS DEFINITION ///
////////////////////////
class DepartmentView : public QWidget {
Q_OBJECT
private:
    BankController* controller;
    Department* department;
    Ui::DepartmentView *ui;
    Agent* agent;
    AgentTable* agentTable;

public:
    explicit DepartmentView(BankController* controller, Agent* agent, const std::string& departmentName, QWidget *parent = nullptr);
    ~DepartmentView() override;

    void updateAgentTable(Agent agent);
    Inquiry getSelectedInquiry();
};


#endif
