#include "WarPrinter.h"
#include "Card.h"

#include <iostream>

using namespace std;

//default constructor
WarPrinter::WarPrinter(){};

//welcomes user
void WarPrinter::PrintWelcome(){
    cout << "Welcome to the Game of War!" << endl << endl;
}

//notification of shuffling
void WarPrinter::PrintShuffle(){
    cout << "Shuffling..." << endl;
}

//initial deck intro
void WarPrinter::PrintInitialDeckIntro(){
    cout << endl << "Initial decks: " << endl;
}

//prints player info at start of game
void WarPrinter::PrintPlayerInfo(char* playerId, int numCards){
    cout << "Player " << *playerId << ": " << endl;
    cout << "There are " << numCards << " cards in the deck" << endl;
}

//prints cards for when cards are dealt;
void WarPrinter::PrintCard(int index, int* cardValue, int* cardSuit){
    cout << "Card " << index << ", ";
    PrintCard(cardValue, cardSuit);
    cout << endl;
}

//prints round
void WarPrinter::PrintRound(int round){
    cout << endl << "========== Round " << round << " ==========" << endl;
}

//prints player deck is empty
void WarPrinter::PrintDeckEmpty(char* playerID){
    cout << "Player " << *playerID << "'s deck is empty!" << endl;
    cout << "They are using their played cards." << endl;
}

//prints player's attack
void WarPrinter::PrintAttack(char* playerID, int* cardValue, int* cardSuit){

    cout << "Player " << *playerID << " plays ";
    PrintCard(cardValue, cardSuit);
    cout << endl;
}

//prints winner of a battle
void WarPrinter::PrintBattleWinner(char* playerID){
    cout << "Player " << playerID << " wins the loot!" << endl << endl;
}

//prints when there is a tie
void WarPrinter::PrintTie(){
    cout << "It's a tie!" << endl;
    cout << "The battle continues..." << endl << endl;
}

//prints players card counts
void WarPrinter::PrintPlayerDeckInfo(char* playerID, int* numCardsDeck, int* numCardsPlayed){
    cout << "Player " << *playerID << " has " << *numCardsDeck << " cards in their deck and ";
    cout << *numCardsPlayed << " cards in their played pile" << endl;
}

//prints winner of the game
void WarPrinter::PrintGameResults(char* loserID, char* winnerID){
    cout << endl << "Player " << *loserID << " is out of cards. Player " << *winnerID << " wins!" << endl;
}


//logic for combining a card's value and suit, without new line
void WarPrinter::PrintCard(int* value, int* suit){

    //instantiate array
    char* valueString = new char[20];

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


    //instantiating array for largest suit name (diamonds)
    char* suitString = new char[20];

    //switch statement to return suit c string
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
            suitString = "Blank";
            break;
    }
    cout << valueString << " of " << suitString;
    /* TODO: delete these
    for(int i = 0; i < 10 ;i++){
        valueString[i] == 0;
    }
    delete valueString;
    for(int i = 0; i < 10 ;i++){
        if(suitString[i] == '\0'){
            suitString[i] == 0;
        }
    }
    delete suitString;
    */
}
