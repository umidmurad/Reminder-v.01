#include "User.h"
#include <iostream>
#include <cctype>
#include <windows.h>
#include <cstring>
#include <fstream>

using namespace std;


void User::setFirstName()
{
    string first;
    cout << "Enter first name: ";                                       //checks firstname
    getline(cin,first);
    // copy at most 10 characters from string to lastName
    int length = first.size();
    length = ( length < 10 ? length : 9 );
    first.copy( firstName, length );
    firstName[ length ] = '\0'; // append null character to lastName
}

string User::getFirstName() const
{
    return firstName;                       //returns firstname
}

void User::setUserName()
{
    string uName;
    cout << "Enter username: ";                                             //checks username
    getline(cin, uName);
    // copy at most 15 characters from string to lastName
    int length = uName.size();
    length = ( length < 15 ? length : 14 );
    uName.copy( userName, length );
    userName[ length ] = '\0'; // append null character to lastName

}

string User::getUserName() const
{
    return userName;      //returs username
}


void User::setPassword()
{
    bool passValid(char [], int);

    int LENGTH;
    char userInput[100];


    //outputs the criterias
    cout << "Create a password which satisfies the list below:" << endl;
    cout << "At least 6 characters\n"
    << "At least one uppercase\n"
    << "At least one lowercase\n"
    << "At least one digit\n"
    << "----------------------\n";
    cout << "Enter the password: ";

    do
    {
        cin.getline(userInput, 100); //user's unputs
        //identifies the length
        LENGTH = strlen(userInput);

        if(LENGTH < 5)
            cout << ">>Invalid password<<" << endl;
    }
    while (LENGTH < 5 || !passValid(userInput, LENGTH)); //loops until the conditions are right
    password =  userInput;

    }

//Funtion to identify a valid password
bool passValid(char arr[], int size)
{    int count = 0;
    bool digit = false;
    bool upper = false;
    bool lower = false;


    //this loop searches digits, upper and lower letters
    for(count = 0; count < size; count++)
    {
        if(isdigit(arr[count]))
            digit = true;
        if(isupper(arr[count]))
            upper = true;
        if(islower(arr[count]))
            lower = true;
    }
    if(digit == false)
        cout << "You should have at least one digit in your password" << endl;
    if(upper == false)
        cout << "You should have at least one uppercase letter in your password" << endl;
    if(lower == false)
        cout << "You should have at least one lowercase letter in your password" << endl;

    //if loop finds a digit, a upper, and a lower letter, it returns 'true'
    if(digit && upper && lower == true)
        return true;

    else
        return false;
}


string User::getPassword() const
{
    return password;
}

void User::saveUsersToFile(const User &newUser) {
    string dltus;
    string fileName = newUser.userName;
    ifstream usernamesdlt("un.txt"); //deleting the old users
    usernamesdlt >> dltus;
    dltus = dltus + ".txt";
    remove(dltus.c_str());
    usernamesdlt.close();

    ofstream usernames("un.txt" , ios::trunc);          //creates untxt file to get the usernames names, trunc functions clears the text for the new user
    usernames << fileName;
    usernames.close();


    fileName = fileName +".txt";
    ofstream usersFile(fileName.c_str(), ios::trunc);
    if (!usersFile) {
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }
    else {
     usersFile << newUser.firstName << "\n";
        usersFile << newUser.userName << "\n";
        usersFile << newUser.password <<"\n";
        usersFile.close();
    }
}

bool User::checkPassword(const User &refUser) {
    string userInput;
    bool valid = false;
    int count = 0;

    cout << refUser.getFirstName() << " confirm password : ";           //related with function in loginmenu.cpp
                                                                        //wants to confirm the password.
    while (count < 3) {
        getline(cin, userInput);
    if(userInput == refUser.getPassword())
    {
        valid = true;
        break;
    }
    else
    {
        cout << "Try again." << endl;
        valid = false;
        count++;
    }
    }//while


    return valid;

}


