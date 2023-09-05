#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "search_functions.h"

using namespace std;

int main() {
    cout << "finding file..." << endl;

    //assign file to variable
    ifstream inFile;

    //vectors to store phonebook
    vector<string> names;
    vector<string> phoneNumbers;

    //open file
    inFile.open("PhoneBook.txt");

    //handle file not opening
    if(!inFile.is_open()){
        cout << "Could not open file" << endl;
        return -1;
    }

    //parse file, iterating through each line
    string input;
    int commaIndex;
    while(getline(inFile, input)){
        //find comma in the line to use as delimiter
        commaIndex = input.find(',');
        //append piece before the comma to the end of the names array
        names.push_back(input.substr(0, commaIndex));
        //append piece after the comma to the end of the phone numbers array
        phoneNumbers.push_back(input.substr(commaIndex + 1, input.size()));
    }
    //close file
    inFile.close();

    //main file loop
    int userSelection;
    do {
        //display menu
        cout<< endl << "Select the number corresponding to what you would like to do." << endl <<
                "1. Find By Name (Recursive)" << endl <<
                "2. Find By Name (Iterative)" << endl <<
                "3. Find By Phone Number (Recursive)" << endl <<
                "4. Find By Phone Number (Iterative)" << endl <<
                "5. Quit" << endl;
        //verify user input a number
        while(!(cin >> userSelection)){
            //clears out cin cause of error
            cin.clear();
            //ignores current input line up to 999 characters to reset cin
            cin.ignore(999, '\n');
            cout << "Please enter a number" << endl;
        }

        //process users selection and verify its validity
        string query;
        switch(userSelection){
            case 1:
                searchRecursive(names, "Kim");
                break;
            case 2:
                searchIterative(names, "Kim");
                break;
            case 3:
                searchRecursive(phoneNumbers, "27");
                break;
            case 4:
                searchIterative(phoneNumbers, "27");
                break;
            case 5:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Please enter a valid option (1, 2, 3, 4, 5)" << endl;
                break;
        }

        // prompt user for query
        // search
        // display results
    } while (userSelection != 5);
}

