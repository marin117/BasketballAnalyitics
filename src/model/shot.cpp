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
    if (json.contains("x") && json["x"].isDouble()){
        x = json["x"].toInt();
    }
    if (json.contains("y") && json["y"].isDouble()){
        y = json["y"].toInt();
    }
    if (json.contains("isContested") && json["isContested"].isBool()){
        isContested = json["isContested"].toBool();
    }
    if (json.contains("isMiss") && json["isMiss"].isBool()){
        isMiss = json["isMiss"].toBool();
    }
    if (json.contains("isThreePoints") && json["isThreePoints"].isBool()){
        isThreePoints = json["isThreePoints"].toBool();
    }
}

void Shot::writeToJson(QJsonObject &json)
{
    json["x"] = x;
    json["y"] = y;
    json["isContested"] = isContested;
    json["isMiss"] = isMiss;
    json["isThreePoints"] = isThreePoints;
}
