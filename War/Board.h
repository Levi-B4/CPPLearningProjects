#ifndef BOARD_H
#define BOARD_H

#include "Player.h"

class Board{
    public:
        //default constructor
        Board();

        //game loop, returns winner (1/2)
        void Play();

        //destructor
        ~Board();

    private:
        //players
        Player* p1;
        Player* p2;

        //attacking cards
        Card* p1Attack;
        Card* p2Attack;

        //holds cards in case of tie
        CardPile* tieBounty;

        //logic for each round
        void playRound();
};

#endif // BOARD_H
