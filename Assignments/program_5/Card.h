/*AUTHOR: Landon M. Brown
*FILE TITLE: Card.h
*ASSIGNMENT DESCRIPTION: this file is used to define a card
*DUE DATE: TBD
*DATE CREATED: 12/4/2019
*DATE LAST MODIFIED: 12/5/2019
 */

#include <string>

class Card{
private:
    std::string suit;
    char value;
    Card* next;
    Card* prev;

public:
    //empty constructor
    Card(){
        suit = "spade";
        value = '2';
        next = NULL;
        prev = NULL;
    }

    //loaded constructor
    Card(std::string s, char c){
        suit = s;
        value = c;
        next = NULL;
        prev = NULL;
    }

    //copy constructor
    Card(const Card& c){
        suit = c.suit;
        value = c.value;
        next = c.next;
        prev = c.prev;
    }

    //overloaded assignment operator
    Card& operator= (const Card& that){
        if(this != &that){
            this->suit = that.suit;
            this->value = that.value;
            this->next = that.next;
            this->prev = that.prev;
        }
        return *this;
    }

    //returns card->next
    Card* _getNext(){
        return this->next;
    }

    //sets card->next
    void _setNext(Card* n){
        this->next = n;
    }

    //returns card->prev
    Card* _getPrev(){
        return this->prev;
    }

    //sets card->prev
    void _setPrev(Card* p){
        this->prev = p;
    }

    //returns card->suit
    std::string _getSuit(){
        return this->suit;
    }

    //sets card->suit
    void _setSuit(std::string s){
        this->suit = s;
    }

    //returs card->value
    char _getValue(){
        return this->value;
    }

    ///sets card->value
    void _setValue(char v){
        this->value = v;
    }
};