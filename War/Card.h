#ifndef CARD_H
#define CARD_H

enum SUIT {CLUB, DIAMOND, HEART, SPADE};
enum VALUE {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

class Card{
    public:

        //constructor - parameters: int value, int suit
        Card(int value, int suit);

        //Getter - returns value as string
        const char* GetValueString();

        //Getter - get value
        int GetValue();

        //Getter - returns suit as string
        const char* GetSuitString();

        //default destructor
        ~Card();


    private:

        //suit of card
        int suit;

        //value of card
        int value;
};


#endif // CARD_H
