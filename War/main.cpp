#include <iostream>

#include "Board.h"

using namespace std;

int main()
{
    Board* war = new Board();
    war->Play();

    delete war;

    return 1;
}
