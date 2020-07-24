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
    if(ch == 's')
    {
        game.top_card = choice;
        vector<int>::iterator it;
        it=find (game.player.card_list.begin(), game.player.card_list.end(), choice);
        int n = it - game.player.card_list.begin();  //number from 0
        game.player.card_list.erase(game.player.card_list.begin()+n);
        /*Debugging code*/
        /*for (int i=0; i<game.player.card_list.size(); i++)
            std::cout << ' ' << game.player.card_list[i];*/
        //returns the top card only
    }
    else
    {
        game.top_card = choice;
    }
    return to_string(game.top_card);
}
