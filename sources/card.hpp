#ifndef CARD_HPP
#define CARD_HPP
#include <string>

using namespace std;

class Card{
    private:
    int value;
    string shape;

    public:
    Card(){}
    Card(string shape, int value);
    void setValue(int value);
    void setShape(string shape);
    int getValue();
    string getShape();
};
#endif