#include "mainmodel.h"
#include "model/player.h"
#include <QDebug>

MainModel::MainModel(QObject *parent) : QObject(parent)
{
    teams[0] = new Team();
    teams[1] = new Team();

    QList<Player *> playerList;
    playerList.append(new Player("Ivo", "Ivic", 15, teams[0]));
    playerList.append(new Player("Marko", "Markic", 11, teams[0]));
    playerList.append(new Player("Jure", "Juric", 13, teams[0]));
    playerList.append(new Player("Fran", "Jovic", 12, teams[0]));

    teams[0]->setPlayerList(playerList);

    QList<Player *> playerList2;
    playerList2.append(new Player("Sandro", "Sandric", 4, teams[1]));

    teams[1]->setPlayerList(playerList2);

    playerModel.setPlayerList(teams[0]->getPlayerList());
    setSelectedPlayer(playerModel.getPlayerAt(0));

    connect(this, SIGNAL(refreshList()), &playerModel, SLOT(onRefresh()));
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

void MainModel::onShotAdded(Shot* shot)
{
    Shot* newShot = new Shot();
    newShot->x = shot->x;
    newShot->y = shot->y;
    newShot->isMiss = shot->isMiss;
    selectedPlayer->addShot(newShot);
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

void MainModel::onSelectedTeamChanged(const int &index)
{
    playerModel.setPlayerList(teams[index]->getPlayerList());
    setSelectedPlayer(playerModel.getPlayerAt(0));
    emit refreshList();
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





