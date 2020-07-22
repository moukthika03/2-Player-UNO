#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <string>
class Game
{
private:
    Player  client_player;
    std :: string first_cards;
public:
    Game();
    void setFirstCards (std :: string);
    void split();
};

#endif // GAME_H
