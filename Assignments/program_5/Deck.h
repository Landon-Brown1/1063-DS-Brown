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
    Card* data;
public:
    //empty constructor
    Deck(){
        size = 0;
        capacity = 52;
        data = new Card[capacity];
    }

    //destructor
    ~Deck(){
        delete [] this->data;
    }
    //loaded constructor
    Deck(int s, Card* d, int c = 52){
        size = s;
        capacity = c;
        data = d;
    }

    //copy constructor
    Deck(const Deck& that){
        this->size = that.size;
        this->capacity = that.capacity;
        this->data = new Card[this->capacity];
        for(int i = 0; i < this->size; i++){
            this->data[i] = that.data[i];
        }
    }

    //overloaded assignment operator
    Deck& operator= (const Deck& that){
        if(this != &that){
            this->size = that.size;
            this->capacity = that.capacity;
            delete [] this->data;
            this->data = new Card[this->capacity];
            for(int i = 0; i < this->size; i++){
                this->data[i] = that.data[i];
            }
            return *this;
        }
    }
};