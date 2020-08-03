#include "team.h"
#include "teamstatistics.h"
#include <QJsonArray>
#include "player.h"

Team::Team(QObject *parent) : BaseModel(parent)
{
    statistics = new TeamStatistics(this);
}

QList<Player *> Team::getPlayerList() const
{
    return playerList;
}

void Team::setPlayerList(const QList<Player *> &value)
{
    playerList = value;
}

QString Team::getName() const
{
    return name;
}

void Team::setName(const QString &value)
{
    name = value;
}

Statistics *Team::getStatistics() const
{
    return statistics;
}

void Team::setStatistics(Statistics *value)
{
    statistics = value;
}


void Team::readFromJson(const QJsonObject &)
{
}

void Team::writeToJson(QJsonObject &json)
{
    QJsonArray playersArray;

    for(auto player : playerList){
        QJsonObject playerJson;
        player->writeToJson(playerJson);
        playersArray.append(playerJson);
    }
    json["players"] = playersArray;
}
