/********************************************************************************
** Form generated from reading UI file 'ClientView.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTVIEW_H
#define UI_CLIENTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientView
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *formView;
    QLabel *label;
    QGridLayout *gridLayout;
    QLineEdit *usernameEdit;
    QLabel *label_2;
    QTextEdit *inquiryMessageBox;
    QLabel *label_6;
    QLabel *label_4;
    QLineEdit *firstNameEdit;
    QLineEdit *lastNameEdit;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_7;
    QLineEdit *emailEdit;
    QLineEdit *phoneEdit;
    QPushButton *openInquiryButton;

    void setupUi(QWidget *ClientView)
    {
        if (ClientView->objectName().isEmpty())
            ClientView->setObjectName("ClientView");
        ClientView->resize(400, 356);
        verticalLayout = new QVBoxLayout(ClientView);
        verticalLayout->setObjectName("verticalLayout");
        formView = new QVBoxLayout();
        formView->setObjectName("formView");
        label = new QLabel(ClientView);
        label->setObjectName("label");

        formView->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        usernameEdit = new QLineEdit(ClientView);
        usernameEdit->setObjectName("usernameEdit");

        gridLayout->addWidget(usernameEdit, 2, 1, 1, 1);

        label_2 = new QLabel(ClientView);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        inquiryMessageBox = new QTextEdit(ClientView);
        inquiryMessageBox->setObjectName("inquiryMessageBox");

        gridLayout->addWidget(inquiryMessageBox, 5, 1, 1, 1);

        label_6 = new QLabel(ClientView);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        label_4 = new QLabel(ClientView);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        firstNameEdit = new QLineEdit(ClientView);
        firstNameEdit->setObjectName("firstNameEdit");

        gridLayout->addWidget(firstNameEdit, 0, 1, 1, 1);

        lastNameEdit = new QLineEdit(ClientView);
        lastNameEdit->setObjectName("lastNameEdit");

        gridLayout->addWidget(lastNameEdit, 1, 1, 1, 1);

        label_5 = new QLabel(ClientView);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 5, 0, 1, 1, Qt::AlignmentFlag::AlignTop);

        label_3 = new QLabel(ClientView);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_7 = new QLabel(ClientView);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        emailEdit = new QLineEdit(ClientView);
        emailEdit->setObjectName("emailEdit");

        gridLayout->addWidget(emailEdit, 3, 1, 1, 1);

        phoneEdit = new QLineEdit(ClientView);
        phoneEdit->setObjectName("phoneEdit");

        gridLayout->addWidget(phoneEdit, 4, 1, 1, 1);


        formView->addLayout(gridLayout);

        openInquiryButton = new QPushButton(ClientView);
        openInquiryButton->setObjectName("openInquiryButton");

        formView->addWidget(openInquiryButton);


        verticalLayout->addLayout(formView);


        retranslateUi(ClientView);

        QMetaObject::connectSlotsByName(ClientView);
    } // setupUi

    void retranslateUi(QWidget *ClientView)
    {
        ClientView->setWindowTitle(QCoreApplication::translate("ClientView", "ClientView", nullptr));
        label->setText(QCoreApplication::translate("ClientView", "Fill in the form below to open an inquiry:", nullptr));
        label_2->setText(QCoreApplication::translate("ClientView", "First Name:", nullptr));
        label_6->setText(QCoreApplication::translate("ClientView", "E-mail:", nullptr));
        label_4->setText(QCoreApplication::translate("ClientView", "Username:", nullptr));
        label_5->setText(QCoreApplication::translate("ClientView", "Message:", nullptr));
        label_3->setText(QCoreApplication::translate("ClientView", "Last Name:  ", nullptr));
        label_7->setText(QCoreApplication::translate("ClientView", "Phone Number:", nullptr));
        openInquiryButton->setText(QCoreApplication::translate("ClientView", "Open Inquiry", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientView: public Ui_ClientView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTVIEW_H
