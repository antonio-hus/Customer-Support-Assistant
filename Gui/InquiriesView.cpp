//
// Created by anton on 19/07/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_InquiriesView.h" resolved

#include "InquiriesView.h"
#include "ui_InquiriesView.h"


InquiriesView::InquiriesView(QWidget *parent) :
        QWidget(parent), ui(new Ui::InquiriesView) {
    ui->setupUi(this);
}

InquiriesView::~InquiriesView() {
    delete ui;
}
