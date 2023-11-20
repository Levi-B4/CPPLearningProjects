#include "../Headers/Dog.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//default constructor - no parameters
Dog::Dog(){
    //prompt for dog info
    cout << "Enter your dog's info in the following format:\n";
    cout << "name,age,favoriteToy\n";
    cout << "Ex: Elroy,1,bone" << endl;

    //save input as string stream
    string userInput;
    stringstream dogInfo;
    getline(cin, userInput);
    dogInfo << userInput;

    //process dog's name
    getline(dogInfo, name, ',');

    //process dog's age
    string ageString;
    getline(dogInfo, ageString, ',');
    age = stoi(ageString);

    //process dog's favorite toy
    getline(dogInfo, favoriteToy/*, ','*/);
}

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
