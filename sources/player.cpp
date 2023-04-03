#include "player.hpp"
#include <string>
#include <iostream>
#include "game.hpp"

using namespace std;
using namespace ariel;

Player:: Player(string name){
    this->name = name;
    this->deck={};
    this->won=0;
}

int Player::stacksize(){
    return this->deck.size();
}

int Player::cardesTaken(){
    return this->won;
}

string Player::getName(){
    return this->name;
}

void Player::addCard(Card card){
    this->deck.push_back(card);
}

void Player::cardsWon(){
    this->won+=2;
}

// void Player::drawCase(Card card){
//     this->cards_won.push_back(card);
// }

Card& Player::getCard(){
    if(this->stacksize()>0){
        Card& card=this->deck.back();
        this->deck.pop_back();
        return card;
    }
    throw "Deck is empty.";
}

int Player::peek(){
    if(this->stacksize()){
        return this->deck.back().getValue();
    }
    throw "Deck is empty.";
}
Card Player::back(){
    if(this->stacksize()){
        return this->deck.back();
    }
    throw "Deck is empty.";
}

