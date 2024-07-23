#ifndef CUSTOMER_SUPPORT_ASSISTANT_AIMODEL_H
#define CUSTOMER_SUPPORT_ASSISTANT_AIMODEL_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <string>
// Qt Libraries
#include <QObject>
#include <QCoreApplication>
#include <QNetworkAccessManager>
// Project Libraries
#include "UrgencyLevel.h"
#include "Department.h"
#include "Inquiry.h"


////////////////////////
/// CLASS DEFINITION ///
///////////////////////
// AI Model Class
class AIModel : public QObject {
Q_OBJECT
private:

    // Network Elements
    QNetworkAccessManager *manager;
    QString apiKey;
    QUrl requestUrl;

    // Prompt Elements
    std::vector<std::string> departments;
    std::vector<std::string> urgencies;

    // Request - Inquiry Map
    std::unordered_map<QNetworkReply*, Inquiry> inquiriesMap;

private slots:
    void onFinished(QNetworkReply *reply);

public:
    explicit AIModel(QObject *parent = nullptr);
    ~AIModel();
    void setDepartments(std::vector<std::string> departments);
    void setUrgencies(std::vector<std::string> urgencies);
    void sendRequest(const Inquiry& inquiry);

signals:
    void isClassified(std::pair<Inquiry, std::pair<UrgencyLevel, Department>> reply);
};

#endif
