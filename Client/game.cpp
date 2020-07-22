#include "game.h"
#include <string>
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

}
