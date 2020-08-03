#include "shot.h"

Shot::Shot(QObject *parent) : BaseModel(parent)
{

}

Shot::Shot(const bool &isMiss, const bool &isContested, const bool &isThreePoints, const int& x, const int& y, QObject *parent) :
    isMiss(isMiss), isContested(isContested), isThreePoints(isThreePoints), x(x), y(y), BaseModel(parent)
{

}


void Shot::readFromJson(const QJsonObject &json)
{
}

void Shot::writeToJson(QJsonObject &json)
{
    json["x"] = x;
    json["y"] = y;
    json["isContested"] = isContested;
    json["isMiss"] = isMiss;
    json["isThreePoints"] = isThreePoints;
}
