#include "player.h"
#include "playerstatistics.h"
#include <QJsonArray>

#define QUARTER 5

Player::Player(QObject *parent) : BaseModel(parent)
{
    statistics = new PlayerStatistics(this);
    quarterStatistics.reserve(QUARTER);
    for(int i = 0; i < QUARTER; i++){
        quarterStatistics.append(new Statistics(this));
    }
}

Player::Player(const QString &name, const QString &surname,const int &number, QObject *parent) : BaseModel(parent),
    name(name), surname(surname), number(number)
{
    statistics = new PlayerStatistics(this);
    quarterStatistics.reserve(QUARTER);
    for(int i = 0; i < QUARTER; i++){
        quarterStatistics.append(new Statistics(this));
    }
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

QList<Shot *> Player::getShotsCopy()
{
    return shots;
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

QList<Statistics *> Player::getQuarterStatistics() const
{
    return quarterStatistics;
}


void Player::addShot(Shot *shot)
{
    shots.append(shot);
    statistics->addPoints(shot);
    emit shotsChanged();
}

void Player::popShot(){
    if(shots.isEmpty())
        return;
    auto shot = shots.last();
    statistics->popPoints(shot);
    delete shot;
    shots.removeLast();
}


void Player::readFromJson(const QJsonObject &json)
{
    if(json.contains("name") && json["name"].isString())
        name = json["name"].toString();
    if(json.contains("surname") && json["surname"].isString())
        surname = json["surname"].toString();
    if(json.contains("number") && json["number"].isDouble())
        number = json["number"].toInt();

    if(json.contains("statistics") && json["statistics"].isObject()){
        QJsonObject statsJson = json["statistics"].toObject();
        auto stats = new PlayerStatistics(this);
        stats->readFromJson(statsJson);
        this->statistics = stats;
    }

    if(json.contains("quarterStatistics") && json["quarterStatistics"].isArray()){
        QJsonArray quarterStatisticsArray = json["quarterStatistics"].toArray();
        quarterStatistics.reserve(quarterStatisticsArray.size());
        for(int i = 0; i < quarterStatisticsArray.size(); i++){
            QJsonObject s = quarterStatisticsArray[i].toObject();
            auto qStatistics = new Statistics(this);
            qStatistics->readFromJson(s);
            quarterStatistics[i] = qStatistics;
        }
    }

    if(json.contains("shots") && json["shots"].isArray()){
        QJsonArray shotsArray = json["shots"].toArray();
        shots.reserve(shotsArray.size());
        for(int i = 0; i < shotsArray.size(); i++){
            QJsonObject shot = shotsArray[i].toObject();
            auto s = new Shot(this);
            s->readFromJson(shot);
            shots.append(s);
        }
    }
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
    for(auto &shot : qAsConst(shots)){
        QJsonObject shotJson;
        shot->writeToJson(shotJson);
        shotsArray.append(shotJson);
    }
    json["shots"] = shotsArray;

    QJsonArray quarterStatisticsArray;
    for(auto &s : qAsConst(quarterStatistics)){
        QJsonObject qStatisicsJson;
        s->writeToJson(qStatisicsJson);
        quarterStatisticsArray.append(qStatisicsJson);
    }
    json["quarterStatistics"] = quarterStatisticsArray;
}

QQmlListProperty<Shot> Player::shotsList
()
{
    return QQmlListProperty<Shot>(this, &shots);
}

int Player::shotsCount() const
{
    return shots.size();
}

Shot *Player::shotAt(int i) const
{
    return shots.at(i);
}

QQmlListProperty<Statistics> Player::quarterStatisticsList()
{
    return QQmlListProperty<Statistics>(this, &quarterStatistics);
}

int Player::statisticsCount() const
{
    return quarterStatistics.size();
}

Statistics *Player::statisticsAt(int i) const
{
    return quarterStatistics.at(i);
}


int Player::shotsCount(QQmlListProperty<Shot>* list) {
    return reinterpret_cast< Player* >(list->data)->shotsCount();
}

Shot* Player::shotAt(QQmlListProperty<Shot>* list, int i)
{
    return reinterpret_cast< Player* >(list->data)->shotAt(i);
}

int Player::statisticsCount(QQmlListProperty<Statistics> *list)
{
    return reinterpret_cast< Player* >(list->data)->statisticsCount();
}

Statistics *Player::statisticsAt(QQmlListProperty<Statistics> *list, int i)
{
    return reinterpret_cast< Player* >(list->data)->statisticsAt(i);

}
