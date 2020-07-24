#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;
class Card
{
private:

public:
    Card();
    virtual string play(char = 's') = 0;
};

#endif // CARD_H
