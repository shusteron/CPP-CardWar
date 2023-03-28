#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdio.h>

namespace ariel{}
using namespace std;
class Player{

    string name;
    
    public:
        Player(){}
        Player(string name);
        int stacksize();
        int cardesTaken();
};
#endif
