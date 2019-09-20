#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

    ifstream infile;
    vector<int> A;
    int x=0;

    //read input
    infile.open("108.txt");
    while(!infile.eof()){
        infile >> x;
        A.push_back(x);   
    }
    infile.close();

    //
    return 0;
}