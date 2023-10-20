#include "Board.h"
#include "Player.h"

#include <iostream>

using namespace std;

Board::Board(){
    //create players
    p1 = new Player();
    p2 = new Player();
}

//Game loop; returns winner
void Board::Play(){
    //get each players attacking card
    p1Attack = p1->playCard();
    p2Attack = p2->playCard();

    //get value
    char* p1CardString = p1Attack->ToString();
    char* p2CardString = p2Attack->ToString();

    std::cout << "Player 1 plays ";
    for(int i = 0; p1CardString[i] != '\0'; i++){
        cout << p1CardString[i];
    }
    cout << endl;

    std::cout << "Player 2 plays ";
    for(int i = 0; p2CardString[i] != '\0'; i++){
        cout << p2CardString[i];
    }
    cout << endl;
}

Board::~Board(){

}
