#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>

#include "albumdao.h"
#include "picturedao.h"

class QSqlDatabase;

const QString DATABASE_FILENAME = "gallery.db";

class DatabaseManager
{
public:
    static DatabaseManager& instance();
    ~DatabaseManager();

    DatabaseManager& operator=(const DatabaseManager& rhs) = delete;
    DatabaseManager(const DatabaseManager& rhs) = delete;

protected:
    explicit DatabaseManager(const QString& path = DATABASE_FILENAME);

private:
    QSqlDatabase* database_;

public:
   const AlbumDao albumDao;
   const PictureDao pictureDao;
};

#endif // DATABASEMANAGER_H
