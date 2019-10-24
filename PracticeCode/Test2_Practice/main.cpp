#include <iostream>

using namespace std;

struct Node{          
  int data;           
  Node *next;
  Node(){
      data = 0;
      next = NULL;
  }
  Node(int x){
      data = x;
      next = NULL;
  }
};

struct List{
    Node* head;

    List(){
        head = NULL;
    }
    void Push(int x){
        Node* temp = new Node(x);
        if(head == NULL){
            head = temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
    }
    ostream& print(ostream& out){
        Node* temp = head;
        while(temp != NULL){
            out << temp->data << " ";
            temp = temp->next;
        }
        return out;
    }
};


int main(){

    List Numbers;
    
    Numbers.Push(23);
    Numbers.Push(11);
    Numbers.Push(9);
    Numbers.Push(6);
    Numbers.Push(4);

    Numbers.print(cout);
    cout << endl;
    Numbers.head->next->next->data = Numbers.head->next->next->next->data/3;
    Numbers.print(cout);
    cout << endl;
    Numbers.head->data = Numbers.head->data +2;
    Numbers.print(cout);
    cout << endl;

    return 0;
}