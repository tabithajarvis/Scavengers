#ifndef CARD_DB_H
#define CARD_DB_H

#include "card.h"

class CardDB
{
public:
    CardDB();
    Card GetCard(int id);

private:
    std::map<int, Card> map;
};

#endif // CARD_DB_H
