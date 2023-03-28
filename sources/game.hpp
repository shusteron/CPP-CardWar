#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"

namespace ariel{}
using namespace std;

class Game{
    Player p1;
    Player p2;

    public:
    
    Game(){}
    Game(Player p1, Player p2);

    void playTurn();

    void printLastTurn();

    void playAll();

    void printWiner();

    void printLog();
    void printStats();

};
#endif
