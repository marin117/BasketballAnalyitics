#include "mainmodel.h"
#include "model/player.h"
#include <QDebug>

MainModel::MainModel(QObject *parent) : QObject(parent)
{
    QList<Player> playerList;
    playerList.append(Player("Ivo", "Ivic", 15));
    playerList.append(Player("Marko", "Markic", 11));
    playerList.append(Player("Jure", "Juric", 13));
    playerList.append(Player("Fran", "Jovic", 12));

    playerModel.setPlayerList(playerList);
}

PlayerTableModel* MainModel::getPlayerModel()
{
    return &playerModel;
}

int MainModel::getSelectedPlayer() const
{
    return selectedPlayer;
}

void MainModel::setSelectedPlayer(int value)
{
    selectedPlayer = value;
}

void MainModel::onSelectedPlayerChanged(const int &pos)
{
    setSelectedPlayer(pos);
    qDebug() << playerModel.getPlayerAt(pos)->getName();
    emit selectedPlayerChanged();
}

