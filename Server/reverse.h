#ifndef REVERSE_H
#define REVERSE_H

#include "special.h"
#include <iostream>

using namespace std;
class Reverse : public Special
{
protected:
    char color;
public:
    Reverse(int, char);
    string play(char = 's');
};

#endif // REVERSE_H
