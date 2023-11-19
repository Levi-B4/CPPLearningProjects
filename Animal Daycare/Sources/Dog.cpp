#include "../Headers/Dog.h"

#include <iostream>
#include <string>

using namespace std;

//constructor - parameters: name, age, favoriteToy
Dog::Dog(string name, int age, string favoriteToy)
    : Animal(name, age){
    this->favoriteToy = favoriteToy;
}

//overrides Animal::Print() - outputs dog info
void Dog::Print(){
    cout << "printed" << endl;
}

//default destructor
Dog::~Dog(){};
