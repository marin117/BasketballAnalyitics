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


void Team::readFromJson(const QJsonObject &json)
{
    if(json.contains("name") && json["name"].isString())
        name = json["name"].toString();

    if(json.contains("statistics") && json["statistics"].isObject()){
        QJsonObject statsJson = json["statistics"].toObject();
        auto stats = new TeamStatistics(this);
        stats->readFromJson(statsJson);
        this->statistics = stats;
    }

    if(json.contains("players") && json["players"].isArray()){
        QJsonArray playersArray = json["players"].toArray();
        playerList.reserve(playersArray.size());
        for(int i = 0; i < playersArray.size(); i++){
            QJsonObject player= playersArray[i].toObject();
            auto p = new Player(this);
            p->readFromJson(player);
            playerList.append(p);
        }

    }
}

void Team::writeToJson(QJsonObject &json)
{
    QJsonArray playersArray;

    json["name"] = name;

    QJsonObject statisticsJson;
    statistics->writeToJson(statisticsJson);
    json["statistics"] = statisticsJson;

    for(auto player : playerList){
        QJsonObject playerJson;
        player->writeToJson(playerJson);
        playersArray.append(playerJson);
    }
    json["players"] = playersArray;
}
