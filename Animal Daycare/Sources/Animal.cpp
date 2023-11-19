#include "../Headers/Animal.h"

//constructor - parameters: name, age
Animal::Animal(string name, int age){
    this->name = name;
    this->age = age;
}

//default destructor
Animal::~Animal(){};
