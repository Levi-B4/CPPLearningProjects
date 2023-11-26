#ifndef CARD_H
#define CARD_H

enum SUIT {CLUB, DIAMOND, HEART, SPADE};
enum RANK {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

class Card{
    public:

        //constructor - parameters: int suit, int value
        Card(int suit, int value);

        //Getter - returns value as string
        const char* GetRankString();

        //Getter - get value
        int GetRank();

        //Getter - returns suit as string
        const char* GetSuitString();

        //Getter - get suit
        int GetSuit();


    private:

        //suit of card
        int suit;

        //value of card
        int value;
};


#endif // CARD_H
