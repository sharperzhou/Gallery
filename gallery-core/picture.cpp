#include "picture.h"

Picture::Picture(const QString &filePath)
    : Picture(QUrl::fromLocalFile(filePath))
{
}

Picture::Picture(const QUrl &fileUrl)
    : id_(-1),
      albumId_(-1),
      fileUrl_(fileUrl)
{
}

int Picture::id() const
{
    return id_;
}

void Picture::setId(int id)
{
    id_ = id;
}

int Picture::albumId() const
{
    return albumId_;
}

void Picture::setAlbumId(int albumId)
{
    albumId_ = albumId;
}

QUrl Picture::fileUrl() const
{
    return fileUrl_;
}

void Picture::setFileUrl(const QUrl &fileUrl)
{
    fileUrl_ = fileUrl;
}
