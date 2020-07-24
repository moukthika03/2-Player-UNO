#include "numbered.h"
#include <vector>

using namespace std;

Numbered::Numbered(int value, char colour)
{
    this->value = value;
    this->colour = colour;
}

string Numbered :: play(Game &game, int choice, char ch)
{
    game.top_card = game.player.card_list[choice-1];
    game.player.card_list.erase(game.player.card_list.begin()+choice-1);
    if(ch == 's')
    {

    }
    else
    {

    }
    return "Check";
}
