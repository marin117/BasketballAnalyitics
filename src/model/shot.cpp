#include "shot.h"

Shot::Shot(QObject *parent) : BaseModel(parent)
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

    if (json.contains("isOffhand") && json["isOffhand"].isBool()) {
        isOffhand = json["isOffhand"].toBool();
    }
    if (json.contains("isOffTheDribble") && json["isOffTheDribble"].isBool()) {
        isOffTheDribble = json["isOffTheDribble"].toBool();
    }
    if (json.contains("isCatchAndShoot") && json["isCatchAndShoot"].isBool()) {
        isCatchAndShoot = json["isCatchAndShoot"].toBool();
    }
    if (json.contains("isPickAndRoll") && json["isPickAndRoll"].isBool()) {
        isPickAndRoll = json["isPickAndRoll"].toBool();
    }
    if (json.contains("isPickAndPop") && json["isPickAndPop"].isBool()) {
        isPickAndPop = json["isPickAndPop"].toBool();
    }
    if (json.contains("isPost") && json["isPost"].isBool()) {
        isPost = json["isPost"].toBool();
    }
    if (json.contains("isMismatch") && json["isMismatch"].isBool()) {
        isMismatch = json["isMismatch"].toBool();
    }
    if (json.contains("isIso") && json["isIso"].isBool()) {
        isIso = json["isIso"].toBool();
    }
    if (json.contains("isLayup") && json["isLayup"].isBool()) {
        isLayup = json["isLayup"].toBool();
    }
    if (json.contains("isFaul") && json["isFaul"].isBool()) {
        isFaul = json["isFaul"].toBool();
    }
    if (json.contains("isTransition") && json["isTransition"].isBool()) {
        isTransition = json["isTransition"].toBool();
    }
    if (json.contains("isClutch") && json["isClutch"].isBool()) {
        isClutch = json["isClutch"].toBool();
    }
    if (json.contains("isDunk") && json["isDunk"].isBool()) {
        isDunk = json["isDunk"].toBool();
    }
    if (json.contains("isFloater") && json["isFloater"].isBool()) {
        isFloater = json["isFloater"].toBool();
    }

    if (json.contains("isEurostep") && json["isEurostep"].isBool()) {
        isEurostep = json["isEurostep"].toBool();
    }
}

void Shot::writeToJson(QJsonObject &json)
{
    json["x"] = x;
    json["y"] = y;
    json["isContested"] = isContested;
    json["isMiss"] = isMiss;
    json["isThreePoints"] = isThreePoints;
    json["isOffhand"] = isOffhand;
    json["isOffTheDribble"] = isOffTheDribble;
    json["isCatchAndShoot"] = isCatchAndShoot;
    json["isPickAndRoll"] = isPickAndRoll;
    json["isPickAndPop"] = isPickAndPop;
    json["isPost"] = isPost;
    json["isMismatch"] = isMismatch;
    json["isIso"] = isIso;
    json["isLayup"] = isLayup;
    json["isFaul"] = isFaul;
    json["isTransition"] = isTransition;
    json["isClutch"] = isClutch;
    json["isDunk"] = isDunk;
    json["isFloater"] = isFloater;
    json["isEurostep"] = isEurostep;

}
