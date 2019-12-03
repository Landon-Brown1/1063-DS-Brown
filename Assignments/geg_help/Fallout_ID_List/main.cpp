/* 
AUTHORS: Landon Brown, Gage Weatherred
FILE: main.cpp
PURPOSE: the purpose of this file is to create a menu through
    which we can search and find different ID's info and such
    of items, characters, etc. in the popular game Fallout 4.
DATE CREATED: 11/25/2019
*/

#include <iostream>     //obvious
#include <string>       //obvious
#include <fstream>      //input and output streams
#include <iomanip>      //for cleaning and formatting
#include <cmath>        //for higher math
#include "windows.h"    //for time statements (Sleep)

using namespace std;

int main(){
//declaring variables
    char input = '2';
    char check = 'y';
    bool exitKey = false, wrongFlag = true;

//opening string of text for the menu
    cout << "Hello user, what Fallout aspect would you like to see today?" << endl;
    cout << "(You may press the '*' key at any time to exit the program.)" << endl << endl;

//-------------------this is the loop for the whole program. This runs until you press the "=" key.---------------------//
    while(!exitKey){                                                                                                    //
                                                                                                                        //
//this loop is for your first user input. it runs until it gets a valid input from the choice selection.                //
        while(wrongFlag){                                                                                               //
            cout << "Please enter the number of your search term from the list below: " << endl;                        //
            cout << "1. ID"         << endl;                                                                            //
            cout << "2. Name"       << endl;                                                                            //
            cout << "3. Item Type"  << endl;                                                                            //
            //you can add more search types here ^                                                                      //
                                                                                                                        //
            cin >> input;                                                                                               //
            if(input == '='){                                                                                           //
                exitKey = true;                                                                                         //
                break;                                                                                                  //
            }                                                                                                           //
                                                                                                                        //
//this switch function will run based on what search type the user inputs to the program                                //
            switch(input){                                                                                              //
                case '1':                                                                                               //
                    cout << endl << "You entered [ 1. ID ]. Is this correct? (y or n): ";                               //
                    cin >> check;                                                                                       //
                    if(check == '='){                                                                                   //
                        exitKey = true;                                                                                 //
                        break;                                                                                          //
                    }                                                                                                   //
                    switch(check){                                                                                      //
                        case 'y':                                                                                       //  
                            wrongFlag = false;                                                                          //
                            break;                                                                                      //  
                        case 'n':                                                                                       //
                            break;                                                                                      //
                    }                                                                                                   //
                    break;                                                                                              //
                case '2':                                                                                               //
                    cout << endl << "You entered [ 2. Name ]. Is this correct? (y or n): ";                             //
                    cin >> check;                                                                                       //
                    if(check == '=')                                                                                    //
                     exitKey = true;                                                                                    //
                    switch(check){                                                                                      //  
                        case 'y':                                                                                       //
                            wrongFlag = false;                                                                          //
                            break;                                                                                      //
                        case 'n':                                                                                       //
                            break;                                                                                      //
                    }                                                                                                   //
                    break;                                                                                              //
                case '3':                                                                                               //
                    cout << endl << "You entered [ 3. Item Type ]. Is this correct? (y or n): ";                        //
                    cin >> check;                                                                                       //
                    if(check == '=')                                                                                    //
                     exitKey = true;                                                                                    //
                    switch(check){                                                                                      //
                        case 'y':                                                                                       //
                            wrongFlag = false;                                                                          //
                            break;                                                                                      //
                        case 'n':                                                                                       //
                            break;                                                                                      //
                    }                                                                                                   //
                    break;                                                                                              //
                //this runs if an invalid search type has been entered                                                  //
                default:                                                                                                //
                    cout << "Error, invalid response. Please enter the NUMBER of your selection Kappa ;)";              //
                    cout << endl << endl;                                                                               //
                    break;                                                                                              //
            }                                                                                                           //
            if(check == '='){                                                                                           //
                exitKey = true;                                                                                         //  
                break;                                                                                                  //
            }                                                                                                           //
        }                                                                                                               //
                                                                                                                        //
        exitKey = true;                                                                                                 //
                                                                                                                        //
    }                                                                                                                   //
    //------------------------------------------------------------------------------------------------------------------//    
    cout << "DONE" << endl;
    return 0;
}