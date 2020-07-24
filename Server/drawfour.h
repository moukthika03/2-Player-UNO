#ifndef DRAWFOUR_H
#define DRAWFOUR_H

#include "draw.h"
#include <iostream>

using namespace std;
class drawFour : public Draw
{
public:
    drawFour(int, int);
    string play(char = 's');
};

#endif // DRAWFOUR_H
