#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Card;


class Player
{
private:
    vector<int> card_list;

public:
    Player();
    friend class Game;
    friend class server;
    friend class Numbered;
    friend class drawFour;
    friend class drawTwo;
    friend class Reverse;
    friend class Skip;
    friend class Wild;
};

#endif // PLAYER_H
