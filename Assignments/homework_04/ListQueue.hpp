/*AUTHOR: Landon M. Brown
*FILE TITLE: ListQueue.hpp
*FILE DESCRIPTION: this file holds definitions for all of our list-based queue functions.
*DUE DATE: 10/15/2019
*DATE CREATED: 10/15/2019
*DATE LAST MODIFIED: 10/15/2019
 */

#include <iostream>

using namespace std;

//animal object
struct Animal {
    string name;
    double weight;
    double scary;

    Animal(){                       // base constructor
        name = "";
        weight = 0.0;
        scary = 99.0;
    }
    Animal(string name,double weight,double scary){   // overloaded constructor
        this->name = name;
        this->weight = weight;
        this->scary = scary;
    }
};

//overloaded output operator for an animal list
ostream &operator<<(ostream &os, const Animal *a){
    os << a->name << ':' << a->weight << ':' << a->scary;
    return os;
}

struct Node{          // Typical node setup for a list. 
  Animal *A;           // animal data.
  Node *Next;

  Node(){             // default constructor
    A = NULL;
    Next = NULL;
  }

  Node(Animal* a){      // overloaded constructor
    A = new Animal(a->name,a->weight,a->scary);
    Next = NULL;
  }
};

/**
 * List Queue
 * 
 * List Based Queue
 * 
 */
class ListQueue{
private:
  Node* Front;                          // front of the queue (where we remove from)
  Node* Rear;                           // rear of the queue (where we add to)
public:
  ListQueue();                          // construct
  void Push(Animal*);                   // add animal to rear
  Animal* Pop();                        // remove from front
  ofstream& Print(ofstream& out);       // print for debugging
  bool Empty();                         // is queue empty (can't remove from empty queue)
  ofstream& PrintPointers(ofstream&);   // added for lecture purposes
  Node* GetFront();                     // added for lecture purposes
};


/**
 * ListQueue
 * Purpose:
 *     Constructs our queue
 * Params:
 *     void
 * Returns:
 *     void
 */
ListQueue::ListQueue(){
  Front = Rear = NULL;
}

/**
 * Push
 * Purpose:
 *     Adds item to rear of queue
 * Params:
 *     animal *a : item to be added
 * Returns:
 *     void
 */
void ListQueue::Push(Animal *a){
  Node* temp = new Node(a);     // allocate new memory

  if(Front == NULL){              // if list is empty
    Front = Rear = temp;          // point everyone to it
  }else{
    Rear->Next = temp;            // otherwise link last node to new one
    Rear = temp;                  // then point Rear to it.
  }

}

/**
 * Pop
 * Purpose:
 *     Removes item from front of queue
 * Params:
 *     void
 * Returns:
 *     animal : front item
 */
Animal* ListQueue::Pop(){
  Animal *temp = Front->A;     // get front data temporarily
  Node* T = Front;            // Point to the front temporarily
  Front = Front->Next;        // Move front to next item 
  delete T;                   // Now we can delete the old front

  if(!Front){                 // If front is NULL make rear NULL as well
    Rear = NULL;              // because if front is NULL list is empty!  
  }

  return temp;                // return front animal
}

/**
 * Print
 * Purpose:
 *     Prints items in queue for debugging
 * Params:
 *     ofstream&
 * Returns:
 *     ofstream&
 */
ofstream& ListQueue::Print(ofstream& out){
  Node* temp = Front;

  while(temp){
    out<<temp->A;
    if(temp->Next){
      out<<" -> ";
    }
    temp = temp->Next;
  }
  out<<endl;
  return out;
}

/**
 * Empty
 * Purpose:
 *     Checks for empty queue. Cant remove from empty queue!
 * Params:
 *     void
 * Returns:
 *     bool: true == empty 
 */
bool ListQueue::Empty(){
  return Front == NULL;
}

/**
 * PrintPointers
 * Purpose:
 *     Prints front and rear values for lecture purposes
 * Params:
 *     ofstream&
 * Returns:
 *     ofstream&
 */
ofstream& ListQueue::PrintPointers(ofstream& out){
  out<<"Front = "<<Front<<endl;
  out<<"Rear = "<<Rear<<endl;
  return out;
}


/**
 * GetFront
 * Purpose:
 *     Returns the front node, for lecture purposes
 * Params:
 *     void
 * Returns:
 *     Node*
 */
Node* ListQueue::GetFront(){
  return Front;
}