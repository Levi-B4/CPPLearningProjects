#include "Board.h"

int main()
{
    //create game
    Board* war = new Board();

    //play game
    war->Play();

    //delete game
    delete war;

    return 1;
}
