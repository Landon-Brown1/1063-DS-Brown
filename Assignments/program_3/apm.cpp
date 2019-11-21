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
struct Node
{
    int data;
    Node *next;
    Node *prev;
    //base constructor
    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    //loaded constructor
    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

//List Object
class List
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    //base constructor for empty list
    List()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    //destructor
    ~List(){
        while(head){
            Node* temp = head->next;
            delete head;
            head = temp;
        }
        tail = NULL;
    }
    //copy constructor, I purposefully don't
    //  use any functions in my constructors
    //  for my own sanity in debugging
    List(const List &other)
    {
        if (other.head)
        {
            Node *oldTemp = other.head;
            this->head = new Node(oldTemp->data);
            this->tail = this->head;
            Node *newTemp = this->head;
            Node *newPrev = newTemp;
            oldTemp = oldTemp->next;
            while (oldTemp)
            {
                newTemp = new Node(oldTemp->data);
                newTemp->prev = newPrev;
                newPrev->next = newTemp;
                newPrev = newTemp;
                oldTemp = oldTemp->next;
            }
            this->tail = newTemp;
            this->size = other.size;
        }
    }
    //overloaded assignment operator
    const List& operator=(List& other)
    {
        if (this == &other) // if both lists are the same dont change
            return *this;

        delete this;        //call destructor

        Node* current = other.head;   // set ptr to first link
        while(current != NULL)       // until ptr points beyond last link
        {
            GiveBack(current->data); // print data
            current = current->next; // move to next link
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
    void GiveFront(int x)
    {
        if (!head)
        {
            //  cout << "Adding to empty list";
            head = new Node(x);
            tail = head;
        }
        else
        {
            //  cout << "Adding to Non-empty list";
            Node *temp = new Node(x);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        this->size++;
    }

    //************************************************************
    // description: push a Node to the back of the list          *
    // return: none                                              *
    // precondition: a list exists                               *
    // postcondition: the list has one more node at the back     *
    //************************************************************
    void GiveBack(int x)
    {
        if (!head)
        {
            head = new Node(x);
            tail = head;
        }
        else
        {
            // cout << "B";
            Node *temp = new Node(x);
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        this->size++;
    }

    //pops (for the sake of variety)
    //************************************************************
    // description: pop a Node from the front of the list        *
    // return: none                                              *
    // precondition: a list exists and is not empty              *
    // postcondition: the list has one less node at the front    *
    //************************************************************
    int TakeFront()
    {
        int RetVal = 0;
        if (head)
        {
            RetVal = head->data;
            Node *temp = head->next;
            delete head;
            head = temp;
            if (head)
                head->prev = NULL;
            else
                tail = NULL;
            this->size--;
        }
        return RetVal;
    }

    //************************************************************
    // description: pop a Node from the back of the list         *
    // return: none                                              *
    // precondition: a list exists and is not empty              *
    // postcondition: the list has one less node at the back     *
    //************************************************************
    int TakeBack()
    {
        int RetVal = 0;
        if (head)
        {
            RetVal = tail->data;
            Node *temp = tail->prev;
            delete tail;
            tail = temp;
            if (tail)
                tail->next = NULL;
            else
                head = NULL;

            this->size--;
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
    ostream &Print(ostream &out)
    {
        Node *temp = head;
        if(temp == NULL){
            out << "EMPTY LIST" << endl;
            return out;
        }
        while (temp != NULL)
        {
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
    ostream &PrintReverse(ostream &out)
    {
        Node *temp = tail;
        while (temp)
        {
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
    List Add(List b)
    {
        List newAdd;

        while (this->size > 0 || b.size > 0){
             newAdd.GiveFront(TakeBack() + b.TakeBack());
            // cout << this->size << " " << b.size << endl;
        }
           
        Node *temp = newAdd.tail;
        while (temp)
        {
            if (temp->data >= 10)
            {
                if (temp->prev == NULL)
                {
                    newAdd.GiveFront((temp->data / 10));
                    temp->data = temp->data % 10;
                    temp = temp->prev;
                }
                else
                {
                    temp->prev->data += (temp->data / 10);
                    temp->data = temp->data % 10;
                    temp = temp->prev;
                }
            }
            else{
                temp = temp->prev;
            }
        }
        return newAdd;
    }

    //************************************************************
    // description: subtract the contents of 2 lists             *
    // return: List                                              *
    // precondition: 2 lists exist and are not empty             *
    // postcondition: list2 subbed from list1 and returned as one*
    //************************************************************
     List Subtract(List b)
    {
        List newSub;

        while (this->size > 0 || b.size > 0)
            newSub.GiveFront(TakeBack() - b.TakeBack());

        Node *temp = newSub.tail;
        while (temp)
        {
            if (temp->data < 0)
            {
                if (temp->prev == NULL)
                {
                    newSub.GiveFront(0);
                    temp = temp->prev;
                }
                else
                {
                    temp->prev->data -= (1);
                    temp->data = temp->data + 10;
                    temp = temp->prev;
                }
            }
            else{
                temp = temp->prev;
            }
        }
        return newSub;
    }

    //************************************************************
    // description: multiply the contents of 2 lists and         *
    // return: List                                              *
    // precondition: 2 lists exist and are not empty             *
    // postcondition: lists are multiplied and returned as one   *
    //************************************************************
    List Multiply(List b){
        List newList;
        for(int i = 0; i < b.size; i++){
            List tempList;
            cout << "Made tempList" << endl;
            Node* L1 = this->tail;
            cout << "Made L1" << endl;
            while (L1){
                cout << "push to front of tempList..." << endl;
                tempList.GiveFront(L1->data * b.tail->data);
                cout << "traverse list 1" << endl;
                L1 = L1->prev;
            }
            for(int f = 0; f < i; f++){
                cout << "adding a 0 to the end of tempList" << endl;
                tempList.GiveBack(0);
            } 
            
            tempList.Print(cout);

            cout << "adding tempList to newList" << endl;
            List oof = newList.Add(tempList);       //system didnt like me using the function
            oof.Print(cout);
            newList = oof;                          // to add them so i made another list
            newList.Print(cout);
            cout << "remove the last node in b" << endl;
            b.TakeBack();
        }
        
        cout << "return newList" << endl;
        return newList;
    }
};
/*main*/
/////////////////////////////////////////////
int main()
{

    ifstream inFile;
    ofstream outFile;
    inFile.open("input_data.txt");
    outFile.open("output.num");
    outFile << "Landon Brown" << endl
            << "Program 3" << endl
            << "Arbitrary Precision Math" << endl
            << endl;
    char operation = ' ';
    int problems = 99; //(っ▀¯▀)つ and a bitch ain't one
    string n1 = "", n2 = "";

    inFile >> problems;
    for (int i = 0; i < problems; i++)
    {
        List A, B;
        inFile >> operation >> n1 >> n2;
        for (int f = 0; f < n1.size(); f++)
        {
            int hemp = n1[f] - 48;
            A.GiveBack(hemp);
        }
        for (int f = 0; f < n2.size(); f++)
        {
            int hemp = n2[f] - 48;
            B.GiveBack(hemp);
        }

        outFile << "Operation " << (i + 1) << ": ";
        switch (operation)
        {
            case '+':
                outFile << "Addition" << endl;
                outFile << "Answer:" << endl << endl;
                    (A.Add(B)).Print(outFile);
                outFile << endl;
                break;
            case '-':   
                outFile << "Subtraction" << endl;
                outFile << "Answer:" << endl << endl;
                    (A.Subtract(B)).Print(outFile);
                outFile << endl;
                break;
            case '*':   
                outFile << "Multiplication" << endl;
                outFile << "Answer:" << endl << endl;
                    (A.Multiply(B)).Print(outFile);
                outFile << endl;
                break;
            default:
                break;
        }
    }

    inFile.close();
    outFile.close();
    return 0;
}