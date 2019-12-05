/*AUTHOR: Landon M. Brown
*FILE TITLE: Player.h
*ASSIGNMENT DESCRIPTION: this file is used to define a player
*DUE DATE: TBD
*DATE CREATED: 12/4/2019
*DATE LAST MODIFIED: 12/5/2019
 */

#include "Deck.h"

struct Hand{
    Card *head;
    Card *tail;
    int size;

    //empty constructor
    Hand(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    //loaded constructor
    Hand(int s){
        size = s;
        head = NULL;
        tail = NULL;
    }

    //destructor
    ~Hand(){
        Card* temp = head;
        while(temp){
            temp = head->_getNext();
            delete head;
            head = temp;
        }
        head = NULL;
    }

    //copy constructor
    Hand(const Hand& that){
        this->head = NULL;
        if(that.head){
            this->head = new Card(*that.head);
            Card* T1 = this->head;
            Card* T2 = that.head->_getNext();
            while(T2){
                T1->_setNext(new Card(*T2));
                T1 = T1->_getNext();
                T2 = T2->_getNext();
            }
        }
    }

};

class Player{





};