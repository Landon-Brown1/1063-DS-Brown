/*AUTHOR: Landon M. Brown
*FILE TITLE: main.cpp
*FILE DESCRIPTION: this file runs our code
*DUE DATE: 10/15/2019
*DATE CREATED: 10/15/2019
*DATE LAST MODIFIED: 10/15/2019
 */

#include <iostream>
#include <fstream>

#include "ListQueue.hpp"

using namespace std;

int main(){

    ofstream outFile;
    ifstream inFile;
    outFile.open("output_data.txt");
    inFile.open("animals.txt");

    ListQueue queue;                          // Queue instance 
    Animal b;                                 // used to initialize a to an animal
    Animal *a = &b;                           // animal pointer used to hold popped animals

    while (!inFile.eof()) {                   // load animal with file data
        inFile >> a->name >> a->weight >> a->scary;
        Animal *b = new Animal(a->name, a->weight, a->scary);    // allocate memory for an animal
        queue.Push(b);
    }
    inFile.close();

    outFile << endl;                          // ummmm 

    queue.Print(outFile);                     // print queue to see where values are

    for(int i = 0; i < 6; i++){               // remove 5 items +1
        if(!queue.Empty()){
        Animal *a = queue.Pop();
        outFile << "Item: " << a << endl;     // print out items
        }else{
        outFile << "Empty queue!" << endl;
        }
    }

    queue.Print(outFile);                      // print again to show front removal
    queue.PrintPointers(outFile);
}