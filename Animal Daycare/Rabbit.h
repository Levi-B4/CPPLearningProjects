#ifndef RABBIT_H
#define RABBIT_H

#include <string>

#include "Animal.h"

using namespace std;

class Rabbit : public Animal{
    public:
        //constructor - parameters: name, age, numberOfCarrots
        Rabbit(string name, int age, int numberOfCarrots);

        //virtual print: outputs rabbit info
        void Print();

        //Getter: GetNumberOfCarrots
        int GetNumberOfCarrots();
        //Setter: SetNumberOfCarrots
        void SetNumberOfCarrots(int numberOfCarrots);

        //default destructor
        ~Rabbit();

    private:
        //daily cost to keep animal at daycare
        int dailyFee = 15;
        //number of carrots rabbit is allowed each day
        int numberOfCarrots;

};





#endif // RABBIT_H
