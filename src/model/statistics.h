#ifndef STATISITCS_H
#define STATISITCS_H

#include <QObject>
#include "basemodel.h"

class Statistics : public BaseModel
{
    Q_OBJECT
    Q_PROPERTY(int points READ getPoints WRITE setPoints NOTIFY pointsChanged)
    Q_PROPERTY(int shotsScored READ getShotsScored WRITE setShotsScored NOTIFY shotsScoredChanged)
    Q_PROPERTY(int shotsNum READ getShotsNum WRITE setShotsNum NOTIFY shotsNumChanged)
    Q_PROPERTY(int offensiveRebounds READ getOffensiveRebounds WRITE setOffensiveRebounds NOTIFY offensiveReboundsChanged)
    Q_PROPERTY(int defensiveRebounds READ getDefensiveRebounds WRITE setDefensiveRebounds NOTIFY defensiveReboundsChanged)
    Q_PROPERTY(int steals READ getSteals WRITE setSteals NOTIFY stealsChanged)
    Q_PROPERTY(int assists READ getAssists WRITE setAssists NOTIFY assistsChanged)
    Q_PROPERTY(int blocks READ getBlocks WRITE setBlocks NOTIFY blocksChanged)
    Q_PROPERTY(int turnovers READ getTurnovers WRITE setTurnovers NOTIFY turnoversChanged)

public:
    explicit Statistics(QObject *parent = nullptr);

    int getPoints() const;
    void setPoints(int value);

    int getShotsScored() const;
    void setShotsScored(int value);

    int getShotsNum() const;
    void setShotsNum(int value);

    int getOffensiveRebounds() const;
    void setOffensiveRebounds(int value);

    int getDefensiveRebounds() const;
    void setDefensiveRebounds(int value);

    int getSteals() const;
    void setSteals(int value);

    int getAssists() const;
    void setAssists(int value);



    int getBlocks() const;
    void setBlocks(int value);

    int getTurnovers() const;
    void setTurnovers(int value);

signals:
    Q_INVOKABLE void pointsChanged();
    Q_INVOKABLE void shotsScoredChanged();
    Q_INVOKABLE void shotsNumChanged();
    Q_INVOKABLE void offensiveReboundsChanged();
    Q_INVOKABLE void defensiveReboundsChanged();
    Q_INVOKABLE void stealsChanged();
    Q_INVOKABLE void assistsChanged();
    Q_INVOKABLE void blocksChanged();
    Q_INVOKABLE void turnoversChanged();

protected:
    int points = 0;
    int shotsScored = 0;
    int shotsNum = 0;
    int offensiveRebounds = 0;
    int defensiveRebounds = 0;
    int steals = 0;
    int assists = 0;
    int blocks = 0;
    int turnovers = 0;

    // BaseModel interface
public:
    void readFromJson(const QJsonObject &) override;
    void writeToJson(QJsonObject &) override;
};

#endif // STATISITCS_H
