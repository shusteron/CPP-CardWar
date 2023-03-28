#include "card.hpp"
#include "game.hpp"
#include "player.hpp"
#include "doctest.h"

#include <iostream>
#include <string>
#include <stdio.h>

TEST_CASE("is the cards split evenly"){
    Player p1("ron");
    Player p2("shuster");
    Game game(p1,p2);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);

}

TEST_CASE("is the number of both stacks equel to 52 after a turn"){
    Player p1("ron");
    Player p2("shuster");
    Game game(p1,p2);
    game.playTurn();
    CHECK(p1.stacksize()+p1.cardesTaken()+p2.cardesTaken()+p2.stacksize()==52);
    
}

TEST_CASE("is constructors initialized succeessfully"){
    Player p1("ron");
    Player p2("shuster");
    CHECK_NOTHROW(Player p3("joey"));
    CHECK_NOTHROW(Player p4("tribiano"));
    CHECK_NOTHROW(Game game(p1,p2));

}
TEST_CASE("check if decks are finished successfully"){
    Player p1("ron");
    Player p2("shuster");
    Game game(p1,p2);
    game.playAll();
    CHECK((p1.stacksize()==0 && p2.stacksize()==0));
}

TEST_CASE("is the game finished"){
    Player p1("ron");
    Player p2("shuster");
    Game game(p1,p2);
    game.playAll();
    CHECK(p1.stacksize()==0);
    CHECK(p2.stacksize()==0);
}

TEST_CASE("Are the methods pass successfully?"){
    Player p1("ron");
    Player p2("shuster");
    Game game(p1,p2);
    CHECK_NOTHROW(p1.cardesTaken());
    CHECK_NOTHROW(p1.stacksize());
    CHECK_NOTHROW(p2.cardesTaken());
    CHECK_NOTHROW(p2.stacksize());
    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printStats());

}

TEST_CASE("Doesn't let play after game finished"){
    Player p1("ron");
    Player p2("shuster");
    Game game(p1,p2);
    game.playAll();
    CHECK_THROWS(game.playTurn());
}



