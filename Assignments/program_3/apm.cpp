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
            Node* temp = head->next;    //until the list is empty
            delete head;                //delete a node
            head = temp;                //move to next node
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
            Node *oldTemp = other.head;             //temp pointer to traverse old list
            this->head = new Node(oldTemp->data);   //new head = to the other head data
            this->tail = this->head;                //tail = head
            Node *newTemp = this->head;             //new pointer to traverse new list
            Node *newPrev = newTemp;                //another to keep prev position so
            oldTemp = oldTemp->next;                //we can link the new list together
            while (oldTemp)
            {
                newTemp = new Node(oldTemp->data);  //make new node
                newTemp->prev = newPrev;            //link node to prev node
                newPrev->next = newTemp;            //link prev node to new node
                newPrev = newTemp;                  //move ptrs down
                oldTemp = oldTemp->next;
            }
            this->tail = newTemp;                   //tail is the last item in the list
            this->size = other.size;                //size is equal to the other list's size
        }
    }
    //overloaded assignment operator
    const List& operator=(List& other)
    {
        if (this == &other)          // if both lists are the same dont change
            return *this;

        delete this;                 // call destructor

        Node* current = other.head;  // set ptr to first link
        while(current != NULL)       // until ptr points beyond last link
        {
            GiveBack(current->data); // make list data = to other list data
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
            head = new Node(x);         //if list is empty, make a new node
            tail = head;                //and set head and tail = that
        }
        else
        {
            Node *temp = new Node(x);   //make a new node and link
            temp->next = head;          //it in the the front of the
            head->prev = temp;          //list properly
            head = temp;
        }
        this->size++;                   //increment size
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
            head = new Node(x);         //if list is empty, make a new node
            tail = head;                //and set head and tail = that
        }
        else
        {
            Node *temp = new Node(x);   //make a new node and link
            temp->prev = tail;          //it in the the end of the
            tail->next = temp;          //list properly
            tail = temp;
        }
        this->size++;                   //increment size
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
        int RetVal = 0;                 //if list is empty return 0
        if (head)
        {
            RetVal = head->data;        //set return = first value
            Node *temp = head->next;
            delete head;                //delete first value
            head = temp;
            if (head)                   //if list is still not empty,
                head->prev = NULL;      //just set head prev to null
            else
                tail = NULL;            //else, make sure tail=null

            this->size--;               //decrement size of list
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
        int RetVal = 0;                 //if list is empty return 0
        if (head)
        {
            RetVal = tail->data;        //set return = last value
            Node *temp = tail->prev;
            delete tail;                //delete last value
            tail = temp;
            if (tail)                   //if list is still not empty,
                tail->next = NULL;      //just set tail next to null
            else                        
                head = NULL;            //else, make sure head=null

            this->size--;               //decrement size of list
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
            out << "EMPTY LIST" << endl;    //if list is empty, say so
            return out;
        }
        while (temp != NULL)
        {
            out << temp->data;              //until list is empty, print
            temp = temp->next;              //and move to next node
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
        Node *temp = tail;          //same as print but bassackwards
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

        while (this->size > 0 || b.size > 0) //run till both lists are empty
             newAdd.GiveFront(TakeBack() + b.TakeBack());
                                             //just pop both values and add for new node
           
        Node *temp = newAdd.tail;            //ptr for traversal from back of list
        while (temp)
        {
            if (temp->data >= 10)            //if the data in the node is >1 digit
            {
                if (temp->prev == NULL)      //if at the front of the list
                {
                    newAdd.GiveFront((temp->data / 10));//make new node at front
                    temp->data = temp->data % 10;
                    temp = temp->prev;
                }
                else
                {
                    temp->prev->data += (temp->data / 10);//just add carry to next node
                    temp->data = temp->data % 10;
                    temp = temp->prev;
                }
            }
            else
            {
                temp = temp->prev;                  //just traverse if num is <10
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
        if(this->size < b.size){
            while (this->size > 0 || b.size > 0)//run till both lists are empty
                newSub.GiveFront(b.TakeBack() - TakeBack());
                                            //just take last val from both and sub
            newSub.GiveFront((-1 * newSub.TakeFront()));
        }
        else{
            while (this->size > 0 || b.size > 0)//run till both lists are empty
                newSub.GiveFront(TakeBack() - b.TakeBack());
                                            //just take last val from both and sub
        }
        Node *temp = newSub.tail;
        while (temp)
        {
            if (temp->data < 0)             //if data is negative
            {
                if (temp->prev == NULL)     //if at the front of the list
                {
                    temp = temp->prev;      //just move, first val says negative
                }
                else
                {
                    temp->prev->data -= (1);//sub 1 from prev node
                    temp->data = temp->data + 10;//add 10 to current node
                    temp = temp->prev;      //traverse
                }
            }
            else{
                temp = temp->prev;          //traverse
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
        int count = 0;                        //count for num of 0's
        List newList;              
        while(b.head){                        //outer loop for grand scheme
            List tempList;                    //temp list to hold each inner runthrough
            Node* L1 = this->tail;            //pointer to traverse top loop
            while (L1){
                tempList.GiveFront(L1->data * b.tail->data);
                L1 = L1->prev;                //mult i value in the 2nd list with 
            }                                 //all vals in the first list
            for(int f = 0; f < count; f++){
                tempList.GiveBack(0);         //0's to append for each iteration of the outer loop
            } 
        
            List oof = newList.Add(tempList); //system didnt like me setting newList = result
            newList = oof;                    //of newList.Add(tempList) so i made another list
            b.TakeBack();                       //remove last val from second loop and start over
            count++;
        }
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