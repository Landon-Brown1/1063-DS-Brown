/*AUTHOR: Landon M. Brown
*FILE TITLE: main.cpp (homework_04)
*ASSIGNMENT DESCRIPTION: the purpose of this program is to 
*   fix the ordering function we made in class
*DUE DATE: 11/07/2019  
*DATE CREATED: 11/07/2019
*DATE LAST MODIFIED: 11/07/2019
 */


#include <iostream>
#include <string>
#include <fstream> 

using namespace std;

struct Node{
  string word;
  Node* Next;

//************************************************************
// description: node constructor                             *
// return: none                                              *
// precondition: a valid string is given                     *
// postcondition: a node object is created                   *
//************************************************************
  Node(string w){
    word = w;
    Next = NULL;
  }
};

class Dictionary {
    private:
Node* Start;

//************************************************************
// description: make all letters for word(input) lowercase   *
// return: the input, lowercased                             *
// precondition: a valid word is given                       *
// postcondition: all letters in the word are now lowercase  *
//************************************************************
string LowerCase(string input){
    for(int i=0;i<input.length();i++){
        if((int)input[i] < 96){
            input[i] += 32;
        }
    }
    return input;
}

    public:

//************************************************************
// description: basic dictionary constructor                 *
// return: none                                              *
// precondition: none                                        *
// postcondition: a list object is created                   *
//************************************************************
Dictionary(){
    Start = NULL;
}

//************************************************************
// description: adds an animal to the list                   *
// return: none                                              *
// precondition: a list exists                               *
// postcondition: an animal(word) is added to the list       *
//************************************************************
void Add(string word){

    word = LowerCase(word);
    // create new memory
    Node* temp = new Node(word);

    // if list is empty hook in new Node
    if(Start == NULL){
        Start = temp;
    }else{
        // get ready to walk the list
        Node* traverse = Start;
        while(traverse->Next != NULL){
            // walks the list
            traverse = traverse->Next;
        }
        // now at proper place to link in new memory
        traverse->Next = temp;
    }
}

//************************************************************
// description: remove a given animal from the list          *
// return: the popped animal                                 *
// precondition: a list exists                               *
// postcondition: an animal of word(key) is removed          *
//************************************************************
string Remove(string key){
    string temp = "";

    if(!Start){
        return "";
    }else{
        Node* cptr = Start;
        Node* prev = Start;
        while(cptr && cptr->word != key){
            prev = cptr;
            cptr = cptr->Next;
        }
        // if cptr then we found the word
        if(cptr){
            temp = cptr->word;
            prev->Next = cptr->Next;
            delete cptr;
        }else{
            // no word, return empty
            temp = "";
        }
        return temp;
    }
    return temp;
}

//************************************************************
// description: fix the list to be in ascending order        *
// return: none                                              *
// precondition: a list exists                               *
// postcondition: the list is reordered if it has values     *
//************************************************************
//done with 3 pointers, 2 strings and a boolean
void ReOrder(){
    //exists so that the max values can be moved to the end easily
    Node* Tail = this->Start;
    while(Tail->Next != NULL){
        Tail = Tail->Next;
    }
    bool done = false;
    //runs until there are no nodes sorted on any given pass
    while(done == false){
        done = true;
        //list traversal pointers
        Node* temp = this->Start;
        Node* prev = this->Start;
        //keeping track of max and min words
        string minWord = Start->word;
        string maxWord = Tail->word;
        //pass loop
        while(temp->Next != NULL){
            //these two statements are probably unneccessary, 
            //but in a long list they can make the runtime a 
            //bit faster by putting max and min values at the
            //beginning and end of list, saving us more
            //traversals                        //////
            if(temp->word < minWord){               //
                minWord = temp->word;               // 
                prev->Next = temp->Next;            //
                temp->Next = this->Start;           //
                this->Start = temp;                 //
                done = false;                       //
                temp = prev;                        //
            }else if(temp->word > maxWord){         //
                maxWord = temp->word;               //
                prev->Next = temp->Next;            //
                temp->Next = NULL;                  //
                Tail->Next = temp;                  //
                Tail = temp;                        //
                done = false;                       //
                temp = prev;                    //////

                //this basically just swaps two values if they
                //aren't in order on that pass
            }else if(temp->Next->word < temp->word){
                prev->Next = temp->Next;
                temp->Next = temp->Next->Next;
                prev->Next->Next = temp;
                done = false;
            }
            prev = temp;
            temp = temp->Next;
        }
    }
}

//************************************************************
// description: print the list of animals with arrows        *
// return: none                                              *
// precondition: a list exists                               *
// postcondition: the list is printed out if it has values   *
//************************************************************
void Print(){
    Node* temp = Start;
    while(temp){
        cout<<temp->word;
        if(temp->Next){
            cout<<"->";
        }
        temp = temp->Next;
    }
    cout<<endl;
}

};                    /*main*/
/////////////////////////////////////////////////////

int main() {
  Dictionary W;

  W.Add("Ant");
  W.Add("Dog");
  W.Add("Aaron");
  W.Add("Aardvark");
  W.Add("Cat");
  W.Add("Cow");
  W.Add("Rabbit");
  W.Add("Jackal");
  W.Add("Gator");
  W.Add("Zebra");
  W.Add("Hare");
  W.Add("Aardvark");
  W.Add("Yeti");
  W.Add("Crab");
  W.Add("Tapir");
  W.Add("Rockfish");
  W.Add("Tiger");
  W.Add("Octopus");
  W.Add("Quokka");
  W.Add("Egret");

  W.Print();
  cout << endl;
  W.ReOrder();
  W.Print();

}