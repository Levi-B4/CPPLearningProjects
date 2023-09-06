#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "search_functions.h"

using namespace std;

int main() {
    //assign file to variable
    ifstream inFile;

    //vectors to store phone book
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
    cout << "Welcome to the phone book" << endl;
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
        int result;
        switch(userSelection){
            case 1:
                //get name to search
                cout << "What name are you searching for?" << endl;
                while(getline(cin, query)){
                    if(!query.empty()){
                        break;
                    }
                }
                //search phone book for name
                result = searchRecursive(names, query);
                //print out result of search
                if(result == -1){
                    cout << query << " was not found in the phone book" << endl << endl;
                }
                else{
                    cout << result << ". " << names[result] << " - " << phoneNumbers[result] << endl << endl;
                }

                break;
            case 2:
                //get name to search
                cout << "What name are you searching for?" << endl;
                while(getline(cin, query)){
                    if(!query.empty()){
                        break;
                    }
                }
                //search phone book for name
                result = searchIterative(names, query);
                //print out result of search
                if(result == -1){
                    cout << query << " was not found in the phone book" << endl << endl;
                }
                else{
                    cout << result << ". " << names[result] << " - " << phoneNumbers[result] << endl << endl;
                }
                break;
            case 3:
                //get phone number to search
                cout << "What phone number are you searching for?" << endl;
                while(getline(cin, query)){
                    if(!query.empty()){
                        break;
                    }
                }
                //search phone book for phone number
                result = searchRecursive(phoneNumbers, query);
                //print out result of search
                if(result == -1){
                    cout << query << " was not found in the phone book" << endl << endl;
                }
                else{
                    cout << result << ". " << names[result] << " - " << phoneNumbers[result] << endl << endl;
                }
                break;
            case 4:
                //get phone number to search
                cout << "What phone number are you searching for?" << endl;
                while(getline(cin, query)){
                    if(!query.empty()){
                        break;
                    }
                }
                //search phone book for phone number
                result = searchIterative(phoneNumbers, query);
                //print out result of search
                if(result == -1){
                    cout << query << " was not found in the phone book" << endl << endl;
                }
                else{
                    cout << result << ". " << names[result] << " - " << phoneNumbers[result] << endl << endl;
                }
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Please enter a valid option (1, 2, 3, 4, 5)" << endl;
                break;
        }
    } while (userSelection != 5);
}

