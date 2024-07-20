#include "InquiriesView.h"
#include "ui_InquiriesView.h"


InquiriesView::InquiriesView(BankController* controller, QWidget *parent) :
        controller{controller}, QWidget(parent), ui(new Ui::InquiriesView) {
    ui->setupUi(this);

    // Setting the Models of the Views
    auto* pendingModel = new PendingTable(this->controller);
    ui->pendingView->setModel(pendingModel);

    auto* processingModel = new ProcessingTable(this->controller);
    ui->processingView->setModel(processingModel);

    auto* completedModel = new CompletedTable(this->controller);
    ui->completedView->setModel(completedModel);
}

InquiriesView::~InquiriesView() {
    delete ui;
}
