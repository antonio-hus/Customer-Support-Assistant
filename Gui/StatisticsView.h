#ifndef CUSTOMER_SUPPORT_ASSISTANT_STATISTICSVIEW_H
#define CUSTOMER_SUPPORT_ASSISTANT_STATISTICSVIEW_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// Qt Libraries
#include <QWidget>
#include <QPainter>
#include <QMap>
// Project Libraries
#include "../Controller/BankController.h"
#include "../Utils/ObserverPattern.h"


////////////////////////////
/// NAMESPACE DEFINITION ///
////////////////////////////
QT_BEGIN_NAMESPACE
namespace Ui { class StatisticsView; }
QT_END_NAMESPACE


////////////////////////
/// CLASS DEFINITION ///
////////////////////////
class StatisticsView : public QWidget, public Observer {
Q_OBJECT
private:
    BankController* controller;
    Ui::StatisticsView *ui;

    // Data Processing for Graph Visualization
    QMap<QString, int> departmentCounts;
    void processInquiries();

protected:

    // Painting the Graph
    void paintEvent(QPaintEvent *event) override;

public:
    explicit StatisticsView(BankController* controller, QWidget *parent = nullptr);
    void notify() override;
    ~StatisticsView() override;
};


#endif
