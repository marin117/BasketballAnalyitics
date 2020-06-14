#include "team.h"

Team::Team(QObject *parent) : QObject(parent)
{

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
