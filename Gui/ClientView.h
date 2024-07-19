//
// Created by anton on 19/07/2024.
//

#ifndef CUSTOMER_SUPPORT_ASSISTANT_CLIENTVIEW_H
#define CUSTOMER_SUPPORT_ASSISTANT_CLIENTVIEW_H

#include <QWidget>
#include "../Utils/ObserverPattern.h"


QT_BEGIN_NAMESPACE
namespace Ui { class ClientView; }
QT_END_NAMESPACE

class ClientView : public QWidget, public Observer {
Q_OBJECT

public:
    explicit ClientView(QWidget *parent = nullptr);

    ~ClientView() override;

private:
    Ui::ClientView *ui;
};


#endif //CUSTOMER_SUPPORT_ASSISTANT_CLIENTVIEW_H
