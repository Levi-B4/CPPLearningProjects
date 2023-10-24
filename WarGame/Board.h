#ifndef BOARD_H
#define BOARD_H

#include "Player.h"
#include "WarPrinter.h"

class Board{
    public:
        //default constructor
        Board();

        //game loop, returns winner (1/2)
        void Play();

        //destructor
        ~Board();

    private:
        //outputs game info to user
        WarPrinter* printer;

        //players
        Player* players[2];
        int numPlayers;

        //attacking cards
        Card* attackingCards[2];

        //holds cards in case of tie
        CardPile* loot;

        //deals cards to players
        void DealCards();

        //logic for each round
        void PlayRound();
        //set up player attacking cards
        void PlayersAttack();
        //compare  players' attacks
        void ProcessBattle();
        //transfer loot to winner
        void TransferLoot(Player* player);
};

#endif // BOARD_H
