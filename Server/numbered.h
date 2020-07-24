#ifndef NUMBERED_H
#define NUMBERED_H

#include "card.h"
#include <iostream>
#include "game.h"
using namespace std;
class Numbered : public Card
{
protected:
    char colour;
    int value;
public:
    Numbered(int, char);
    string play(Game &, int, char = 's');
};

#endif // NUMBERED_H
