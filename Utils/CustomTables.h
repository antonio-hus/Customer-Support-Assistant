#ifndef CUSTOMER_SUPPORT_ASSISTANT_CUSTOMTABLES_H
#define CUSTOMER_SUPPORT_ASSISTANT_CUSTOMTABLES_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
// Qt Libraries
#include <QAbstractTableModel>
// Project Libraries
#include "../Repository/BankRepository.h"


////////////////////////
/// CLASS DEFINITION ///
///////////////////////
// Pending Inquiries Table Model
class PendingTable: public QAbstractTableModel {
private:
    BankRepository* repository;

public:
    explicit PendingTable(BankRepository* repository): repository(repository) {};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

};

// Processing Inquiries Table Model
class ProcessingTable: public QAbstractTableModel {
private:
    BankRepository* repository;

public:
    explicit ProcessingTable(BankRepository* repository): repository(repository) {};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

};

// Completed Inquiries Table Model
class CompletedTable: public QAbstractTableModel {
private:
    BankRepository* repository;

public:
    explicit CompletedTable(BankRepository* repository): repository(repository) {};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

};

// Department Inquiries Table Model
class DepartmentTable: public QAbstractTableModel {
private:
    BankRepository* repository;
    Department* department;

public:
    explicit DepartmentTable(BankRepository* repository, Department* department): repository(repository), department(department) {};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

};

// Agent Inquiries Table Model
class AgentTable: public QAbstractTableModel {
private:
    BankRepository* repository;

public:
    explicit AgentTable(BankRepository* repository): repository(repository) {};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

};

#endif
