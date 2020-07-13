#ifndef SPECIAL_H
#define SPECIAL_H

#include "card.h"

class Special : public Card
{
protected:
    int value;
public:
    Special(int);
};

#endif // SPECIAL_H
