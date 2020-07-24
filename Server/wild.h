#ifndef WILD_H
#define WILD_H

#include "colorchange.h"
#include <iostream>
#include"game.h"
using namespace std;
class Wild : public colorChange
{
public:
    Wild(int);
    string play(Game &, int, char = 's');
};

#endif // WILD_H
