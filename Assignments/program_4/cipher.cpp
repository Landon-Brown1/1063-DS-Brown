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

private:
    string encodedMessage;     //to hold encoded text
    string decodedMessage;     //holds decoded text
    int shift;          //to hold the shift number

public:
    //empty constructor
    CaesarCipher(){
        encodedMessage = "";
        decodedMessage = "";
        shift = 0;
    }
    //loaded constructor
    CaesarCipher(string em, string dm, int s){
        encodedMessage = em;
        decodedMessage = dm;
        shift = s;
    }

    //*************************************************************
    // DESCRIPTION: encrypts a string given a specific shift value*
    // RETURN: void                                               *
    // PRECONDITION: valid data to encrypt                        *
    // POSTCONDITION: data is encrypted at a certain shift value  *
    //*************************************************************
    void Encrypt(){
        int intVal;
        for(int i = 0; i < decodedMessage.size(); i++){
            encodedMessage = decodedMessage;
            intVal = (int)encodedMessage[i] - 65;   // Turn it into an integer number between 0-25
            intVal += shift % 26;                   // Shift the letter, using mod to wrap back around
            encodedMessage[i] = intVal + 65;        // Turn integer back into an ascii upper case letter
            
        }
    }
    //*************************************************************
    // DESCRIPTION: decrypts a string given a specific shift value*
    // RETURN: void                                               *
    // PRECONDITION: valid data to decrypt                        *
    // POSTCONDITION: data is decrypted at a certain shift value  *
    //*************************************************************
    void Decrypt(){
        int intVal;
        for(int i = 0; i < encodedMessage.size(); i++){
            decodedMessage = encodedMessage;
            intVal = (int)decodedMessage[i] - 65;   // Turn it into an integer number between 0-25
            intVal -= shift % 26;                   // Shift the letter, using mod to wrap back around
            decodedMessage[i] = intVal + 65;        // Turn integer back into ASCII upper letter
        }
    }
    //************************************************************
    // DESCRIPTION: a method that uppercases a string            *
    // RETURN: string                                            *
    // PRECONDITION: string is passed in                         *
    // POSTCONDITION: returns that string, but uppercased        *
    //************************************************************
    string UpperCase(){
        int intVal;
        for(int i = 0; i < decodedMessage.size(); i++){ //for whole string,
            if(intVal >= 97 && intVal <= 122){          //if the value is a valid letter
                intVal = (int)decodedMessage[i] - 65;   //change to int
                intVal -= 32;                           //subtract correct ASCII value to upper
                decodedMessage[i] = intVal + 65;        //convert back
            }
        }
        return decodedMessage;
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
        in.open(fileName.c_str());  //open file

        int sh = 0;
        string mes = "";
        in >> sh >> mes;            //read message and shift
        SetShift(sh);
        encodedMessage = mes;       //store them

        in.close();                 //close file
    }
    //************************************************************
    // DESCRIPTION: writes encoded text to an output stream      *
    // RETURN: ofstream&                                         *
    // PRECONDITION: file data and stream are valid              *
    // POSTCONDITION: string is printed to an output stream      *
    //************************************************************
    ofstream& WriteCipherText(string fileName){
        ofstream out;
        out.open(fileName.c_str());


        out.close();
        return out;
    }
    //************************************************************
    // DESCRIPTION: reads a plaintext file into a string         *
    // RETURN: void                                              *
    // PRECONDITION: file contains valid data                    *
    // POSTCONDITION: stores the data for manipulation           *
    //************************************************************
    void ReadPlainText(string fileName){
        ifstream in;
        in.open(fileName.c_str());  //open file

        int sh = 0;
        string mes = "";
        in >> sh >> mes;            //read message and shift
        SetShift(sh);
        decodedMessage = mes;       //store them

        in.close();                 //close file
    }
    //************************************************************
    // DESCRIPTION: writes plaintext to an output stream         *
    // RETURN: ofstream&                                         *
    // PRECONDITION: file data and stream are valid              *
    // POSTCONDITION: string is printed to an output stream      *
    //************************************************************
    ofstream& WritePlainText(string fileName){
        ofstream out;
        out.open(fileName.c_str());

        out << decodedMessage << endl << endl;

        out.close();
        return out;
    }


};
////////////////////////main//////////////////////////////

int main(){

    ifstream inFile;
    ofstream outFile;
    string I = "encrypted.txt";
    string O = "decrypted.txt";
    inFile.open(I.c_str());
    outFile.open(O.c_str());
    CaesarCipher A;

    int numReads = 0;
    char choice = ' ';
    bool Flag = false;
    inFile >> numReads;

    outFile << "LANDON M BROWN" << endl;
    outFile << "11/26/2019" << endl;
    outFile << "program_4 output" << endl << endl;

    for(int f = 0; f < numReads; f++){
        A.ReadCipherText(I);
        A.Decrypt();
        A.WritePlainText(O);
    }

    // for(int i = 0; i < numReads; i++){
    //     while(!Flag){
    //         cout << "1. Encrypt" << endl;
    //         cout << "2. Decrypt" << endl;
    //         cout << "Choice: ";
    //         cin >> choice;
    //         switch(choice){
    //             case '1':
    //                 //encrypt
    //                 Flag = true;
    //                 break;
    //             case '2':
    //                 //decrypt
    //                 Flag = true;
    //                 break;
    //             default:
    //                 cout << "Invalid entry, try again.";
    //                 cout << endl << endl;
    //                 break;
    //         }
    //     } 
    // }

    inFile.close();

    cout << "End Code" << endl;
    return 0;
}
