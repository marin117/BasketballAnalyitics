#ifndef SHOOTMODEL_H
#define SHOOTMODEL_H
#include <QPoint>

class Shot
{
public:
    Shot();
    Shot(const bool& isMiss, const bool& isContested, const bool& isThreePoints, const QPoint& pos);
    bool isMiss = false;
    bool isContested = false;
    bool isThreePoints = false;
    QPoint pos;
};

#endif // SHOOTMODEL_H
