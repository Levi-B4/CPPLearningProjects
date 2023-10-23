#ifndef CARD_H
#define CARD_H

class Card{
    public:

        //constructor with given suit and value
        Card(int value, int suit);

        //returns value of card
        int* GetValue();

        //returns value as c-string
        char* GetValueString();

        //gets suit id of card
        int* GetSuit();

        //gets suit as c-string
        char* GetSuitString();

        //destructor
        ~Card();

    private:
        //card suit id (alphabetical order)
        int suit;
        //card value 1-13
        int value;
};

#endif // CARD_H
