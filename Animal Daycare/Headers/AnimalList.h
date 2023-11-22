#ifndef ANIMALLIST_H
#define ANIMALLIST_H

#include "Animal.h"
#include "Node.h"

class AnimalList{
    public:
        //default constructor
        AnimalList();

        //Loads animals from external file
        void LoadAnimals();

        //saves animals to external file
        void SaveAnimals();

        //inserts an animal at end of list
        void Insert(Animal* animal);

        //removes an animal - parameters: int index
        void RemoveAt(int index);

        //Returns pointer to animal at index, returns nullptr if out if index
        Animal* GetAnimalAt(int index);

        //prints out all animals
        void Print();

        //destructor - iterates through list and deletes each node
        ~AnimalList();

    private:
        //first node in the list
        Node* head = nullptr;
};



#endif // ANIMALLIST_H
