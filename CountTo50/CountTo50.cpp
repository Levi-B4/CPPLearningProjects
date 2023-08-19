#include <iostream>

using namespace std;

int main()
{
    //prints to console asking users name
    cout << "What is your name" << endl;
    //gets input from console
    string name;
    cin >> name;
    //prints out name
    cout << "Your name is " << name << endl;

    //outputs numbers counting to 50
    for(int i = 1; i <= 50; i++){
        cout << i << endl;
    }

    //if a windows system use pause to wait till key pressed
    #ifdef _WIN64
        system("pause");
    //if not windows system use read to wait till key pressed
    #else
        system("read");
    #endif

    //ends method
    return 0;
}
