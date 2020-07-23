#include "game.h"
#include "card.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

string Game :: shuffle_and_distribute()
{
    while(shuffled.size()!= 108)
    {
        int numb = rand()%108 + 1;
        if( find(shuffled.begin(), shuffled.end(), numb) == shuffled.end())
            shuffled.push_back(numb);
    }

    cout << endl;
    for (unsigned i = 0; i < 7; i++)
    {
        player.card_list.push_back(shuffled[0]);
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


   top_card = shuffled[0];
   shuffled.erase(shuffled.begin());
    cout << "Top card is " << top_card << endl;
    displayCards();
    return client_cards;
}

string Game:: getColor(int num)
{
    if (num <= 25)
        return "Red";
    else if (num <= 50)
        return "Yellow";
    else if(num <= 75)
        return "Green";
    else if(num <= 100)
        return "Blue";
    else
        return "Special";
}
string Game::getNumber(int num)
{
    if(num >= 105)
        return "Draw 4";
    else if(num >= 101)
        return "Wild";
    else
    {
        if((num % 25) <= 10)
            return to_string((num%25) - 1);
        else if((num % 25) <= 19)
            return to_string((num%25) - 10);
        else if((num%25) <= 21)
            return "Skip";
        else if((num%25) <= 23)
            return "Reverse";
        else
            return "Draw 2";
    }
}

void Game::displayCards()
{
    cout << "\nYou have the cards:" << endl;
    for (unsigned i = 0; i < player.card_list.size(); i++)
    {
        cout << endl << i+1 << ". ";
        cout << getColor(player.card_list[i]) << " " << getNumber(player.card_list[i]) << " " ;
    }
}


bool Game::verify(int chosen)
{
    if(chosen % 25 == top_card % 25)
    {
        return true;
    }
    int i = 1, j = 25;
    for(; i < 75; i += 25, j += 25)
    {
        if((i <= chosen && chosen <= j) && (i <= top_card && top_card <= j) )
            return true;
    }
    return false;
}

void Game :: drawCards()
{
    player.card_list.push_back(shuffled[0]);
    shuffled.erase(shuffled.begin());
}
