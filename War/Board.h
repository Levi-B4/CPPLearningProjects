#ifndef BOARD_H
#define BOARD_H

class Board{
    public:
        //game loop, returns winner (1/2)
        int play();

    private:
        //players
        Player p1;
        Player p2;

        //holds cards in case of tie
        CardPile* tieBounty;

        //logic for each round
        void playRound();

        //destructor
        ~Board();
};

#endif // BOARD_H
