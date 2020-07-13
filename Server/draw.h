#ifndef DRAW_H
#define DRAW_H

#include "special.h"

class Draw : public Special
{
protected:
        int draw;
public:
    Draw(int, int);
};

#endif // DRAW_H
