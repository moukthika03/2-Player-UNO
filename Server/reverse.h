#ifndef REVERSE_H
#define REVERSE_H

#include "special.h"
#include <iostream>
#include "game.h"
using namespace std;
class Reverse : public Special
{
protected:
    char color;
public:
    Reverse(int, char);
    string play(Game &, int, char = 's');
};

#endif // REVERSE_H
