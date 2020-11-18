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

    teams[0]->setName("Team 1");
    teams[1]->setName("Team 2");
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

void MainModel::onSelectedPlayerChanged(const int &pos)
{
    if(!playerModel->getPlayerList().size())
        return;
    setSelectedPlayer(playerModel->getPlayerAt(pos));
    emit selectedPlayerChanged();
}

void MainModel::onShotAdded(Shot* shot)
{
    Shot* newShot = new Shot();

    copyShot(newShot, shot);
    selectedPlayer->addShot(newShot);
    selectedTeamStatistics()->addPoints(shot);
    playerSelectedQuarterStatistics()->addPoints(shot);

    emit teamStatisticsChanged();
    emit playerStatisticsChanged();
}

void MainModel::onShotUndo(){
    if(selectedPlayer->getShots()->isEmpty())
        return;
    auto shot = selectedPlayer->getShots()->last();

    selectedTeamStatistics()->popPoints(shot);
    selectedPlayer->popShot();
    auto &shotQuarterStatistics = selectedPlayer->getQuarterStatistics().at(shot->quarter);
    shotQuarterStatistics->popPoints(shot);
    emit teamStatisticsChanged();
    emit playerStatisticsChanged();
}

void MainModel::copyShot(Shot *newShot, Shot *shot){
    newShot->x = shot->x;
    newShot->y = shot->y;
    newShot->quarter = selectedQuarter;

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
    newShot->isFloater = shot->isFloater;
    newShot->isEurostep = shot->isEurostep;
    newShot->isPutback = shot->isPutback;
    newShot->isSecondChance = shot->isSecondChance;
    newShot->isOffTurnover = shot->isOffTurnover;
    newShot->isFadeaway = shot->isFadeaway;
    newShot->isStepback = shot->isStepback;
    newShot->isDrive = shot->isDrive;
    newShot->isReverse = shot->isReverse;
    newShot->isRoll = shot->isRoll;
    newShot->isUpAndUnder = shot->isUpAndUnder;
    newShot->isHookshot = shot->isHookshot;
    newShot->isTurnaround = shot->isTurnaround;
    newShot->isCut = shot->isCut;
    newShot->isScreenAssisted = shot->isScreenAssisted;
    newShot->isAssisted = shot->isAssisted;
    newShot->isBlocked = shot->isBlocked;
    newShot->isShot = shot->isShot;
}

QString MainModel::getNotes() const
{
    return notes;
}

void MainModel::setNotes(const QString &value)
{
    notes = value;
}

Team *MainModel::getTeam1() const
{
    return teams[0];
}


Team *MainModel::getTeam2() const
{
    return teams[1];
}

int MainModel::getSelectedQuarter() const
{
    return selectedQuarter;
}

void MainModel::setSelectedQuarter(int value)
{
    selectedQuarter = value;
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

Statistics *MainModel::playerSelectedQuarterStatistics()
{
    if(selectedPlayer && selectedQuarter < selectedPlayer->getQuarterStatistics().size())
        return selectedPlayer->getQuarterStatistics()[selectedQuarter];
    return new Statistics(this);
}


void MainModel::exportData(const QString& filename)
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

    json["notes"] = notes;

    saveFile.write(QJsonDocument(json).toJson());
}

void MainModel::importData(const QUrl &url)
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

    if(loadObj.contains("notes") && loadObj["notes"].isString()){
        notes = loadObj["notes"].toString();
        emit notesChanged();
    }
    onSelectedPlayerChanged(0);
    team1Changed();
    team2Changed();
}



