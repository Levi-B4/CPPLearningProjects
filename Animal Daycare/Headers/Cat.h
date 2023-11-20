#ifndef CAT_H
#define CAT_H

#include <string>

#include "Animal.h"

using namespace std;

class Cat : public Animal{
    public:
        //constructor - parameters: name, age, isOutDoor
        Cat(string name, int age, bool isOutDoor);

        //overrides Animal::Print() - outputs cat info
        void Print() override;

        //Getter: GetIsOutdoor
        bool GetIsOutdoor();

        //Setter: SetIsOutdoor
        void SetIsOutdoor(bool isOutdoor);

        //default destructor
        ~Cat();

    private:
        //daily cost to keep cat at daycare
        int dailyFee = 25;

        //true if cat is an outdoor cat
        bool isOutdoor;




};



#endif // CAT_H