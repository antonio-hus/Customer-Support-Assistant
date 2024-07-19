/********************************************************************************
** Form generated from reading UI file 'InquiriesView.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INQUIRIESVIEW_H
#define UI_INQUIRIESVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InquiriesView
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *pendingView;
    QLabel *label_2;
    QTableView *processingView;
    QLabel *label_3;
    QTableView *completedView;

    void setupUi(QWidget *InquiriesView)
    {
        if (InquiriesView->objectName().isEmpty())
            InquiriesView->setObjectName("InquiriesView");
        InquiriesView->resize(400, 643);
        verticalLayout = new QVBoxLayout(InquiriesView);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(InquiriesView);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        pendingView = new QTableView(InquiriesView);
        pendingView->setObjectName("pendingView");

        verticalLayout->addWidget(pendingView);

        label_2 = new QLabel(InquiriesView);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        processingView = new QTableView(InquiriesView);
        processingView->setObjectName("processingView");

        verticalLayout->addWidget(processingView);

        label_3 = new QLabel(InquiriesView);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        completedView = new QTableView(InquiriesView);
        completedView->setObjectName("completedView");

        verticalLayout->addWidget(completedView);


        retranslateUi(InquiriesView);

        QMetaObject::connectSlotsByName(InquiriesView);
    } // setupUi

    void retranslateUi(QWidget *InquiriesView)
    {
        InquiriesView->setWindowTitle(QCoreApplication::translate("InquiriesView", "InquiriesView", nullptr));
        label->setText(QCoreApplication::translate("InquiriesView", "Pending:", nullptr));
        label_2->setText(QCoreApplication::translate("InquiriesView", "Processing:", nullptr));
        label_3->setText(QCoreApplication::translate("InquiriesView", "Completed:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InquiriesView: public Ui_InquiriesView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INQUIRIESVIEW_H
