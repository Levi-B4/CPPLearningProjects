#include "Player.h"
#include "CardPile.h"

#include <iostream>

using namespace std;

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
Card* Player::playCard(){

}
