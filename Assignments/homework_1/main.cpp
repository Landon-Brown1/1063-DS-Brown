/*
* AUTHOR: Landon Brown
* ASSIGNMENT TITLE: homework_1
* ASSIGNMENT DESCRIPTION: make a more efficient version of the
*       code done in class that can use at least 2 files and open/
*       close in/output files.
* DUE DATE: 9/3/2019
* DATE CREATED: 8/29/2019
*/

/*
 * DATA ABSTRACTION:
 * 		Output file stream is opened
 * 		3 variables, a, b, and c, are initialized for use with their counterparts in the formula
 * INPUT:
 * 		The program reads input in the format of 'first\0last\ng1\0g2\0g3'
 *          from the input file and assigns the variables accordingly
 * PROCESS:
 * 		The students' info is read in from a file
 * 		The students' info is printed to an output file
 * OUTPUT:
 * 		The class of students is read and processed
 * 		The Students' names and grades are printed to an output file
 * ASSUMPTIONS:
 * 		It is assumed that, having been prompted to do so, the user will correctly input data
 */

#include <iostream>
#include <string>
#include <fstream>

const int SIZE = 10;    //<-- I used to do it this way, don't know if thats improper

using namespace std;

struct Student
{
    string fname;
    string lname;
    int numGrades;
    int grades[10];
};

//***********************************************************************
// DESCRIPTION: load in a list of students and put them into a list     *
// RETURN: int                                                          *
// PRECONDITION: all objects are real and valid                         *
// POSTCONDITION: returns the number of students in the list            *
//                                                                      *
//***********************************************************************

int loadClassList(Student *classList, string fileName)
{
    ifstream inFile;
    inFile.open(fileName.c_str());
    int i = 0;
    int temp = 0;

    while (!inFile.eof()){
        inFile  >> classList[i].fname
                >> classList[i].lname
                >> temp;

                classList[i].numGrades = temp;

        for(int j = 0; j < classList[i].numGrades; j++){
            inFile  >> classList[i].grades[j];
        }
        temp = 0;
        i++;
    }

    inFile.close();
    return i;
}

//***********************************************************************
// DESCRIPTION: Prints a list of students to the console                *
// RETURN: void                                                         *
// PRECONDITION: all students have initialized traits                   *
// POSTCONDITION: the list of students is printed to the screen         *
//                                                                      *
//***********************************************************************

void printClassList(Student *classList, int classSize){

    ofstream outputFile;
    outputFile.open("student_output.dat");

    outputFile << "Students" << endl;
    outputFile << "=================================" << endl;

    for (int i = 0; i < classSize; i++){
        outputFile << (i+1) << ". ";
        outputFile << classList[i].fname << " "
                   << classList[i].lname << ":    ";

        for(int j = 0; j < classList[i].numGrades; j++){
            outputFile << classList[i].grades[j] << " ";
        }
        outputFile << endl;
    }

    outputFile.close();
}

//------------End function list--------------------------------------------//

int main(){

    Student classList[100];
    int classSize = 0;

    // Call the loadClassList function to open a file and load an array
    // of `Student` structs.
    classSize = loadClassList(classList, "input_data.txt");

    // Function returned how many lines (students) read in, lets print it.
    cout << "Class Size: " << classSize << endl;

    // Function to print out an array of students in a formatted way.
    printClassList(classList, classSize);


    return 0;
}
