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
    Q_PROPERTY(QQmlListProperty<Shot> selectedShots READ selectedShots)

    Q_PROPERTY(Statistics* playerStatistics READ selectedPlayerStatistics NOTIFY playerStatisticsChanged)
    Q_PROPERTY(Statistics* teamStatistics READ selectedTeamStatistics NOTIFY teamStatisticsChanged)
    Q_PROPERTY(Statistics* playerQuarterStatistics READ playerSelectedQuarterStatistics NOTIFY playerQuarterStatisticsChanged)

    Q_PROPERTY(PlayerListModel* playerModel READ getPlayerModel NOTIFY playerModelChanged)

    Q_PROPERTY(Player* selectedPlayer READ getSelectedPlayer NOTIFY selectedPlayerChanged)

    Q_PROPERTY(int selectedQuarter READ getSelectedQuarter WRITE setSelectedQuarter NOTIFY selectedQuarterChanged)
public:
    explicit MainModel(QObject *parent = nullptr);

    PlayerListModel* getPlayerModel();

    Player *getSelectedPlayer() const;
    void setSelectedPlayer(Player *value);

    QQmlListProperty<Shot> selectedShots();
    int shotsCount() const;
     Shot *shotAt(int i) const;
    static int shotsCount(QQmlListProperty<Shot>*);
    static Shot* shotAt(QQmlListProperty<Shot>*, int i);

    Statistics *selectedPlayerStatistics();
    Statistics *selectedTeamStatistics();
    Statistics *playerSelectedQuarterStatistics();

    Q_INVOKABLE void exportData(const QString& filename);
    Q_INVOKABLE void importData(const QUrl &url);


    int getSelectedQuarter() const;
    void setSelectedQuarter(int value);

public slots:
    void onSelectedPlayerChanged(const int& pos);
    void onShotAdded(Shot* shot);
    void onShotUndo();
    void onWidthChanged(const int& width, const int& prevWidth);
    void onHeightChanged(const int& height, const int& prevHeight);
    void onSelectedTeamChanged(const int& index);

signals:
    void selectedPlayerChanged();
    void refreshList();
    void playerStatisticsChanged();
    Q_INVOKABLE void teamStatisticsChanged();
    void selectedQuarterChanged();
    void playerQuarterStatisticsChanged();
    void playerModelChanged();

private:
    void copyShot(Shot *newShot, Shot *shot);

    PlayerListModel *playerModel;
    Player *selectedPlayer = nullptr;
    Team* teams[2] = {nullptr, nullptr};
    int selectedTeamIndex = 0;
    int selectedQuarter = 0;

};

#endif // MAINMODEL_H
