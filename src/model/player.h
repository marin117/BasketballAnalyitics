#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include <vector>
#include "shot.h"
#include <QObject>

class Player
{
public:
    Player();
    Player(const QString &name, const QString &surname,const int &number);
    Q_INVOKABLE QString getName() const;
    void setName(const QString &value);

    QString getSurname() const;
    void setSurname(const QString &value);

    int getNumber() const;
    void setNumber(int value);

    const std::vector<Shot>& getShots() const;
    void setShots(const std::vector<Shot> &value);
    void addShot(const Shot& shot);
    void undoShot();

private:
    QString name = "";
    QString surname = "";
    int number = 0;
    std::vector<Shot> shots;

};

#endif // PLAYER_H
