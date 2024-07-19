//
// Created by anton on 19/07/2024.
//

#ifndef CUSTOMER_SUPPORT_ASSISTANT_INQUIRIESVIEW_H
#define CUSTOMER_SUPPORT_ASSISTANT_INQUIRIESVIEW_H

#include <QWidget>
#include "../Utils/ObserverPattern.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InquiriesView; }
QT_END_NAMESPACE

class InquiriesView : public QWidget, public Observer {
Q_OBJECT

public:
    explicit InquiriesView(QWidget *parent = nullptr);

    ~InquiriesView() override;

private:
    Ui::InquiriesView *ui;
};


#endif //CUSTOMER_SUPPORT_ASSISTANT_INQUIRIESVIEW_H
