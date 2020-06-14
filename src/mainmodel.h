#ifndef MAINMODEL_H
#define MAINMODEL_H

#include <QObject>
#include "model/playerlistmodel.h"
#include <QQmlListProperty>
#include "src/model/team.h"

class MainModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Shot> selectedShots READ selectedShots())
public:
    explicit MainModel(QObject *parent = nullptr);

    Q_INVOKABLE PlayerListModel* getPlayerModel();

    Q_INVOKABLE QString getSelectedPlayerName();
    Q_INVOKABLE QList<Shot *> getSelectedPlayerShots();
    Player *getSelectedPlayer() const;
    void setSelectedPlayer(Player *value);

    QQmlListProperty<Shot> selectedShots();
    int shotsCount() const;
     Shot *shotAt(int i) const;
    static int shotsCount(QQmlListProperty<Shot>*);
    static Shot* shotAt(QQmlListProperty<Shot>*, int i);


public slots:
    void onSelectedPlayerChanged(const int& pos);
    void onShotAdded(Shot* shot);
    void onWidthChanged(const int& width, const int& prevWidth);
    void onHeightChanged(const int& height, const int& prevHeight);
    void onSelectedTeamChanged(const int& index);

signals:
    void selectedPlayerChanged();
    void refreshList();

private:
    PlayerListModel playerModel;
    Player *selectedPlayer;
    Team* teams[2];
    int selectedTeamIndex = 0;

};

#endif // MAINMODEL_H
