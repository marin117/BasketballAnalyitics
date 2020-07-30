#ifndef BASEMODEL_H
#define BASEMODEL_H
#include <QObject>
#include <QJsonObject>

class BaseModel : public QObject
{
    Q_OBJECT
public:
    explicit BaseModel(QObject *parent = nullptr) : QObject(parent){}

    virtual void readFromJson(const QJsonObject&) = 0;
    virtual void writeToJson(QJsonObject&) = 0;


};
#endif // BASEMODEL_H
