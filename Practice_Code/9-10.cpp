//creating a linked list

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int d = 0, Node* n = NULL){
        data = d;
        next = n;
    }
};

class List{
    private:
        Node* head;
        Node* tail;


    public:
        List(){
            head = NULL;
            tail = NULL;
        }

        void add(int d = 0){
            //list is no
            if(tail != NULL){
                tail->next = new Node(d);
                tail = tail->next;
            }
            else{head = new Node(d);
            tail = head;
            }
            
        }


};

int main(){

    List myList;


    cout << "Hello World" << endl;

    return 0;
}

/*
create a program that acts as a base converter

int main(){
    stringstream number = 0;
    int fromBase        = 0;
    int toBase          = 0;
    string confirm      = NULL;
    bool sure           = false;
    bool flag           = false;
    
    while(!sure){
    
        cout << "Please enter a base to convert from: ";
        cin >> fromBase;
        cout << endl;
        cout << "A base to convert to: ";
        cin >> toBase;
        cout << endl;
        cout << "And a number to convert: ";
        cin >> number;
        cout << endl;

        cout << "Okay, so you want to convert " << number 
             << " base " << fromBase 
             << " to base " << toBase << "?" << endl;

        while(!flag){
            cout << endl << "Type 'y' or 'n'";
            cin >> confirm;
            if(confirm == y){
                sure = true;
                flag = true;
            }
            else if(confirm == n){
                cout << "Okay, I'll reset your values."
                flag = true;
            }
            else{
                cout << "Invalid input, please try again." << endl;
            }
        
        } 

    }
    
}


*/