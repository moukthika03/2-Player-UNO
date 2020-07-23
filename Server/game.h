#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "card.h"
#include "wild.h"
#include "drawtwo.h"
#include "drawfour.h"
#include "numbered.h"
#include "skip.h"
#include "reverse.h"
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
    Game()
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
    string shuffle_and_distribute();
    string getColor(int);
    string getNumber(int);
    void displayCards();
    bool verify(int);
    void drawCards();

    friend class server;
};

#endif // GAME_H
