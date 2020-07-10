#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Game
{
private:
    vector<int> shuffled;

public:
    void shuffle_cards();
};

#endif // GAME_H
