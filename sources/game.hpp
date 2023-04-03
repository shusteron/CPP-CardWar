#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include <vector>
#include "card.hpp"

namespace ariel{}
using namespace std;

class Game{
    private:
    Player* p1;
    Player* p2;
    Card cards[53];
    void shuffle();
    void createDeck();
    void printDeck();
    void splitDecks();

    

    public:
    
    Game(){}
    Game(Player &p1, Player &p2);

    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
};
#endif
