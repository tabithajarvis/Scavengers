#ifndef DECK_H
#define DECK_H

#include "card_widget.h"

#include <QString>

static const int STARTING_HAND_SIZE=5;

class Deck
{
public:
    Deck();
    void StartGame();
    void Shuffle();
    void AddCard(Card card);
    CardInstance Draw();
    int hand_size() { return hand_size_; }
    const std::vector<CardInstance> hand() { return hand_; }
    const std::vector<CardInstance> player_side() { return player_side_; }
    const std::vector<CardInstance> enemy_side() { return enemy_side_; }
    const std::vector<CardInstance> shared_side() { return enemy_side_; }
    bool ParseDeckList(const QString &file_name);

private:
    std::list<CardInstance> all_cards_;
    std::vector<CardInstance> library_;
    std::vector<CardInstance> hand_;
    std::vector<CardInstance> graveyard_;
    std::vector<CardInstance> player_side_;
    std::vector<CardInstance> enemy_side_;
    std::vector<CardInstance> shared_side_;
    int hand_size_ = STARTING_HAND_SIZE;
};

#endif // DECK_H
