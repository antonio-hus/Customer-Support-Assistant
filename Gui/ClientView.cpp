#include "ClientView.h"
#include "ui_ClientView.h"


ClientView::ClientView(BankController* controller, QWidget *parent) :
        controller{controller}, QWidget(parent), ui(new Ui::ClientView) {
    ui->setupUi(this);
}

ClientView::~ClientView() {
    delete ui;
}
