#include "team.h"
#include "teamstatistics.h"

Team::Team(QObject *parent) : QObject(parent)
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
