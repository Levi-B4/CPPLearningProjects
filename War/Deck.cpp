#include <iostream>
#include <time.h>

#include "./Deck.h"

using std::cout;
using std::endl;

//default constructor
Deck::Deck(){
    numCards = 0;
}

//adds card to top of deck
void Deck::AddCard(Card* card){
    cards[numCards++] = card;
}

//returns top card of deck
Card* Deck::DrawCard(){
    return cards[--numCards];
}

//Getter - numCards
int Deck::GetNumCards(){
    return numCards;
}

//randomizes card order
void Deck::Shuffle(){
    //shuffle config
    int seed = time(0);
    int numShuffles = 20;
    int numShuffleDecks= 5;

    //create decks to randomly assign cards to
    Deck** shuffleDecks = new Deck*[numShuffleDecks];
    for(int i = 0; i < numShuffleDecks; i++){
        shuffleDecks[i] = new Deck();
    }

    for(int i = 0; i < numShuffles; i++){
        //distribute to shuffle decks
        while(numCards > 0){
            //keep seed high so it doesn't hit 0
            if(seed < 100){
                //add in case of seed being 0 at start
                seed += numShuffleDecks;
                //multiply by number greater than the number of shuffle decks to keep seed high
                seed *= numShuffleDecks + 2;
            }
            //put card in a random shuffle deck based off of the seed
            shuffleDecks[seed % numShuffleDecks]->AddCard(DrawCard());
            //divide by the number of decks to make next loop different
            seed /= numShuffleDecks;
        }

        //add from all of the shuffle decks till they are empty
        for(int j = 0; j < numShuffleDecks; j++){
            while(shuffleDecks[j]->GetNumCards() > 0){
                AddCard(shuffleDecks[j]->DrawCard());
            }
        }
    }

    //delete shuffle decks from heap
    for(int i = 0; i < numShuffleDecks; i++){
        delete shuffleDecks[i];
    }

    //delete shuffle decks array from heap
    delete shuffleDecks;
}

void Deck::PrintCards(){
    cout << "There are " << numCards << " cards in this deck" << endl;

    for(int i = 0; i < numCards; i++){
        cout << "Card " << i << ", " << cards[i]->GetValueString() << " of " << cards[i]->GetSuitString() << endl;
    }

}

//default destructor;
Deck::~Deck(){
    for(int i = 0; i < numCards; i++){
        delete cards[i];
    }
}
