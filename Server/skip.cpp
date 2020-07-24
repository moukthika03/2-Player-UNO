#include "skip.h"
#include <vector>

Skip::Skip(int value, char color) : Special(value)
{
    this->color = color;
}

string Skip :: play(Game &game, int choice, char ch)
{
    game.top_card = game.player.card_list[choice-1];
    game.player.card_list.erase(game.player.card_list.begin()+choice-1);
    return "Check";
}
