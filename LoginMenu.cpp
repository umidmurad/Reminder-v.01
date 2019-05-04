
#include "User.h"
#include "LoginMenu.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdbool>
#include <string>
#include <fstream>
using namespace std;
bool found = false;
bool passfound =false;

void removeFile(string fileName);

void LoginMenu:: menuu() {

    cout << "Login [L]" << endl;
    cout << "Register [R]" << endl;
    cout << ">";

    string logReg;
    cin >> logReg;
    cin.ignore(1000, 10);
    if(logReg == "L"||logReg =="l")
       {
           toLogin();                                       // Login / Register page
       }
    else if (logReg =="R"||logReg=="r")
    {
        toRegister();
    }
    else {
         cout << "Wrong input! Cancellation Processed.\n";
                Sleep(500);
                cout <<"...";
                                                                        // if user fails to enter r or L program exits.
                Sleep(500);
                cout << "\nClosing the application.";
                Sleep(500);
                exit(EXIT_FAILURE);
    }

}

bool LoginMenu::toLogin()                //if entered L  they are sent to this login  bool function
{
    string userCheck, userChecktxt;

    cout << "What is your username: \n>";
    getline(cin, userCheck);
    userChecktxt= userCheck + ".txt";
    fstream file(userChecktxt.c_str(), ios::in );
    if (file.fail()) {

        cerr << "Username not found!" << endl;
        cout << "Retry again." <<endl;
        Sleep(1000);                                            // If username doesn't match up with the file, error code, app closing.
        cout << "\nClosing the application.";
        Sleep(800);
        exit(EXIT_FAILURE);

    }

    string passwordcheck;
    string lineus, lineps;
    while(!file.eof())
    {
        file>> lineus;
        if(lineus.c_str()==userCheck)              //this function checks for the username, just in case, even though it was checked initially at the top.
        {
          found =true;

        }
    }
    if(found==false)
    {
                cout << "ERROR: Username not found!" <<endl;
                exit(EXIT_FAILURE);
    }
    file.close();
    fstream ifile(userChecktxt.c_str(), ios::in | ios::out);
    cout <<"Enter Password: " <<endl;

    cin >> passwordcheck;
    //getline(cin,passwordcheck);

        ifile >> lineps;
        ifile >>lineps;
        ifile>> lineps;                                                 // Password is correct passwordcheck true, access grants.
        if(lineps.c_str()==passwordcheck)
        {
            passfound=true;
            cout << "Password is correct! Access is granted!\n";
            Sleep(1000);
        }


     if(passfound==false)
    {
        cout << "Password is incorrect. [Tip:If you forgot the password, register a new account. Old Data will be lost.]";
        Sleep(3000);
        exit(EXIT_FAILURE);           // if password is incorrect , exits from program.
    }
    ifile.close();
    return true;
}

void LoginMenu::toRegister()             //register page
{

    string reading;
    fstream read("lists.txt", ios::in|ios::out);
    if(read.good())
       {
        while(!read.eof())
            {
                read >> reading;
                remove(reading.c_str());              //if user is new then this function checks the lists txt
                                                    // if there are old to do lists saved it, deletes them all.
            }
       }
    else{}
    read.close();
    ofstream open("lists.txt", std::ofstream::out | std::ofstream::trunc);       // opening lists as trunc to delete everything in it.
    ofstream close();
    User newUser;
    cout << "Creating new user" <<  endl;
    newUser.setFirstName(); //create first name
    newUser.setUserName(); //create username
    newUser.setPassword(); //create password
    newUser.saveUsersToFile(newUser);


    //delete all the files belonged old user





    if (newUser.checkPassword(newUser) == true)
    {
        cout << "Password is correct" << endl;                                    //this function is related to a function in
        cout << "Account Created successfully!" <<endl;                           // users.cpp, we ask to confirm the password
        Sleep(3000);
        system("cls");
        menuu();
    }
    else{
        cout << "Password was entered incorrectly 3 times.\n";
        cout << "Information saved.";                                           //if they cant confirm the password, this function
        cout <<"\nExitting...";                                             //still saves the data, but exits just in case.
        Sleep(2000);
        exit(EXIT_FAILURE);
    }
}
