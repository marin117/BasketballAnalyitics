#include "mainmodel.h"
#include "model/player.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include "model/playerstatistics.h"

MainModel::MainModel(QObject *parent) : QObject(parent)
{
    playerModel = new PlayerListModel(this);
    connect(this, SIGNAL(refreshList()), playerModel, SLOT(onRefresh()));

    teams[0] = new Team(this);
    teams[1] = new Team(this);

    QList<Player *> pl1;
    QList<Player *> pl2;


    pl1.append(new Player("Fran", "Jovic", 10, this));
    pl1.append(new Player("Ivan", "Zebec", 5, this));
    pl2.append(new Player("Marko", "Matoc", 7, this));
    pl2.append(new Player("Duje", "Strukan", 4, this));

    teams[0]->setPlayerList(pl1);
    teams[1]->setPlayerList(pl2);
    playerModel->setPlayerList(pl1);
    onSelectedPlayerChanged(0);
}

PlayerListModel* MainModel::getPlayerModel()
{
    return playerModel;
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
    if(!playerModel->getPlayerList().size())
        return;
    setSelectedPlayer(playerModel->getPlayerAt(pos));
    qDebug() << selectedPlayer->getName();
    emit selectedPlayerChanged();
}

void MainModel::onShotAdded(Shot* shot)
{
    Shot* newShot = new Shot();

    copyShot(newShot, shot);
    selectedPlayer->addShot(newShot);

    selectedTeamStatistics()->setShotsNum(selectedTeamStatistics()->getShotsNum() + 1);

    if(!shot->isMiss){
        if(!shot->isThreePoints)
            selectedTeamStatistics()->setPoints(selectedTeamStatistics()->getPoints() + 2);
        else
            selectedTeamStatistics()->setPoints(selectedTeamStatistics()->getPoints() + 3);
        selectedTeamStatistics()->setShotsScored(selectedTeamStatistics()->getShotsScored() + 1);
    }
    emit teamStatisticsChanged();
    emit playerStatisticsChanged();
}

void MainModel::onShotUndo(){
    if(selectedPlayer->getShots()->isEmpty())
        return;
    auto shot = selectedPlayer->getShots()->last();
    if(!shot->isMiss){
        if(!shot->isThreePoints)
            selectedTeamStatistics()->setPoints(selectedTeamStatistics()->getPoints() - 2);
        else
            selectedTeamStatistics()->setPoints(selectedTeamStatistics()->getPoints() - 3);
        selectedTeamStatistics()->setShotsScored(selectedTeamStatistics()->getShotsScored() - 1);
    }
    selectedPlayer->popShot();
    emit teamStatisticsChanged();
    emit playerStatisticsChanged();
}

void MainModel::copyShot(Shot *newShot, Shot *shot){
    newShot->x = shot->x;
    newShot->y = shot->y;

    newShot->isMiss = shot->isMiss;
    newShot->isOffhand = shot->isOffhand;
    newShot->isOffTheDribble = shot->isOffTheDribble;
    newShot->isCatchAndShoot = shot->isCatchAndShoot;
    newShot->isPickAndRoll = shot->isPickAndRoll;
    newShot->isPickAndPop = shot->isPickAndPop;
    newShot->isPost = shot->isPost;
    newShot->isMismatch = shot->isMismatch;
    newShot->isIso = shot->isIso;
    newShot->isLayup = shot->isLayup;
    newShot->isFaul = shot->isFaul;
    newShot->isTransition = shot->isTransition;
    newShot->isThreePoints = shot->isThreePoints;
    newShot->isContested = shot->isContested;
    newShot->isClutch = shot->isClutch;
    newShot->isDunk = shot->isDunk;
}

void MainModel::onWidthChanged(const int &width, const int &prevWidth)
{
    for(auto team : teams){
        for(auto player : team->getPlayerList()){
            for(int i = 0; i < player->getShots()->size(); i++){
                int newX = player->getShots()->at(i)->x * width / prevWidth;
                player->getShots()->at(i)->x = newX;
            }
        }
    }
}

void MainModel::onHeightChanged(const int& height, const int& prevHeight){
    for(auto team : teams){
        for(auto player : team->getPlayerList()){
            for(int i = 0; i < player->getShots()->size(); i++){
                int newY = player->getShots()->at(i)->y * height / prevHeight;
                player->getShots()->at(i)->y = newY;
            }
        }
    }
}

void MainModel::onSelectedTeamChanged(const int &index)
{
    if(!teams[index])
        return;
    playerModel->setPlayerList(teams[index]->getPlayerList());
    if(playerModel->getPlayerList().size())
        setSelectedPlayer(playerModel->getPlayerAt(0));
    selectedTeamIndex = index;
    emit teamStatisticsChanged();
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
    return QQmlListProperty<Shot>(this, selectedPlayer->getShots());
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

Statistics *MainModel::selectedPlayerStatistics()
{
    if(selectedPlayer)
        return selectedPlayer->getStatistics();
    return new Statistics(this);
}

Statistics *MainModel::selectedTeamStatistics()
{
    if(teams[selectedTeamIndex])
        return teams[selectedTeamIndex]->getStatistics();
    return new Statistics(this);
}

void MainModel::exportTeams(const QString& filename)
{
    if (!QDir("tmp").exists()){
        QDir().mkdir("tmp");
    }
    QJsonObject json;
    QJsonArray teamsArray;
    for(auto team : teams){
        if(!team)
            break;
        QJsonObject teamJson;
        team->writeToJson(teamJson);
        teamsArray.append(teamJson);

    }
    json["teams"] = teamsArray;
    qDebug() << json;
    QUrl url = QDir("tmp").filePath(filename);
    QFile saveFile(url.toString());

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return;
    }

    saveFile.write(QJsonDocument(json).toJson());
}

void MainModel::importTeams(const QUrl &url)
{
    QFile loadFile(url.toLocalFile());

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qDebug() << loadFile.errorString();
        qWarning("Couldn't open save file.");
        return;
    }

    QByteArray saveData = loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    QJsonObject loadObj = loadDoc.object();

    QJsonArray teamsArray = loadObj["teams"].toArray();

    for(int i = 0; i < teamsArray.size(); i++){
        QJsonObject teamJson = teamsArray[i].toObject();
        teams[i] = new Team(this);
        teams[i]->readFromJson(teamJson);
    }
    playerModel->setPlayerList(teams[0]->getPlayerList());

    refreshList();
    if(playerModel->getPlayerList().size())
        setSelectedPlayer(playerModel->getPlayerAt(0));

    onSelectedPlayerChanged(0);
}





