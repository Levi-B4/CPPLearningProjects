#include "../Headers/AnimalList.h"
#include "../Headers/Node.h"

#include "../Headers/Animal.h"
#include "../Headers/Cat.h"
#include "../Headers/Dog.h"
#include "../Headers/Rabbit.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <array>

//default constructor
AnimalList::AnimalList(){}

//load animals from external file
void AnimalList::LoadAnimals(){
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
            Insert(new Cat(animalInfo[1], stoi(animalInfo[2]), animalInfo[3] == "true"));
        } else{
            if(animalInfo[0] == "dog"){
                Insert(new Dog(animalInfo[1], stoi(animalInfo[2]), animalInfo[3]));
            } else {
            Insert(new Rabbit(animalInfo[1], stoi(animalInfo[2]), stoi(animalInfo[3])));
            }
        }
        //empty string stream
        animalInput.clear();
    }
    //close file in which animals are saved
    inFile.close();
}

//saves animals to external file
void AnimalList::SaveAnimals(){
    //create output file stream
    ofstream outFile;

    //open output file
    outFile.open("DaycareAnimals.txt");

    //iterate through list and write animal save string to output file
    for(Node* i = head; i != nullptr; i = i->GetNext()){
        outFile << i->GetValue()->GetSaveString() << endl;
    }

    //close output file
    outFile.close();
}

//inserts an animal at end of list - parameters Animal* animal
void AnimalList::Insert(Animal* animal){
    //sets to head if no animal has been added yet
    if(head == nullptr){
        head = new Node(animal);
        return;
    }

    //iterate through list until at the end
    Node* currentNode = head;
    while(currentNode->GetNext() != nullptr){
        currentNode = currentNode->GetNext();
    }
    //last node now points to new animal
    currentNode->SetNext(new Node(animal));
}

//removes an animal - parameters: int index
void AnimalList::RemoveAt(int index){

    //accounts for first cage being 1
    index--;

    //temporarily holds node
    Node* tempNodePtr;

    //if first index, set head to the next node
    if(index == 0){

        //save next node
        tempNodePtr = head->GetNext();

        //delete head
        delete head;

        //set head to next node
        head = tempNodePtr;

        return;
    }

    //tracks current node
    Node* currentNode = head;

    //iterate through list until at node before index
    for(int i = 0; i < index - 1; i++){
        currentNode = currentNode->GetNext();
    }

    //get node after index
    tempNodePtr = currentNode->GetNext()->GetNext();

    //delete index
    delete currentNode->GetNext();

    //set next node for the node before index, to the node after index
    currentNode->SetNext(tempNodePtr);
}

//returns pointer to the animal at the given index
Animal* AnimalList::GetAnimalAt(int index){
    //tracks current node
    Node* currentNode = head;

    //iterate through list till at index or nullptr
    for(int i = 0; i < index; i++){
        //if out of range return nullptr
        if(currentNode = nullptr){
            return nullptr;
        }

        //increment to next node
        currentNode = currentNode->GetNext();
    }

    return currentNode->GetValue();
}

//outputs list of all animals
void AnimalList::Print(){
    //if no animals, notify user
    if(head == nullptr){
        cout << "\nno animals are in the daycare." << endl;
        return;
    }

    //iterate through list and output animal information
    Node* currentNode = head;
    for(int i = 1; currentNode != nullptr; i++){
        cout << "\n--- Cage " << i << " ---" << endl;
        //call Print() of the animal
        currentNode->GetValue()->Print();

        //increment to next animal
        currentNode = currentNode->GetNext();
    }
}

//destructor - iterates through list and deletes each node
AnimalList::~AnimalList(){

    //if list is empty, don't delete anything
    if(head == nullptr){
        return;
    }

    //holds node before current iteration, so it can be deleted
    Node* previousNode = head;

    //iterate through list until at the end, deleting each
    for(Node* currentNode = previousNode->GetNext(); currentNode != nullptr; currentNode = currentNode->GetNext()){

        //delete node before current iteration
        delete previousNode;

        //set previous node to current node
        previousNode = currentNode;

    }

    //delete final node
    delete previousNode;
}









