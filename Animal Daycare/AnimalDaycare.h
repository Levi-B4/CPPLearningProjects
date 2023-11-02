
#include <string>

class AnimalDaycare{
public:
    //default constructor
    AnimalDaycare();
    //daycare logic
    void Run();
    //default destructor
    ~AnimalDaycare();

private:

    //linkedList allAnimals


    //outputs list of all animals
    void ViewAnimals();

    //drop-off animal
    void AddAnimal();

    //pick-up animal
    void RemoveAnimal();

};
