#include "game.hpp"
#include <stdio.h>
#include "card.hpp"
#include <iostream>
#include <cstdlib>


namespace ariel{}
using namespace std;

Game::Game(Player &p1, Player &p2){
    this->p1=&p1;
    this->p2=&p2;
    for(int i=0;i<53;i++){
        this->cards[i].setShape("");
        this->cards[i].setValue(0);

    }
    createDeck();
    splitDecks();
}


void Game::splitDecks(){
    // Dealing the deck to the players.
    for(int i=1;i<53;i++){
        if(i<=26){
            this->p1->addCard(this->cards[i]);
        }
        else{
            this->p2->addCard(this->cards[i]);
        }
    }        
}

void Game::createDeck(){
    int index=1;
    for(int i=1;i<=13;i++){
        Card card("hearts",i);
        this->cards[index++]=card;
    }
    for(int i=1;i<=13;i++){
        Card card("clubs",i);
        this->cards[index++]=card;
    }
    for(int i=1;i<=13;i++){
        Card card("diamonds",i);
        this->cards[index++]=card;
    }
    for(int i=1;i<=13;i++){
        Card card("spades",i);
        this->cards[index++]=card;
    }
    shuffle();
}

void Game::shuffle(){
    Card shuffled_deck[53];
    int count_minus=0;
    int index=1;
    srand(time(nullptr));
    while(count_minus<52){
        // Generate random index number between 1 to 53. Without the 0 index.
        int random = rand()%53+1;  
        // Check if the card already exists in the shuffled deck. 
        if(shuffled_deck[index].getValue()!= this->cards[random].getValue() && shuffled_deck[index].getShape()!= this->cards[random].getShape()){
            shuffled_deck[index].setShape(this->cards[random].getShape());
            shuffled_deck[index].setValue(this->cards[random].getValue());
            index++;
            count_minus++;
        }
    }
    //Setting the original deck to the shuffeld one.
    for(int i=1;i<53;i++){
        this->cards[i].setShape(shuffled_deck[i].getShape());
        this->cards[i].setValue(shuffled_deck[i].getValue());

    }
}
void Game::printDeck(){
    for(int i=1;i<53;i++){
        cout << to_string(this->cards[i].getValue()) + " of " + this->cards[i].getShape()<<endl;
    }
}
void Game::playTurn(){
    if(this->p1->peek() > this->p2->peek()){
        this->p1->cardsWon(this->p1->getCard(), this->p2->getCard());
    }
    else if (this->p1->peek() < this->p2->peek())
    {
        this->p2->cardsWon(this->p2->getCard(), this->p1->getCard());
    }
    // In case of draw.
    else{
        bool draw_winner=false;
        vector<Card> alice; // Stands for p1 stack.
        vector<Card> bob;   // Stands for p2 stack.
        while(draw_winner==false && this->p1->stacksize()>0){
            alice.push_back(this->p1->getCard());
            alice.push_back(this->p1->getCard());
            alice.push_back(this->p1->getCard());
            bob.push_back(this->p2->getCard());
            bob.push_back(this->p2->getCard());
            bob.push_back(this->p2->getCard());
            if(alice.back()>bob.back()){
                draw_winner=true;
                while(alice.size()>0){
                    this->p1->cardsWon(alice.pop_back(),bob.pop_back());
                }
            }
            else if(alice.back()<bob.back()){
                draw_winner=true;
                while(alice.size()>0){
                    this->p2->cardsWon(bob.pop_back(),alice.pop_back());
                }
            }
            else{
                continue;
            }
            
        }
    }
        
    
    
}

void Game::playAll(){}
void Game::printLastTurn(){}
void Game::printLog(){}
void Game::printStats(){}
void Game::printWiner(){}
