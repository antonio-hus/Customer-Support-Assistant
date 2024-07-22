#ifndef CUSTOMER_SUPPORT_ASSISTANT_CUSTOMTABLES_H
#define CUSTOMER_SUPPORT_ASSISTANT_CUSTOMTABLES_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
// Qt Libraries
#include <QAbstractTableModel>
// Project Libraries
#include "../Controller/BankController.h"


////////////////////////
/// CLASS DEFINITION ///
///////////////////////
// Pending Inquiries Table Model
class PendingTable: public QAbstractTableModel {
private:
    BankController* controller;

public:
    explicit PendingTable(BankController* controller): controller(controller) {};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    void resetModel();
};

// Processing Inquiries Table Model
class ProcessingTable: public QAbstractTableModel {
private:
    BankController* controller;

public:
    explicit ProcessingTable(BankController* controller): controller(controller) {};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    void resetModel();
};

// Completed Inquiries Table Model
class CompletedTable: public QAbstractTableModel {
private:
    BankController* controller;

public:
    explicit CompletedTable(BankController* controller): controller(controller) {};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    void resetModel();
};

// Department Inquiries Table Model
class DepartmentTable: public QAbstractTableModel {
private:
    BankController* controller;
    Department department;

public:
    explicit DepartmentTable(BankController* controller, Department department): controller(controller), department(department) {};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    void resetModel();
};

// Agent Inquiries Table Model
class AgentTable: public QAbstractTableModel {
private:
    BankController* controller;
    Agent agent;

public:
    explicit AgentTable(BankController* controller, Agent agent): controller(controller), agent(agent) {};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    void resetModel();
};

#endif
