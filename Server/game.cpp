#include "game.h"
#include "card.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void Game :: shuffle_cards()
{
    while(shuffled.size()!= 108)
    {
        int numb = rand()%108 + 1;
        if( find(shuffled.begin(), shuffled.end(), numb) == shuffled.end())
            shuffled.push_back(numb);
    }
    for(unsigned i = 0; i < shuffled.size(); i++)
    {
        cout << shuffled.at(i) << " ";
    }
}
