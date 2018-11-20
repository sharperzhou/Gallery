#include "albummodel.h"

#include "album.h"

using namespace std;

AlbumModel::AlbumModel(QObject *parent)
    : QAbstractListModel(parent),
      dbMgr(DatabaseManager::instance()),
      albums_(dbMgr.albumDao.albums())
{
}

QModelIndex AlbumModel::addAlbum(const Album &album)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    auto newAlbum = make_unique<Album>(album);
    dbMgr.albumDao.addAlbum(*newAlbum);
    albums_.emplace_back(move(newAlbum));
    endInsertRows();

    return index(rowIndex);
}

int AlbumModel::rowCount(const QModelIndex &parent) const
{
    return static_cast<int>(albums_.size());
}

QVariant AlbumModel::data(const QModelIndex &index, int role) const
{
    QVariant var;
    if (!isIndexValid(index))
        return var;

    const auto& album = *albums_[static_cast<size_t>(index.row())];

    switch (role) {
    case IdRole:
        var = album.id();
        break;

    case NameRole:
    case Qt::DisplayRole:
        var = album.name();
        break;

    default:
        break;
    }

    return var;
}

bool AlbumModel::removeRows(int row, int count, const QModelIndex &parent)
{

}

QHash<int, QByteArray> AlbumModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[NameRole] = "name";
    return roles;
}

bool AlbumModel::isIndexValid(const QModelIndex &index) const
{

}
