#include "mainmodel.h"
#include "model/player.h"
#include <QDebug>

MainModel::MainModel(QObject *parent) : QObject(parent)
{
    QList<Player *> playerList;
    playerList.append(new Player("Ivo", "Ivic", 15));
    playerList.append(new Player("Marko", "Markic", 11));
    playerList.append(new Player("Jure", "Juric", 13));
    playerList.append(new Player("Fran", "Jovic", 12));

    playerModel.setPlayerList(playerList);
    setSelectedPlayer(playerModel.getPlayerAt(0));
}

PlayerTableModel* MainModel::getPlayerModel()
{
    return &playerModel;
}


QString MainModel::getSelectedPlayerName()
{
    return selectedPlayer->getName();
}

QList<Shot *> MainModel::getSelectedPlayerShots()
{
    return *selectedPlayer->getShots();
}

void MainModel::onSelectedPlayerChanged(const int &pos)
{
    setSelectedPlayer(playerModel.getPlayerAt(pos));
    qDebug() << selectedPlayer->getName();
    emit selectedPlayerChanged();
}

void MainModel::onShotAdded(const int &x, const int &y)
{
    Shot* shot = new Shot();
    shot->x = x;
    shot->y = y;
    selectedPlayer->addShot(shot);
    for(auto i : *selectedPlayer->getShots()){
        qDebug() << i->getX() << "  " << i->getY();
    }
}

Player *MainModel::getSelectedPlayer() const
{
    return selectedPlayer;
}

void MainModel::setSelectedPlayer(Player *value)
{
    selectedPlayer = value;
}

QQmlListProperty<Shot> MainModel::selectedShots()
{
    return QQmlListProperty<Shot>(this, *selectedPlayer->getShots());
}

int MainModel::shotsCount() const
{
    return selectedPlayer->getShots()->size();
}

Shot *MainModel::shotAt(int i) const
{
    return selectedPlayer->getShots()->at(i);
}


int MainModel::shotsCount(QQmlListProperty<Shot>* list) {
    return reinterpret_cast< MainModel* >(list->data)->shotsCount();
}

Shot* MainModel::shotAt(QQmlListProperty<Shot>* list, int i)
{
    return reinterpret_cast< MainModel* >(list->data)->shotAt(i);
}





