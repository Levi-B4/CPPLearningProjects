#include <iostream>
#include <stack>
#include <queue>

using namespace std;

//may be used to create an undo function.
//each action stored on a stack and when undo is pressed
//you would undo the action on top of the stack
void myStack(int* intArray, int arraySize){
    //create stack
    stack<int> aStack;

    //push values on top of stack
    for(int i = 0; i < arraySize; i++){
        aStack.push(intArray[i]);
    }

    cout << "Going Through a Stack: ";

    //accessing stack
    for(int i = 0; i < arraySize; i++){
        //gets value that was last added to stack
        cout << aStack.top();
        //removes a value, always the last value added
        aStack.pop();
    }

    cout << endl;
}

//may used when serving customers.
//each customer would be put into a queue until resources are available
//then the first one would be accessed and serviced
void myQueue(int* intArray, int arraySize){
    //create queue
    queue<int> aQueue;

    //push values to back of queue
    for(int i = 0; i < arraySize; i++){
        aQueue.push(intArray[i]);
    }

    cout << "Going Through a Queue: ";

    //accessing queue
    for(int i = 0; i < arraySize; i++){
        //gets first value of the queue (last value may also be accessed)
        cout << aQueue.front();
        //removes a value, always the first value added
        aQueue.pop();
    }

    cout << endl;
}


int main()
{
    //create arraySize var
    int arraySize = 5;
    //create an int array
    int myNumbers[5];
    //add values to int array
    for(int i = 0; i < arraySize; i++){
        myNumbers[i] = i;
    }

    cout << "Starting Input Order: ";

    //print the starting array
    for(int i = 0; i < arraySize; i++){
        cout << myNumbers[i];
    }
    cout << endl;

    //put int array into a stack and then print in the order they are accessed after
    myStack(myNumbers, arraySize);

    //put int array into a queue and then print in the order they are accessed after
    myQueue(myNumbers, arraySize);

}
