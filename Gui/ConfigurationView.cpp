///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// Project Libraries
#include "ConfigurationView.h"
#include "ui_ConfigurationView.h"


////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
// Class Constructor
ConfigurationView::ConfigurationView(QWidget *parent) :
       QWidget(parent), ui(new Ui::ConfigurationView) {
    ui->setupUi(this);

    // Handle Configuration Submission
    connect(ui->submitButton, &QPushButton::clicked, [=, this]{

        // Check configuration values - non-empty and positive
        if((ui->customerServiceBox->text().isEmpty() || stoi(ui->customerServiceBox->text().toStdString()) < 0) ||
        (ui->personalBankingBox->text().isEmpty() || stoi(ui->personalBankingBox->text().toStdString()) < 0) ||
        (ui->businessBankingBox->text().isEmpty() || stoi(ui->businessBankingBox->text().toStdString()) < 0) ||
        (ui->investmentServicesBox->text().isEmpty() || stoi(ui->investmentServicesBox->text().toStdString()) < 0) ||
        (ui->loansMortgagesBox->text().isEmpty() || stoi(ui->loansMortgagesBox->text().toStdString()) < 0) ||
        (ui->riskManagementBox->text().isEmpty() || stoi(ui->riskManagementBox->text().toStdString()) < 0) ||
        (ui->itSupportBox->text().isEmpty() || stoi(ui->itSupportBox->text().toStdString()) < 0) ||
        (ui->hrBox->text().isEmpty() || stoi(ui->hrBox->text().toStdString()) < 0) ||
        (ui->financeAccountingBox->text().isEmpty() || stoi(ui->financeAccountingBox->text().toStdString()) < 0))
        { QMessageBox::critical(this, "Invalid Configuration", "All fields must be positive");  }

        // Create department map
        std::unordered_map<Department, int> departmentMap = {
                { Department::CustomerService, stoi(ui->customerServiceBox->text().toStdString()) },
                { Department::PersonalBanking, stoi(ui->personalBankingBox->text().toStdString()) },
                { Department::BusinessBanking, stoi(ui->businessBankingBox->text().toStdString()) },
                { Department::InvestmentServices, stoi(ui->investmentServicesBox->text().toStdString()) },
                { Department::LoansMortgages, stoi(ui->loansMortgagesBox->text().toStdString()) },
                { Department::RiskManagement, stoi(ui->riskManagementBox->text().toStdString()) },
                { Department::ITSupport, stoi(ui->itSupportBox->text().toStdString()) },
                { Department::HR, stoi(ui->hrBox->text().toStdString()) },
                { Department::FinanceAccounting, stoi(ui->financeAccountingBox->text().toStdString()) },
        };

        // Initialize repository & controller
        this->repository = new BankRepository(departmentMap);
        this->controller = new BankController(this->repository);

        // Hiding View
        this->hide();

        // Starting Up Views
        // Client View
        auto* clientView =  new ClientView(controller);
        allocatedViews.push_back(clientView);
        clientView->show();

        // Controller View
        auto* controllerView =  new ControllerView(controller);
        allocatedViews.push_back(controllerView);
        controllerView->show();

        // Department Views
        // Looping over all departments
        int agentID = 0;
        for (const auto& pair : departmentMap) {

            // Opening the agents as specified in config
            for (int i = 1; i <= pair.second; ++i) {
                agentID ++;
                auto* agent = new Agent(agentID, pair.first);
                allocatedAgents.push_back(agent);

                auto* departmentView = new DepartmentView(controller, agent, toString(pair.first) + " - agent " + std::to_string(i));
                allocatedViews.push_back(departmentView);
                departmentView->show();
            }
        }
    });

}

// Class Destructor
ConfigurationView::~ConfigurationView() {
    delete ui;
    for(auto screen:this->allocatedViews){
        delete screen;
    }
    delete repository;
    delete controller;
}
