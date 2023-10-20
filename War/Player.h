#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "CardPile.h"

class Player{
    public:
        //default constructor
        Player();

        //gets main pile
        CardPile* GetDeck();
        //gets played cards
        CardPile* GetPlayedCards();

        //draws card from players deck, if returns null then player loses
        Card* playCard();

        //destructor
        ~Player();


    private:
        //players main pile
        CardPile* deck = new CardPile();
        //cards that have been played and won
        CardPile* playedCards = new CardPile();

        //shuffles playedCards and replaces deck
        void usePlayedCards();
};

#endif // PLAYER_H
