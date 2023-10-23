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

        //default destructor
        ~WarPrinter();

    private:
        //logic for combining a card's value and suit, without new line
        void PrintCard(int* cardValue, int* cardSuit);
};



#endif // WARPRINTER_H
