#ifndef SHOOTMODEL_H
#define SHOOTMODEL_H
#include <QObject>
#include "basemodel.h"

class Shot : public BaseModel
{
    Q_OBJECT

    Q_PROPERTY(bool isMiss MEMBER isMiss NOTIFY isMissChanged )
    Q_PROPERTY(bool isContested MEMBER isContested NOTIFY isContestedChanged )
    Q_PROPERTY(bool isThreePoints MEMBER isThreePoints NOTIFY isThreePointsChanged )
    Q_PROPERTY(bool isOffhand MEMBER isOffhand NOTIFY isOffhandChanged )
    Q_PROPERTY(bool isOffTheDribble MEMBER isOffTheDribble NOTIFY isOffTheDribbleChanged )
    Q_PROPERTY(bool isCatchAndShoot MEMBER isCatchAndShoot NOTIFY isCatchAndShootChanged )
    Q_PROPERTY(bool isPickAndRoll MEMBER isPickAndRoll NOTIFY isPickAndRollChanged )
    Q_PROPERTY(bool isPickAndPop MEMBER isPickAndPop NOTIFY isPickAndPopChanged )
    Q_PROPERTY(bool isPost MEMBER isPost NOTIFY isPostChanged )
    Q_PROPERTY(bool isMismatch MEMBER isMismatch NOTIFY isMismatchChanged )
    Q_PROPERTY(bool isIso MEMBER isIso NOTIFY isIsoChanged )
    Q_PROPERTY(bool isLayup MEMBER isLayup NOTIFY isLayupChanged )
    Q_PROPERTY(bool isFaul MEMBER isFaul NOTIFY isFaulChanged )
    Q_PROPERTY(bool isTransition MEMBER isTransition NOTIFY isTransitionChanged )
    Q_PROPERTY(bool isClutch MEMBER isClutch NOTIFY isClutchChanged )
    Q_PROPERTY(bool isDunk MEMBER isDunk NOTIFY isDunkChanged )
    Q_PROPERTY(bool isFloater MEMBER isFloater NOTIFY isFloaterChanged )
    Q_PROPERTY(bool isEurostep MEMBER isEurostep NOTIFY isEurostepChanged )
    Q_PROPERTY(bool isPutback MEMBER isPutback NOTIFY isPutbackChanged )
    Q_PROPERTY(bool isSecondChance MEMBER isSecondChance NOTIFY isSecondChanceChanged )
    Q_PROPERTY(bool isOffTurnover MEMBER isOffTurnover NOTIFY isOffTurnoverChanged )

    Q_PROPERTY(int x MEMBER x)
    Q_PROPERTY(int y MEMBER y)
    Q_PROPERTY(int quarter MEMBER quarter)
public:
    explicit Shot(QObject *parent = nullptr);
    bool isMiss = false;
    bool isContested = false;
    bool isThreePoints = false;
    bool isOffhand = false;
    bool isOffTheDribble = false;
    bool isCatchAndShoot = false;
    bool isPickAndRoll = false;
    bool isPickAndPop = false;
    bool isPost = false;
    bool isMismatch = false;
    bool isIso = false;
    bool isLayup = false;
    bool isFaul = false;
    bool isTransition = false;
    bool isClutch = false;
    bool isDunk = false;
    bool isFloater = false;
    bool isEurostep = false;
    bool isPutback = false;
    bool isSecondChance = false;
    bool isOffTurnover = false;

    int x;
    int y;
    int quarter = 0;

    // BaseModel interface
signals:
    void isMissChanged();
    void isContestedChanged();
    void isThreePointsChanged();
    void isOffhandChanged();
    void isOffTheDribbleChanged();
    void isCatchAndShootChanged();
    void isPickAndRollChanged();
    void isPickAndPopChanged();
    void isPostChanged();
    void isMismatchChanged();
    void isIsoChanged();
    void isLayupChanged();
    void isFaulChanged();
    void isTransitionChanged();
    void isClutchChanged();
    void isDunkChanged();
    void isFloaterChanged();
    void isEurostepChanged();
    void isPutbackChanged();
    void isSecondChanceChanged();
    void isOffTurnoverChanged();

public:
    void readFromJson(const QJsonObject &) override;
    void writeToJson(QJsonObject &) override;
};

#endif // SHOOTMODEL_H
