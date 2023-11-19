#include "../Headers/Cat.h"

#include <iostream>
#include <string>

using namespace std;

//constructor - parameters: name, age, isOutDoor
Cat::Cat(string name, int age, bool isOutDoor)
    : Animal(name, age){
    this->isOutdoor = isOutdoor;
}

//overrides Animal::Print() - outputs cat info
void Cat::Print(){
    cout << "printed" << endl;
}

Cat::~Cat(){};
