#ifndef CARD_PILE_H
#define CARD_PILE_H

#include "Card.h"

class CardPile{
    public:
        //default Constructor
        Pile();

        //adds card to end of card array
        void AddCardToPile(Card* card);
        //simulates drawing a card
        Card* DrawCard();
        //returns total number of cards in card array
        int GetNumCards();
        //randomizes order of card array
        void Shuffle();
        //prints out number of cards
        void PrintCards();

        //destructor
        ~CardPile();

    private:
        //holds all cards in pile
        Card * cards[52];
        //total cards in pile
        int numCards;
};

#endif // CARD_PILE_H
