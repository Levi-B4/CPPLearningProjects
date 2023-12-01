#ifndef DECK_H
#define DECK_H

#include <stack>

#include "./Card.h"

#define MAX_CARDS 52

using std::stack;

class Deck{
    public:

        //default constructor
        Deck();

        //adds card to the bottom of the deck
        void AddCard(Card* card);

        //removes top card from the deck
        Card* DrawCard();

        //returns number of cards in cards stack
        int GetNumCards();

        //randomizes card order
        void Shuffle();

        //outputs the cards in the deck to the user
        void PrintCards();

        //default destructor
        ~Deck();

    private:

        //Cards in deck
        stack<Card*> cards;
};

#endif // DECK_H
