/********************************************************************************
** Form generated from reading UI file 'ConfigurationView.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATIONVIEW_H
#define UI_CONFIGURATIONVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigurationView
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QSpinBox *customerServiceBox;
    QLabel *label_4;
    QSpinBox *personalBankingBox;
    QLabel *label_5;
    QSpinBox *businessBankingBox;
    QLabel *label_6;
    QSpinBox *investmentServicesBox;
    QLabel *label_7;
    QSpinBox *loansMortgagesBox;
    QLabel *label_8;
    QSpinBox *riskManagementBox;
    QLabel *label_9;
    QSpinBox *itSupportBox;
    QLabel *label_10;
    QSpinBox *hrBox;
    QLabel *label_11;
    QSpinBox *financeAccountingBox;
    QPushButton *submitButton;

    void setupUi(QWidget *ConfigurationView)
    {
        if (ConfigurationView->objectName().isEmpty())
            ConfigurationView->setObjectName("ConfigurationView");
        ConfigurationView->resize(400, 373);
        verticalLayout_2 = new QVBoxLayout(ConfigurationView);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(ConfigurationView);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_2 = new QLabel(ConfigurationView);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);


        verticalLayout_2->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_3 = new QLabel(ConfigurationView);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        customerServiceBox = new QSpinBox(ConfigurationView);
        customerServiceBox->setObjectName("customerServiceBox");

        gridLayout->addWidget(customerServiceBox, 0, 1, 1, 1);

        label_4 = new QLabel(ConfigurationView);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        personalBankingBox = new QSpinBox(ConfigurationView);
        personalBankingBox->setObjectName("personalBankingBox");

        gridLayout->addWidget(personalBankingBox, 1, 1, 1, 1);

        label_5 = new QLabel(ConfigurationView);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        businessBankingBox = new QSpinBox(ConfigurationView);
        businessBankingBox->setObjectName("businessBankingBox");

        gridLayout->addWidget(businessBankingBox, 2, 1, 1, 1);

        label_6 = new QLabel(ConfigurationView);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        investmentServicesBox = new QSpinBox(ConfigurationView);
        investmentServicesBox->setObjectName("investmentServicesBox");

        gridLayout->addWidget(investmentServicesBox, 3, 1, 1, 1);

        label_7 = new QLabel(ConfigurationView);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        loansMortgagesBox = new QSpinBox(ConfigurationView);
        loansMortgagesBox->setObjectName("loansMortgagesBox");

        gridLayout->addWidget(loansMortgagesBox, 4, 1, 1, 1);

        label_8 = new QLabel(ConfigurationView);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        riskManagementBox = new QSpinBox(ConfigurationView);
        riskManagementBox->setObjectName("riskManagementBox");

        gridLayout->addWidget(riskManagementBox, 5, 1, 1, 1);

        label_9 = new QLabel(ConfigurationView);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 6, 0, 1, 1);

        itSupportBox = new QSpinBox(ConfigurationView);
        itSupportBox->setObjectName("itSupportBox");

        gridLayout->addWidget(itSupportBox, 6, 1, 1, 1);

        label_10 = new QLabel(ConfigurationView);
        label_10->setObjectName("label_10");

        gridLayout->addWidget(label_10, 7, 0, 1, 1);

        hrBox = new QSpinBox(ConfigurationView);
        hrBox->setObjectName("hrBox");

        gridLayout->addWidget(hrBox, 7, 1, 1, 1);

        label_11 = new QLabel(ConfigurationView);
        label_11->setObjectName("label_11");

        gridLayout->addWidget(label_11, 8, 0, 1, 1);

        financeAccountingBox = new QSpinBox(ConfigurationView);
        financeAccountingBox->setObjectName("financeAccountingBox");

        gridLayout->addWidget(financeAccountingBox, 8, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        submitButton = new QPushButton(ConfigurationView);
        submitButton->setObjectName("submitButton");

        verticalLayout_2->addWidget(submitButton);


        retranslateUi(ConfigurationView);

        QMetaObject::connectSlotsByName(ConfigurationView);
    } // setupUi

    void retranslateUi(QWidget *ConfigurationView)
    {
        ConfigurationView->setWindowTitle(QCoreApplication::translate("ConfigurationView", "ConfigurationView", nullptr));
        label->setText(QCoreApplication::translate("ConfigurationView", "Initial Department Configuration:", nullptr));
        label_2->setText(QCoreApplication::translate("ConfigurationView", "Please input the number of agents from each Department", nullptr));
        label_3->setText(QCoreApplication::translate("ConfigurationView", "Customer Service:", nullptr));
        label_4->setText(QCoreApplication::translate("ConfigurationView", "Personal Banking:", nullptr));
        label_5->setText(QCoreApplication::translate("ConfigurationView", "Business Banking:", nullptr));
        label_6->setText(QCoreApplication::translate("ConfigurationView", "Investment Services:", nullptr));
        label_7->setText(QCoreApplication::translate("ConfigurationView", "Loans & Mortgages:", nullptr));
        label_8->setText(QCoreApplication::translate("ConfigurationView", "Risk Management:", nullptr));
        label_9->setText(QCoreApplication::translate("ConfigurationView", "IT Support:", nullptr));
        label_10->setText(QCoreApplication::translate("ConfigurationView", "HR:", nullptr));
        label_11->setText(QCoreApplication::translate("ConfigurationView", "FInance & Accounting:", nullptr));
        submitButton->setText(QCoreApplication::translate("ConfigurationView", "Submit Configuration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigurationView: public Ui_ConfigurationView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATIONVIEW_H
