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

PlayerListModel* MainModel::getPlayerModel()
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
}

void MainModel::onWidthChanged(const int &width, const int &prevWidth)
{
    for(auto player : playerModel.getPlayerList()){
        for(int i = 0; i < player->getShots()->size(); i++){
            int newX = player->getShots()->at(i)->getX() * width / prevWidth;
            player->getShots()->at(i)->setX(newX);
        }
    }
}

void MainModel::onHeightChanged(const int& height, const int& prevHeight){
    for(auto player : playerModel.getPlayerList()){
        for(int i = 0; i < player->getShots()->size(); i++){
            int newY = player->getShots()->at(i)->getY() * height / prevHeight;
            player->getShots()->at(i)->setY(newY);
        }
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





