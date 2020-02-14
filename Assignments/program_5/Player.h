/*AUTHOR: Landon M. Brown
*FILE TITLE: Player.h
*ASSIGNMENT DESCRIPTION: this file is used to define a player
*DUE DATE: TBD
*DATE CREATED: 12/4/2019
*DATE LAST MODIFIED: 12/5/2019
 */

#include "Deck.h"

//hand object
struct Hand{
    Card *head;
    Card *tail;
    int size;
    int value;

    //empty constructor
    Hand(){
        head = NULL;
        tail = NULL;
        size = 0;
        value = 0;
    }

    //loaded constructor (unnecessary)
    // Hand(int s, int v){
    //     size = s;
    //     value = v;
    //     head = NULL;
    //     tail = NULL;
    // }

    //destructor
    ~Hand(){
        Card* temp = head;
        while(temp){
            temp = head->_getNext();
            delete head;
            head = temp;
        }
        head = NULL;
        tail = NULL;
    }

    //copy constructor
    Hand(const Hand& that){
        this->head = NULL;
        this->tail = NULL;
        if(that.head){
            this->head = new Card(*that.head);
            Card* T1 = this->head;
            this->tail = this->head;
            Card* T2 = that.head->_getNext();
            while(T2){
                T1->_setNext(new Card(*T2));
                this->tail = T1->_getNext();
                T1 = T1->_getNext();
                T2 = T2->_getNext();
            }
        }
    }

    void Add(Card c){
        if (!head)
        {
            head = new Card(c);         //if list is empty, make a new node
            tail = head;                //and set head and tail = that
        }
        else
        {
            Card *temp = new Card(c);       //make a new card and link
            temp->_setPrev(tail);           //it in the the end of the
            tail->_setNext(temp);           //hand properly
            tail = temp;
        }
        this->size++;                   //increment size
    }

    
};

// //player object
// class Player{
// private:
//     Hand* hand;
//     int score;

// public:
//     Player(){
//         hand = NULL;
//         score = 0;
//     }

//     ~Player(){
//         delete hand;
//     }





// };