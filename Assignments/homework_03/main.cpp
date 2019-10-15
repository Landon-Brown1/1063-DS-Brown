/*AUTHOR: Landon M. Brown
*ASSIGNMENT TITLE: homework_03
*ASSIGNMENT DESCRIPTION: Edit the ListStack and main so that the 
*   overloaded constructor is used instead of the default one.
*DUE DATE: 10/15/2019
*DATE CREATED: 10/12/2019
*DATE LAST MODIFIED: 10/12/2019
 */

#include <iostream>
#include <fstream>

#include "ListStack.h"

using namespace std;

int main(){
    ifstream inFile("animals.txt");      // input file of animal info    
    ofstream outFile("output_file.dat"); // output results of main functions               
    Animal *a;                           // animal pointer used to hold popped animals
    ListStack s;                         // List based stack object

    while (!inFile.eof()) {
        inFile >> a->name >> a->weight >> a->scary;              // load animal with file data
        Animal *b = new Animal(a->name, a->weight, a->scary);    // allocate memory for an animal
        s.Push(b);
    }

    outFile << "INITIAL LIST:" << endl;
    s.Print(outFile);          // Print the stack

    outFile << endl;            // ummm

    a = s.Pop();                // get animal off top of stack
    
    outFile << "Pop -> " << a << endl;       // print animal (cout operator overloaded)

    a = s.Pop();                // get animal off top of stack again
    
    outFile << "Pop -> " << a << endl;       // print animal (cout operator overloaded)

    outFile << endl;            // ummm

    outFile << "ENDING LIST:" << endl;
    s.Print(outFile);           // print the stack

    return 0;
}