#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

//converts a character to an integer
int charToIntUpToHexadecimal(char number){
    //subtracts ASSCII values to find the numerical value
    return int((number <= '9') ? number - '0' : number - '0' - ('A' - '9') + 1);
}
//converts an integer to a character
char intToCharUpToHexadecimal(int number){
    //adds ASSCII values to find the numerical value
    return (number <= 9) ? number + '0' : number + '0' + ('A' - '9') - 1;
}

//converts string number of any base to decimal integer
long long StringToDecimal(string stringNumber, int originalSystemBase){
    long long total = 0;
    //reverses order of string
    reverse(stringNumber.begin(), stringNumber.end());
    //uses formula to convert each digit to base 10 then adds them to the total
    for(int i = 0; i < stringNumber.length(); i++){
        total += charToIntUpToHexadecimal(stringNumber[i]) * pow(originalSystemBase, i);
    }
    return total;
}

//converts decimal to a binary string
string decimalToAnyNumberSystemString(long long decimalNumber, int desiredBase){
    string reverseBinaryNumber = "";
    int currentRemainder;
    //divides the decimal number by the base of the desired number system
    //appending the remainder each time to the result
    while(decimalNumber != 0){
        currentRemainder = decimalNumber % desiredBase;
        decimalNumber = (decimalNumber - currentRemainder) / desiredBase;
        reverseBinaryNumber += intToCharUpToHexadecimal(currentRemainder);
    }

    //reverses reverseBinaryNumber so its outputted in correct order
    reverse(reverseBinaryNumber.begin(), reverseBinaryNumber.end());

    return reverseBinaryNumber;
}

//intakes equation and outputs answer
string processEquation(string equation){
    string parsedEquation[4];

    char currentChar;
    int equationIndex = 0;

    //iterates through equation and creates an array of each piece
    for(int i = 0; i < equation.length(); i++){
        currentChar = equation[i];
        //moves to next index of array when there is a space
        if(currentChar == ' '){
            equationIndex ++;
        }
        //adds character to string in array if it is not a space
        else{
            parsedEquation[equationIndex] += currentChar;
        }
    }

    long long numbersAsDecimal[2];

    //check for number system then convert to decimal
    //inputting the number and number system
    if(parsedEquation[0] == "B"){
        numbersAsDecimal[0] = StringToDecimal(parsedEquation[1], 2);
        numbersAsDecimal[1] = StringToDecimal(parsedEquation[3], 2);
    }
    else if(parsedEquation[0] == "H"){
        numbersAsDecimal[0] = StringToDecimal(parsedEquation[1], 16);
        numbersAsDecimal[1] = StringToDecimal(parsedEquation[3], 16);
    }
    else{
        numbersAsDecimal[0] = StringToDecimal(parsedEquation[1], 10);
        numbersAsDecimal[1] = StringToDecimal(parsedEquation[3], 10);
    }

    long long answerInDecimal;
    //check for equation operator then solve the equation
    if (parsedEquation[2] == "+"){
            answerInDecimal = numbersAsDecimal[0] + numbersAsDecimal[1];
    }
    else if (parsedEquation[2] == "-"){
            answerInDecimal = numbersAsDecimal[0] - numbersAsDecimal[1];
    }

    else if (parsedEquation[2] == "*"){
            answerInDecimal = numbersAsDecimal[0] * numbersAsDecimal[1];
    }

    else if (parsedEquation[2] == "/"){
            answerInDecimal = numbersAsDecimal[0] / numbersAsDecimal[1];
    }

    string answer;
    //check for number system
    //then convert decimal int to the desired system as a string
    if(parsedEquation[0] == "B"){
        answer = decimalToAnyNumberSystemString(answerInDecimal, 2);
    }
    else if(parsedEquation[0] == "H"){
        answer = decimalToAnyNumberSystemString(answerInDecimal, 16);
    }
    else {
        answer = decimalToAnyNumberSystemString(answerInDecimal, 10);
    }

    return answer;
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
	numberOfEquations = charToIntUpToHexadecimal(inputLine[0]);

    //iterate through each equation
    for(int i = 0; i < numberOfEquations; i++){
        //read equation
        getline(inputFile, inputLine, '\n');
        //process equation
        string finalAnswer = processEquation(inputLine);
        //output answer to equation
        cout << finalAnswer << endl;
    }

	// Close file
	inputFile.close();

    return 0;
}
