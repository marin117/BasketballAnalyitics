#include "player.h"

Player::Player()
{
}

Player::Player(const QString &name, const QString &surname,const int &number) :
    name(name), surname(surname), number(number)
{
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

const std::vector<Shot>& Player::getShots() const
{
    return shots;
}


void Player::setShots(const std::vector<Shot> &value)
{
    shots = value;
}

void Player::addShot(const Shot &shot)
{
    shots.emplace_back(shot);
}

void Player::undoShot(){
    if(shots.size()){
        shots.pop_back();
    }
}
