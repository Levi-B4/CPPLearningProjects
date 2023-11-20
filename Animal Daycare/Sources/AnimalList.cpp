#include "../Headers/AnimalList.h"
#include "../Headers/Node.h"

#include <iostream>

//default constructor
AnimalList::AnimalList(){}

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

//outputs list of all animals
/*
--- Cage # ---
Animal: <type>
Name: <name>
Age: <age>
Fee: <fee>
other info: <other>
*/
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










