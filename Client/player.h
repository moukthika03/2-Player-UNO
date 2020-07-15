#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

using namespace std;

class Player
{
private:
    vector<int> card_list;
public:
    Player();
    friend class Game;
};

#endif // PLAYER_H
