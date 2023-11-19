#include <string>

#include "Animal.h"
#include "AnimalList.h"

class AnimalDaycare{
public:
    //Constructor
    AnimalDaycare();

    //daycare logic
    void Run();

    //Destructor
    ~AnimalDaycare();

private:
    //linkedList of all animals
    AnimalList animals;

    //loads animal from external file to a linked list
    void LoadAnimals();

    //drop-off animal
    void AddAnimal();

    //pick-up animal
    void RemoveAnimal();

};
