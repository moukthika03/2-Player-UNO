#ifndef DRAWFOUR_H
#define DRAWFOUR_H

#include "draw.h"
#include <iostream>
#include "game.h"
#include"colorchange.h"
using namespace std;
class drawFour : public Draw, public colorChange
{
public:
    drawFour(int, int);
    string play(Game &, int, char = 's');
};

#endif // DRAWFOUR_H
