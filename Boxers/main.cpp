#include "Header/Boxer.h"
#include "Header/Professional.h"
#include "Header/Amateur.h"

#include <iostream>

using namespace std;

int main()
{
    const unsigned numBoxers = 3;

    //create array of boxers
    Boxer* boxers[numBoxers] = {
        new Boxer("Joe Smith", 10, 3),
        new Professional("Texas Athletic Commission", "Fred Jackson", 4, 5),
        new Amateur("Dallas Golden Gloves", "Tommy Johnson", 3, 3)
    };

    //iterate through boxers and print them
    for(unsigned i = 0; i < numBoxers; i++)
        cout << boxers[i]->toString() << endl;

    return 0;
}
