#ifndef DECK_H
#define DECK_H

#include "card.h"

#include <QString>

static const int STARTING_HAND_SIZE=5;

class Deck
{
public:
    Deck();
    void StartGame();
    void Shuffle();
    void AddCard(Card card);
    Card Draw();
    int hand_size() { return hand_size_; }
    bool ParseDeckList(const QString &file_name);

private:
    std::vector<Card> all_cards_;
    std::vector<Card> library_;
    std::vector<Card> hand_;
    std::vector<Card> graveyard_;
    int hand_size_ = STARTING_HAND_SIZE;
};

#endif // DECK_H
