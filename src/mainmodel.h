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

    Q_PROPERTY(Statistics* playerStatistics READ selectedPlayerStatistics NOTIFY playerStatisticsChanged)
    Q_PROPERTY(Statistics* teamStatistics READ selectedTeamStatistics NOTIFY teamStatisticsChanged)
    Q_PROPERTY(Statistics* playerQuarterStatistics READ playerSelectedQuarterStatistics NOTIFY playerQuarterStatisticsChanged)

    Q_PROPERTY(PlayerListModel* playerModel READ getPlayerModel NOTIFY playerModelChanged)

    Q_PROPERTY(Player* selectedPlayer READ getSelectedPlayer NOTIFY selectedPlayerChanged)

    Q_PROPERTY(int selectedQuarter READ getSelectedQuarter WRITE setSelectedQuarter NOTIFY selectedQuarterChanged)
    Q_PROPERTY(QString notes READ getNotes WRITE setNotes NOTIFY notesChanged)

    Q_PROPERTY(Team *team1 READ getTeam1  NOTIFY team1Changed)
    Q_PROPERTY(Team *team2 READ getTeam2  NOTIFY team2Changed)

public:
    explicit MainModel(QObject *parent = nullptr);

    PlayerListModel* getPlayerModel();

    Player *getSelectedPlayer() const;
    void setSelectedPlayer(Player *value);

    Statistics *selectedPlayerStatistics();
    Statistics *selectedTeamStatistics();
    Statistics *playerSelectedQuarterStatistics();

    Q_INVOKABLE void exportData(const QString& filename);
    Q_INVOKABLE void importData(const QUrl &url);


    int getSelectedQuarter() const;
    void setSelectedQuarter(int value);

    QString getNotes() const;
    void setNotes(const QString &value);

    Team *getTeam1() const;
    Team *getTeam2() const;


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
    void notesChanged();
    void team1Changed();
    void team2Changed();

private:
    void copyShot(Shot *newShot, Shot *shot);

    PlayerListModel *playerModel;
    Player *selectedPlayer = nullptr;
    Team* teams[2] = {nullptr, nullptr};
    int selectedTeamIndex = 0;
    int selectedQuarter = 0;

    QString notes;

};

#endif // MAINMODEL_H
