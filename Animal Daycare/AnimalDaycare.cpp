#include <iostream>
#include <string>

#include "Cat.h"
#include "Dog.h"
#include "Rabbit.h"
#include "Animal.h"
#include "AnimalDaycare.h"

using namespace std;

//default constructor
AnimalDaycare::AnimalDaycare(){};

//daycare logic
void AnimalDaycare::Run(){
    cout << "Welcome to Animal Day Care!\n" <<
            "_____________________________" << endl;
    //load current pets from file and add them to a linked list

    //user menu selection
    int userSelection;
    //true if user selects exit
    bool exit = false;

    //run program till user selects exit
    while(!exit){
        //resetting user selection
        userSelection = -1;

        //menu
        cout << "What would you like to do? (enter the number of your selection)\n" <<
                "0: Exit\n" <<
                "1: View all pets\n" <<
                "2: Drop-off pet\n" <<
                "3: Pick-up pet" << endl;

        //get user selection
        cin >> userSelection;

        //if input isn't a number, prompt for input till it is a number
        while(cin.fail())
        {
            //resents cin
            cin.clear();
            //ignores 100 characters or until there is a new line character
            cin.ignore(100, '\n');

            //get new user input
            cout << "Please enter a number." << endl;
            cin >> userSelection;
        }

        //process user selection
        switch(userSelection){
            case 0:
                exit = true;
                break;
            case 1:
                ViewAnimals();
                break;
            case 2:
                AddAnimal();
                break;
            case 3:
                RemoveAnimal();
                break;
            default:
                cout << "Please enter a valid number (0,1,2,3)" << endl;
                break;
        }
    }
}

//default destructor
AnimalDaycare::~AnimalDaycare(){};

//outputs list of all animals
/*
--- Cage # ---
Animal: <type>
Name: <name>
Age: <age>
Fee: <fee>
other info: <other>
*/
void AnimalDaycare::ViewAnimals(){
    cout << "Not yet implimented" << endl;
}

//drop off animal
//get animal type
//get the animals info (you may assume it is entered correctly)
//create animal and add to linked list
void AnimalDaycare::AddAnimal(){
    cout << "Not yet implimented" << endl;
}

//pick up animal
//ask for cage number
//remove animal from linked list
void AnimalDaycare::RemoveAnimal(){
    cout << "Not yet implimented" << endl;
}

