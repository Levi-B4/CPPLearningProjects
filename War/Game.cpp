#include <iostream>

#include "./Game.h"
#include "./Deck.h"

using std::cout;
using std::endl;

//default constructor
Game::Game(){};

//main game loop
void Game::Play(){


    //deal cards to players
    DealCards();

    while(playerA.HasCards() && playerB.HasCards()){
        Battle();
    }



}

//players battle, returns true if someone runs out of cards
void Game::Battle(){
    playerB.GetPlayedDeck()->AddCard(playerA.GetToPlayDeck()->DrawCard());
}


//deal cards to players
void Game::DealCards(){

    cout << "Welcome to the Game of War!" << endl;

    //holds starting cards
    Deck* tempDeck = new Deck();

    //create a ful deck of cards
    for(int i = 0; i < MAX_CARDS; i++){
        tempDeck->AddCard(new Card(i % 13, i / 13));
    }

    cout << "Shuffling initial deck..." << endl;

    //shuffle deck before dealing
    tempDeck->Shuffle();

    //deal cards to players
    while(tempDeck->GetNumCards() > 0){
        playerA.GetToPlayDeck()->AddCard(tempDeck->DrawCard());
        playerB.GetToPlayDeck()->AddCard(tempDeck->DrawCard());
    }

    //output each player's toPlayDeck
    cout << "\nPlayer A:" << endl;
    playerA.GetToPlayDeck()->PrintCards();

    cout << "\nPlayer B:" << endl;
    playerB.GetToPlayDeck()->PrintCards();

    //delete tempDeck from heap
    delete tempDeck;


}



