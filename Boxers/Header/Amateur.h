#ifndef AMATEUR_H
#define AMATEUR_H

#include "Boxer.h"

#include <string>

using std::string;

class Amateur : public Boxer{
    public:
        //constructor - Parameters: string goldenGlovesOrganization, string name, int numWins, int numLosses
        Amateur(string goldenGlovesOrganization, string name, int numWins, int numLosses);

        //overrides Boxer.toString() - outputs boxer data as string
        string toString();

        //destructor
        ~Amateur();

    private:
        //organization which amateur boxer competes in
        string goldenGlovesOrganization;

};

#endif // AMATEUR_H
