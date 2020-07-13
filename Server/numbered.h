#ifndef NUMBERED_H
#define NUMBERED_H

#include "card.h"

class Numbered : public Card
{
protected:
    char colour;
    int value;
public:
    Numbered(int, char);
    void play();
};

#endif // NUMBERED_H
