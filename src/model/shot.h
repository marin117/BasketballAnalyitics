#ifndef SHOOTMODEL_H
#define SHOOTMODEL_H
#include <QObject>

class Shot : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool isMiss MEMBER isMiss)
    Q_PROPERTY(int x MEMBER x)
    Q_PROPERTY(int y MEMBER y)
public:
    Shot(QObject *parent = nullptr);
    Shot(const bool& isMiss, const bool& isContested, const bool& isThreePoints, const int& x, const int& y, QObject *parent = nullptr);
    bool isMiss = false;
    bool isContested = false;
    bool isThreePoints = false;
    int x;
    int y;
};

#endif // SHOOTMODEL_H
