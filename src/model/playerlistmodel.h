#ifndef PLAYERTABLEMODEL_H
#define PLAYERTABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include "player.h"

class PlayerListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit PlayerListModel(QObject *parent = nullptr);


    enum {
        NameRole = Qt::UserRole + 1,
        SurnameRole,
        NumberRole
    };

    // Header:
    //QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    //int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QHash<int, QByteArray> roleNames() const override;


    // Add data:
    Q_INVOKABLE bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    Q_INVOKABLE bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    QList<Player *> getPlayerList() const;
    void setPlayerList(const QList<Player *> &value);

    Player *getPlayerAt(const int& pos);

public slots:
    void onRefresh();


private:
    QList<Player *> playerList;

    // QAbstractItemModel interface
};

#endif // PLAYERTABLEMODEL_H
