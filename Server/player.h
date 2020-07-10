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
    vector<Card*> card_list;
public:
    Player();
};

#endif // PLAYER_H
