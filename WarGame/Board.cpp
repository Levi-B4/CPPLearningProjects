#include "Board.h"
#include "Player.h"
#include "WarPrinter.h"

#include <iostream>

using namespace std;

Board::Board(){
    //create players
    numPlayers = 2;
    players[0] = new Player('A');
    players[1] = new Player('B');
    //create deck to hold the loot of each round
    loot = new CardPile();
    //create object to output to the user
    printer = new WarPrinter();
}

//Game loop; returns winner
void Board::Play(){
    //welcome user
    printer->PrintWelcome();

    DealCards();


}

void Board::DealCards(){
    //create deck as loot
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= 13; j++){
            loot->AddCardToPile(new Card(j, i));
        }
    }

    //notify user of shuffling
    printer->PrintShuffle();

    //shuffle deck
    loot->Shuffle();

    //print initial decks intro
    printer->PrintInitialDeckIntro();

    //holds a card to print it, then give it to player
    Card* cardToMove;

    //deal cards evenly to players, leaving extra in the loot
    for(int i = 0; i < numPlayers; i++){
        //print out player starting info
        printer->PrintPlayerInfo(players[i]->GetPlayerID(), 52 / numPlayers);
        //give player their cards
        for(int j = 0; j < 52 / numPlayers; j++){
            //get card from loot
            cardToMove = loot->DrawCard();
            //display card
            printer->PrintCard(j + 1, cardToMove->GetValue(), cardToMove->GetSuit());
            //give card to player
            players[i]->GetDeck()->AddCardToPile(cardToMove);
        }
    }
}



Board::~Board(){

}
