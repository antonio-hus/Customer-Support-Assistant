///////////////////////
/// IMPORTS SECTION ///
//////////////////////
#include "InquiriesView.h"
#include "ui_InquiriesView.h"


////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
// Constructor
InquiriesView::InquiriesView(BankController* controller, QWidget *parent) :
        controller{controller}, QWidget(parent), ui(new Ui::InquiriesView) {
    ui->setupUi(this);

    /// VIEW CONFIGURATION
    // Setting the Models of the Views
    this->pendingTable = new PendingTable(this->controller);
    ui->pendingView->setModel(this->pendingTable);

    this->processingTable = new ProcessingTable(this->controller);
    ui->processingView->setModel(this->processingTable);

    this->completedTable = new CompletedTable(this->controller);
    ui->completedView->setModel(this->completedTable);

    /// VIEW SLOTS
    // MVC - View Refresh
    connect(this->controller, &BankController::pendingDataChanged, this, &InquiriesView::updatePendingTable);
    connect(this->controller, &BankController::processingDataChanged, this, &InquiriesView::updateProcessingTable);
    connect(this->controller, &BankController::completedDataChanged, this, &InquiriesView::updateCompletedTable);
}

// Destructor
InquiriesView::~InquiriesView() {
    delete ui;
    delete this->pendingTable;
    delete this->processingTable;
    delete this->completedTable;
}

// MVC - View Refresh
void InquiriesView::updatePendingTable() {
    this->pendingTable->resetModel();
}

void InquiriesView::updateProcessingTable() {
    this->processingTable->resetModel();
}

void InquiriesView::updateCompletedTable() {
    this->completedTable->resetModel();
}