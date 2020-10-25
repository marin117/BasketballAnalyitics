#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include <vector>
#include "shot.h"
#include <QObject>
#include <QQmlListProperty>
#include "basemodel.h"

class Statistics;

class Player : public BaseModel
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Shot> shots READ shotsList NOTIFY shotsChanged)
public:
    explicit Player(QObject *parent = nullptr);
    explicit Player(const QString &name, const QString &surname,const int &number, QObject *parent = nullptr);
    Q_INVOKABLE QString getName() const;
    void setName(const QString &value);

    QString getSurname() const;
    void setSurname(const QString &value);

    int getNumber() const;
    void setNumber(int value);

    void addShot(Shot* shot);
    void popShot();

    QList<Shot *>* getShots();
    QList<Shot*> getShotsCopy();
    void setShots(const QList<Shot *> &value);

    Statistics *getStatistics() const;
    void setStatistics(Statistics *value);

    QVector<Statistics *> getQuarterStatistics() const;

    QQmlListProperty<Shot> shotsList();
    int shotsCount() const;
     Shot *shotAt(int i) const;

signals:
    void shotsChanged();

private:
    QString name = "";
    QString surname = "";
    int number = 0;
    QList<Shot *> shots;
    Statistics *statistics;
    QVector<Statistics *> quarterStatistics;

    static int shotsCount(QQmlListProperty<Shot>*);
    static Shot* shotAt(QQmlListProperty<Shot>*, int i);

    // BaseModel interface
public:
    void readFromJson(const QJsonObject &) override;
    void writeToJson(QJsonObject &) override;
};

#endif // PLAYER_H
