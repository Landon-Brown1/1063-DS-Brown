/*AUTHOR: Landon M. Brown
*FILE NAME: main.cpp
*ASSIGNMENT DESCRIPTION: This project will add functions to resize an
*   array if the number of elements gets too large or too small.
*DUE DATE: 10/8/2019
*DATE CREATED: 10/1/2019
*DATE LAST MODIFIED: 10/8/2019
 */

#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"

using namespace std;

int main(){

    string x = "";
    int y = 0;
    Stack Foo(10);
    int largestSize = 0;

    ifstream inFile;
    ofstream outFile;
    inFile.open("input_data.txt");

    while(inFile>>x>>y){
        if(x == "+"){
            Foo.Push(y);
            if(Foo.getSize() > largestSize){
                largestSize = Foo.getSize();
            }
        }
        else if(x == "-"){
            Foo.Pop();
        }
    }
    inFile.close();

    outFile.open("stack_out.dat");
    outFile << "Landon Brown" << endl;
    outFile << "10/8/2019"    << endl;
    outFile << "Program 2"    << endl; 
    outFile << endl;
    outFile << "Stack Size: " << Foo.getSize() << endl;
    outFile << "Largest Size: " << largestSize << endl;
    outFile << "Values: ";
    Foo.Print(outFile);
    outFile.close();
    
    return 0;
}