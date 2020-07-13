#ifndef REVERSE_H
#define REVERSE_H

#include "special.h"

class Reverse : public Special
{
protected:
    char color;
public:
    Reverse(int, char);
    void play();
};

#endif // REVERSE_H
