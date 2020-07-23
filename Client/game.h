#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <string>
class Game
{
private:
    Player  player;
    std :: string first_cards;
public:
    Game();
    void setFirstCards (std :: string);
    void split();
    string getColor(int);
};

#endif // GAME_H