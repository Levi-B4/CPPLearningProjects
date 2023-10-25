#ifndef WARPRINTER_H
#define WARPRINTER_H

#include "Card.h"


//outputs to console
class WarPrinter{
    public:
        //default constructor
        WarPrinter();

        //welcomes user
        void PrintWelcome();

        //notification of shuffling
        void PrintShuffle();

        //initial deck intro
        void PrintInitialDeckIntro();

        //prints player info at start of game
        void PrintPlayerInfo(char* playerID, int numCards);

        //prints cards for when cards are dealt;
        void PrintCard(int index, int* cardValue, int* cardSuit);

        //prints requested round
        void PrintRound(int round);

        //prints player deck is empty
        void PrintDeckEmpty(char* playerID);

        //prints player's attack
        void PrintAttack(char* playerID, int* cardValue, int* cardSuit);

        //print who wins an attack
        void PrintBattleWinner(char* playerID);

        //print when there is a tie
        void PrintTie();

        //prints player's card count
        void PrintPlayerDeckInfo(char* playerID, int* numCardsDeck, int* numCardsPlayed);

        //prints winner of the game
        void PrintGameResults(char* loserID, char* winnerID);

        //prints blank line
        void PrintBlankLine();

        //default destructor
        ~WarPrinter();

    private:
        //logic for combining a card's value and suit, without new line
        void PrintCard(int* cardValue, int* cardSuit);

        //allows char* to be set to a const char* and still be deleted
        void constCStringToCString(char* cString, const char* constCString);
};



#endif // WARPRINTER_H
