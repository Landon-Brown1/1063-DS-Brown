#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(){

    ifstream inFile;
    ofstream outFile;
    inFile.open("input.txt");
    outFile.open("output.txt");

    string name;
    string azeroes;
    string bzeroes;
    int hours = 0;
    int length = 0;
    double time = 0;
    float charge = 0;
    double mins = 0;

    outFile << "Landon Brown" << endl << endl;
    outFile << "Name         Start Time    Length        Charge" << endl;
    outFile << "-----------------------------------------------" << endl;

    while(inFile >> name >> time >> length){
        hours = time;
        mins = (time - hours) * 100;

        if(time <= 23.59 && time >= 0){
            if(time <= 6.59){
                charge = length * .12;
                if(mins < 10){
                    azeroes = ":0";
                }else{
                    azeroes = ":";
                }
                if(hours < 10){
                    bzeroes = "0";
                }
                else{
                    bzeroes = "";
                }
            }
            else if(time < 19){
                charge = length * .55;
                if(mins < 10){
                    azeroes = ":0";
                }else{
                    azeroes = ":";
                }
                if(hours < 10){
                    bzeroes = "0";
                }
                else{
                    bzeroes = "";
                }
            }
            else if(time <= 23.59){
                charge = length * .35;
                if(mins < 10){
                    azeroes = ":0";
                }else{
                    azeroes = ":";
                }
                if(hours < 10){
                    bzeroes = "0";
                }
                else{
                    bzeroes = "";
                }
            }
            outFile << left << setw(12) << name << right << setw(6) << " ";
            outFile << bzeroes << hours << azeroes << mins << setw(10) << length;
            outFile << "      $" << setw(7) << fixed << setprecision(2) << charge; 
            outFile << fixed << setprecision(0) << endl;
        }else{
            if(mins < 10){
                azeroes = ":0";
            }else{
                azeroes = ":";
            }
            if(hours < 10){
                bzeroes = "0";
            }
            else{
                bzeroes = "";
            }
                outFile << left << setw(12) << name << right << setw(6) << " ";
                outFile << bzeroes << hours << azeroes << mins << setw(10) << length;
                outFile << setw(14) << "ERROR" << endl;
        }
    }
    inFile.close();
    outFile.close();
    return 0;
}