#ifndef ANIMAL_H
#include "Animal.h"

class AnimalList{
    public:
        //constructor
        AnimalList();

        //inserts an animal at end of list
        void Insert(Animal animal)

        //removes an animal - parameters: cageNumber
        void RemoveAt(int cageNumber);

        //prints out all animals
        void Print();

        //Getter: GetHead
        Animal* GetHead();

    private:
        Animal* head;

};



#endif // ANIMAL_H
