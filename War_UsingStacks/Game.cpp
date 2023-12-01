#include <iostream>

#include "./Game.h"
#include "./Deck.h"

using std::cout;
using std::endl;

//default constructor
Game::Game(){
    inPlay = new Deck();
};

//main game loop
void Game::Play(){

    cout << "Welcome to the Game of War!" << endl;

    //deal cards to players
    DealCards();

    //while players still have cards, keep playing rounds
    for(int i = 0; playerA.HasCards() && playerB.HasCards(); i++){
        cout << "\n======== Round " << i << " ========" << endl;
        Battle();
    }

    //output who loses
    if(playerA.HasCards()){
        cout << "Player B ran out of cards. Player B has lost.";
    } else {
        cout << "Player A ran out of cards. Player A has lost.";
    }
}

//default destructor
Game::~Game(){
    delete inPlay;
}

//players battle, returns true if someone runs out of cards
void Game::Battle(){

    //if a player is out of cards, stop battle
    if(!playerA.HasCards() || !playerB.HasCards()){
        return;
    }

    //get each player's attack
    Card* attackA = playerA.PlayCard();
    Card* attackB = playerB.PlayCard();

    //output each player's attack
    cout << "Player A plays " << attackA->GetValueString() << " of " << attackA->GetSuitString();
    cout << "\nPlayer B plays " << attackB->GetValueString() << " of " << attackB->GetSuitString() << endl;

    //add attacks to inplay deck
    inPlay->AddCard(attackA);
    inPlay->AddCard(attackB);

    cout << "this is after adding attacks" << endl;

    //if attacks are equal, battle again
    if(attackA->GetValue() == attackB->GetValue()){

        cout << "It's a tie... battle again!\n" << endl;

        //output card counts
        PrintCardCounts();

        //keep battling to resolve tie
        Battle();

        return;
    }

    //identify player with higher attack
    Player* winner = attackA->GetValue() > attackB->GetValue() ? &playerA : &playerB;

    //output winner
    if(winner == &playerA){
        cout << "Player A wins the loot!" << endl;
    } else {
        cout << "Player B wins the loot!" << endl;
    }

    //give inplay cards to winner
    while(inPlay->GetNumCards() > 0){
        winner->GetPlayedDeck()->AddCard(inPlay->DrawCard());
    }

    //output the number of cards in each players decks
    PrintCardCounts();
}


//deal cards to players
void Game::DealCards(){

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

// output amount of cards in each deck of each player
void Game::PrintCardCounts(){

    // output counts for player A
    cout << "\nPlayer A has " << playerA.GetToPlayDeck()->GetNumCards() << " cards in their \"to play deck\" and ";
    cout << playerA.GetPlayedDeck()->GetNumCards() << " cards in their \"played deck\"." << endl;

    // output counts for player B
    cout << "Player B has " << playerB.GetToPlayDeck()->GetNumCards() << " cards in their \"to play deck\" and ";
    cout << playerB.GetPlayedDeck()->GetNumCards() << " cards in their \"played deck\".\n" << endl;
}



