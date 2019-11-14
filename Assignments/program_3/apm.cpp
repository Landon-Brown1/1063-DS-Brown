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
//Node Object
struct Node{
    int data;
    Node* next;
    Node* prev;
    //base constructor
    Node(){
        data = 0;
        next = NULL;
        prev = NULL;
    }
    //loaded constructor
    Node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
}; 

//List Object
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
                //copy constructor and set new head
                this->head = other.head;
            }
            return *this;
        }

        //pushes (for the sake of variety)
        //************************************************************
        // description: push a Node to the front of the list         *
        // return: none                                              *
        // precondition: a list exists                               *
        // postcondition: the list has one more node at the front    *
        //************************************************************
        void GiveFront(int x){
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

        //************************************************************
        // description: push a Node to the back of the list          *
        // return: none                                              *
        // precondition: a list exists                               *
        // postcondition: the list has one more node at the back     *
        //************************************************************
        void GiveBack(int x){
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
        //************************************************************
        // description: pop a Node from the front of the list        *
        // return: none                                              *
        // precondition: a list exists and is not empty              *
        // postcondition: the list has one less node at the front    *
        //************************************************************
        int TakeFront(){
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

        //************************************************************
        // description: pop a Node from the back of the list         *
        // return: none                                              *
        // precondition: a list exists and is not empty              *
        // postcondition: the list has one less node at the back     *
        //************************************************************
        int TakeBack(){
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
        //************************************************************
        // description: print the contents of a list                 *
        // return: ostream&                                          *
        // precondition: a list exists and is not empty              *
        // postcondition: the list is printed to an ostream          *
        //************************************************************
        ostream& Print(ostream& out){
            Node* temp = head;
            while(temp != NULL){
                out << temp->data;
                temp = temp->next;
            }
            out << endl;
            return out;
        }
        //(for shits and giggles)
        //************************************************************
        // description: print the contents of a list, backwards      *
        // return: ostream&                                          *
        // precondition: a list exists and is not empty              *
        // postcondition: list is printed to an ostream in reverse   *
        //************************************************************
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

        // operations
        //************************************************************
        // description: add the contents of 2 lists                  *
        // return: List                                              *
        // precondition: 2 lists exist and are not empty             *
        // postcondition: the lists are added and returned as one    *
        //************************************************************
        List Add(List b){
            List res;
            Node* L1t = tail;
            Node* L2t = b.tail;
            int carry = 0;
            int data1 = L1t->data;
            int data2 = L2t->data;

            while(L1t != NULL || L2t != NULL){
                res.GiveFront((data1 + data2 + carry));
                
                carry = 0;
                if(res.head->data >= 10){
                    res.head->data -= 10;
                    carry = 1;
                }

                if(L1t->prev != NULL){
                    L1t = L1t->prev;
                    data1 = L1t->data;
                }else if(!L1t && L2t){
                    
                    data1 = 0;
                }else{
                    L1t = L1t->prev;
                }
                if(L2t->prev != NULL){
                    L2t = L2t->prev;
                    data2 = L2t->data;
                }else if(!L2t && L1t){
                    data2 = 0;
                }else{
                    L2t = L2t->prev;
                }
            }
            
            return res;
        }

        //************************************************************
        // description: subtract the contents of 2 lists             *
        // return: List                                              *
        // precondition: 2 lists exist and are not empty             *
        // postcondition: list2 subbed from list1 and returned as one*
        //************************************************************
        //  List Subtract(List b){
        //     List res;
        //     Node* L1t = tail;
        //     Node* L2t = b.tail;
        //     bool carry = false;
        //     int data1 = L1t->data;
        //     int data2 = L2t->data;

        //     while(L1t != NULL || L2t != NULL){
        //         if(carry == true){
        //             res.GiveFront((data1 - data2 - 1));
        //         }else{
        //             res.GiveFront((data1 - data2));
        //         }
        //         carry = false;
        //         if(res.head->data <= 0){
        //             res.head->data += 10;
        //             carry = true;
        //         }

        //         if(L1t->prev != NULL){
        //             L1t = L1t->prev;
        //             data1 = L1t->data;
        //         }else if(!L1t && L2t){
        //             data1 = 0;
        //         }else{
        //             L1t = L1t->prev;
        //         }
        //         if(L2t->prev != NULL){
        //             L2t = L2t->prev;
        //             data2 = L2t->data;
        //         }else if(!L2t && L1t){
        //             data2 = 0;
        //         }else{
        //             L2t = L2t->prev;
        //         }
        //     }
        //     res.Print(cout);
        //     return res;
        // }

        //************************************************************
        // description: multiply the contents of 2 lists and         *
        // return: List                                              *
        // precondition: 2 lists exist and are not empty             *
        // postcondition: lists are multiplied and returned as one   *
        //************************************************************
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
    List A,B,Empty;

    inFile >> problems;
    for(int i = 0; i < problems; i++){
        inFile >> operation >> n1 >> n2;
        for(int f = 0; f < n1.size(); f++){
            int hemp = n1[f]-48;
            A.GiveBack(hemp);
        }
        for(int f = 0; f < n2.size(); f++){
            int hemp = n2[f]-48;
            B.GiveBack(hemp);
        }
        cout << operation << endl;
        A.Print(cout);
        B.Print(cout);
        cout << endl;
        
        outFile << "Operation " << (i+1) << ": ";
        switch(operation){
            case '+':   outFile << "Addition" << endl;
                        outFile << "Answer:" << endl << endl;
                        (A.Add(B)).Print(outFile);
                        outFile << endl;
                        A = Empty;
                        B = Empty;
                        break;
            case '-':   outFile << "Subtraction" << endl;
                        outFile << "Answer:" << endl << endl;
                        (A.Add(B)).Print(outFile);
                        outFile << endl;
                        A = Empty;
                        B = Empty;
                        break;
            // case '*':   outFile << "Multiplication";
            //             outFile << "Answer:" << endl << endl;
            //             Result = A.Multiply(B);
            //             outFile << endl;
            //             break;
            default:    break;
        }
    }

    inFile.close();
    outFile.close();
    return 0;
}