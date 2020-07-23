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
    Game();
    string shuffle_and_distribute();
    string getColor(int);
    string getNumber(int);
    void displayCards();
    bool verify(int);
    void drawCards();

    friend class server;
};

#endif // GAME_H
