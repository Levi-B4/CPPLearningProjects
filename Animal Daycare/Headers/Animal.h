#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;

class Animal{
    public:
        //default constructor - no parameters
        Animal();

        //constructor - parameters: name, age
        Animal(string name, int age);

        //pure virtual print: children use to print out animal info
        virtual void Print() = 0;

        //Getter - GetDailyFee
        double GetDailyFee();

        //Getter - GetName
        string GetName();
        //Setter - SetName
        void SetName(string name);

        //Getter - GetAge
        int GetAge();
        //Setter - SetAge
        void setAge(int age);

        //default destructor
        ~Animal();

    protected:
        //daily cost to keep animal at daycare
        int dailyFee;

        //name of animal
        string name;

        //age of animal
        int age;



};

#endif // ANIMAL_H
