#ifndef DATABASE_H
#define DATABASE_H

#include <map>

#include <QtSql/QSqlDatabase>

#include "card.h"

class Database
{
public:
    Database();
    ~Database();
    Card GetCard(int id);

private:
    std::map<int, Card> map;
    QSqlDatabase db_;
};

#endif // DATABASE_H
