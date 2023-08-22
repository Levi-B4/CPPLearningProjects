#include <iostream>

using namespace std;

void displayGraphic(int resolution){
    //create an amount of lines equal to resolution
    for(int i = 1; i <= resolution; i++){
        //reduce the amount of spaces each iteration from resolution-1 to 0
        for(int j = 0; j < resolution - i; j++){
            cout << ' ';
        }
        //increase the amount of * each iteration from 1 to resolution
        for(int k = 0; k < i; k++){
            cout << "*";
        }
        //create new line
        cout << endl;
    }

}

int main()
{
    int userInput = 0;

    //prompt user for input
    cout << "Input an integer in the range 5 to 15:" << endl;
    cin >> userInput;
    //clears any input errors
    cin.clear();
    //skips until it skips 999999999 characters or a line
    cin.ignore(999999999, '\n');

    //repeats till user inputs an int within the range
    while(userInput < 5 || userInput > 15){
        cout << "Please verify your input is an integer in the range 5 to 15:" << endl;
        cin >> userInput;
        //clears any input errors
        cin.clear();
        //skips until it skips 999999999 characters or a line
        cin.ignore(999999999, '\n');
    }

    //display graphic
    displayGraphic(userInput);

    return 0;
}
