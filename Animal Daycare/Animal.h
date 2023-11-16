#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;

class Animal{
    public:
        ////constructor - parameters: name, age
        //Animal();

        //virtual print: outputs animal info
        virtual void Print();

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

        //destructor
        ~Animal();

    protected:
        //daily cost to keep animal at daycare
        int dailyFee;

    private:
        //name of animal
        string name;
        //age of animal
        int age;



};

#endif // ANIMAL_H
