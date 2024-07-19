//
// Created by anton on 19/07/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DepartmentView.h" resolved

#include "DepartmentView.h"
#include "ui_DepartmentView.h"


DepartmentView::DepartmentView(QWidget *parent) :
        QWidget(parent), ui(new Ui::DepartmentView) {
    ui->setupUi(this);
}

DepartmentView::~DepartmentView() {
    delete ui;
}
