#include "InquiriesView.h"
#include "ui_InquiriesView.h"


InquiriesView::InquiriesView(BankController* controller, QWidget *parent) :
        controller{controller}, QWidget(parent), ui(new Ui::InquiriesView) {
    ui->setupUi(this);
}

InquiriesView::~InquiriesView() {
    delete ui;
}
