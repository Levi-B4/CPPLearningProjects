#include "search_functions.h"
#include <cassert>
#include <vector>
#include <iostream>

int main(){
    //data to test against
    std::vector<std::string> test = {
        "abcd",
        "efgh",
        "ijkl",
        "mnop",
        "qrst"
    };

    //tests for recursive search functions
    assert(searchRecursive(test, "abcd") == 0);
    assert(searchRecursive(test, "aoeu") == -1);
    assert(searchRecursive(test, "mnop") == 3);
    assert(searchRecursive(test, "e") == -1);
    assert(searchRecursive(test, "QRST") == -1);

    //tests for recursive search functions
    assert(searchIterative(test, "abcd") == 0);
    assert(searchIterative(test, "aoeu") == -1);
    assert(searchIterative(test, "mnop") == 3);
    assert(searchIterative(test, "e") == -1);
    assert(searchIterative(test, "QRST") == -1);

    //state success
    std::cout << "test was successful" << std::endl;

    return 0;
}
