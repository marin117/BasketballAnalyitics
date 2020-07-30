#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include <vector>
#include "shot.h"
#include <QObject>
#include "basemodel.h"

class Statistics;

class Player : public BaseModel
{
    Q_OBJECT
public:
    Player(QObject *parent = nullptr);
    Player(const QString &name, const QString &surname,const int &number, QObject *parent = nullptr);
    Q_INVOKABLE QString getName() const;
    void setName(const QString &value);

    QString getSurname() const;
    void setSurname(const QString &value);

    int getNumber() const;
    void setNumber(int value);

//    const QList<Shot>& getShots() const;
//    void setShots(const QList<Shot> &value);
    void addShot(Shot* shot);
//    void undoShot();

    QList<Shot *>* getShots();
    void setShots(const QList<Shot *> &value);

    Statistics *getStatistics() const;
    void setStatistics(Statistics *value);

private:
    QString name = "";
    QString surname = "";
    int number = 0;
    QList<Shot *> shots;
    Statistics *statistics;


    // BaseModel interface
public:
    void readFromJson(const QJsonObject &) override;
    void writeToJson(QJsonObject &) override;
};

#endif // PLAYER_H
