#ifndef CUSTOMER_SUPPORT_ASSISTANT_CLIENTVIEW_H
#define CUSTOMER_SUPPORT_ASSISTANT_CLIENTVIEW_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
// Qt Libraries
#include <QMessageBox>
#include <QWidget>
// Project Libraries
#include "../Domain/Inquiry.h"
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
class ClientView : public QWidget {
Q_OBJECT
private:
    BankController* controller;
    Ui::ClientView *ui;

public:
    explicit ClientView(BankController* controller, QWidget *parent = nullptr);
    ~ClientView() override;
};


#endif
