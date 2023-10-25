//used to generate a seed for shuffling
#include <time.h>

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

bool CardPile::HasCards(){
    return numCards > 0;
}

//randomizes order of card array
void CardPile::Shuffle(){
    //shuffle config
    int seed = time(0);
    int numShuffles = 20;
    int numShufflePiles = 5;

    //create piles to randomly assign cards to
    CardPile** shufflePiles = new CardPile*[numShufflePiles];
    for(int i = 0; i < numShufflePiles; i++){
        shufflePiles[i] = new CardPile();
    }

    for(int i = 0; i < numShuffles; i++){
        //distribute to shuffle piles
        while(HasCards()){
            //keep seed high so it doesn't hit 0
            if(seed < 100){
                //add in case of seed being 0 at start
                seed += numShufflePiles;
                //multiply by number greater than the number of shuffle piles to keep seed high
                seed *= numShufflePiles + 2;
            }
            //put card in a random shuffle pile based off of the seed
            shufflePiles[seed % numShufflePiles]->AddCardToPile(DrawCard());
            //divide by the number of piles to make next loop different
            seed /= numShufflePiles;
        }

        //add from all of the shuffle piles till they are empty
        for(int j = 0; j < numShufflePiles; j++){
            while(shufflePiles[j]->HasCards()){
                AddCardToPile(shufflePiles[j]->DrawCard());
            }
        }
    }
    //delete all shuffle piles
    for(int i = 0; i < numShufflePiles; i++){
        delete shufflePiles[i];
    }
    delete shufflePiles;
}

//destructor
CardPile::~CardPile(){
    while(HasCards()){
        delete DrawCard();
    }

};
