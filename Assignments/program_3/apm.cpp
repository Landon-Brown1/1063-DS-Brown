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
    const List &operator=(List other)
    {
        if (this != &other)
        {
            //delete old list
            Node *current = this->head;
            Node *temp;
            while (current)
            {
                temp = current->next;
                delete current;
                current = temp;
            }
            this->head = NULL;
            //copy constructor and set new head
            this->head = other.head;
            this->size = other.size;
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
            // cout << "A";
            head = new Node(x);
            tail = head;
        }
        else
        {
            // cout << "F";
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
        char RetVal = 0;
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
        char RetVal = 0;
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
        List newList;

        while (this->size > 0 || b.size > 0)
            newList.GiveFront(TakeBack() + b.TakeBack());

        Node *temp = newList.tail;
        while (temp)
        {
            if (temp->data >= 10)
            {
                if (temp->prev == NULL)
                {
                    newList.GiveFront((temp->data / 10));
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
        return newList;
    }

    //************************************************************
    // description: subtract the contents of 2 lists             *
    // return: List                                              *
    // precondition: 2 lists exist and are not empty             *
    // postcondition: list2 subbed from list1 and returned as one*
    //************************************************************
     List Subtract(List b)
    {
        List newList;

        while (this->size > 0 || b.size > 0)
            newList.GiveFront(TakeBack() - b.TakeBack());

        Node *temp = newList.tail;
        while (temp)
        {
            if (temp->data < 0)
            {
                if (temp->prev == NULL)
                {
                    newList.GiveFront(0);
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
        return newList;
    }

    //************************************************************
    // description: multiply the contents of 2 lists and         *
    // return: List                                              *
    // precondition: 2 lists exist and are not empty             *
    // postcondition: lists are multiplied and returned as one   *
    //************************************************************
    List Multiply(List b){
        List nList;
        List tempList;

        //need to rewrite: make it so that it reads a single integer
        //  multiplication into a linked list, then adds it to a total list
        while (b.size > 0){
            //pointer to traverse first list
            Node* L1 = this->tail;
            //pointer to traverse second list
            Node* L2 = b.tail;
            //result for each individual digit
            long int tempResult = 0;
            //total for each loop
            long long int total = 0;
            //carry of each individual digit
            long int carry = 0;
            //number of runs in the inside loop
            int numRuns = 0;
            /*inner loop to multiply each number*/
            while(L1){
                // printf("Multiplying %d x %d\n", L1->data, L2->data);
                tempResult = L1->data * L2->data;
                // printf("TempResult is %d\n", tempResult);
                tempResult += carry;
                carry = 0;
                if(L1->prev){
                    carry += (tempResult / 10);
                    // printf("TempResult is %d and TR mod 10 is %d\n", tempResult, (tempResult % 10));
                    total += (tempResult % 10) * pow(10.0,numRuns);
                    // printf("Carry is %d and remainder is %f\n", tempResult / 10,  (tempResult % 10) * pow(10.0,numRuns));
                    // printf("%d mod 10 = %d and 10^%d = %f\n", tempResult, (tempResult % 10), numRuns, pow(10,numRuns));
                }else{
                    // printf("Carry is %d and remainder is %f\n", tempResult / 10,  (tempResult % 10) * pow(10.0,numRuns));
                    total += ((tempResult * pow(10.0,numRuns)));
                }
                // cout << total << " " << tempResult << " " << carry << " " << endl;
                numRuns++;
                L1 = L1->prev;
            }
            nList.GiveFront(total);
            b.TakeBack();
        }

        //this chuck traverses the new list, and moves digits over
        //  due to carries as it goes. 
        //  (ex from 12->34->1->58 to 1->5->4->6->8)
        Node *temp = nList.tail;
        while (temp)
        {
            if (temp->data >= 10)
            {
                if (temp->prev == NULL)
                {
                    nList.GiveFront((temp->data / 10));
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
        return nList;
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