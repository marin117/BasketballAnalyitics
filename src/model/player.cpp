#include "player.h"
#include "playerstatistics.h"
#include <QJsonArray>

Player::Player(QObject *parent) : BaseModel(parent)
{
    statistics = new PlayerStatistics(this);
}

Player::Player(const QString &name, const QString &surname,const int &number, QObject *parent) :
    name(name), surname(surname), number(number), BaseModel(parent)
{
    statistics = new PlayerStatistics(this);
}

QString Player::getName() const
{
    return name;
}

void Player::setName(const QString &value)
{
    name = value;
}

QString Player::getSurname() const
{
    return surname;
}

void Player::setSurname(const QString &value)
{
    surname = value;
}

int Player::getNumber() const
{
    return number;
}

void Player::setNumber(int value)
{
    number = value;
}

QList<Shot *>* Player::getShots()
{
    return &shots;
}

void Player::setShots(const QList<Shot *> &value)
{
    shots = value;
}

Statistics *Player::getStatistics() const
{
    return statistics;
}

void Player::setStatistics(Statistics *value)
{
    statistics = value;
}


void Player::addShot(Shot *shot)
{
    shots.push_back(shot);
    if (!shot->isMiss)
        statistics->setPoints(statistics->getPoints() + 2);
}


void Player::readFromJson(const QJsonObject &)
{
}

void Player::writeToJson(QJsonObject &json)
{
    json["name"] = name;
    json["surname"] = surname;
    json["number"] = number;

    QJsonObject statisticsJson;
    statistics->writeToJson(statisticsJson);
    json["statistics"] = statisticsJson;

    QJsonArray shotsArray;
    for(auto shot : shots){
        QJsonObject shotJson;
        shot->writeToJson(shotJson);
        shotsArray.append(shotJson);
    }
    json["shots"] = shotsArray;
}
