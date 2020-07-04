#include "statistics.h"

Statistics::Statistics(QObject *parent) : QObject(parent)
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

int Statistics::getAssits() const
{
    return assits;
}

void Statistics::setAssits(int value)
{
    assits = value;
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