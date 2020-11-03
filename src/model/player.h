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
    Q_PROPERTY(QQmlListProperty<Statistics> quarterStatistics READ quarterStatisticsList NOTIFY quarterStatisticsChanged)

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

    QList<Statistics *> getQuarterStatistics() const;

    QQmlListProperty<Shot> shotsList();
    int shotsCount() const;
     Shot *shotAt(int i) const;

     QQmlListProperty<Statistics> quarterStatisticsList();
     int statisticsCount() const;
      Statistics *statisticsAt(int i) const;

signals:
    void shotsChanged();
    void quarterStatisticsChanged();

private:
    QString name = "";
    QString surname = "";
    int number = 0;
    QList<Shot *> shots;
    Statistics *statistics;
    QList<Statistics *> quarterStatistics;

    static int shotsCount(QQmlListProperty<Shot>*);
    static Shot* shotAt(QQmlListProperty<Shot>*, int i);

    static int statisticsCount(QQmlListProperty<Statistics>*);
    static Statistics* statisticsAt(QQmlListProperty<Statistics>*, int i);


    // BaseModel interface
public:
    void readFromJson(const QJsonObject &) override;
    void writeToJson(QJsonObject &) override;
};

#endif // PLAYER_H
