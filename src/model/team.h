#ifndef TEAM_H
#define TEAM_H

#include <QObject>
#include "basemodel.h"

class Statistics;
class Player;

class Team : public BaseModel
{
    Q_OBJECT
public:
    explicit Team(QObject *parent = nullptr);

    QList<Player *> getPlayerList() const;

    void setPlayerList(const QList<Player *> &value);

    QString getName() const;
    void setName(const QString &value);

    Statistics *getStatistics() const;
    void setStatistics(Statistics *value);

signals:

private:
    QString name;
    QList<Player *> playerList;
    Statistics *statistics;


    // BaseModel interface
public:
    void readFromJson(const QJsonObject &) override;
    void writeToJson(QJsonObject &) override;
};

#endif // TEAM_H
