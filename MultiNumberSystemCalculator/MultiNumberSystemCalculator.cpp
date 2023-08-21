#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//intakes equation and outputs answer
int processEquation(string equation){
    string parsedEquation[4];

    char currentChar;
    int equationIndex = 0;

    cout << "length: " << equation.length() << endl;
    cout << "[parser] equation: " << equation << endl;

    //iterates through equation and creates an array of each piece
    for(int i = 0; i < equation.length(); i++){
        currentChar = equation[i];
        cout << "character " << i  << ":" << currentChar <<endl;
        //moves to next index of array when there is a space
        if(currentChar == ' '){
            equationIndex ++;
        }
        //adds character to string in array if it is not a space
        else{
            parsedEquation[equationIndex] += currentChar;
        }
    }

    for(int i = 0; i < 4; i++){
        cout << parsedEquation[i] << endl;
    }

    return 1;
}

int main()
{
    int numberOfEquations;
    string inputLine;

    //instantiate file object
    ifstream inputFile;

    //load file
    inputFile.open("inputFile.txt");

    //check if file can be read
    if(!inputFile.is_open()){
		cout << "Could not open file." << endl;
		return -1;
	}

	//Read first line of file, to know how many equations are in the file
	getline(inputFile, inputLine, '\n');
	numberOfEquations = stoi(inputLine);
	cout << "number of equations: " << numberOfEquations << endl;

    //iterate through each equation
    for(int i = 0; i < numberOfEquations; i++)
        //read equation
        getline(inputFile, inputLine, '\n');
        cout << "[main] equation: " << inputLine << endl;
        //parse equation
        processEquation(inputLine);

	// Close the file
	inputFile.close();



    return 0;
}
