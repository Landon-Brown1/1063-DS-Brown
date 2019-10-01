#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    int lineSize = 0;
    int lossReports = 0;
    bool new_line = true;
    ifstream inFile;
    inFile.open("12356.txt");

    while(!inFile.eof()){
        if(new_line == true){
            inFile >> lineSize;
            inFile >> lossReports;
            new_line = false;
        }
        vector<int> V(lineSize);
        for(int i = 0; i < lineSize; i++){
            V.push_back(i);
        }
    }

    return 0;
}