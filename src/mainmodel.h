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

    int getSelectedPlayer() const;
    void setSelectedPlayer(int value);

public slots:
    void onSelectedPlayerChanged(const int& pos);

signals:
    void selectedPlayerChanged();

private:
    PlayerTableModel playerModel;
    int selectedPlayer;
};

#endif // MAINMODEL_H
