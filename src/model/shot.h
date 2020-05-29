#ifndef SHOOTMODEL_H
#define SHOOTMODEL_H
#include <QObject>

class Shot : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool isMiss MEMBER isMiss)
    Q_PROPERTY(int x MEMBER x READ getX WRITE setX)
    Q_PROPERTY(int y MEMBER y READ getY WRITE setY)
public:
    Shot(QObject *parent = nullptr);
    Shot(const bool& isMiss, const bool& isContested, const bool& isThreePoints, const int& x, const int& y, QObject *parent = nullptr);
    bool isMiss = false;
    bool isContested = false;
    bool isThreePoints = false;
    int x;
    int y;
    bool getIsMiss() const;
    void setIsMiss(bool value);
    bool getIsContested() const;
    void setIsContested(bool value);
    bool getIsThreePoints() const;
    void setIsThreePoints(bool value);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
};

#endif // SHOOTMODEL_H
