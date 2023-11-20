#include "../Headers/Rabbit.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//default constructor - no parameters
Rabbit::Rabbit(){
    //prompt for rabbit info
    cout << "Enter your rabbit's info in the following format:\n";
    cout << "name,age,numberOfCarrots\n";
    cout << "Ex: Elroy,1,5" << endl;

    //save input as string stream
    string userInput;
    stringstream rabbitInfo;
    getline(cin, userInput);
    cout << "input: userInput" << endl;
    rabbitInfo << userInput;

    //process rabbit's name
    getline(rabbitInfo, name, ',');

    //process rabbit's age
    string ageString;
    getline(rabbitInfo, ageString, ',');
    age = stoi(ageString);

    //process number of carrots rabbit can have per day
    string numberOfCarrotsString;
    getline(rabbitInfo, numberOfCarrotsString/*, ','*/);
    numberOfCarrots = stoi(numberOfCarrotsString);
}

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
