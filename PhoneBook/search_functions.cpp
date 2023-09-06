#include <vector>
#include <string>
#include <iostream>

using namespace std;
//searches for query inside of a vector using a recursive function
int searchRecursive(std::vector<std::string> &data, std::string query)
{
    //save data to new vector
    std::vector<std::string> unsearchedData = data;
    //check last element of vector
    if(unsearchedData.back() == query){
        //return index of element if found
        return unsearchedData.size() - 1;
    }
    //remove checked element
    unsearchedData.erase(unsearchedData.end());
    //return not found if all elements have been checked
    if(unsearchedData.empty()){
        return -1;
    }
    //recursively search the rest of the unchecked elements
    return searchRecursive(unsearchedData, query);
}
//searches for query inside of a vector using an iterative function
int searchIterative(std::vector<std::string> &data, std::string query)
{
    //iterate through vector
    for(int i = 0; i < data.size(); i++){
        //return index if value matches
        if(data[i]==query){
            return i;
        }
    }
    return -1;
}
