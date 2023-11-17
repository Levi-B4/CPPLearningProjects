#ifndef BOXER_H
#define BOXER_H

#include <string>

using std::string;

class Boxer{
    public:
        //constructor - Parameters: string name, int numWins, int numLosses
        Boxer(string name, int numWins, int numLosses);

        //virtual function: outputs boxer data as string
        virtual string toString();

        //destructor
        ~Boxer();

    protected:
        //Boxer's name
        string name;

        //Number of Wins
        int numWins;

        //Number of Losses
        int numLosses;

    private:

};

#endif // BOXER_H
