#include <iostream>
#include <time.h>
#include <stack>

#include "./Deck.h"

using std::cout;
using std::endl;

//default constructor
Deck::Deck(){
}

//adds card to top of deck
void Deck::AddCard(Card* card){
    cards.push(card);
}

//returns top card of deck
Card* Deck::DrawCard(){
    //access top card
    Card* output = cards.top();
    //remove top card
    cards.pop();
    //return top card
    return output;
}

//returns number of cards in cards stack
int Deck::GetNumCards(){
    return cards.size();
}

void Deck::Shuffle(){
    //shuffle config
        //number of times to shuffle
    int numShuffles = 100;
        //number of decks the target deck will be shuffled into
    int numShuffleDecks= 5;

    //used to create sudo random
    int seed;

    //create decks to randomly assign cards to
    Deck** shuffleDecks = new Deck*[numShuffleDecks];
    for(int i = 0; i < numShuffleDecks; i++){
        shuffleDecks[i] = new Deck();
    }

    //shuffle the amount of specified times - numShuffles
    for(int i = 0; i < numShuffles; i++){
        //creates sudo random based off current time
        seed = time(0);

        //distribute to shuffle decks
        while(!cards.empty()){
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

        //add from all of the shuffle decks to the target deck until they are empty
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

//outputs the cards in the deck to the user
void Deck::PrintCards(){
    //holds cards as stack is iterated through
    stack<Card*> tempStack;

    cout << "There are " << cards.size() << " cards in this deck" << endl;

    //print each card in the deck
    for(int i = 0; !cards.empty(); i++){
        cout << "Card " << i << ", " << cards.top()->GetValueString() << " of " << cards.top()->GetSuitString() << endl;
        tempStack.push(cards.top());
        cards.pop();
    }

    // move cards back onto main card stack
    while(!tempStack.empty()){
        cards.push(tempStack.top());
        tempStack.pop();
    }
}

//default destructor;
Deck::~Deck(){
    //iterate through card stack and delete each card
    while(!cards.empty()){
        delete cards.top();
        cards.pop();
    }
}
