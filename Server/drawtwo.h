#ifndef DRAWTWO_H
#define DRAWTWO_H

#include "draw.h"
#include <iostream>
#include "game.h"
using namespace std;

class drawTwo : public Draw
{
private:
public:
    drawTwo(int, int);
    string play(Game &, int, char = 's');
};

#endif // DRAWTWO_H
