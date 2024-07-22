/********************************************************************************
** Form generated from reading UI file 'DepartmentView.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPARTMENTVIEW_H
#define UI_DEPARTMENTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DepartmentView
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QLabel *label;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *usernameBox;
    QLabel *label_3;
    QTextEdit *messageBox;
    QLabel *label_4;
    QLineEdit *urgencyBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *closeInquiryButton;

    void setupUi(QWidget *DepartmentView)
    {
        if (DepartmentView->objectName().isEmpty())
            DepartmentView->setObjectName("DepartmentView");
        DepartmentView->resize(554, 634);
        verticalLayout = new QVBoxLayout(DepartmentView);
        verticalLayout->setObjectName("verticalLayout");
        tableView = new QTableView(DepartmentView);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);

        label = new QLabel(DepartmentView);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(DepartmentView);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        usernameBox = new QLineEdit(DepartmentView);
        usernameBox->setObjectName("usernameBox");
        usernameBox->setEnabled(false);

        gridLayout->addWidget(usernameBox, 0, 1, 1, 1);

        label_3 = new QLabel(DepartmentView);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 0, 1, 1, Qt::AlignmentFlag::AlignTop);

        messageBox = new QTextEdit(DepartmentView);
        messageBox->setObjectName("messageBox");
        messageBox->setEnabled(false);

        gridLayout->addWidget(messageBox, 1, 1, 1, 1);

        label_4 = new QLabel(DepartmentView);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        urgencyBox = new QLineEdit(DepartmentView);
        urgencyBox->setObjectName("urgencyBox");
        urgencyBox->setEnabled(false);

        gridLayout->addWidget(urgencyBox, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        closeInquiryButton = new QPushButton(DepartmentView);
        closeInquiryButton->setObjectName("closeInquiryButton");

        horizontalLayout->addWidget(closeInquiryButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DepartmentView);

        QMetaObject::connectSlotsByName(DepartmentView);
    } // setupUi

    void retranslateUi(QWidget *DepartmentView)
    {
        DepartmentView->setWindowTitle(QCoreApplication::translate("DepartmentView", "DepartmentView", nullptr));
        label->setText(QCoreApplication::translate("DepartmentView", "Currently Selected:", nullptr));
        label_2->setText(QCoreApplication::translate("DepartmentView", "User:", nullptr));
        label_3->setText(QCoreApplication::translate("DepartmentView", "Message:", nullptr));
        label_4->setText(QCoreApplication::translate("DepartmentView", "Urgency:", nullptr));
        closeInquiryButton->setText(QCoreApplication::translate("DepartmentView", "Close Inquiry", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepartmentView: public Ui_DepartmentView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPARTMENTVIEW_H
