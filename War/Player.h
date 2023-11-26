#ifndef PLAYER_H
#define PLAYER_H

#include "./deck.h"

class Player{
    public:

        //default constructor
        Player();

        //Getter - toPlayDeck
        Deck* GetToPlayDeck();

        //Getter - playedDeck
        Deck* GetPlayedDeck();


    private:

        //hold cards that player plays from
        Deck* toPlayDeck;

        //holds cards that have been played
        Deck* playedDeck;
};


#endif // PLAYER_H
