#include "statistics.h"

Statistics::Statistics(QObject *parent) : BaseModel(parent)
{

}

int Statistics::getPoints() const
{
    return points;
}

void Statistics::setPoints(int value)
{
    points = value;
    emit pointsChanged();
}

int Statistics::getShotsScored() const
{
    return shotsScored;
}

void Statistics::setShotsScored(int value)
{
    shotsScored = value;
    emit shotsScoredChanged();
}

int Statistics::getShotsNum() const
{
    return shotsNum;
}

void Statistics::setShotsNum(int value)
{
    shotsNum = value;
    emit shotsNumChanged();
}

int Statistics::getOffensiveRebounds() const
{
    return offensiveRebounds;
}

void Statistics::setOffensiveRebounds(int value)
{
    offensiveRebounds = value;
    emit offensiveReboundsChanged();
}

int Statistics::getDefensiveRebounds() const
{
    return defensiveRebounds;
}

void Statistics::setDefensiveRebounds(int value)
{
    defensiveRebounds = value;
    emit defensiveReboundsChanged();
}

int Statistics::getSteals() const
{
    return steals;
}

void Statistics::setSteals(int value)
{
    steals = value;
    emit stealsChanged();
}

int Statistics::getAssists() const
{
    return assists;
}

void Statistics::setAssists(int value)
{
    assists = value;
    emit assistsChanged();
}

int Statistics::getBlocks() const
{
    return blocks;
}

void Statistics::setBlocks(int value)
{
    blocks = value;
    emit blocksChanged();
}

int Statistics::getTurnovers() const
{
    return turnovers;
}

void Statistics::setTurnovers(int value)
{
    turnovers = value;
    emit turnoversChanged();
}

int Statistics::getFreeThrowsMade() const
{
    return freeThrowsMade;
}

void Statistics::setFreeThrowsMade(int value)
{
    freeThrowsMade = value;
    setFreeThrows(freeThrows + 1);
    setPoints(points + 1);
    emit freeThrowsMadeChanged();
}

int Statistics::getFreeThrows() const
{
    return freeThrows;
}

void Statistics::setFreeThrows(int value)
{
    freeThrows = value;
    emit freeThrowsChanged();
}


void Statistics::readFromJson(const QJsonObject &)
{
}

void Statistics::writeToJson(QJsonObject &json)
{
    json["points"] = points;
    json["shotsScored"] = shotsScored;
    json["shotsNum"] = shotsNum;
    json["offensiveRebounds"] = offensiveRebounds;
    json["defensiveRebounds"] = defensiveRebounds;
    json["steals"] = steals;
    json["assists"] = assists;
    json["blocks"] = blocks;
    json["turnovers"] = turnovers;
    json["freeThrowsMade"] = freeThrowsMade;
    json["freeThrows"] = freeThrows;

}
