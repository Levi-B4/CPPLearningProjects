#include "../Header/Amateur.h"

#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::cout;
using std::endl;


Amateur::Amateur(string goldenGlovesOrganization, string name, int numWins, int numLosses)
            : Boxer(name, numWins, numLosses){

    this->goldenGlovesOrganization = goldenGlovesOrganization;
}

string Amateur::toString(){
    std::stringstream ss;
    ss << name << " wins: " << numWins << " losses: " << numLosses << " " << goldenGlovesOrganization;
    return ss.str();
}

Amateur::~Amateur(){}
