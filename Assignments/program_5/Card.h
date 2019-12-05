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

public:
    //empty constructor
    Card(){
        suit = "spade";
        value = '2';
        next = NULL;
    }

    //loaded constructor
    Card(std::string s, char c){
        suit = s;
        value = c;
        next = NULL;
    }

    //copy constructor
    Card(const Card& c){
        suit = c.suit;
        value = c.value;
    }

    //overloaded assignment operator
    Card& operator= (const Card& that){
        if(this != &that){
            this->suit = that.suit;
            this->value = that.value;
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