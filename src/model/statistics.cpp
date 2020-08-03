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
}

int Statistics::getShotsScored() const
{
    return shotsScored;
}

void Statistics::setShotsScored(int value)
{
    shotsScored = value;
}

int Statistics::getShotsNum() const
{
    return shotsNum;
}

void Statistics::setShotsNum(int value)
{
    shotsNum = value;
}

int Statistics::getOffensiveRebounds() const
{
    return offensiveRebounds;
}

void Statistics::setOffensiveRebounds(int value)
{
    offensiveRebounds = value;
}

int Statistics::getDefensiveRebounds() const
{
    return defensiveRebounds;
}

void Statistics::setDefensiveRebounds(int value)
{
    defensiveRebounds = value;
}

int Statistics::getSteals() const
{
    return steals;
}

void Statistics::setSteals(int value)
{
    steals = value;
}

int Statistics::getAssists() const
{
    return assists;
}

void Statistics::setAssists(int value)
{
    assists = value;
}

int Statistics::getBlocks() const
{
    return blocks;
}

void Statistics::setBlocks(int value)
{
    blocks = value;
}

int Statistics::getTurnovers() const
{
    return turnovers;
}

void Statistics::setTurnovers(int value)
{
    turnovers = value;
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
}
