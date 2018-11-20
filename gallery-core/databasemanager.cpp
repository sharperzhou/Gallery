#include "databasemanager.h"

#include <QSqlDatabase>

DatabaseManager &DatabaseManager::instance()
{
    static DatabaseManager instance;
    return instance;
}

DatabaseManager::~DatabaseManager()
{
    database_->close();
    delete database_;
}

DatabaseManager::DatabaseManager(const QString &path)
    : database_(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
      albumDao(*database_),
      pictureDao(*database_)

{
    database_->setDatabaseName(path);
    database_->open();

    albumDao.init();
    pictureDao.init();
}
