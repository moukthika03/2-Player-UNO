#ifndef WILD_H
#define WILD_H

#include "colorchange.h"
#include <iostream>

using namespace std;
class Wild : public colorChange
{
public:
    Wild(int);
    string play(char = 's');
};

#endif // WILD_H
