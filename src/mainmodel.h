#ifndef MAINMODEL_H
#define MAINMODEL_H

#include <QObject>
#include "model/playertablemodel.h"

class MainModel : public QObject
{
    Q_OBJECT
public:
    explicit MainModel(QObject *parent = nullptr);

    Q_INVOKABLE PlayerTableModel* getPlayerModel();

    Q_INVOKABLE Player* getSelectedPlayer();
    void setSelectedPlayer(int value);
    Q_INVOKABLE QString getSelectedPlayerName();
public slots:
    void onSelectedPlayerChanged(const int& pos);
    void onShotAdded(const int& x, const int& y);

signals:
    void selectedPlayerChanged();

private:
    PlayerTableModel playerModel;
    int selectedPlayer = 0;
};

#endif // MAINMODEL_H