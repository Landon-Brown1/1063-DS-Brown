/*AUTHOR: Landon M. Brown
*FILE NAME: functions.cpp
*ASSIGNMENT DESCRIPTION: This project will add functions to resize an
*   array if the number of elements gets too large or too small.
*DUE DATE: 10/8/2019
*DATE CREATED: 10/1/2019
*DATE LAST MODIFIED: 10/1/2019
 */

#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;

//************************************************************
// description: basic stack constructor                      *
// return: none                                              *
// precondition: none                                        *
// postcondition: creates a stack of size 100                *
//                                                           *
//************************************************************
Stack::Stack(){
  Size = 100;
  A = new int[Size];
  Top = -1;
  resized = false;
}

//************************************************************
// description: destructor for a stack object                *
// return: none                                              *
// precondition: a stack exists                              *
// postcondition: the stack is deleted                       *
//                                                           *
//************************************************************
Stack::~Stack(){
  delete[] A;
}

//************************************************************
// description: loaded constructor for a stack               *
// return: none                                              *
// precondition: an integer is passed in for size            *
// postcondition: a stack of size s is created               *
//                                                           *
//************************************************************
Stack::Stack(int s){
  Size = s;
  A = new int[Size];
  Top = -1;
  resized = false;
}

//************************************************************
// description: returns the size of the stack                *
// return: int                                               *
// precondition: a stack exists                              *
// postcondition: returns an integer                         *
//                                                           *
//************************************************************
int Stack::getSize(){
  return Size;
}

//************************************************************
// description: looks to see if stack needs resizing         *
// return: none                                              *
// precondition: a stack exists                              *
// postcondition: enlarges or reduces size of stack if needed*
//                                                           *
//************************************************************
void Stack::_checkResize(){
  if (Top >= (Size * .8)){
    resized = true;
    _enlarge();
  }
  if (Top <= (Size * .2) && resized == true){
    _reduce();
  }
}

//************************************************************
// description: enlarges the size of the stack               *
// return: int                                               *
// precondition: a stack exists                              *
// postcondition: increases the size of stack and returns it *
//                                                           *
//************************************************************
int Stack::_enlarge(){
  int newSize = (Size * 1.5);
  int *A2 = new int[newSize];
  for(int i = 0; i < Size; i++){
    A2[i] = A[i];
  }
  delete [] A;
  A = A2;
  Size = newSize;
  return newSize;
}

//************************************************************
// description: shrinks the size of the stack                *
// return: int                                               *
// precondition: a stack exists                              *
// postcondition: reduces the size of stack and returns it   *
//                                                           *
//************************************************************
int Stack::_reduce(){
  int newSize = (Size * .5);
  int *A2 = new int[newSize];
  for(int i = 0; i < newSize; i++){
    A2[i] = A[i];
  }
  delete [] A;
  A = A2;
  Size = newSize;
  return newSize;

}

//************************************************************
// description: adds a val and increments top of stack       *
// return: bool                                              *
// precondition: a non-full stack exists                     *
// postcondition: returns false if full true if not          *
//                                                           *
//************************************************************
bool Stack::Push(int val){
  if (!Full()){
    Top++;
    A[Top] = val;
    _checkResize();
    return true;
  }
  else{
    return false;
  }
}

//************************************************************
// description: removes and returns top of stack             *
// return: int                                               *
// precondition: a stack with values exists                  *
// postcondition: returns value taken from the stack         *
//                                                           *
//************************************************************
int Stack::Pop(){
  if (!Empty()){
    int temp = 0;
    temp = A[Top];
    Top--;
    _checkResize();
    return temp;
  }
  else{
    return -696969;
  }
  return 0;
}

//************************************************************
// description: prints stack to screen                       *
// return: none                                              *
// precondition: a stack exists                              *
// postcondition: a stack's values are printed to ostream    *
//                                                           *
//************************************************************
void Stack::Print(ostream& out){
  for (int i = Top; i >= 0; i--){
    out << A[i] << " ";
  }
}


//************************************************************
// description: Is stack empty                               *
// return: bool                                              *
// precondition: a stack exists                              *
// postcondition: returns true if full false if not          *
//                                                           *
//************************************************************
bool Stack::Empty(){
  return Top < 0;
}

//************************************************************
// description: Is stack full                                *
// return: bool                                              *
// precondition: a stack exists                              *
// postcondition: returns true if full false if not          *
//                                                           *
//************************************************************
bool Stack::Full(){
  return (Top == Size - 1);
}