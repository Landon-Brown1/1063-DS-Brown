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
        encodedMessage = decodedMessage;
        for(int i = 0; i < decodedMessage.size(); i++){
            intVal = (int)encodedMessage[i];        // Turn it into an integer number between 0-25
            if(intVal >= 65 && intVal <= 90){
                intVal += shift;                    // Shift the value
                if(intVal > 65){                    //if the value is too small to be a letter,
                    intVal -= 26;                   //make it back into one
                }
                encodedMessage[i] = intVal;         // Turn integer back into ASCII upper letter
            }
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
        decodedMessage = encodedMessage;
        for(int i = 0; i < encodedMessage.size(); i++){
            intVal = (int)decodedMessage[i];        // Turn it into an integer number between 0-25
            if(intVal >= 65 && intVal <= 90){
                intVal -= shift;                    // Shift the value
                if(intVal < 65){                    //if the value is too small to be a letter,
                    intVal += 26;                   //make it back into one
                }
                decodedMessage[i] = intVal;         // Turn integer back into ASCII upper letter
            }
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
    void ReadCipherText(ifstream& in){
        int string_size = 8;
        int sh = 0;
        string mes = "";
        char temp = ' ';            //program is being weird for getline
        in >> sh >> temp;           //read shift
        
        getline(in, mes);
        SetShift(sh);
        encodedMessage = temp;
        encodedMessage += mes;      //store them
    }
    //************************************************************
    // DESCRIPTION: writes encoded text to an output stream      *
    // RETURN: ofstream&                                         *
    // PRECONDITION: file data and stream are valid              *
    // POSTCONDITION: string is printed to an output stream      *
    //************************************************************
    ofstream& WriteCipherText(ofstream& out){
        out << encodedMessage << endl << endl;
        return out;
    }
    //************************************************************
    // DESCRIPTION: reads a plaintext file into a string         *
    // RETURN: void                                              *
    // PRECONDITION: file contains valid data                    *
    // POSTCONDITION: stores the data for manipulation           *
    //************************************************************
    void ReadPlainText(ifstream& in){
        int string_size = 8;
        int sh = 0;
        string mes = "";
        char temp = ' ';            //program is being weird for getline
        in >> sh >> temp;           //read shift
        
        getline(in, mes);
        SetShift(sh);
        decodedMessage = temp;
        decodedMessage += mes;      //store them
    }
    //************************************************************
    // DESCRIPTION: writes plaintext to an output stream         *
    // RETURN: ofstream&                                         *
    // PRECONDITION: file data and stream are valid              *
    // POSTCONDITION: string is printed to an output stream      *
    //************************************************************
    ofstream& WritePlainText(ofstream& out){
        out << decodedMessage << endl << endl;
        return out;
    }


};
////////////////////////main//////////////////////////////

int main(){

    ifstream inFile;
    ofstream outFile;
    inFile.open("encrypted.txt");
    outFile.open("decrypted.txt");
    CaesarCipher A;

    int numReads = 0;
    char choice = ' ';
    bool Flag = false;
    inFile >> numReads;

    outFile << "LANDON M BROWN" << endl;
    outFile << "11/26/2019" << endl;
    outFile << "program_4 output" << endl << endl;

    for(int i = 0; i < numReads; i++){
        while(!Flag){
            cout << "1. Encrypt" << endl;
            cout << "2. Decrypt" << endl;
            cout << "Choice: ";
            cin >> choice;
            switch(choice){
                case '1':
                    //encrypt
                    A.UpperCase();
                    A.Encrypt();
                    A.WriteCipherText(outFile);
                    Flag = true;
                    break;
                case '2':
                    //decrypt
                    A.Decrypt();
                    A.WritePlainText(outFile);
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
    outFile.close();

    cout << "End Code" << endl;
    return 0;
}
