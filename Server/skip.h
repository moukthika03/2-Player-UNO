#ifndef SKIP_H
#define SKIP_H

#include "special.h"

class Skip : public Special
{
protected:
    char color;
public:
    Skip(int, char);
    void play();
};

#endif // SKIP_H
