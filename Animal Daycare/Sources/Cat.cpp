#include "../Headers/Cat.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//default constructor - no parameters
Cat::Cat(){
    //prompt for cat info
    cout << "Enter your cat's info in the following format:\n";
    cout << "name,age,isOutdoor\n";
    cout << "Ex: Elroy,1,true" << endl;

    //save input as string stream
    string userInput;
    stringstream catInfo;
    getline(cin, userInput);
    catInfo << userInput;

    //process cat's name
    getline(catInfo, name, ',');

    //process cat's age
    string ageString;
    getline(catInfo, ageString, ',');
    age = stoi(ageString);

    //process if cat is indoor or outdoor
    string isOutdoorString;
    getline(catInfo, isOutdoorString/*, ','*/);
    isOutdoor = isOutdoorString == "true";
}

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
