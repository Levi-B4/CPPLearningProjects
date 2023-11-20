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
    cout << "Animal: Dog" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Fee: " << dailyFee << endl;
    cout << "Favorite Toy: " << favoriteToy << endl;
}

//default destructor
Dog::~Dog(){};
