#ifndef CARD_H
#define CARD_H

class Card{
    public:

        //constructor with given suit and value
        Card(int* value, int* suit);

        //returns value of card
        int* GetValue();
        //sets value of card
        void SetValue(int* value);

        //gets suit id of card
        int* GetSuit();
        //sets suit of card
        void SetSuit(int* suit);

        //describes card as a string; "value of suit"
        char* ToString();

        //destructor
        ~Card();

    private:
        //card suit id (alphabetical order)
        int* suit;
        //card value 1-13
        int* value;

        //returns value as c-string
        char* GetValueString();
        //gets suit as c-string
        char* GetSuitString();
};

#endif // CARD_H
