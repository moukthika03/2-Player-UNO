#ifndef CARD_H
#define CARD_H
#include"game.h"
#include <iostream>
using namespace std;
class Card
{
private:

public:
    Card();
    virtual string play(Game &, int, char = 's') = 0;
};

#endif // CARD_H
