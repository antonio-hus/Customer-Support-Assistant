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
    return this->controller->getPendingSize();
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
        auto [begin, end] = this->controller->getPending();

        // Out of bounds
        if (row >= std::distance(begin, end)) {
            return {};
        }

        // Get the inquiry from the range
        auto inquiry = *(begin + row);

        // Populating table column data
        switch (col) {
            case 0: return QVariant::fromValue(QString::fromStdString(std::to_string(inquiry.getInquiryID())));
            case 1: return QVariant::fromValue(QString::fromStdString(inquiry.getUser()->getUsername()));
            case 2: return QVariant::fromValue(QString::fromStdString(inquiry.getDescription()));
            case 3: return QVariant::fromValue(QString::fromStdString(toString(inquiry.getAssignedDepartment())));
            case 4: return QVariant::fromValue(QString::fromStdString(toString(inquiry.getStatus())));
            case 5: return QVariant::fromValue(QString::fromStdString(toString(inquiry.getUrgencyLevel())));
            default:
                return {};
        }
    }

    // Other roles not supported
    return {};
}

void PendingTable::resetModel() {
    this->beginResetModel();
    this->endResetModel();
}

QVariant PendingTable::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return QString("Inquiry ID");
            case 1:
                return QString("User");
            case 2:
                return QString("Description");
            case 3:
                return QString("Department");
            case 4:
                return QString("Status");
            case 5:
                return QString("Urgency Level");
            default:
                return QVariant();
        }
    } else if (orientation == Qt::Vertical) {
        return QString(">");
    }
    return QVariant();
}

// Processing Inquiries Table Model Implementation
int ProcessingTable::rowCount(const QModelIndex &parent) const {
    return this->controller->getProcessingSize();
}

int ProcessingTable::columnCount(const QModelIndex &parent) const {
    return 6;
}

QVariant ProcessingTable::data(const QModelIndex &index, int role) const {

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
        auto [begin, end] = this->controller->getProcessing();

        // Out of bounds
        if (row >= std::distance(begin, end)) {
            return {};
        }

        // Get the inquiry from the range
        auto it = begin;
        std::advance(it, row);

        // Get the inquiry from the range
        auto& inquiry = it->second.begin()->second;

        // Populating table column data
        switch (col) {
            case 0: return QVariant::fromValue(QString::fromStdString(std::to_string(inquiry.getInquiryID())));
            case 1: return QVariant::fromValue(QString::fromStdString(inquiry.getUser()->getUsername()));
            case 2: return QVariant::fromValue(QString::fromStdString(inquiry.getDescription()));
            case 3: return QVariant::fromValue(QString::fromStdString(toString(inquiry.getAssignedDepartment())));
            case 4: return QVariant::fromValue(QString::fromStdString(toString(inquiry.getStatus())));
            case 5: return QVariant::fromValue(QString::fromStdString(toString(inquiry.getUrgencyLevel())));
            default:
                return {};
        }
    }

    // Other roles not supported
    return {};
}

void ProcessingTable::resetModel() {
    this->beginResetModel();
    this->endResetModel();
}

QVariant ProcessingTable::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return QString("Inquiry ID");
            case 1:
                return QString("User");
            case 2:
                return QString("Description");
            case 3:
                return QString("Department");
            case 4:
                return QString("Status");
            case 5:
                return QString("Urgency Level");
            default:
                return QVariant();
        }
    } else if (orientation == Qt::Vertical) {
        return QString(">");
    }
    return QVariant();
}

// Completed Inquiries Table Model Implementation
int CompletedTable::rowCount(const QModelIndex &parent) const {
    return this->controller->getCompletedSize();
}

int CompletedTable::columnCount(const QModelIndex &parent) const {
    return 6;
}

QVariant CompletedTable::data(const QModelIndex &index, int role) const {
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
        auto [begin, end] = this->controller->getCompleted();

        // Out of bounds
        if (row >= std::distance(begin, end)) {
            return {};
        }

        // Get the inquiry from the range
        auto inquiry = *(begin + row);

        // Populating table column data
        switch (col) {
            case 0: return QVariant::fromValue(QString::fromStdString(std::to_string(inquiry.getInquiryID())));
            case 1: return QVariant::fromValue(QString::fromStdString(inquiry.getUser()->getUsername()));
            case 2: return QVariant::fromValue(QString::fromStdString(inquiry.getDescription()));
            case 3: return QVariant::fromValue(QString::fromStdString(toString(inquiry.getAssignedDepartment())));
            case 4: return QVariant::fromValue(QString::fromStdString(toString(inquiry.getStatus())));
            case 5: return QVariant::fromValue(QString::fromStdString(toString(inquiry.getUrgencyLevel())));
            default:
                return {};
        }
    }

    // Other roles not supported
    return {};
}

QVariant CompletedTable::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return QString("Inquiry ID");
            case 1:
                return QString("User");
            case 2:
                return QString("Description");
            case 3:
                return QString("Department");
            case 4:
                return QString("Status");
            case 5:
                return QString("Urgency Level");
            default:
                return QVariant();
        }
    } else if (orientation == Qt::Vertical) {
        return QString(">");
    }
    return QVariant();
}

void CompletedTable::resetModel() {
    this->beginResetModel();
    this->endResetModel();
}

// Department Inquiries Table Model Implementation
int DepartmentTable::rowCount(const QModelIndex &parent) const {
    return this->controller->getProcessingByDepartmentSize(this->department);
}

int DepartmentTable::columnCount(const QModelIndex &parent) const {
    return 6;
}

QVariant DepartmentTable::data(const QModelIndex &index, int role) const {
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
        auto [begin, end] = this->controller->getProcessingByDepartment(this->department);

        // Out of bounds
        if (row >= std::distance(begin, end)) {
            return {};
        }

        // Get the inquiry from the range
        auto it = begin;
        std::advance(it, row);

        // Get the inquiry from the range
        auto& inquiry = it->second;

        // Populating table column data
        switch (col) {
            case 0: return QVariant::fromValue(QString::fromStdString(std::to_string(inquiry.getInquiryID())));
            case 1: return QVariant::fromValue(QString::fromStdString(inquiry.getUser()->getUsername()));
            case 2: return QVariant::fromValue(QString::fromStdString(inquiry.getDescription()));
            case 3: return QVariant::fromValue(QString::fromStdString(toString(inquiry.getAssignedDepartment())));
            case 4: return QVariant::fromValue(QString::fromStdString(toString(inquiry.getStatus())));
            case 5: return QVariant::fromValue(QString::fromStdString(toString(inquiry.getUrgencyLevel())));
            default:
                return {};
        }
    }

    // Other roles not supported
    return {};
}

QVariant DepartmentTable::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return QString("Inquiry ID");
            case 1:
                return QString("User");
            case 2:
                return QString("Description");
            case 3:
                return QString("Department");
            case 4:
                return QString("Status");
            case 5:
                return QString("Urgency Level");
            default:
                return QVariant();
        }
    } else if (orientation == Qt::Vertical) {
        return QString(">");
    }
    return QVariant();
}

void DepartmentTable::resetModel() {
    this->beginResetModel();
    this->endResetModel();
}

// Agent Inquiries Table Model Implementation
int AgentTable::rowCount(const QModelIndex &parent) const {
    return this->controller->getProcessingByAgentSize(this->agent);
}

int AgentTable::columnCount(const QModelIndex &parent) const {
    return 6;
}

QVariant AgentTable::data(const QModelIndex &index, int role) const {
    // Validate Index
    if (!index.isValid() || index.row() < 0 || index.row() >= rowCount() || index.column() < 0 || index.column() >= columnCount()) {

        // Invalid Index
        return {};
    }

    // Display Role
    if (role == Qt::DisplayRole) {
        int row = index.row();
        int col = index.column();

        // Get the range of agent's inquiries
        auto [begin, end] = this->controller->getProcessingByAgent(agent);

        // Out of bounds
        if (row >= std::distance(begin, end)) {
            return {};
        }

        // Get the inquiry from the range
        auto inquiry = *(begin + row);

        // Populating table column data
        switch (col) {
            case 0: return QVariant::fromValue(QString::fromStdString(std::to_string(inquiry.getInquiryID())));
            case 1: return QVariant::fromValue(QString::fromStdString(inquiry.getUser()->getUsername()));
            case 2: return QVariant::fromValue(QString::fromStdString(inquiry.getDescription()));
            case 3: return QVariant::fromValue(QString::fromStdString(toString(inquiry.getAssignedDepartment())));
            case 4: return QVariant::fromValue(QString::fromStdString(toString(inquiry.getStatus())));
            case 5: return QVariant::fromValue(QString::fromStdString(toString(inquiry.getUrgencyLevel())));
            default:
                return {};
        }
    }

    // Other roles not supported
    return {};
}

QVariant AgentTable::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return QString("Inquiry ID");
            case 1:
                return QString("User");
            case 2:
                return QString("Description");
            case 3:
                return QString("Department");
            case 4:
                return QString("Status");
            case 5:
                return QString("Urgency Level");
            default:
                return QVariant();
        }
    } else if (orientation == Qt::Vertical) {
        return QString(">");
    }
    return QVariant();
}

void AgentTable::resetModel() {
    this->beginResetModel();
    this->endResetModel();
}
