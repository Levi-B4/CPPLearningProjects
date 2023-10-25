#include "Player.h"
#include "CardPile.h"

//default constructor
Player::Player(char playerID){
    deck = new CardPile();
    this->playerID = playerID;
}

char* Player::GetPlayerID(){
    return &playerID;
}

//return players main card pile
CardPile* Player::GetDeck(){
    return this->deck;
}

//returns player's played cards
CardPile* Player::GetPlayedCards(){
    return this->playedCards;
}

//gets top card of the players deck
Card* Player::PlayCard(){
    if(deck->HasCards()){
        return deck->DrawCard();
    }
    return nullptr;
}

//transfers played cards to players deck
void Player::UsePlayedCards(){
    while(playedCards->HasCards()){
        deck->AddCardToPile(playedCards->DrawCard());
    }
}

//returns true if player has cards
bool Player::HasCards(){
    return (deck->HasCards() || playedCards->HasCards());
}

//default destructor
Player::~Player(){
    //delete players deck
    delete deck;
    //delete played cards
    delete playedCards;
}
