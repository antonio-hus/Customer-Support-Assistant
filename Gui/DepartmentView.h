//
// Created by anton on 19/07/2024.
//

#ifndef CUSTOMER_SUPPORT_ASSISTANT_DEPARTMENTVIEW_H
#define CUSTOMER_SUPPORT_ASSISTANT_DEPARTMENTVIEW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class DepartmentView; }
QT_END_NAMESPACE

class DepartmentView : public QWidget {
Q_OBJECT

public:
    explicit DepartmentView(QWidget *parent = nullptr);

    ~DepartmentView() override;

private:
    Ui::DepartmentView *ui;
};


#endif //CUSTOMER_SUPPORT_ASSISTANT_DEPARTMENTVIEW_H
