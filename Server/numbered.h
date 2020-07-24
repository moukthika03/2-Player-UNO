#ifndef NUMBERED_H
#define NUMBERED_H

#include "card.h"
#include <iostream>

using namespace std;
class Numbered : public Card
{
protected:
    char colour;
    int value;
public:
    Numbered(int, char);
    string play(char = 's');
};

#endif // NUMBERED_H
