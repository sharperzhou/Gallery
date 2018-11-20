#include "album.h"


Album::Album(const QString& name)
    : id_(-1),
      name_(name)
{
}

int Album::id() const
{
    return id_;
}

void Album::setId(int id)
{
    id_ = id;
}

QString Album::name() const
{
    return name_;
}

void Album::setName(const QString &name)
{
    name_ = name;
}
