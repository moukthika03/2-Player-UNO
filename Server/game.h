#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "card.h"
#include "server.h"
#include "player.h"

using namespace std;

class Game
{
private:
    vector<int> card_list_client;
    vector<int> shuffled;
    server host;
    int top_card;
    vector<Card*> card_list;
    Player server_player;
public:
    void shuffle_and_distribute();

};

#endif // GAME_H
