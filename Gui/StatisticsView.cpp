//
// Created by anton on 19/07/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_StatisticsView.h" resolved

#include "StatisticsView.h"
#include "ui_StatisticsView.h"


StatisticsView::StatisticsView(BankController* controller, QWidget *parent) :
        controller{controller}, QWidget(parent), ui(new Ui::StatisticsView) {
    ui->setupUi(this);
}

StatisticsView::~StatisticsView() {
    delete ui;
}
