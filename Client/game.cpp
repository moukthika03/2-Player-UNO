#include "game.h"
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
Game::Game()
{

}

void Game :: setFirstCards(string first_cards)
{
    this->first_cards = first_cards;
    split();
}

void Game :: split()
{
    int n = first_cards.length();
    cout << "\nLength of first cards is " << n << endl;
    char char_array[n + 1];

    strcpy(char_array, first_cards.c_str());
    cout << "\nChar array is " << endl;
    for (int i = 0; i < n; i++)
            cout << char_array[i];
    cout << endl;
    char *token = strtok(char_array, " ");

    int spaces = 0;
    for (int i = 0; i < n; i++)
            if (char_array[i] == ' ')
                spaces++;
    cout << "Number of spaces are " << spaces << endl;
    while (token != NULL)
    {
       cout << "\ninside\n";
       cout << "token is " << token << endl;
       int num = stoi(token);
       player.card_list.push_back(num);
       token = strtok(NULL, " ");
    }

    cout << "\nCard list is " << endl;
    for (unsigned i = 0; i < player.card_list.size(); i++)
            cout << player.card_list[i] << " ";
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
