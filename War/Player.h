#ifndef PLAYER_H
#define PLAYER_H

#include "./deck.h"

class Player{
    public:

        //default constructor
        Player();

        //Getter - toPlay deck
        Deck* GetToPlayDeck();

        //Getter - played deck
        Deck* GetPlayedDeck();

        //returns true if player has cards
        bool HasCards();

        ~Player();

    private:

        //hold cards that player plays from
        Deck* toPlay;

        //holds cards that have been played
        Deck* played;
};


#endif // PLAYER_H
