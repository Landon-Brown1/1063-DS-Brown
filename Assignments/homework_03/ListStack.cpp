/*AUTHOR: Landon M. Brown
*FILE TITLE: ListStack.cpp
*ASSIGNMENT DESCRIPTION: List stack implementation file.
*DUE DATE: 10/15/2019
*DATE CREATED: 10/12/2019
*DATE LAST MODIFIED: 10/12/2019
 */

#include "ListStack.h"

ostream &operator<<(ostream &os, const Animal *a){
    os << a->name << ':' << a->weight << ':' << a->scary;
    return os;
}

Animal::Animal(){
    name = "";
    weight = 0.0;
    scary = 99.0;
}

Animal::Animal(string name,double weight,double scary){
    this->name = name;
    this->weight = weight;
    this->scary = scary;
}

Node::Node(){
    A = NULL;
    Next = NULL;
}

Node::Node(Animal *a){
    A = new Animal(a->name,a->weight,a->scary);
    Next = NULL;
}

ListStack::ListStack(){
    Top = NULL;
}

void ListStack::Push(Animal *a){
    if(Top == NULL){
        Top = new Node(a);
    }
    else{
        Node* Temp = new Node(a);
        Temp->Next = Top;
        Top = Temp;
    }
}

Animal* ListStack::Pop(){
    if(Top == NULL){
        Node* Temp = Top;
        Animal *a = Top->A;
        Top = Top->Next;
        delete Temp;
        return a;
    }
    else{
        return NULL;
    }
}

ostream& ListStack::Print(ostream& out){
    Node* Temp = Top;
    while(Temp != NULL){
        out << Temp->A << endl;
        Temp = Temp->Next;
    }
    return out;
}