#ifndef PLAYER_H
#define PLAYER_H

#include "./Deck.h"

class Player{
    public:

        // default constructor
        Player();

        // Getter - toPlay deck
        Deck* GetToPlayDeck();

        // Getter - played deck
        Deck* GetPlayedDeck();

        // returns top card of toPlay
        // shuffles and replaces toPlay with played if toPlay is empty
        Card* PlayCard();

        // returns true if player has cards
        bool HasCards();

        // default destructor
        ~Player();

    private:

        // hold cards that player plays from
        Deck* toPlay;

        // holds cards that have been played
        Deck* played;
};


#endif // PLAYER_H
