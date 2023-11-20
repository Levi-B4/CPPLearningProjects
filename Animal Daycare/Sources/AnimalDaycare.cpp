#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <sstream>

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
    LoadAnimals();

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
                exit = true;
                break;
            case 1:
                animals.Print();
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

//loads animals from external file
void AnimalDaycare::LoadAnimals(){
    //instantiate file
    ifstream inFile;

    //open file
    inFile.open("DaycareAnimals.txt");

    //parse file
    string inputLine;
    stringstream animalInput;
    array<string, 4> animalInfo;
    int i;

    //iterate file and add animals to linked list animals
    while(getline(inFile,inputLine)){
        //save line as a string stream
        animalInput << inputLine;

        //iterate through stream and add each comma separated value to an array
        i = 0;
        while(getline(animalInput, inputLine, ',')){
            animalInfo[i] = inputLine;
            i++;
        }
//may use enum and switch here
        //create animal in list based off of input
        if(animalInfo[0] == "cat"){
            animals.Insert(new Cat(animalInfo[1], stoi(animalInfo[2]), animalInfo[3] == "true"));
        } else{
            if(animalInfo[0] == "dog"){
                animals.Insert(new Dog(animalInfo[1], stoi(animalInfo[2]), animalInfo[3]));
            } else {
            animals.Insert(new Rabbit(animalInfo[1], stoi(animalInfo[2]), stoi(animalInfo[3])));
            }
        }
        //empty string stream
        animalInput.clear();
    }
    //close file in which animals are saved
    inFile.close();
}

//save animals to external file
void AnimalDaycare::SaveAnimals(){
    cout << "save not implemented" << endl;
}

//get animal type
//get the animals info (you may assume it is entered correctly)
//create animal and add to linked list
void AnimalDaycare::AddAnimal(){

    //prompt user for animal type
    string animalType;
    cout << "What animal are you dropping off? (c,d,r): ";
    getline(cin, animalType);

    (animalType == "c") ? animals.Insert(new Cat())
        : (animalType == "d") ? animals.Insert(new Dog())
        :  animals.Insert(new Rabbit());

    /*
    if("c") animals.Insert(new Cat());
    if("d") animals.Insert(new Dog());
    if("r") animals.Insert(new Rabbit());
    */
}

//pick up animal
//ask for cage number
//remove animal from linked list
void AnimalDaycare::RemoveAnimal(){
    cout << "RemoveAnimal not yet implimented" << endl;
}

