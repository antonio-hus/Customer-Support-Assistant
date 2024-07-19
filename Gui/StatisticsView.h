//
// Created by anton on 19/07/2024.
//

#ifndef CUSTOMER_SUPPORT_ASSISTANT_STATISTICSVIEW_H
#define CUSTOMER_SUPPORT_ASSISTANT_STATISTICSVIEW_H

#include <QWidget>
#include "../Controller/BankController.h"


QT_BEGIN_NAMESPACE
namespace Ui { class StatisticsView; }
QT_END_NAMESPACE

class StatisticsView : public QWidget {
Q_OBJECT

public:
    explicit StatisticsView(BankController* controller, QWidget *parent = nullptr);

    ~StatisticsView() override;

private:
    BankController* controller;
    Ui::StatisticsView *ui;
};


#endif //CUSTOMER_SUPPORT_ASSISTANT_STATISTICSVIEW_H
