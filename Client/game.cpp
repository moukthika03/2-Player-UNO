#include "game.h"
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


void Game :: setFirstCards(string first_cards)
{
    this->first_cards = first_cards;
    split();
}

bool Game::verify(int chosen)
{

    /*cout << "\nTop card is " << top_card << endl;
    cout << "Chosen card is " << chosen << endl;*/
    if(chosen == 0 || (chosen >= 101 && chosen <= 108))
        return true;
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
    for(; i <= 76; i += 25, j += 25)
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


void Game :: split()
{
    int n = first_cards.length();
    char char_array[n + 1];

    strcpy(char_array, first_cards.c_str());
    cout << "\nChar array is " << endl;
    for (int i = 0; i < n; i++)
            cout << char_array[i];
    cout << endl;
    char *token = strtok(char_array, " ");

    while (token != NULL)
    {

       int num = stoi(token);
       player.card_list.push_back(num);
       token = strtok(NULL, " ");
    }

    /*
    cout << "\nCard list is " << endl;
    for (unsigned i = 0; i < player.card_list.size(); i++)
            cout << player.card_list[i] << " ";
    */
    displayCards();
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
