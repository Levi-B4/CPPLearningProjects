#include "../Headers/Node.h"

//Constructor - Parameters: Animal* animal
Node::Node(Animal* animal){
    this->value = animal;
}

//Getter - GetNext
Node* Node::GetNext(){
    return next;
}

//Setter - SetNext
void Node::SetNext(Node* next){
    this->next = next;
}

//Getter - GetValue
Animal* Node::GetValue(){
    return value;
}

//destructor - deletes animal pointed to by value
Node::~Node(){
    //delete animal
    delete value;
}
