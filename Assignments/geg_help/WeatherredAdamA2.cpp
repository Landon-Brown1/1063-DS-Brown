// AUTHOR: Adam Weatherred
// ASSIGNMENT TITLE: Programming Homework 1
// ASSIGNMENT DESCRIPTION: This program uses the input and output 
//    file streams to print to an output file in a specific format.
// DUE DATE: 10/11/2019
// DATE CREATED: 10/8/2019
// DATE LAST MODIFIED: 10/10/2019

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(){

    ofstream Outfile;
    ifstream Infile;
    
    string Name;
    string Mnumber;
    int SSN = 0;
    int Age = 0;
    

    Outfile.open("AdamWeatherredMiniDB.txt");

    Outfile << "Enter the names of three students." << endl;
    Outfile << "================================" << endl;
   
    Outfile << "Student #1 Name: Eduardo" << endl; 
    Outfile << "Student #1 SSN: 123456789" << endl;
    Outfile << "Student #1 Age: 40" << endl;
    Outfile << "Student #1 Mnumber: M111111" << endl;
   
    Outfile << "================================" << endl;
   
    Outfile << "Student #2 Name: Andres" << endl;
    Outfile << "Student #2 SSN: 987654321" << endl;
    Outfile << "Student #2 Age: 30" << endl;
    Outfile << "Student #2 Mnumber: M222222" << endl;

    Outfile << "================================" << endl;

    Outfile << "Student #3 Name: Colmenares" << endl;
    Outfile << "Student #3 SSN: 192837465" << endl;
    Outfile << "Student #3 Age: 20" << endl;
    Outfile << "Student #3 Mnumber: M333333" << endl;

    Outfile << "================================" << endl;

    Outfile << "The names were saved to a file." << endl;
    Outfile << "WE ARE DONE WRITING TO A FILE" << endl;
   
    Outfile << "=======================================" << endl;

    Outfile << "NOW IT IS TIME TO READ DATA FROM A FILE." << endl;
   Infile.open("input_data.txt");
  
   while(Infile >> Name >> SSN >> Age >> Mnumber){
    Outfile << left << setw(16) << Name 
            << setw(16) << SSN 
            << setw(12) << Age 
            << setw(8) << Mnumber
            << endl;
   }

    Infile.close();

    Outfile << "=======================================" << endl;
    Outfile << "WE ARE DONE READING THE FILE" << endl;
    Outfile << "Check what you have on screen" << endl;
    Outfile << "=======================================" << endl;
    Outfile << "Press any key to continue . . . ";
    
    Outfile.close();
    return 0;
}