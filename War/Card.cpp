#include <iostream>
#include "Card.h"

using namespace std;

Card::Card(int* value, int* suit){
    this->value = value;
    this->suit = suit;
}

int* Card::GetValue(){
    return value;
}

//sets value of the card
void Card::SetValue(int* value){
    this->value = value;
}

//gets suit id of the card (in alphabetical order)
int* Card::GetSuit(){
    return suit;
}

void Card::SetSuit(int* suit){
    this->suit = suit;
}

//outputting card as {value} of {suit}
char* Card::ToString(){
    //instantiating output string
    char* output = new char[16];

    //define pieces of output
    char* cardValue = GetValueString();
    char* preposition = " of ";
    char* cardSuit = GetSuitString();

    //iterator for output
    int n = 0;
    //concat card value
    for(int i = 0; cardValue[i] != '\0'; i++, n++){
        output[i] = cardValue[i];
    }
    //concat preposition
    for(int j = 0; preposition[j] != '\0'; j++, n++){
        output[n] = preposition[j];
    }
    //concat card suit
    for(int k = 0; cardSuit[k] != '\0'; k++, n++){
        output[n] = cardSuit[k];
    }
    //concat terminator
    output[n] = '\0';

    return output;
}

char* Card::GetValueString(){
    //instantiate array
    char* valueString = new char[6];

    //array of char arrays for possible values
    char** possibleValues = new char*[13]{
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "jack",
        "queen",
        "king"
    };

    //sets value of valueString to corresponding array in possibleValues
    valueString = possibleValues[*value - 1];

    //deletes possibleValues array
    delete possibleValues;
    //returns pointer to valueString

    return valueString;
}

char* Card::GetSuitString(){
    //instantiating array for largest suit name (diamonds)
    char* suitString = new char[9];

    //switch statement to return suits
    switch(*suit){
        case 0:
            suitString = "clubs";
            break;
        case 1:
            suitString = "diamonds";
            break;
        case 2:
            suitString = "hearts";
            break;
        case 3:
            suitString = "spades";
            break;
        default:
            std::cout << "invalid suit" << std::endl;
            break;
    }

    return suitString;
}
