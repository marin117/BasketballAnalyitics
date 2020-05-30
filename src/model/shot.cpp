#include "shot.h"

Shot::Shot(QObject *parent) : QObject(parent)
{

}

Shot::Shot(const bool &isMiss, const bool &isContested, const bool &isThreePoints, const int& x, const int& y, QObject *parent) :
    isMiss(isMiss), isContested(isContested), isThreePoints(isThreePoints), x(x), y(y), QObject(parent)
{

}

int Shot::getY() const
{
    return y;
}

void Shot::setY(int value)
{
    y = value;
}

int Shot::getX() const
{
    return x;
}

void Shot::setX(int value)
{
    x = value;
}

bool Shot::getIsThreePoints() const
{
    return isThreePoints;
}

void Shot::setIsThreePoints(bool value)
{
    isThreePoints = value;
}

bool Shot::getIsContested() const
{
    return isContested;
}

void Shot::setIsContested(bool value)
{
    isContested = value;
}

bool Shot::getIsMiss() const
{
    return isMiss;
}

void Shot::setIsMiss(bool value)
{
    isMiss = value;
}
