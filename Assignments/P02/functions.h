/*AUTHOR: Landon M. Brown
*FILE NAME: functions.h
*ASSIGNMENT DESCRIPTION: This project will add functions to resize an
*   array if the number of elements gets too large or too small.
*DUE DATE: 10/8/2019
*DATE CREATED: 10/1/2019
*DATE LAST MODIFIED: 10/8/2019
 */

/**
 * File: stack.h
 * Author: Terry Griffin
 * Course: CMPS 1063 - Fall 2019
 * Date: 24 Sep 24
 * Description:
 *    Definition of our stack class.
 */
#pragma once
#include<iostream>

class Stack{
  private:
    int *A;                   // container of items (could make it a list)
    int Top;                  // keep track of top
    int Size;                 // Arrays need a size
    bool resized;             // tells whether the stack has been previously resized

    void _checkResize();      // returns if the array needs to be enlarged
    int _enlarge();           // embiggens the array
    int _reduce();            // shrinks the array

  public:
    Stack();                  // Default constructor
    ~Stack();                 // Destructor
    Stack(int);               // overloaded constructor

    int getSize();
    bool Push(int);           // Push value onto stack
    int Pop();                // Remove item from top of stack
    void Print(std::ostream&);// Help inspect values
    bool Empty();             // Is stack empty
    bool Full();              // is stack full

};
