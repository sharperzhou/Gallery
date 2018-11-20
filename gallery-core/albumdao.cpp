#include "albumdao.h"

#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "album.h"

using namespace std;

AlbumDao::AlbumDao(QSqlDatabase& database)
    : database_(database)
{
}

void AlbumDao::init() const
{
    if (!database_.tables().contains("albums")) {
        QSqlQuery query(database_);
        query.exec("CREATE TABLE albums("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "name TEXT)");
    }
}

void AlbumDao::addAlbum(Album &album) const
{
    QSqlQuery query(database_);
    query.prepare("INSERT INTO albums(name) VALUES(@name)");
    query.bindValue("@name", album.name());
    query.exec();
    album.setId(query.lastInsertId().toInt());
}

void AlbumDao::updataAlbum(const Album &album) const
{

}

void AlbumDao::removeAlbum(int id) const
{

}

std::vector<std::unique_ptr<Album> > AlbumDao::albums() const
{
    QSqlQuery query("SELECT * FROM albums", database_);
    query.exec();

    vector<unique_ptr<Album>> list;
    while (query.next()) {
        unique_ptr<Album> album = make_unique<Album>();
        album->setId(query.value("id").toInt());
        album->setName(query.value("name").toString());

        list.emplace_back(move(album));
    }

    return list;
}
