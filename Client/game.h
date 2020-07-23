#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <string>
class Game
{
private:
    Player  player;
    std :: string first_cards;
    int top_card;
public:
    Game();
    void setFirstCards (std :: string);
    void split();
    string getColor(int);
    string getNumber(int);
    void displayCards();
    bool verify(int);
    friend class client;
};

#endif // GAME_H
