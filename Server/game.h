#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include"player.h"
using namespace std;
//small change
class Game
{
private:
    vector<int> card_list_client;
    vector<int> shuffled;
    int top_card;

    Player player;
public:
    Game()
    {

    }
    string shuffle_and_distribute();
    string getColor(int);
    string getNumber(int);
    void displayCards();
    bool verify(int);
    void drawCards();

    friend class Numbered;
    friend class drawFour;
    friend class drawTwo;
    friend class Reverse;
    friend class Skip;
    friend class Wild;
    friend class server;
};

#endif // GAME_H
