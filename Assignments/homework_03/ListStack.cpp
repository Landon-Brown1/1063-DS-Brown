/*AUTHOR: Landon M. Brown
*FILE TITLE: ListStack.cpp
*ASSIGNMENT DESCRIPTION: List stack implementation file.
*DUE DATE: 10/15/2019
*DATE CREATED: 10/12/2019
*DATE LAST MODIFIED: 10/12/2019
 */

#include "ListStack.h"

//overloaded output operator for an animal list
ostream &operator<<(ostream &os, const Animal *a){
    os << a->name << ':' << a->weight << ':' << a->scary;
    return os;
}

//Empty animal constructor
Animal::Animal(){
    name = "";
    weight = 0.0;
    scary = 99.0;
}

//loaded animal constructor
Animal::Animal(string name,double weight,double scary){
    this->name = name;
    this->weight = weight;
    this->scary = scary;
}

//empty node constructor
Node::Node(){
    A = NULL;
    Next = NULL;
}

//loaded node constructor
Node::Node(Animal *a){
    A = new Animal(a->name,a->weight,a->scary);
    Next = NULL;
}

//empty stack constructor
ListStack::ListStack(){
    Top = NULL;
}

//************************************************************
// description: push an animal to the stack                  *
// return: void                                              *
// precondition: valid animal object is given                *
// postcondition: animal is added to the stack               *
//************************************************************
void ListStack::Push(Animal *f){
    if(Top == NULL){
        Top = new Node(f);
    }
    else{
        Node* Temp = new Node(f);
        Temp->Next = Top;
        Top = Temp;
    }
}

//************************************************************
// description: pop an animal from the stack                 *
// return: Animal                                            *
// precondition: the stack is not empty                      *
// postcondition: animal returned from the stack             *
//************************************************************  
Animal* ListStack::Pop(){
    if(Top == NULL){
        return NULL;
    }
    else{
        Node* Temp = Top;
        Animal *f = Top->A;
        Top = Top->Next;
        delete Temp;
        return f;
    }
}

//************************************************************
// description: print the stack to an ostream                *
// return: ostream&                                          *
// precondition: valid ostream is given                      *
// postcondition: animal stack is printed to given ostream   *
//************************************************************ 
ostream& ListStack::Print(ostream& out){
    Node* Temp = Top;
    while(Temp != NULL){
        out << Temp->A << endl;
        Temp = Temp->Next;
    }
    return out;
}