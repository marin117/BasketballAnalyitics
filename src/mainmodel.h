#ifndef MAINMODEL_H
#define MAINMODEL_H

#include <QObject>
#include "model/playerlistmodel.h"
#include <QQmlListProperty>
#include "src/model/team.h"

class PlayerStatistics;

class MainModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Shot> selectedShots READ selectedShots())
    Q_PROPERTY(Statistics* playerStatistics READ selectedPlayerStatistics() NOTIFY playerStatisticsChanged)
    Q_PROPERTY(Statistics* teamStatistics READ selectedTeamStatistics() NOTIFY teamStatisticsChanged)
public:
    explicit MainModel(QObject *parent = nullptr);

    Q_INVOKABLE PlayerListModel* getPlayerModel();

    Q_INVOKABLE QString getSelectedPlayerName();
    Q_INVOKABLE QList<Shot *> getSelectedPlayerShots();
    Q_INVOKABLE Player *getSelectedPlayer() const;
    void setSelectedPlayer(Player *value);

    QQmlListProperty<Shot> selectedShots();
    int shotsCount() const;
     Shot *shotAt(int i) const;
    static int shotsCount(QQmlListProperty<Shot>*);
    static Shot* shotAt(QQmlListProperty<Shot>*, int i);

    Statistics *selectedPlayerStatistics();
    Statistics *selectedTeamStatistics();

    Q_INVOKABLE void exportTeams();
    Q_INVOKABLE void importTeams();


public slots:
    void onSelectedPlayerChanged(const int& pos);
    void onShotAdded(Shot* shot);
    void onWidthChanged(const int& width, const int& prevWidth);
    void onHeightChanged(const int& height, const int& prevHeight);
    void onSelectedTeamChanged(const int& index);

signals:
    void selectedPlayerChanged();
    void refreshList();
    void playerStatisticsChanged();
    Q_INVOKABLE void teamStatisticsChanged();

private:
    void copyShot(Shot *newShot, Shot *shot);

    PlayerListModel *playerModel;
    Player *selectedPlayer = nullptr;
    Team* teams[2] = {nullptr, nullptr};
    int selectedTeamIndex = 0;

};

#endif // MAINMODEL_H
