///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// Project Libraries
#include "ControllerView.h"
#include "ClientView.h"
#include "InquiriesView.h"
#include "StatisticsView.h"
#include "ui_ControllerView.h"


////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
// Class Constructor
ControllerView::ControllerView(BankController* controller, QWidget *parent) :
        controller{controller}, QWidget(parent), ui(new Ui::ControllerView) {
    ui->setupUi(this);

    /// GUI Handlers
    // Create Inquiry Button
    // Open a Client View screen
    connect(ui->createInquiryButton, &QPushButton::clicked, [=, this]{
        auto* clientView = new ClientView(controller, this);
        clientView->show();
    });

    // View Inquiries Button
    // Open an Inquiries View screen
    connect(ui->viewInquiriesButton, &QPushButton::clicked, [=, this]{
        auto* inquiriesView = new InquiriesView(controller, this);
        inquiriesView->show();
    });

    // View Statistics Button
    // Open a Statistics screen
    connect(ui->viewStatisticsButton, &QPushButton::clicked, [=, this]{
        auto* statisticsView = new StatisticsView(controller, this);
        statisticsView->show();
    });
}

// Class Destructor
ControllerView::~ControllerView() {
    delete ui;
}
