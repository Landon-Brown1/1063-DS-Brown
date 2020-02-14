/*AUTHOR: Landon M. Brown
*FILE TITLE: blackjack.cpp
*ASSIGNMENT DESCRIPTION: the purpose of this assignment is essentially implement a 
*   game of blackjack using what we've learned about classes and functions as well 
*   as the TermGame library Jeremy has created.
*DUE DATE: TBD
*DATE CREATED: 12/4/2019
*DATE LAST MODIFIED: 12/5/2019
 */

#include <iostream>
#include <fstream>
#include <iomanip>
//string is in card.h

#include "TermGame.h"
#include "Player.h"
#include "Opponent.h"

    //going to try creating without namespace std

namespace TP = TermPrint;
namespace TG = TermGame;
// namespace TE = TermError;

int main(){

    srand(time(NULL));

    TP::print("PROGRAM CURRENTLY RUNS ALL THE WAY THROUGH", (rand() % 8), (rand() % 8), false);

    return 0;
}