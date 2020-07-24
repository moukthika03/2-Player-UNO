#include "reverse.h"
#include <vector>

Reverse::Reverse(int value, char color) : Special (value)
{
    this->color = color;
}

string Reverse :: play(Game &game, int choice, char ch)
{
    if(ch == 's')
    {
        vector<int>::iterator it;
        it=find (game.player.card_list.begin(), game.player.card_list.end(), choice);
        int n = it - game.player.card_list.begin();  //number from 0
        game.player.card_list.erase(game.player.card_list.begin()+n);
        /*Debugging code*/
        /*for (int i=0; i<game.player.card_list.size(); i++)
            std::cout << ' ' << game.player.card_list[i];*/
        //returns the top card only
    }
    game.top_card = choice;
    return "Play again";
}
