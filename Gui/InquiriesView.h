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
class InquiriesView : public QWidget {
Q_OBJECT
private:
    BankController* controller;
    Ui::InquiriesView *ui;
    PendingTable* pendingTable;
    ProcessingTable* processingTable;
    CompletedTable* completedTable;

public:
    explicit InquiriesView(BankController* controller, QWidget *parent = nullptr);
    ~InquiriesView() override;

    void updatePendingTable();
    void updateProcessingTable();
    void updateCompletedTable();
};


#endif
