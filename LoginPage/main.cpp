#include <iostream>
#include <exception>
#include <string>

using namespace std;

class PasswordTooShort : public runtime_error{
     public:
        //forward message to base class constructor
        PasswordTooShort(string msg) : runtime_error(msg){};
};


class DoesNotContainDigit : public runtime_error{
    public:
        //forward message to base class constructor
        DoesNotContainDigit(string msg) : runtime_error(msg){};
};



int main()
{
    //variables for login
    string username;
    string password;
    bool valid = false;

    //prompt for user name
    cout << "Please enter a user name: " << endl;
    //get user name from user
    getline(cin, username);

    //verify password
    while(!valid){
        //prompt for password
        cout << "\nPlease enter a password: " << endl;
        //get password from user
        getline(cin, password);

        try{
            //if password size is too short, throw error
            if(password.size() < 6)
                throw PasswordTooShort("Password must be at least 6 characters");

            //if password does not contain a digit, throw error
            if(string::npos == password.find_first_of("0123456789"))
                throw DoesNotContainDigit("Password must contain a digit");

            valid = true;
        //catch error and display error message
        } catch(exception& e){
            cout << "invalid password: " << e.what() << endl;
        }
    }

    cout << "Congratulations, you have successfully logged in!" << endl;


    return 0;
}
