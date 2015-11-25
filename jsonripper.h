#ifndef JSONRIPPER_H
#define JSONRIPPER_H

#include <QJsonDocument>

class JsonRipper
{
public:
    JsonRipper(const QByteArray JsonFile);

    void print();

private:
    QByteArray JsonFile_;
};

#endif // JSONRIPPER_H
