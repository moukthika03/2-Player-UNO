#ifndef DRAWTWO_H
#define DRAWTWO_H

#include "draw.h"
#include <iostream>

using namespace std;

class drawTwo : public Draw
{
private:
public:
    drawTwo(int, int);
    string play(char = 's');
};

#endif // DRAWTWO_H
