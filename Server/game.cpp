#include "game.h"
#include "card.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <drawfour.h>
#include <wild.h>
#include <numbered.h>
#include <reverse.h>
#include <drawtwo.h>
#include <skip.h>
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
string  Game:: getNumber(int num)
{
    if(num >= 105)
        return "Draw 4";
    else if(num >= 101)
        return "Wild";
    else
    {
        if((num % 25) <= 10 && num % 25 != 0)
            return to_string((num%25) - 1);
        else if((num % 25) <= 19 && num % 25 != 0)
            return to_string((num%25) - 10);
        else if((num%25) <= 21 && num % 25 != 0)
            return "Skip";
        else if((num%25) <= 23 && num % 25 != 0)
            return "Reverse";
        else
            return "Draw 2";
    }
}

void Game::displayCards()
{
    cout << "\nThe Top card is " << getColor(top_card) << " " << getNumber(top_card) << " Code is " << top_card << endl;
    cout << "\nYou have the cards:" << endl;
    for (unsigned i = 0; i < player.card_list.size(); i++)
    {
        cout << endl << i+1 << ". ";
        cout << getColor(player.card_list[i]) << " " << getNumber(player.card_list[i]) << " Code is " << player.card_list[i] << " " ;
    }
}


bool Game::verify(int chosen)
{
    cout << "\nTop card is " << top_card << endl;
    cout << "Chosen card is " << chosen << endl;
    if(top_card == -1 && (chosen >= 1 || chosen <= 25))
        return true;
    if(top_card == -2 && (chosen >= 25 || chosen <= 50))
        return true;
    if(top_card == -3 && (chosen >= 51 || chosen <= 75))
        return true;
    if(top_card == -4 && (chosen >= 75 || chosen <= 100))
        return true;
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

bool Game :: verifyAll()
{
    for(unsigned i = 0; i < player.card_list.size(); i++)
    {
        if (verify(player.card_list[i]))
        {
            return false;
        }
    }
    return true;
}

bool Game :: drawCards()
{
    bool flag = false;
    if(!verifyAll())
    {
        player.card_list.push_back(shuffled[0]);
        if (verify(shuffled[0]))
        {
            top_card = shuffled[0];
            player.card_list.erase(player.card_list.end());
            flag = true;
        }
        shuffled.erase(shuffled.begin());

    }
    return flag;
}
