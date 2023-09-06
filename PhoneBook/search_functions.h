#include <vector>
#include <string>

#ifndef SEARCH_FUNCTIONS
#define SEARCH_FUNCTIONS
//searches for query inside of a vector using a recursive function
int searchRecursive(std::vector<std::string> &data, std::string query);
//searches for query inside of a vector using an iterative function
int searchIterative(std::vector<std::string> &data, std::string query);

#endif
