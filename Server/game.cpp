#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include "drawfour.h"
#include "wild.h"
#include "numbered.h"
#include "reverse.h"
#include "drawtwo.h"
#include "skip.h"
#include "game.h"
#include "card.h"

using namespace std;
//small change
Game :: Game ()
{
    int i;
    for(i = 1; i <= 108; i++ )
    {
        if(i >= 105)
            card_list[i] = new drawFour(i, 4);
        else if(i >= 101)
            card_list[i] = new Wild(i);
        else
        {
            char c;
            if(i <= 25)
                c = 'r';
            else if(i <= 50)
                c = 'g';
            else if(i <= 75)
                c = 'b';
            else
               c = 'y';
            if((i % 25) <= 10 && i % 25 !=0)
            {
                card_list[i] = new Numbered(i%25-1, c);
            }
            else if((i % 25) <= 19 && i % 25 != 0)
            {
                card_list[i] = new Numbered(i%25-10, c);
            }
            else if((i%25) <= 21 && i % 25 != 0)
            {
                card_list[i] = new Skip(i ,c);
            }
            else if((i%25) <= 21 && i % 25 != 0)
            {
                card_list[i] = new Reverse(i, c);
            }
            else
            {
                card_list[i] = new  drawTwo(2, i);
            }
        }
    }
}

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
