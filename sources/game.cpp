#include "game.hpp"
#include <stdio.h>

namespace ariel{}
using namespace std;

Game::Game(Player p1, Player p2){
    this->p1=p1;
    this->p2=p2;
}
void Game::playAll(){}
void Game::playTurn(){}
void Game::printLastTurn(){}
void Game::printLog(){}
void Game::printStats(){}
void Game::printWiner(){}
