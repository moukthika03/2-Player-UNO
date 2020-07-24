#include "skip.h"

Skip::Skip(int value, char color) : Special(value)
{
    this->color = color;
}

string Skip :: play(Game &G, int choice, char ch)
{
    return "Check";
}
