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
    cout << "Animal: Cat" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Fee: " << dailyFee << endl;
    cout << "Indoor/Outdoor: ";

    //convert isOutdoor to desired output
    if(isOutdoor){
        cout << "Outdoor" << endl;
    } else {
        cout << "indoor" << endl;
    }
}

Cat::~Cat(){};
