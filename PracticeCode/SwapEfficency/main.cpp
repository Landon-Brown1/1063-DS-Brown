#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
int main(){

    int a[100];
    srand(123);
    ofstream out;
    out.open("output.txt");

    for(int i = 0; i < 100; i++){
        a[i] = rand() % 100;
    }

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(a[j] > a[i]){
                swap(a[j],a[i]);
                j++;
                out << "█";
            }
        }
        out << endl;
    }

    out.close();
    return 0;
}