#include "playertablemodel.h"
#include <QDebug>

PlayerTableModel::PlayerTableModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int PlayerTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return playerList.size();
}

//int PlayerTableModel::columnCount(const QModelIndex &parent) const
//{
//    if (parent.isValid())
//        return 0;

//    return 3;
//}

QVariant PlayerTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if(index.row() >= playerList.size() || index.row() < 0)
        return QVariant();


    Player player = playerList.at(index.row());
    switch (role) {
    case NameRole:
        return player.getName();
    case SurnameRole:
        return player.getSurname();
    case NumberRole:
        return player.getNumber();
    default:
        break;
    }
    return QVariant();
}

bool PlayerTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole){
        int row = index.row();
        Player player = playerList.at(row);

        switch (role) {
        case NameRole:
            player.setName(value.toString());
            break;
        case SurnameRole:
            player.setSurname(value.toString());
            break;
        case NumberRole:
            player.setNumber(value.toInt());
            break;
        default:
            break;
        }
        playerList.replace(row, player);
        emit(dataChanged(index, index, {role, Qt::EditRole}));

        return true;
    }
    return false;
}

Qt::ItemFlags PlayerTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}

bool PlayerTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    Player p;
    playerList.append(p);
    endInsertRows();
    return true;
}


bool PlayerTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    if(row >=0 && row < playerList.size())
        playerList.removeAt(row);
    endRemoveRows();
    return true;
}


void PlayerTableModel::setPlayerList(const QList<Player> &value)
{
    playerList = value;
}

Player *PlayerTableModel::getPlayerAt(const int &pos)
{
    return &playerList[pos];
}

QList<Player> PlayerTableModel::getPlayerList() const
{
    return playerList;
}



QHash<int, QByteArray> PlayerTableModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name" ;
    roles[SurnameRole] = "surname";
    roles[NumberRole] = "number";
    return roles;
}