#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdio.h>
#include <vector>
#include "card.hpp"

namespace ariel{}
using namespace std;
class Player{
    private:
    string name;
    vector<Card> deck;
    vector<Card> cards_won;
    
    
    public:
        Player(){}
        Player(string name);
        int stacksize();
        int cardesTaken();
        void addCard(Card card);
        Card getCard();
        Card peek();
        void cardsWon(Card card1,Card card2);
        void cardsWon(Card card);
        string getName();

};
#endif
