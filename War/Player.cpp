#include "./Player.h"

//Default constructor
Player::Player(){
    toPlay = new Deck();
    played = new Deck();
}

//Getter - toPlay deck
Deck* Player::GetToPlayDeck(){
    return toPlay;
}

//Getter - played deck
Deck* Player::GetPlayedDeck(){
    return played;
}

// returns top card of toPlay
// if toPlay is empty, replaces toPlay with played and shuffles
Card* Player::PlayCard(){
    //refill toPlay deck if empty
    if(toPlay->GetNumCards() == 0){

        //temporarily holds pointer to current toPlay deck
        Deck* tempDeck = toPlay;

        //replace toPlay deck with played deck
        toPlay = played;

        //set played deck to old toPlay deck
        played = tempDeck;

        //shuffle toPlay deck
        toPlay->Shuffle();
    }

    return toPlay->DrawCard();
}

//returns true if player has cards
bool Player::HasCards(){
    return GetToPlayDeck()->GetNumCards() > 0 || GetPlayedDeck()->GetNumCards() > 0;
}

//default destructor
Player::~Player(){
    delete toPlay;
    delete played;
}
