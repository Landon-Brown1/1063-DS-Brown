/*
* AUTHOR: Landon Brown
* ASSIGNMENT TITLE: program_4 
* ASSIGNMENT DESCRIPTION: write code for a class that can read and interpret encoded 
*       as well as decoded text and perform encryption and decryption on said text,
*       while also being able to input and output to and from different files.
* FILE NAME: cipher.cpp
* DUE DATE: 11/26/2019  
* DATE CREATED: 11/22/2019
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class CaesarCipher{

    string message;     //to hold the text
    int shift;          //to hold the shift number

    //empty constructor
    CaesarCipher(){
        message = "";
        shift = 0;
    }
    //loaded constructor
    CaesarCipher(string m, int s){
        message = m;
        shift = s;
    }

    //*************************************************************
    // DESCRIPTION: encrypts a string given a specific shift value*
    // RETURN: void                                               *
    // PRECONDITION: valid data to encrypt                        *
    // POSTCONDITION: data is encrypted at a certain shift value  *
    //*************************************************************
    void Encrypt(){
        
    }
    //*************************************************************
    // DESCRIPTION: decrypts a string given a specific shift value*
    // RETURN: void                                               *
    // PRECONDITION: valid data to decrypt                        *
    // POSTCONDITION: data is decrypted at a certain shift value  *
    //*************************************************************
    void Decrypt(){

    }
    //************************************************************
    // DESCRIPTION: a method that uppercases a string            *
    // RETURN: string                                            *
    // PRECONDITION: string is passed in                         *
    // POSTCONDITION: returns that string, but uppercased        *
    //************************************************************
    string UpperCase(){

        return "a";
    }
    //************************************************************
    // DESCRIPTION: sets the shift amount for your class (def 13)*
    // RETURN: void                                              *
    // PRECONDITION: valid int or no param passed in             *
    // POSTCONDITION: shift is set to 13 or whatever is passed in*
    //************************************************************
    void SetShift(int s = 13){
        shift = s;
    }
    //************************************************************
    // DESCRIPTION: reads an encrypted file into a string        *
    // RETURN: void                                              *
    // PRECONDITION: file contains valid data                    *
    // POSTCONDITION: stores the data for manipulation           *
    //************************************************************
    void ReadCipherText(string fileName){
        ifstream in;
        in.open(fileName.c_str());

        in.close();
    }
    //************************************************************
    // DESCRIPTION: writes encoded text to an output stream      *
    // RETURN: ofstream&                                         *
    // PRECONDITION: file data and stream are valid              *
    // POSTCONDITION: string is printed to an output stream      *
    //************************************************************
    ofstream& WriteCipherText(string fileName, ofstream& out){
        ofstream outFile;
        outFile.open(fileName.c_str());

        outFile.close();
        return out;
    }
    //************************************************************
    // DESCRIPTION: reads an plaintext file into a string        *
    // RETURN: void                                              *
    // PRECONDITION: file contains valid data                    *
    // POSTCONDITION: stores the data for manipulation           *
    //************************************************************
    void ReadPlainText(string fileName){
        ifstream in;
        in.open(fileName.c_str());


        in.close();
    }
    //************************************************************
    // DESCRIPTION: writes plaintext to an output stream         *
    // RETURN: ofstream&                                         *
    // PRECONDITION: file data and stream are valid              *
    // POSTCONDITION: string is printed to an output stream      *
    //************************************************************
    ofstream& WritePlainText(string fileName, ofstream& out){
        ofstream outFile;
        outFile.open(fileName.c_str());

        outFile.close();
        return out;
    }


};

////////////////////////main//////////////////////////////

int main(){

    ifstream inFile;
    inFile.open("encrypted.txt");
    int numReads = 0;
    char choice = ' ';
    bool Flag = false;
    inFile >> numReads;

    for(int i = 0; i < numReads; i++){
        while(!Flag){
            cout << "1. Encrypt" << endl;
            cout << "2. Decrypt" << endl;
            cout << "Choice: ";
            cin >> choice;
            switch(choice){
                case '1':
                    //encrypt
                    Flag = true;
                    break;
                case '2':
                    //decrypt
                    Flag = true;
                    break;
                default:
                    cout << "Invalid entry, try again.";
                    cout << endl << endl;
                    break;
            }
        }
        
    }

    inFile.close();

    cout << "End Code" << endl;
    return 0;
}