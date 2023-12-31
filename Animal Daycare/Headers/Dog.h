#ifndef DOG_H
#define DOG_H

#include <string>

#include "Animal.h"

using namespace std;


class Dog : public Animal
{
    public:
        //default constructor - no pameters
        Dog();

        //constructor - parameters: name, age, favoriteToy
        Dog(string name, int age, string favoriteToy);

        //overrides Animal::Print() - outputs dog info
        void Print();

        //overrides Animal:: GetSaveString() - returns animal as string for file saving
        string GetSaveString();

        //Getter: GetFavoriteToy
        string GetFavoriteToy();

        //Setter: SetFavoriteToy
        void SetFavoriteToy();

        //default destructor
        ~Dog();

    private:
        //daily cost to keep dog at daycare
         int dailyFee = 50;

         //dog's favorite toy
         string favoriteToy;
};

#endif // DOG_H
