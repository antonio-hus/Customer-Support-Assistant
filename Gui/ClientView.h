#ifndef CUSTOMER_SUPPORT_ASSISTANT_CLIENTVIEW_H
#define CUSTOMER_SUPPORT_ASSISTANT_CLIENTVIEW_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
// Qt Libraries
#include <QWidget>
// Project Libraries
#include "../Controller/BankController.h"
#include "../Utils/ObserverPattern.h"


////////////////////////////
/// NAMESPACE DEFINITION ///
////////////////////////////
QT_BEGIN_NAMESPACE
namespace Ui { class ClientView; }
QT_END_NAMESPACE


////////////////////////
/// CLASS DEFINITION ///
////////////////////////
class ClientView : public QWidget, public Observer {
Q_OBJECT
private:
    BankController* controller;
    Ui::ClientView *ui;

public:
    explicit ClientView(BankController* controller, QWidget *parent = nullptr);
    void notify() override {};
    ~ClientView() override;
};


#endif
