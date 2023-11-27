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


//returns true if player has cards
bool Player::HasCards(){
    return GetToPlayDeck()->GetNumCards() > 0 && GetPlayedDeck()->GetNumCards() > 0;
}

//default destructor
Player::~Player(){
    delete toPlay;
    delete played;
}
