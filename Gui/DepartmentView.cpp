///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// Project Libraries
#include "DepartmentView.h"
#include "ui_DepartmentView.h"


DepartmentView::DepartmentView(BankController* controller, Agent* agent, const std::string& departmentName, QWidget *parent) :
        controller{controller}, agent{agent}, QWidget(parent), ui(new Ui::DepartmentView) {
    ui->setupUi(this);

    /// VIEW CONFIGURATION
    // Set Window Properties
    this->setWindowTitle(QString::fromStdString(departmentName));

    // Set Views
    this->agentTable = new AgentTable(controller, *agent);
    ui->tableView->setModel(this->agentTable);

    /// VIEW SLOTS
    // MVC - View Refresh
    connect(controller, &BankController::agentDataChanged, this, &DepartmentView::updateAgentTable);
    connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged, [=, this]{
        // Get selected inquiry
        auto inquiry = this->getSelectedInquiry();

        // Update view elements
        ui->usernameBox->setText(QString::fromStdString(inquiry.getUser()->getUsername()));
        ui->messageBox->setText(QString::fromStdString(inquiry.getDescription()));
        ui->urgencyBox->setText(QString::fromStdString(toString(inquiry.getUrgencyLevel())));
    });

    // Connect Button Handlers
    connect(ui->closeInquiryButton, &QPushButton::clicked, [=, this]{

        // Get selected inquiry
        auto inquiry = this->getSelectedInquiry();

        // Clear View Elements
        ui->usernameBox->clear();
        ui->messageBox->clear();
        ui->urgencyBox->clear();

        // Process & close inquiry
        this->controller->processInquiry(inquiry);
    });
}

DepartmentView::~DepartmentView() {
    delete ui;
    delete this->agentTable;
}

void DepartmentView::updateAgentTable(Agent agent) {

    // Compare agent signal parameter with our agent
    if(agent == *this->agent) {
        this->agentTable->resetModel();
    }
}

Inquiry DepartmentView::getSelectedInquiry() {

    // Get Selection
    QItemSelectionModel* selectionModel = ui->tableView->selectionModel();
    if (!selectionModel->hasSelection()) {
        QMessageBox::critical(this, "Selection Error", "No row is currently selected!");
    }

    QModelIndexList selectedRows = selectionModel->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::critical(this, "Selection Error", "No row is currently selected!");
    }

    // Compute row by selection
    QModelIndex selectedIndex = selectedRows.at(0);
    int row = selectedIndex.row();

    // Get corresponding inquiry
    auto begin = this->controller->getProcessingByAgent(*this->agent).first;
    std::advance(begin, row);
    Inquiry inquiry = begin->second;

    return inquiry;
}
