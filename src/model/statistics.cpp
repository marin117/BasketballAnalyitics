#include "statistics.h"
#include "shot.h"

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
    if(value < freeThrowsMade){
        setPoints(points - 1);
    }
    else {
        setFreeThrows(freeThrows + 1);
        setPoints(points + 1);
    }
    freeThrowsMade = value;
    emit freeThrowsMadeChanged();
}

int Statistics::getFreeThrows() const
{
    return freeThrows;
}

void Statistics::setFreeThrows(int value)
{
    if(value + 1 == freeThrowsMade){
        freeThrowsMade -= 1;
        points -= 1;
        emit pointsChanged();
        emit freeThrowsMadeChanged();
    }
    freeThrows = value;
    emit freeThrowsChanged();

}

int Statistics::getFouls() const
{
    return fouls;
}

void Statistics::setFouls(int value)
{
    fouls = value;
    emit foulsChanged();
}

int Statistics::getThreePointsMade() const
{
    return threePointsMade;
}

void Statistics::setThreePointsMade(int value)
{
    threePointsMade = value;
    emit threePointsMadeChanged();
}

int Statistics::getThreePointsNum() const
{
    return threePointsNum;
}

void Statistics::setThreePointsNum(int value)
{
    threePointsNum = value;
    emit threePointsNumChanged();
}

void Statistics::addPoints(const Shot *shot)
{
    setShotsNum(shotsNum + 1);

    if (!shot->isMiss){
        if(!shot->isThreePoints)
            setPoints(points + 2);
        else{
            setPoints(points + 3);
            setThreePointsMade(threePointsMade + 1);
            setThreePointsNum(threePointsNum + 1);
        }
        setShotsScored(getShotsScored() + 1);
    }
    else{
        if(shot->isThreePoints)
            setThreePointsNum(threePointsNum + 1);
    }
}

void Statistics::popPoints(const Shot *shot)
{
    setShotsNum(shotsNum - 1);
    if (!shot->isMiss){
        if(!shot->isThreePoints)
            setPoints(points - 2);
        else{
            setPoints(points - 3);
            setThreePointsMade(threePointsMade - 1);
            setThreePointsNum(threePointsNum - 1);
        }
        setShotsScored(shotsScored - 1);
    }
    else{
        if(shot->isThreePoints){
            setThreePointsNum(threePointsNum - 1);
        }
    }
}

void Statistics::readFromJson(const QJsonObject &json)
{
    if(json.contains("points") && json["points"].isDouble()){
        points = json["points"].toInt();
    }
    if(json.contains("shotsScored") && json["shotsScored"].isDouble()){
        shotsScored = json["shotsScored"].toInt();
    }
    if(json.contains("shotsNum") && json["shotsNum"].isDouble()){
        shotsNum = json["shotsNum"].toInt();
    }
    if(json.contains("offensiveRebounds") && json["offensiveRebounds"].isDouble()){
        offensiveRebounds = json["offensiveRebounds"].toInt();
    }
    if(json.contains("defensiveRebounds") && json["defensiveRebounds"].isDouble()){
        defensiveRebounds = json["defensiveRebounds"].toInt();
    }
    if(json.contains("steals") && json["steals"].isDouble()){
        steals = json["steals"].toInt();
    }
    if(json.contains("assists") && json["assists"].isDouble()){
        assists = json["assists"].toInt();
    }
    if(json.contains("blocks") && json["blocks"].isDouble()){
        blocks = json["blocks"].toInt();
    }
    if(json.contains("turnovers") && json["turnovers"].isDouble()){
        turnovers = json["turnovers"].toInt();
    }
    if(json.contains("freeThrows") && json["freeThrows"].isDouble()){
        freeThrows = json["freeThrows"].toInt();
    }
    if(json.contains("freeThrowsMade") && json["freeThrowsMade"].isDouble()){
        freeThrowsMade = json["freeThrowsMade"].toInt();
    }
    if(json.contains("fouls") && json["fouls"].isDouble()){
        fouls = json["fouls"].toInt();
    }
    if(json.contains("threePointsMade") && json["threePointsMade"].isDouble()){
        threePointsMade = json["threePointsMade"].toInt();
    }
    if(json.contains("threePointsNum") && json["threePointsNum"].isDouble()){
        threePointsNum = json["threePointsNum"].toInt();
    }
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
    json["fouls"] = fouls;
    json["rebounds"] = offensiveRebounds + defensiveRebounds;
    if(freeThrows > 0) json["FTpct"] = freeThrowsMade / freeThrows;
    else json["FTpct"] = 0;
    json["threePointsNum"] = threePointsNum;
    json["threePointsMade"] = threePointsMade;
}



