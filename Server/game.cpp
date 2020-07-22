#include "game.h"
#include "card.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void Game :: shuffle_and_distribute()
{
    while(shuffled.size()!= 108)
    {
        int numb = rand()%108 + 1;
        if( find(shuffled.begin(), shuffled.end(), numb) == shuffled.end())
            shuffled.push_back(numb);
    }
    for(unsigned i = 0; i < shuffled.size(); i++)
    {
        cout << shuffled.at(i) << " ";
    }
    cout << endl;
    for (unsigned i = 0; i < 7; i++)
    {
        server_player.card_list.push_back(shuffled[0]);
        shuffled.erase(shuffled.begin());
    }

    for (unsigned i = 0; i < 7; i++)
    {
        card_list_client.push_back(shuffled[0]);
        shuffled.erase(shuffled.begin());
    }

    string client_cards;

    for (unsigned i = 0; i < 7; i++)
    {
        int number = card_list_client[i];
        string sm_str = to_string(number);
        client_cards += sm_str + " ";
    }

    client_cards.pop_back();

    //cout << endl << client_cards;
   host.set_clinet_cards(client_cards);

   top_card = shuffled[0];
   shuffled.erase(shuffled.begin());
    cout << "Top card is " << top_card << endl;
    for(unsigned i = 0; i < shuffled.size(); i++)
    {
        cout << shuffled.at(i) << " ";
    }
}
