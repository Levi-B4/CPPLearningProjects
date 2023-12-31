#ifndef RABBIT_H
#define RABBIT_H

#include <string>

#include "Animal.h"

using namespace std;

class Rabbit : public Animal{
    public:
        //default constructor - no pameters
        Rabbit();

        //constructor - parameters: name, age, numberOfCarrots
        Rabbit(string name, int age, int numberOfCarrots);

        //overrides Animal::Print() - outputs dog info
        void Print();

        //overrides Animal:: GetSaveString() - returns animal as string for file saving
        string GetSaveString();

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
