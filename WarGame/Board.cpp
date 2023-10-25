#include "Board.h"
#include "Player.h"
#include "WarPrinter.h"

//default constructor
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

    //gives each player their cards
    DealCards();

    //loop till only one player has cards
    for(int i = 1; players[0]->HasCards() && players[1]->HasCards(); i++){
        printer->PrintRound(i);
        PlayRound();
    }

    //output results
    if(players[0]->HasCards()){
        printer->PrintGameResults(players[1]->GetPlayerID(), players[0]->GetPlayerID());
    }else{
        printer->PrintGameResults(players[0]->GetPlayerID(), players[1]->GetPlayerID());
    }

}

//deal each player their cards
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

//players a round of war, each player draws a card and winner gets both cards
void Board::PlayRound(){
    //set up player attacks
    PlayersAttack();

    //if an attack is not available, end round
    if(attackingCards[0] == nullptr || attackingCards[1] == nullptr){
        return;
    }

    //compare each player's card and process the result
    ProcessBattle();
}

//set up player attacks
void Board::PlayersAttack(){
    //get each player's attack
    for(int i = 0; i < numPlayers; i++){
        //set attack
        attackingCards[i] = players[i]->PlayCard();
        //verify attack is available
        if(attackingCards[i] == nullptr){
            printer->PrintDeckEmpty(players[i]->GetPlayerID());
            //use played cards if there are any
            if(players[i]->GetPlayedCards()->HasCards()){
                players[i]->UsePlayedCards();
                printer->PrintShuffle();
                players[i]->GetDeck()->Shuffle();
                attackingCards[i] = players[i]->PlayCard();

            }
            //if player has no cards, exit PlayersAttack()
            else{
                //if this is the second player, return the first players card
                if(i == 1){
                    players[0]->GetDeck()->AddCardToPile(attackingCards[0]);
                }
                /*
                //if there is loot give it to the other player
                switch(i){
                    case 0:
                        while(loot->HasCards()){
                            players[1]->GetPlayedCards()->AddCardToPile(loot->DrawCard());
                        }
                        break;
                    case 1:
                        while(loot->HasCards()){
                            players[0]->GetPlayedCards()->AddCardToPile(loot->DrawCard());
                        }
                        break;
                }
                */
                //exit players attack
                return;
            }
        }
        //print player's attack
        printer->PrintAttack(players[i]->GetPlayerID(), attackingCards[i]->GetValue(), attackingCards[i]->GetSuit());
    }
}

//compare each players attack and give winner loot
void Board::ProcessBattle(){
    //if player 1 card is higher than player 2's then give loot to player 1
    if(*attackingCards[0]->GetValue() > *attackingCards[1]->GetValue()){
        printer->PrintBattleWinner(players[0]->GetPlayerID());
        TransferLoot(players[0]);
        //print each player's card counts
        for(int i = 0; i < numPlayers; i++){
            printer->PrintPlayerDeckInfo(players[i]->GetPlayerID(),
                                         players[i]->GetDeck()->GetNumCards(),
                                         players[i]->GetPlayedCards()->GetNumCards());
        }
    }else{
        //if player 2 card is higher than player 1's then give loot to player 2
        if(*attackingCards[0]->GetValue() < *attackingCards[1]->GetValue()){
            printer->PrintBattleWinner(players[1]->GetPlayerID());
            TransferLoot(players[1]);
            //print each player's card counts
            for(int i = 0; i < numPlayers; i++){
                printer->PrintPlayerDeckInfo(players[i]->GetPlayerID(),
                                             players[i]->GetDeck()->GetNumCards(),
                                             players[i]->GetPlayedCards()->GetNumCards());
            }
        }
        //if both cards are equal add them to the bounty deck
        else{
            //print that there was a tie
            printer->PrintTie();
            //moves attacking cards to the loot
            for(int i = 0; i < numPlayers; i++){
                loot->AddCardToPile(attackingCards[i]);
            }
            //print each player's card counts
            for(int i = 0; i < numPlayers; i++){
                printer->PrintPlayerDeckInfo(players[i]->GetPlayerID(),
                                             players[i]->GetDeck()->GetNumCards(),
                                             players[i]->GetPlayedCards()->GetNumCards());
            }
            printer->PrintBlankLine();
            //restarts round
            PlayRound();
        }
    }
}

//transfer loot deck and attacking cards to a player's played pile
void Board::TransferLoot(Player* player){
    //transfer attacking cards
    for(int i = 0; i < numPlayers; i++){
        player->GetPlayedCards()->AddCardToPile(attackingCards[i]);
    }
    //transfer loot
    while(loot->HasCards()){
        player->GetDeck()->AddCardToPile(loot->DrawCard());
    }
}

//default destructor
Board::~Board(){
    //delete printer
    delete printer;
    //delete players and their entities
    for(int i = 0; i < numPlayers; i++){
        delete players[i];
    }
    //delete loot
    delete loot;
}
