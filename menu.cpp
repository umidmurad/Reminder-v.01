    #include <iostream>
    #include <iomanip>
    #include <string>
    #include <stdio.h>
    #include <windows.h>
    #include <cstring>
    #include <vector>
    #include "Reminder.h"
    #include <fstream>
    #include <algorithm>

bool LoginMenu::toLogin();

using namespace std;


    void TDList();
    string menu();
    vector<string> pullFile(string fileName);
    void removeFile(string fileName);
    void pushFile(vector<string> totalList, string fileName);
    bool ifExists(string fileName);
    void printList(vector<string> totalList, string fileName);


string menu()
    {
    system("CLS");
    string name;
    char Choice;

    cout << "-------------------------------------------------\n\nPlanner is a student made simple program\nthat helps users to ease their life.\n\n-------------------------------------------------\n";


    cout << "Reminders                                 Type[R]\nTo Do Lists                               Type[L]\nAbout Us                                  Type[H]\nExit                                      Type[X]\n-------------------------------------------------\n";
    cout << "Enter: ";
    cin>> Choice;
    bool repeat;
    do {
      repeat = false;
    switch(Choice)
    {
    case 'r' :
    case 'R' :
	Functions aFunctions;                        //THIS MODULE IS THE HEART OF THE PROGRAM
	aFunctions.userCH();
            break;                              // it uses switch function to call each function to operate seperatly.
    case 'L':
    case 'l':
            TDList();

            break;
    case 'H':
    case 'h':
            cout << "This application was made by Umid. Last day of edit [5/15/2018].\n\n\nThis Application has two big features. \nFirst feature that we call is Reminder, that has chrono alarm system built in.\nYou can add a timer for yourself, and computer will make a sound when your time is up! \n\nSecond big feature is To Do list.\nTo Do List let's you create multiple lists and add info to it. \n\nIf you have any question, contact me @ umid.murad@hotmail.com.\nEnjoy!" <<endl;
            cout <<endl << "You will be transfered back to the menu in 20 seconds." <<endl;
            Sleep(20000);
            menu();
            break;
    case 'X' :
    case 'x' :
            exit(0);
    default:
     {
         cout << ">";
         cin>> Choice;
     }

    }
    }
    while(repeat);
    }
