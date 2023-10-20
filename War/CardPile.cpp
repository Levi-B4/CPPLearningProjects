#include "CardPile.h"

CardPile::CardPile(){
    numCards = 0;
}

//adds card to end of card array
void CardPile::AddCardToPile(Card* card){
    cards[numCards] = card;
    numCards++;
};



//simulates drawing a card, removing it from end of card array
Card* CardPile::DrawCard(){
    Card* cardToReturn = cards[numCards - 1];
    numCards--;
    return cardToReturn;
}

//returns total number of cards in card array
int* CardPile::GetNumCards(){
    return &this->numCards;
}

//randomizes order of card array
void CardPile::Shuffle(){
    //ToDo
}

//prints out number of cards
void CardPile::PrintCards(){
    //ToDo
}

//destructor
CardPile::~CardPile(){
};
