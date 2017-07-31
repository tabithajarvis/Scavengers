#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "ScavengersApp/card.h"

struct GameState{
  std::vector<CardInstance> cards_in_play;
};

#endif // GAME_STATE_H
