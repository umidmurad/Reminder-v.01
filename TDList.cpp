    #include <iostream>
    #include <iomanip>
    #include <stdio.h>
    #include <windows.h>
    #include <cstring>
    #include <vector>
    #include "Reminder.h"
    #include <fstream>
    #include <algorithm>

using namespace std;






    string menu();
    vector<string> pullFile(string fileName);
    void removeFile(string fileName);
    void pushFile(vector<string> totalList, string fileName);                  //functions will be used in this cpp
    bool ifExists(string fileName);
    void printList(vector<string> totalList, string fileName);
void TDList()
    {

        Sleep(1000);
        system("CLS");

        cout << "                                       Welcome To Do List Section!";
        Sleep(500);
        cout <<"...\n";
        Sleep(500);
        cout <<"Let's create your first to do lists.\n";
        string trash;
        string fileName;
        vector<string> totalList;                        //welcoming the user
        vector<string> names;
        void Menu();


        bool flag=true;
        if (ifExists("lists.txt")){
            names = pullFile("lists.txt");
        }
        cout<<"File List: \n";                                   // opening text file lists
        if(names.size() < 1){
            cout<<"No lists found.\n";
        }
        else{

            for(int c = 0; c < static_cast<int>(names.size()); c++){
                cout<<(c+1)<<". "<<names[c]<<"\n";
            }
        }

        while (flag){
            cout<<"\nEnter the number of the list you would like to load or Enter file name for a new list.\n>", cin>>fileName, cout<<"\n";
            if(isdigit(fileName[0])){

                int x = fileName[0] - '0';                          //this is where we ask for the user to select a list or to create one

                if(x > 0 && x < static_cast<int>(names.size())+1){
                    fileName = names[x-1];
                    flag = false;
                }
                else{
                    cout<<"Not a list number.\n";
                }
            }
            else{
                fileName = fileName + ".txt";
                names.push_back(fileName);
                flag = false;
            }
        }
        pushFile(names, "lists.txt");
        if (ifExists(fileName)){
            totalList = pullFile(fileName);
        }




        bool cont = true;
        while (cont){
            printList(totalList, fileName);
            int choice = 0;
            cout<<"What would you like to do?\n";
            cout<<"1. Add item.\n";
            cout<<"2. Remove item.\n";
            cout <<"3. Sort the list Alphabetically.\n";
            cout <<"4. Clear the List.\n";
            cout<<"5. Swap Elements.\n";                                      //options given to user to use the to do list
            cout <<"6. Select a List.\n";
            cout <<"7. Main Menu.\n";
            cout <<"8. Delete the file and list.\n";

            cout<<">";
            cin>>choice;
            cout<<"\n";
            while(cin.fail()){
                cin.ignore();
                cin.clear();
                rewind(stdin);
                cout<<">", cin>>choice, cout<<"\n";
            }
            if(choice == 1){
                string newItem;
                cout<<"Enter new item: ", cin>>newItem, cout<<"\n";
                if(cin.fail()){
                    cin.ignore();
                    cin.clear();
                    rewind(stdin);
                    cout<<"Enter new item: ", cin>>newItem, cout<<"\n";
                }
                totalList.push_back(newItem);
                pushFile(totalList,fileName);
            }
            else if(choice == 2){
                int itemNumber = 0;
                cout<<"Enter item number to delete: ", cin>>itemNumber, cout<<"\n";
                while(cin.fail() || itemNumber < 1 || itemNumber > static_cast<int>(totalList.size()))
                      {
                    cin.ignore();
                    cin.clear();
                    rewind(stdin);
                    cout<<"Enter item number to delete: ", cin>>itemNumber, cout<<"\n";
                }
                totalList.erase(totalList.begin() + (itemNumber-1));
                pushFile(totalList,fileName);
            }
            else if(choice == 6){
              //list menu
              pushFile(totalList,fileName);
              cout << "Returning Back to Beginning";
              Sleep(500);
              cout <<"...";
              Sleep(2000);
            TDList();
            }
            else if(choice ==3) {
               sort(totalList.begin(),totalList.end());                    //sorting algorithm
               pushFile(totalList,fileName);
            }
            else if (choice ==7){
                     pushFile(totalList,fileName);                  //menu return
                      menu();

            }
            else if (choice ==4){
                    totalList.clear();                     //clears the function
                    pushFile(totalList,fileName);

            }


            else if(choice ==8)
            {
            cout << "Deleting " <<fileName;
            Sleep(1000);
            cout <<"..." <<endl;
            Sleep(1000);
            if( remove( fileName.c_str() ) != 0 ){                  //deleting file
                cout << "Error deleting file\n" ;
               }
            else
                puts( "File successfully deleted" );

            removeFile(fileName.c_str());

            TDList();




            }



            else if(choice ==5)
            {
                try{int k,l,d;
                    d= totalList.size();


                cout <<"Enter first # needs to be swapped.\n";
                cin>>k;                                                       //swap function to swap the vectors
                while(k>d || k<0)
                {
                    throw d;

                }


                cout <<"Enter second # that will be swapped with.\n";
                cin>>l;
                while(l>d || l<0)
                {
                    throw d;
                }


                swap(totalList[k-1],totalList[l-1]);
                pushFile(totalList,fileName);
                pullFile(fileName);
            }catch (int f)
            {
                cout <<"Sorry, Input is not possible. Try again in 3 seconds." <<endl;
                Sleep(2500);
            }

            }
            else{
                cout<<"Invalid Input!\n";
                cin.clear();
                cin.ignore();
            }
        }


    }

vector<string> pullFile(string fileName){
        vector<string> totalList;
        fstream ioFile;
        ioFile.open(fileName.c_str(), fstream::in);
        string bullet;

        while (!ioFile.eof()){
            getline(ioFile, bullet);
            if(!bullet.empty()){                                      //pull the lists file from folder
                totalList.push_back(bullet);
            }
        }

        ioFile.close();

        return totalList;
    }
 void removeFile(string fileName){
        string line;
            ifstream file;
            ofstream outfile;
            file.open("lists.txt");

            outfile.open("newl.txt");
            while(true)
            {                                                          //this void function deletes the files
                file >> line;
                if(line==fileName.c_str()){if( file.eof() )
                    break;}
                else{
                        if( file.eof() ){
                    break;}
                    outfile<<line<<endl;}
            }
            outfile.close();
             file.close();
            remove("lists.txt");
            rename("newl.txt","lists.txt");


    }


    void pushFile(vector<string> totalList, string fileName){
        fstream ioFile;
        ioFile.open(fileName.c_str(), fstream::out);

        for(int c = 0; c < static_cast<int>(totalList.size()); c++){
            if(!totalList[c].empty()){
                ioFile<<totalList[c]<<"\n";
            }                                                            //inserts the vectors
        }

        ioFile.close();


    }


    bool ifExists(string fileName){                   //check see if the file exists
        ifstream infile(fileName);
        return infile.good();
    }

    void printList(vector<string> totalList, string fileName){
        cout << "\033[2J\033[1;1H";
        cout<<"List: "<<fileName<<"...\n";                                        //prints the list
        for(int c = 0; c < static_cast<int>(totalList.size()); c++){
                cout<<(c+1)<<". "<<totalList[c]<<"\n";
            }
        cout<<"\n\n\n\n\n";
    }



