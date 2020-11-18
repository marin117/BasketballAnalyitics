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
    Q_PROPERTY(bool isFadeaway MEMBER isFadeaway NOTIFY isFadeawayChanged)
    Q_PROPERTY(bool isStepback MEMBER isStepback NOTIFY isStepbackChanged)
    Q_PROPERTY(bool isDrive MEMBER isDrive NOTIFY isDriveChanged )
    Q_PROPERTY(bool isReverse MEMBER isReverse NOTIFY isReverseChanged )
    Q_PROPERTY(bool isRoll MEMBER isRoll NOTIFY isRollChanged )
    Q_PROPERTY(bool isUpAndUnder MEMBER isUpAndUnder NOTIFY isUpAndUnderChanged )
    Q_PROPERTY(bool isHookshot MEMBER isHookshot NOTIFY isHookshotChanged )
    Q_PROPERTY(bool isTurnaround MEMBER isTurnaround NOTIFY isTurnaroundChanged )
    Q_PROPERTY(bool isCut MEMBER isCut NOTIFY isCutChanged )
    Q_PROPERTY(bool isScreenAssisted MEMBER isScreenAssisted NOTIFY isScreenAssistedChanged )
    Q_PROPERTY(bool isAssisted MEMBER isAssisted NOTIFY isAssistedChanged )
    Q_PROPERTY(bool isBlocked MEMBER isBlocked NOTIFY isBlockedChanged )
    Q_PROPERTY(bool isShot MEMBER isShot NOTIFY isShotChanged )


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
    bool isFadeaway = false;
    bool isStepback = false;
    bool isDrive = false;
    bool isReverse = false;
    bool isRoll = false;
    bool isUpAndUnder = false;
    bool isHookshot = false;
    bool isTurnaround = false;
    bool isCut = false;
    bool isScreenAssisted = false;
    bool isAssisted = false;
    bool isBlocked = false;
    bool isShot = false;

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
    void isFadeawayChanged();
    void isStepbackChanged();
    void isDriveChanged();
    void isReverseChanged();
    void isRollChanged();
    void isUpAndUnderChanged();
    void isHookshotChanged();
    void isTurnaroundChanged();
    void isCutChanged();
    void isScreenAssistedChanged();
    void isAssistedChanged();
    void isBlockedChanged();
    void isShotChanged();


public:
    void readFromJson(const QJsonObject &) override;
    void writeToJson(QJsonObject &) override;
};

#endif // SHOOTMODEL_H
