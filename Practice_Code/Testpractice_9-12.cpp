#include <iostream>
#include <fstream>

using namespace std;




int main(){

    int capacity = 5;
    int *list = new int[capacity];
    ifstream inData;
    int count = 0;

    inData.open("data.poop");
    if(!inData){
        cout << "Error no data file" << endl;
        exit(1);
    }

        

    while(!inData.eof()){
        
        inData >> list[count];
        cout << list[count] << " ";

        count++;

        if(count == capacity - 1){
            int* temp = new int[2*capacity];
            

            for(int i = 0; i < capacity; i++){
                temp[i] = list[i];
            }
            capacity *= 2;
            delete []list;
            list = temp;
        }
    }

    return 0;
}