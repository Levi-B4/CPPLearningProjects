#include <string>

#include "Animal.h"

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

    //outputs list of all animals
    void ViewAnimals();

    //drop-off animal
    void AddAnimal();

    //pick-up animal
    void RemoveAnimal();

};
