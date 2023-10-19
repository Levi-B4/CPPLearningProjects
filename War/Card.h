#ifndef Card_H
#define CARD_H

class Card{
    public:

        //default constructor
        Card();
        //constructor with given suit and value
        Card(int value, int suit);

        //returns value of card
        int getValue();
        //sets value of card
        void setValue(int value);
        //gets suit id of card
        int GetSuit();
        //gets suit as c-string
        char* getSuitAsString();
        //sets suit of card
        void SetSuit(int suit);
        //describes card as a string; "value of suit"
        char* toString();

        //destructor
        ~Card();

    private:
        //card suit id (alphabetical order)
        int suit;
        //card value 1-13
        int value;
};

#endif // CARD_H
