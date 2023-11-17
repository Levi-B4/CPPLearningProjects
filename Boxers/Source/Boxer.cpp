#include "../Header/Boxer.h"

#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::cout;
using std::endl;


Boxer::Boxer(string name, int numWins, int numLosses){
    this->name = name;
    this->numWins = numWins;
    this->numLosses = numLosses;
}

string Boxer::toString(){
    //ToDo: Concat these correctly
    std::stringstream ss;
    ss << name << " wins: " << numWins << " losses: " << numLosses;
    return ss.str();
}

Boxer::~Boxer(){}
