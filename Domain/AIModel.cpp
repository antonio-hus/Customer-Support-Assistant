/////////////////////////////
/// NOTES - PROMPT DESIGN ///
/////////////////////////////
/**
    PROMPT DESIGN

    SYSTEM:
    You are a bank customer support classifier agent. You will recieve the inquiry and you will output the most appropiate department to assign to and the appropiate urgency level.
    You will only write the department followed by a new line and the urgency level !

    Departments active today are: ( LIST OF DEPARTMENTS )
    - IT Support
    - HR
    - Business Banking
    - ...

    Urgency levels today are: ( LIST OF URGENCY LEVELS )
    - Low
    - Medium
    - High
    - Critical

    User:
    - inquiry

    RETURN VALUE:
    DEPARTMENT \n URGENCY
 **/

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <iostream>
#include <sstream>
// Qt Libraries
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <utility>
// Project Libraries
#include "AIModel.h"


////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
/// AI Model Class
// Constructor
AIModel::AIModel(QObject *parent)
        : QObject(parent),
          manager(new QNetworkAccessManager(this)),
          apiKey(std::getenv("GROQ_API_KEY")),
          requestUrl("https://api.groq.com/openai/v1/chat/completions") {

    // Connect the finished signal of QNetworkReply to the slot
    connect(manager, &QNetworkAccessManager::finished, this, &AIModel::onFinished);
}

// Destructor
AIModel::~AIModel() {
    delete this->manager;
}

// Class Methods
void AIModel::setDepartments(std::vector<std::string> departmentList) {
    this->departments = std::move(departmentList);
}

void AIModel::setUrgencies(std::vector<std::string> urgencyList) {
    this->urgencies = std::move(urgencyList);
}

void AIModel::sendRequest(const Inquiry& inquiry) {
    // Create a network request
    QNetworkRequest request(requestUrl);

    // Set headers
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer " + apiKey.toUtf8());

    // Create JSON data
    QJsonObject jsonObject;
    jsonObject["model"] = "llama3-8b-8192";

    std::string systemPrompt = "You are a bank customer support classifier agent."
                               "You will recieve the inquiry and you will output the most appropiate department to assign to and the appropiate urgency level."
                               "You will only write the department followed by a new line and the urgency level.\n";
    systemPrompt += "\nDepartments List:\n";
    for (const auto& department : departments) {
        systemPrompt += department + "\n";
    }
    systemPrompt += "\nUrgency Levels List:\n";
    for (const auto& urgency : urgencies) {
        systemPrompt += urgency + "\n";
    }

    QJsonArray messagesArray;
    QJsonObject systemMessageObject;
    systemMessageObject["role"] = "system";
    systemMessageObject["content"] = QString::fromStdString(systemPrompt);
    messagesArray.append(systemMessageObject);

    QJsonObject userMessageObject;
    userMessageObject["role"] = "user";
    userMessageObject["content"] = QString::fromStdString(inquiry.getDescription());
    messagesArray.append(userMessageObject);

    jsonObject["messages"] = messagesArray;

    QJsonDocument jsonDoc(jsonObject);
    QByteArray postData = jsonDoc.toJson();

    // Send the POST request
    QNetworkReply* reply = manager->post(request, postData);

    // Map the inquiry to the request
    inquiriesMap.insert(std::make_pair(reply, inquiry));
}

void AIModel::onFinished(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {

        // Handle network error
        reply->deleteLater();
        return;
    }

    // Read Response Data
    QByteArray responseData = reply->readAll();
    QString responseString(responseData);

    // Response format shall be: DEPARTMENT \n URGENCY
    QStringList responseLines = responseString.split('\n');
    if (responseLines.size() != 2) {

        // Handle invalid response format
        reply->deleteLater();
        return;
    }

    // Get Urgency and Department from String
    std::string departmentStr = responseLines[0].toStdString();
    std::string urgencyStr = responseLines[1].toStdString();

    UrgencyLevel urgency = urgencyFromString(urgencyStr);
    Department department = departmentFromString(departmentStr);

    // Get the original inquiry
    auto it = inquiriesMap.find(reply);
    if (it == inquiriesMap.end()) {
        qDebug() << "Inquiry not found.";
        reply->deleteLater();
        return;
    }

    Inquiry inquiry = it->second;
    inquiriesMap.erase(it);

    // Emit signal with the received pair
    emit isClassified(std::make_pair(inquiry, std::make_pair(urgency, department)));

    // Clean-up response
    reply->deleteLater();
}