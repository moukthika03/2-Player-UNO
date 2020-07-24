#ifndef SKIP_H
#define SKIP_H

#include "special.h"
#include <iostream>
#include"game.h"
using namespace std;
class Skip : public Special
{
protected:
    char color;
public:
    Skip(int, char);
    string play(Game &, int, char = 's');
};

#endif // SKIP_H
