/********************************************************************************
** Form generated from reading UI file 'ControllerView.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLLERVIEW_H
#define UI_CONTROLLERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControllerView
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *createInquiryButton;
    QPushButton *viewInquiriesButton;
    QPushButton *viewStatisticsButton;

    void setupUi(QWidget *ControllerView)
    {
        if (ControllerView->objectName().isEmpty())
            ControllerView->setObjectName("ControllerView");
        ControllerView->resize(400, 173);
        horizontalLayout = new QHBoxLayout(ControllerView);
        horizontalLayout->setObjectName("horizontalLayout");
        createInquiryButton = new QPushButton(ControllerView);
        createInquiryButton->setObjectName("createInquiryButton");
        createInquiryButton->setMinimumSize(QSize(100, 100));

        horizontalLayout->addWidget(createInquiryButton);

        viewInquiriesButton = new QPushButton(ControllerView);
        viewInquiriesButton->setObjectName("viewInquiriesButton");
        viewInquiriesButton->setMinimumSize(QSize(100, 100));

        horizontalLayout->addWidget(viewInquiriesButton);

        viewStatisticsButton = new QPushButton(ControllerView);
        viewStatisticsButton->setObjectName("viewStatisticsButton");
        viewStatisticsButton->setMinimumSize(QSize(100, 100));

        horizontalLayout->addWidget(viewStatisticsButton);


        retranslateUi(ControllerView);

        createInquiryButton->setDefault(false);
        viewInquiriesButton->setDefault(false);
        viewStatisticsButton->setDefault(false);


        QMetaObject::connectSlotsByName(ControllerView);
    } // setupUi

    void retranslateUi(QWidget *ControllerView)
    {
        ControllerView->setWindowTitle(QCoreApplication::translate("ControllerView", "ControllerView", nullptr));
        createInquiryButton->setText(QCoreApplication::translate("ControllerView", "Create Inquiry", nullptr));
        viewInquiriesButton->setText(QCoreApplication::translate("ControllerView", "View Inquiries", nullptr));
        viewStatisticsButton->setText(QCoreApplication::translate("ControllerView", "View Statistics", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControllerView: public Ui_ControllerView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLERVIEW_H
