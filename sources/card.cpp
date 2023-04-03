# include "card.hpp"


namespace ariel{}
using namespace std;

Card::Card(string shape, int value){
    this->shape = shape;
    this->value = value;
}
void Card::setValue(int value){
    this->value = value;
}
void Card::setShape(string shape){
    this->shape = shape;
}
int Card::getValue(){
    return this->value;
}

string Card::getShape(){
    return this->shape;
}

