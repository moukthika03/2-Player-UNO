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
