#include "../Header/Professional.h"

#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::cout;
using std::endl;


Professional::Professional(string athleticCommission, string name, int numWins, int numLosses)
            : Boxer(name, numWins, numLosses){

    this->athleticCommission = athleticCommission;
}

string Professional::toString(){
    std::stringstream ss;
    ss << name << " wins: " << numWins << " losses: " << numLosses << " " << athleticCommission;
    return ss.str();
}

Professional::~Professional(){}
