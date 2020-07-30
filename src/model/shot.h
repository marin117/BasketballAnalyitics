#ifndef SHOOTMODEL_H
#define SHOOTMODEL_H
#include <QObject>
#include "basemodel.h"

class Shot : public BaseModel
{
    Q_OBJECT

    Q_PROPERTY(bool isMiss MEMBER isMiss)
    Q_PROPERTY(int x MEMBER x)
    Q_PROPERTY(int y MEMBER y)
public:
    Shot(QObject *parent = nullptr);
    Shot(const bool& isMiss, const bool& isContested, const bool& isThreePoints, const int& x, const int& y, QObject *parent = nullptr);
    bool isMiss = false;
    bool isContested = false;
    bool isThreePoints = false;
    int x;
    int y;

    // BaseModel interface
public:
    void readFromJson(const QJsonObject &) override;
    void writeToJson(QJsonObject &) override;
};

#endif // SHOOTMODEL_H
