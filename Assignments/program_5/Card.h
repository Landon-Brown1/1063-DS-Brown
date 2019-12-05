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
public:
    //empty constructor
    Card(){
        suit = "spade";
        value = '2';
    }

    //loaded constructor
    Card(std::string s, char c){
        suit = s;
        value = c;
    }

    //copy constructor
    Card(const Card& c){
        suit = c.suit;
        value = c.value;
    }

    //overloaded assignment operator
    Card& operator= (const Card& c){
        this->suit = c.suit;
        this->value = c.value;
    }
};