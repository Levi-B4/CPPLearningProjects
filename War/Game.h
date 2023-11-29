#ifndef GAME_H
#define GAME_H

#include "./deck.h"
#include "./Player.h"


class Game{
    public:

        //default constructor
        Game();

        //main game loop
        void Play();

    private:

        //players
        Player playerA;
        Player playerB;

        //holds cards that are currently in play
        Deck inPlay[MAX_CARDS];

        //players battle, returns true if someone runs out of cards
        void Battle();

        //deal cards to players
        void DealCards();

        // output amount of cards in each deck of each player
        void PrintCardCounts();
};



#endif // GAME_H
