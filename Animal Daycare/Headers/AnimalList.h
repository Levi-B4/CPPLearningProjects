#ifndef ANIMALLIST_H
#define ANIMALLIST_H

#include "Animal.h"
#include "Node.h"

class AnimalList{
    public:
        //default constructor
        AnimalList();

        //inserts an animal at end of list
        void Insert(Animal* animal);

        //removes an animal - parameters: int index
        void RemoveAt(int index);

        //prints out all animals
        void Print();

    private:
        //first node in the list
        Node* head = nullptr;
};



#endif // ANIMALLIST_H
