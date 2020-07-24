#include "skip.h"

Skip::Skip(int value, char color) : Special(value)
{
    this->color = color;
}

string Skip :: play(char ch)
{
    return "Check";
}
