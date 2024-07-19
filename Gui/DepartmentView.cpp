///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// Project Libraries
#include "DepartmentView.h"
#include "ui_DepartmentView.h"


DepartmentView::DepartmentView(BankController* controller, const std::string& departmentName, QWidget *parent) :
        controller{controller}, QWidget(parent), ui(new Ui::DepartmentView) {
    ui->setupUi(this);
    this->department = this->controller->createDepartment(departmentName);
    this->setWindowTitle(QString::fromStdString(this->department->getName()));
}

DepartmentView::~DepartmentView() {
    delete ui;
}
