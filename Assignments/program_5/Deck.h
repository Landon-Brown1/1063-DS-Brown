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
    Card* top;

public:
    //empty constructor
    Deck(){
        top = NULL;
    }

    //destructor
    ~Deck(){
        
    }

    //loaded constructor (unnecessary)
    // Deck(int s, Card* d, int c = 52){
    ///
    // }

    //copy constructor
    Deck(const Deck& that){
        
    }

    //overloaded assignment operator
    Deck& operator= (const Deck& that){
        
    }

    //remove a card from the top of the stack and return it
    Card Draw(){
        if(!top){
            std::cout << "Empty Deck" << std::endl;
        }
        else{
            Card* temp = top;
            Card c(*top);
            top = top->_getNext();
            delete temp;
            return c;
        }
    }
};