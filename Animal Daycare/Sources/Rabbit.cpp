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
    cout << "Animal: Rabbit" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Fee: " << dailyFee << endl;
    cout << "Number of Carrots / Day: " << numberOfCarrots << endl;
}

//default destructor
Rabbit::~Rabbit(){};
