/*AUTHOR: Landon M. Brown
*FILE TITLE: ListStack.h
*ASSIGNMENT DESCRIPTION: List stack definition file. This stack hold animal
*   types. Why? Cause integers get a little boring after a while. 
*DUE DATE: 10/15/2019
*DATE CREATED: 10/12/2019
*DATE LAST MODIFIED: 10/12/2019
 */


#include <iostream>

using namespace std;

struct Animal {
    string name;
    double weight;
    double scary;

    Animal();
    Animal(string,double,double);
};

ostream &operator<<(ostream &, const Animal *);

struct Node {
    Animal *A;
    Node *Next;

    Node();
    Node(Animal *a);
};

class ListStack {
private:
    Node *Top;

public:
    ListStack();                    

    void Push(Animal *);          
    Animal *Pop();                 
    ostream& Print(ostream&);       
};