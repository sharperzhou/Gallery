#ifndef ALBUMDAO_H
#define ALBUMDAO_H

#include <memory>
#include <vector>

class QSqlDatabase;
class Album;

class AlbumDao
{
public:
    AlbumDao(QSqlDatabase& database);
    void init() const;

    void addAlbum(Album& album) const;
    void updataAlbum(const Album& album) const;
    void removeAlbum(int id) const;
    std::vector<std::unique_ptr<Album>> albums() const;
private:
    QSqlDatabase& database_;
};

#endif // ALBUMDAO_H
