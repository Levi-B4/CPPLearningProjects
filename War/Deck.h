#ifndef DECK_H
#define DECK_H

#include "./Card.h"

#define MAX_CARDS 52

class Deck{
    public:

        //default constructor
        Deck();

        //adds card to the bottom of the deck
        void AddCard(Card* card);

        //removes top card from the deck
        Card* DrawCard();

        //getter - numCards
        int GetNumCards();

        //randomizes card order
        void Shuffle();

        //outputs the cards in the deck
        void PrintCards();

        //default destructor
        ~Deck();

    private:

        //Cards in deck
        Card* cards[MAX_CARDS];

        //tracks number of cards in deck
        int numCards;


};

#endif // DECK_H
