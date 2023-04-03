#include "player.hpp"
#include <string>
#include <iostream>
#include "game.hpp"

using namespace std;
using namespace ariel;

Player:: Player(string name){
    this->name = name;
    this->deck={};
    this->cards_won={};
}

int Player::stacksize(){
    return this->deck.size();
}

int Player::cardesTaken(){
    return this->cards_won.size();
}

string Player::getName(){
    return this->name;
}

void Player::addCard(Card card){
    this->deck.push_back(card);
}

void Player::cardsWon(Card card1, Card card2){
    this->cards_won.push_back(card1);
    this->cards_won.push_back(card2);

}

void Player::drawCase(Card card){
    this->cards_won.push_back(card);
}

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

