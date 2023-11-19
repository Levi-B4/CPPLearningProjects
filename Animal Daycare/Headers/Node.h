#ifndef NODE_H
#define NODE_H

#include "Animal.h"

class Node{
    public:
        //Constructor - Parameters: Animal* animal
        Node(Animal* animal);

        //Getter - GetNext
        Node* GetNext();

        //Setter - SetNext
        void  SetNext(Node* next);

        //Getter - GetValue
        Animal* GetValue();

    private:
        //location of next node
        Node* next = nullptr;

        //location of an animal
        Animal* value;




};



#endif // NODE_H
