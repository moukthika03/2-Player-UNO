#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "card.h"

#include "player.h"

using namespace std;

class Game
{
private:
    vector<int> card_list_client;
    vector<int> shuffled;

    int top_card;
    vector<Card*> card_list;
    Player player;
public:
    string shuffle_and_distribute();
    string getColor(int);
    string getNumber(int);
    void displayCards();

    friend class Server;
};

#endif // GAME_H
