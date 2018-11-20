#ifndef ALBUMMODEL_H
#define ALBUMMODEL_H

#include <memory>
#include <vector>

#include <QAbstractListModel>
#include <QHash>

#include "gallery-core_global.h"
#include "databasemanager.h"

class Album;

class GALLERYCORESHARED_EXPORT AlbumModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles { IdRole = Qt::UserRole + 1, NameRole };

    AlbumModel(QObject* parent = nullptr);

    QModelIndex addAlbum(const Album& album);

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool removeRows(int row, int count, const QModelIndex &parent) override;
    QHash<int, QByteArray> roleNames() const override;

private:
    DatabaseManager& dbMgr;
    std::vector<std::unique_ptr<Album>> albums_;

    bool isIndexValid(const QModelIndex& index) const;
};

#endif // ALBUMMODEL_H
