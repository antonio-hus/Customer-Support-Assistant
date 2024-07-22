#ifndef CUSTOMER_SUPPORT_ASSISTANT_CONTROLLERVIEW_H
#define CUSTOMER_SUPPORT_ASSISTANT_CONTROLLERVIEW_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// Qt Libraries
#include <QWidget>
// Project Libraries
#include "../Controller/BankController.h"


////////////////////////////
/// NAMESPACE DEFINITION ///
////////////////////////////
QT_BEGIN_NAMESPACE
namespace Ui { class ControllerView; }
QT_END_NAMESPACE


////////////////////////
/// CLASS DEFINITION ///
////////////////////////
class ControllerView : public QWidget {
Q_OBJECT
private:
    BankController* controller;
    Ui::ControllerView *ui;
    std::vector<QWidget*> allocatedScreens;

public:
    explicit ControllerView(BankController* controller, QWidget *parent = nullptr);
    ~ControllerView() override;
};


#endif
