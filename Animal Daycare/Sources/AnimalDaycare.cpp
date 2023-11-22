#include <iostream>
#include <string>

#include "../Headers/Cat.h"
#include "../Headers/Dog.h"
#include "../Headers/Rabbit.h"
#include "../Headers/Animal.h"
#include "../Headers/AnimalDaycare.h"

using namespace std;

//default constructor
AnimalDaycare::AnimalDaycare(){};

//daycare logic
void AnimalDaycare::Run(){
    cout << "Welcome to Animal Day Care!\n" <<
            "_____________________________" << endl;

    //loads animals from external file
    animals.LoadAnimals();

    //user menu selection
    int userSelection;

    //true if user selects exit
    bool exit = false;

    //run program till user selects exit
    while(!exit){

        //menu
        cout << "\nWhat would you like to do? (enter the number of your selection)\n" <<
                "0: Exit\n" <<
                "1: View all pets\n" <<
                "2: Drop-off pet\n" <<
                "3: Pick-up pet" << endl;

        //get user selection
        cin >> userSelection;

        //if input isn't a number, prompt for input till it is a number
        while(cin.fail())
        {
            //resets cin
            cin.clear();
            //ignores 100 characters or until there is a new line character
            cin.ignore(100, '\n');

            //get new user input
            cout << "Please enter a number." << endl;
            cin >> userSelection;
        }

        //ignores 100 characters or until there is a new line character
        cin.ignore(100, '\n');

        //process user selection
        switch(userSelection){
            case 0:
                //exit program loop
                exit = true;
                break;
            case 1:
                //output animals
                animals.Print();
                break;
            case 2:
                //add animal to list
                AddAnimal();
                break;
            case 3:
                //remove animal from list
                RemoveAnimal();
                break;
            default:
                cout << "Please enter a valid number (0,1,2,3)" << endl;
                break;
        }
    }

    cout << "Saving pets..." << endl;

    //save animals to external file
    animals.SaveAnimals();

    cout << "Pets saved!" << endl;
}

//default destructor
AnimalDaycare::~AnimalDaycare(){};

//add animal to list
void AnimalDaycare::AddAnimal(){

    //prompt user for animal type
    string animalType;
    cout << "What animal are you dropping off? (c,d,r): ";
    getline(cin, animalType);

    (animalType == "c") ? animals.Insert(new Cat())
        : (animalType == "d") ? animals.Insert(new Dog())
        :  animals.Insert(new Rabbit());
}

//remove animal from list
void AnimalDaycare::RemoveAnimal(){

    //prompt user for cage number
    int cageNumber;
    cout << "What animal would you like to pick up?\n";
    cout << "Enter Cage Number: ";

    cin >> cageNumber;
    //ignores 5 characters or until there is a new line character
    cin.ignore(5, '\n');

    //remove animal from list at index (cageNumber)
    animals.RemoveAt(cageNumber);

    cout << "\n\nThank you!" << endl;
}

