#include "wild.h"
#include <vector>
Wild::Wild(int a) : Special(a), colorChange(a)
{

}
string Wild::play(Game &game, int choice, char ch)
{
    game.top_card = game.player.card_list[choice-1];
    game.player.card_list.erase(game.player.card_list.begin()+choice-1);
    return "Check";
}
