#include "game.hpp"
#include <stdio.h>
#include "card.hpp"
#include <iostream>
#include <cstdlib>

#define ACE=1;

namespace ariel{}
using namespace std;

Game::Game(Player &p1, Player &p2){
    this->p1=&p1;
    this->p2=&p2;
    this->summary="";
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
string Game::getTurn(string name, Card card){
    return name + " played " + to_string(card.getValue()) + " of " + card.getShape()+".";

}
void Game::playTurn(){

    if(this->p1->peek() > this->p2->peek() && this->p2->peek()!=ACE){
        
        Card& a = this->p1->getCard();
        Card& b = this->p2->getCard();
        this->p1->cardsWon(a, b);
        this->summary+= this->getTurn(this->p1->getName(),a)+
                        this->getTurn(this->p2->getName(),b)+
                        this->p1->getName() + " won.\n";
    }
    else if (this->p1->peek() < this->p2->peek() && this->p2->peek()!=2)
    {
        
        Card& a = this->p1->getCard();
        Card& b = this->p2->getCard();
        this->p2->cardsWon(a, b);
        this->summary+= this->getTurn(this->p1->getName(),a)+
                        this->getTurn(this->p2->getName(),b)+
                        this->p2->getName() + " won.\n";
    }
    // In case of draw.
    else{
        this->summary+=" Draw. ";
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
            if(alice.back().getValue()>bob.back().getValue()){
                this->summary+= this->getTurn(this->p1->getName(),a)+
                        this->getTurn(this->p2->getName(),b)+
                        this->p1->getName() + " won.\n";
                draw_winner=true;
                while(alice.size()>0){
                    this->p1->cardsWon(alice.back(),bob.back());
                    alice.pop_back();
                    bob.pop_back();
                }
            }
            else if(alice.back().getValue()<bob.back().getValue()){
                draw_winner=true;
                while(alice.size()>0){
                    this->p2->cardsWon(bob.back(),alice.back());
                    alice.pop_back();
                    bob.pop_back();
                }
            }
            else{
                continue;
            }
            
        }
        if(draw_winner==false){
            while(alice.size()>0){
                this->p1->drawCase(alice.back());
                this->p2->drawCase(bob.back());
                alice.pop_back();
                bob.pop_back();
            }
        }
    }
        
    
    
}

void Game::playAll(){}
void Game::printLastTurn(){
    cout<< this->summary<<endl;
}
void Game::printLog(){}
void Game::printStats(){}
void Game::printWiner(){}
