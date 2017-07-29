#ifndef CARDDB_H
#define CARDDB_H

#include "card.h"

class CardDB
{
public:
    CardDB();
    Card GetCard(int id);

private:
    std::map<int, Card> map;
};

#endif // CARDDB_H
