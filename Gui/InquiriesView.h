#ifndef CUSTOMER_SUPPORT_ASSISTANT_INQUIRIESVIEW_H
#define CUSTOMER_SUPPORT_ASSISTANT_INQUIRIESVIEW_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// Qt Libraries
#include <QWidget>
// Project Libraries
#include "../Controller/BankController.h"
#include "../Utils/CustomTables.h"
#include "../Utils/ObserverPattern.h"


////////////////////////////
/// NAMESPACE DEFINITION ///
////////////////////////////
QT_BEGIN_NAMESPACE
namespace Ui { class InquiriesView; }
QT_END_NAMESPACE


////////////////////////
/// CLASS DEFINITION ///
////////////////////////
class InquiriesView : public QWidget, public Observer {
Q_OBJECT
private:
    BankController* controller;
    Ui::InquiriesView *ui;

public:
    explicit InquiriesView(BankController* controller, QWidget *parent = nullptr);
    void notify() override {};
    ~InquiriesView() override;
};


#endif
