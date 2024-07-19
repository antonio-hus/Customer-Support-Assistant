//
// Created by anton on 19/07/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ClientView.h" resolved

#include "ClientView.h"
#include "ui_ClientView.h"


ClientView::ClientView(QWidget *parent) :
        QWidget(parent), ui(new Ui::ClientView) {
    ui->setupUi(this);
}

ClientView::~ClientView() {
    delete ui;
}
