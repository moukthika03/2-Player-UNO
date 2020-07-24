#include "wild.h"
#include <vector>
Wild::Wild(int a) : Special(a), colorChange(a)
{

}
string Wild::play(Game &game, int choice, char ch)
{
    string s="1 ";
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
    int temp = game.top_card%25;
    switch(color)
    {
        case 'r':   {
                        break;
                    }
        case 'y':   {
                        temp+=25;
                        break;
                    }
        case 'b':   {
                        temp+=50;
                        break;
                    }
        case 'g':   {
                         temp+=75;
                         break;
                    }
    }
    game.shuffled.push_back(game.top_card);
    random_shuffle(game.shuffled.begin(), game.shuffled.end());
    game.top_card = temp;
    s.append(to_string(game.top_card));
    return s;
}
