#include "../Headers/Rabbit.h"

#include <iostream>
#include <string>

using namespace std;

//constructor - parameters: name, age, numberOfCarrots
Rabbit::Rabbit(string name, int age, int numberOfCarrots)
    : Animal(name, age){
    this->numberOfCarrots = numberOfCarrots;
}

//overrides Animal::Print() - outputs dog info
void Rabbit::Print(){
    cout << "printed" << endl;
}

//default destructor
Rabbit::~Rabbit(){};
