/********************************************************************************
** Form generated from reading UI file 'StatisticsView.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSVIEW_H
#define UI_STATISTICSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatisticsView
{
public:

    void setupUi(QWidget *StatisticsView)
    {
        if (StatisticsView->objectName().isEmpty())
            StatisticsView->setObjectName("StatisticsView");
        StatisticsView->resize(400, 300);

        retranslateUi(StatisticsView);

        QMetaObject::connectSlotsByName(StatisticsView);
    } // setupUi

    void retranslateUi(QWidget *StatisticsView)
    {
        StatisticsView->setWindowTitle(QCoreApplication::translate("StatisticsView", "StatisticsView", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatisticsView: public Ui_StatisticsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSVIEW_H
