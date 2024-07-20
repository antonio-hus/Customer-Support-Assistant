///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// Project Libraries
#include "ClientView.h"
#include "ui_ClientView.h"


////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
ClientView::ClientView(BankController* controller, QWidget *parent) :
        controller{controller}, QWidget(parent), ui(new Ui::ClientView) {
    ui->setupUi(this);

    /// Handling CRUD Operations
    // Form Submit
    connect(ui->openInquiryButton, &QPushButton::clicked, [=, this]{

        // Getting form data
        std::string username = ui->usernameEdit->text().toStdString();
        std::string firstName = ui->firstNameEdit->text().toStdString();
        std::string lastName = ui->lastNameEdit->text().toStdString();
        std::string phoneNumber = ui->phoneEdit->text().toStdString();
        std::string email = ui->emailEdit->text().toStdString();
        std::string message = ui->inquiryMessageBox->toPlainText().toStdString();

        // Create new Inquiry
        try {
            Inquiry newInquiry = this->controller->createInquiry(username, firstName, lastName, email, phoneNumber, message);
            QMessageBox::information(this, "Successful Submit!", "Your inquiry was sent and will be processed shortly. The issue shall be fixed in at most 24h. If the problem persists, please retry...");
        }

        // Invalid Form Data
        catch (UserException& exception) {
            QMessageBox::critical(this, "Invalid User Form Data", exception.what());
        }
        catch (InquiryException& exception) {
            QMessageBox::critical(this, "Invalid Inquiry Form Data", exception.what());
        }
        catch (...) {
            QMessageBox::critical(this, "Invalid Form Data", "There has been an issue submitting the form");
        }

    });
}

ClientView::~ClientView() {
    delete ui;
}
