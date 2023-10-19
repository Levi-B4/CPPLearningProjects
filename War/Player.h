#ifndef PLAYER_H
#define PLAYER_H

class Player{
    public:
        //default constructor
        Player();

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
