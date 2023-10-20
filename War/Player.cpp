#include "Player.h"
#include "CardPile.h"

#include <iostream>

using namespace std;

//default constructor
Player::Player(){
    deck = new CardPile();
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
    int* card = new int[2];
    card[0] = 5;
    card[1] = 2;
    return new Card(card, card + 1);
}
