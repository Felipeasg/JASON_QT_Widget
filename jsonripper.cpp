#include "jsonripper.h"

#include <iostream>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

using namespace std;

JsonRipper::JsonRipper(const QByteArray JsonFile)
{
    JsonFile_ = JsonFile;
}

void JsonRipper::print()
{
    QJsonDocument loadDoc(QJsonDocument::fromJson(JsonFile_));
    QJsonObject jsonObj = loadDoc.object();

    std::string utf8_text = jsonObj["FirstName"].toString().toUtf8().constData();
    cout << utf8_text << endl;
}

