#include "drawfour.h"
#include <vector>

drawFour::drawFour(int draw, int value) : Special(value), Draw(draw, value), colorChange(value)
{

}

string drawFour :: play(Game &game, int choice, char ch)
{
    char color;
    if(ch == 's')
    {
        vector<int>::iterator it;
        it=find (game.player.card_list.begin(), game.player.card_list.end(), choice);
        int n = it - game.player.card_list.begin();  //number from 0
        game.player.card_list.erase(game.player.card_list.begin()+n);
        /*Debugging code*/
        /*for (int i=0; i<game.player.card_list.size(); i++)
            std::cout << ' ' << game.player.card_list[i];*/
        cout<<"\nEnter colour(r, y, g, b):";
        cin>>color;
    }
    else
    {
        color = ch;
    }
    string c = "2 ";
    int a, i;
    for(i=0; i<4; i++)
    {
         a = game.draw();
         c.append(to_string(a));
         c.append(" ");
    }
    int temp;
    switch(color)
    {
        case 'r':   {
                        temp = -1;
                        break;
                    }
        case 'y':   {
                        temp = -2;
                        break;
                    }
        case 'b':   {
                        temp = -3;
                        break;
                    }
        case 'g':   {
                         temp = -4;
                         break;
                    }
    }
    game.shuffled.push_back(game.top_card);
    random_shuffle(game.shuffled.begin(), game.shuffled.end());
    game.top_card = temp;
    c.append(to_string(game.top_card));
    return c;
}
