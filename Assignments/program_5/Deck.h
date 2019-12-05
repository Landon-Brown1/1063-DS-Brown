/*AUTHOR: Landon M. Brown
*FILE TITLE: Deck.h
*ASSIGNMENT DESCRIPTION: this file is used to define a Deck
*DUE DATE: TBD
*DATE CREATED: 12/4/2019
*DATE LAST MODIFIED: 12/5/2019
 */

#include "Card.h"

class Deck{
private:
    int size;
    int capacity;
    Card* top;
public:
    //empty constructor
    Deck(){
        size = 0;
        capacity = 52;
        top = NULL;
    }

    //loaded constructor
    Deck(int s, Card* d, int c = 52){
        // size = s;
        // capacity = c;

        // Card* temp = d;
        // while(d != NULL){

        // }
    }

    //copy constructor
    Deck(const Deck& d){
        
    }

    //overloaded assignment operator
    Deck& operator= (const Deck& d){
        
    }
};