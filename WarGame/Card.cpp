#include "Card.h"

//default constructor
Card::Card(int value, int suit){
    this->value = value;
    this->suit = suit;
}

//returns card value
int* Card::GetValue(){
    return &value;
}

//gets suit id of the card (in alphabetical order)
int* Card::GetSuit(){
    return &suit;
}

//default destructor
Card::~Card(){};
