#include "picturedao.h"

#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "picture.h"

using namespace std;

PictureDao::PictureDao(QSqlDatabase &database)
    : database_(database)
{
}

void PictureDao::init() const
{
    if (!database_.tables().contains("pictures")) {
        QSqlQuery query(database_);
        query.exec("CREATE TABLE pictures("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "album_id INTEGER,"
                   "url TEXT)");
    }
}

std::vector<std::unique_ptr<Picture> > PictureDao::picturesForAlbum(int albumId) const
{

}
