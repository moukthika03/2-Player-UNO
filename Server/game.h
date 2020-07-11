#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include "card.h"
using namespace std;

class Game
{
private:
    vector<int> shuffled;
    vector<int> discarded_pile;
    int top_card;
    vector<Card*> card_list;
public:
    void shuffle_cards();
};

#endif // GAME_H
