#ifndef SHOOTMODEL_H
#define SHOOTMODEL_H
#include <QObject>
#include "basemodel.h"

class Shot : public BaseModel
{
    Q_OBJECT

    Q_PROPERTY(bool isMiss MEMBER isMiss)
    Q_PROPERTY(bool isContested MEMBER isContested)
    Q_PROPERTY(bool isThreePoints MEMBER isThreePoints)
    Q_PROPERTY(bool isOffhand MEMBER isOffhand)
    Q_PROPERTY(bool isOffTheDribble MEMBER isOffTheDribble)
    Q_PROPERTY(bool isCatchAndShoot MEMBER isCatchAndShoot)
    Q_PROPERTY(bool isPickAndRoll MEMBER isPickAndRoll)
    Q_PROPERTY(bool isPickAndPop MEMBER isPickAndPop)
    Q_PROPERTY(bool isPost MEMBER isPost)
    Q_PROPERTY(bool isMismatch MEMBER isMismatch)
    Q_PROPERTY(bool isIso MEMBER isIso)
    Q_PROPERTY(bool isLayup MEMBER isLayup)
    Q_PROPERTY(bool isFaul MEMBER isFaul)
    Q_PROPERTY(bool isTransition MEMBER isTransition)
    Q_PROPERTY(bool isClutch MEMBER isClutch)
    Q_PROPERTY(bool isDunk MEMBER isDunk)
    Q_PROPERTY(bool isFloater MEMBER isFloater)
    Q_PROPERTY(bool isEurostep MEMBER isEurostep)
    Q_PROPERTY(bool isPutback MEMBER isPutback)
    Q_PROPERTY(bool isSecondChance MEMBER isSecondChance)


    Q_PROPERTY(int x MEMBER x)
    Q_PROPERTY(int y MEMBER y)
public:
    explicit Shot(QObject *parent = nullptr);
    bool isMiss = false;
    bool isContested = false;
    bool isThreePoints = false;
    int x;
    int y;
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

    // BaseModel interface
public:
    void readFromJson(const QJsonObject &) override;
    void writeToJson(QJsonObject &) override;
};

#endif // SHOOTMODEL_H
