/*
* AUTHOR: Landon Brown
* ASSIGNMENT TITLE: program_3
* ASSIGNMENT DESCRIPTION: this program will use doubly linked lists
*       to add, subtract and multiply arbitrarily long numbers, 
*       then store them in a file.
* DUE DATE: 11/14/2019
* DATE CREATED: 11/12/2019
*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
                /*objects*/
///////////////////////////////////////////////
struct Node{
    char data;
    Node* next;
    Node* prev;
    //base constructor
    Node(){
        data = 0;
        next = NULL;
        prev = NULL;
    }
    //loaded constructor
    Node(char d){
        data = d;
        next = NULL;
        prev = NULL;
    }
}; 

class List{
    private:
        Node* head;
        Node* tail;
    public:
        //base constructor
        List(){
            head = NULL;
            tail = NULL;
        }
        //copy constructor
        List(const List& other){
            if(other.head){
                Node* oldTemp = other.head;
                this->head = new Node(oldTemp->data);
                this->tail = this->head;
                Node* newTemp = this->head;
                Node* newPrev = newTemp;
                oldTemp = oldTemp->next;
                while(oldTemp){
                    newTemp = new Node(oldTemp->data);
                    newTemp->prev = newPrev;
                    newPrev->next = newTemp;
                    newPrev = newTemp;
                    oldTemp = oldTemp->next;
                }
                this->tail = newTemp;
            }
        }
        //overloaded assignment operator
        const List& operator= (const List& other){
            if(this != &other){
                //delete old list
                Node* current = this->head;
                Node* temp;
                while(current){
                    temp = current->next;
                    delete current;
                    current = temp;
                }
                this->head = NULL;
                List F(other);
                swap(F.head, this->head);
            }
            return *this;
        }
        //pushes (for the sake of variety)
        void GiveFront(char x){
            if(!head){
                // cout << "A";
                head = new Node(x);
                tail = head;
            }
            else{
                // cout << "F";
                Node* temp = new Node(x);
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
        }
        void GiveBack(char x){
            if(!head){
                head = new Node(x);
                tail = head;
            }
            else{
                // cout << "B";
                Node* temp = new Node(x);
                temp->prev = tail;
                tail->next = temp;
                tail = temp;
            }
        }
        //pops (for the sake of variety)
        char TakeFront(){
            char RetVal = 0;
            if(head){
                RetVal = head->data;
                Node* temp = head->next;
                delete head;
                head = temp;
                head->prev = NULL;
            }
            return RetVal;
        }
        char TakeBack(){
            char RetVal = 0;
            if(head){
                RetVal = tail->data;
                Node* temp = tail->prev;
                delete tail;
                tail = temp;
                tail->next = NULL;
            }
            return RetVal;
        }

        //print stuff
        ostream& Print(ostream& out){
            Node* temp = head;
            // cout << "P";
            while(temp != NULL){
                // cout << "P";
                out << temp->data;
                temp = temp->next;
            }
            out << endl;
            return out;
        }
        //(for shits and giggles)
        ostream& PrintReverse(ostream& out){
            Node* temp = tail;
            while(temp){
                // cout << "PR";*
                out << temp->data;
                temp = temp->prev;
            }
            out << endl;
            return out;
        }

        //operations
        // List Add(List b){
        //     List res;
        //     bool carry = false;
        //     while(this->head != NULL || b.head != NULL){
        //         if(carry == true){
        //             res.GiveBack((this->TakeBack() + b.TakeBack() + 1));
        //         }else{
        //             res.GiveBack((this->TakeBack() + b.TakeBack()));
        //         }
        //         carry = false;
        //         if(res.tail->data >= 10){
        //             res.tail -= 10;
        //             carry = true;
        //         }
        //     }
        //     return res;
        // }
        // List Subtract(List b){
        //     List res;
        //     return res;
        // }
        // List Multiply(List b){
        //     List res;
        //     return res;
        // }
};
                /*main*/
/////////////////////////////////////////////
int main(){

    ifstream inFile;
    ofstream outFile;
    inFile.open("input_data.txt");
    outFile.open("output.num");
    outFile << "Landon Brown" << endl
            << "Program 3" << endl
            << "Arbitrary Precision Math" << endl << endl;
    char operation = ' ';
    int problems = 99; //(っ▀¯▀)つ a bitch ain't one
    string n1 = "",n2 = "";
    List A,B,Result;

    inFile >> problems;
    for(int i = 0; i < problems; i++){
        inFile >> operation >> n1 >> n2;
        for(int f = 0; f < n1.size(); f++){
            A.GiveBack(n1[f]);
        }
        for(int f = 0; f < n2.size(); f++){
            B.GiveBack(n2[f]);
        }
        outFile << "Operation " << (i+1) << ": ";
        // switch(operation){
        //     case '+':   outFile << "Addition";
        //                 Result = A.Add(B);
        //                 break;
        //     case '-':   outFile << "Subtraction"; 
        //                 Result = A.Subtract(B);
        //                 break;
        //     case '*':   outFile << "Multiplication";
        //                 Result = A.Multiply(B);
        //                 break;
        //     default:    break;
        // }
        outFile << endl << "Answer:" << endl << endl;
        Result.Print(outFile);
        outFile << endl;
    }

    inFile.close();
    outFile.close();
    return 0;
}