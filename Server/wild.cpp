#include "wild.h"
#include <vector>
Wild::Wild(int a) : Special(a), colorChange(a)
{

}
string Wild::play(Game &game, int choice, char ch)
{
    if(ch == 's')
    {

    }
    else
    {

    }
    game.top_card = game.player.card_list[choice-1];
    game.player.card_list.erase(game.player.card_list.begin()+choice-1);

}
