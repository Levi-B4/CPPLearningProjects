#ifndef PROFESSIONAL_H
#define PROFESSIONAL_H

#include "Boxer.h"

#include <string>

using std::string;

class Professional : public Boxer{
    public:
        //constructor - Parameters: string athleticComission, string name, int numWins, int numLosses
        Professional(string athleticComission, string name, int numWins, int numLosses);

        //overrides Boxer.toString() - outputs boxer data as string
        string toString();

        //destructor
        ~Professional();

    private:
        //sponsor for Boxer
        string athleticCommission;

};

#endif // PROFESSIONAL_H
