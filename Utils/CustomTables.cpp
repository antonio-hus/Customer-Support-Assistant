///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// Project Libraries
#include "CustomTables.h"


////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
// Pending Inquiries Table Model Implementation
int PendingTable::rowCount(const QModelIndex &parent) const {
    return this->repository->getPendingSize();
}

int PendingTable::columnCount(const QModelIndex &parent) const {
    return 6;
}

QVariant PendingTable::data(const QModelIndex &index, int role) const {

    // Validate Index
    if (!index.isValid() || index.row() < 0 || index.row() >= rowCount() || index.column() < 0 || index.column() >= columnCount()) {

        // Invalid Index
        return {};
    }

    // Display Role
    if (role == Qt::DisplayRole) {
        int row = index.row();
        int col = index.column();

        // Get the range of pending inquiries
        auto [begin, end] = this->repository->getPending();

        // Out of bounds
        if (row >= std::distance(begin, end)) {
            return {};
        }

        // Get the inquiry from the range
        auto inquiry = *(begin + row);

        // Populating table column data
        switch (col) {
            case 0: return QVariant::fromValue(QString::fromStdString(inquiry.getID()));
            case 1: return QVariant::fromValue(QString::fromStdString(inquiry.getUser().getUsername()));
            case 2: return QVariant::fromValue(QString::fromStdString(inquiry.getMessage()));
            case 3: return QVariant::fromValue(QString::fromStdString(inquiry.getDepartament().getName()));
            case 4: return QVariant::fromValue(QString::fromStdString(toString(inquiry.getInquiryStatus())));
            case 5: return QVariant::fromValue(QString::fromStdString(toString(inquiry.getUrgencyLevel())));
            default:
                return {};
        }
    }

    // Other roles not supported
    return {};
}

// Processing Inquiries Table Model Implementation
int ProcessingTable::rowCount(const QModelIndex &parent) const {

}

int ProcessingTable::columnCount(const QModelIndex &parent) const {

}

QVariant ProcessingTable::data(const QModelIndex &index, int role) const {

}

// Completed Inquiries Table Model Implementation
int CompletedTable::rowCount(const QModelIndex &parent) const {

}

int CompletedTable::columnCount(const QModelIndex &parent) const {

}

QVariant CompletedTable::data(const QModelIndex &index, int role) const {

}

// Department Inquiries Table Model Implementation
int DepartmentTable::rowCount(const QModelIndex &parent) const {

}

int DepartmentTable::columnCount(const QModelIndex &parent) const {

}

QVariant DepartmentTable::data(const QModelIndex &index, int role) const {

}

// Agent Inquiries Table Model Implementation
int AgentTable::rowCount(const QModelIndex &parent) const {

}

int AgentTable::columnCount(const QModelIndex &parent) const {

}

QVariant AgentTable::data(const QModelIndex &index, int role) const {

}