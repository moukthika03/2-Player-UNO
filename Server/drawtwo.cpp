#include "drawtwo.h"
#include <vector>

drawTwo::drawTwo(int draw, int value) : Special(value), Draw(draw, value)
{

}

string drawTwo :: play(Game &game, int choice, char ch)
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
    }
    string c = "2 ";
    int a = game.draw();
    c.append(to_string(a));
    c.append(" ");
    a = game.draw();
    c.append(to_string(a));
    game.shuffled.push_back(game.top_card);
    random_shuffle(game.shuffled.begin(), game.shuffled.end());
    game.top_card = choice;
    return c;
}
