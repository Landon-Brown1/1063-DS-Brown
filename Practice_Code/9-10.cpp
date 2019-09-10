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