#include "drawfour.h"
#include <vector>

drawFour::drawFour(int draw, int value) : Special(value), Draw(draw, value)
{

}

string drawFour :: play(Game &game, int choice, char ch)
{
    game.top_card = game.player.card_list[choice-1];
    game.player.card_list.erase(game.player.card_list.begin()+choice-1);
    return "Check";
}


