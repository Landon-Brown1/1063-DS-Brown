/*
*AUTHOR: Landon M Brown
*ASSIGNMENT TITLE: Project 1
*ASSIGNMENT DESCRIPTION: Create a class for a linked list of employees
     and read and print to and from data files
*DUE DATE: 9/19/2019   
*DATE CREATED: 9/14/2019
*DATE LAST MODIFIED: 9/19/2019
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//employee object
struct Employee{
    
    string emp_id; 
    string first_name;
    string last_name;
    string gender;
    string email;
    double hourly_pay;
    Employee *Next;

    //basic constructor
    Employee(){
        emp_id = "";
        first_name = "";
        last_name = "";
        gender = "";
        email = "";
        hourly_pay = 0.0;
    }

    //loaded constructor
    Employee(string id,string first,string last,string sex,string mail, double pay){
        emp_id = id;
        first_name = first;
        last_name = last;
        gender = sex;
        email = mail;
        hourly_pay = pay * 1.0;
    }
};

//linked list
class EmployeeList{

private:
    Employee* Head;

public:
    //basic constructor
    EmployeeList(){
        Head = NULL;
    }

    //************************************************************
    // description: adds an employee to the front of the list    *
    // return: none                                              *
    // precondition: a list exists to hold the employee          *
    // postcondition: the new employee is added to the list      *
    //                                                           *
    //************************************************************
    void push(Employee e){
        // Employee* Temp = new Employee(e);

        // if(Head == NULL){
        //     Head = Temp;
        //     Temp->Next = NULL;
        // }else{
        //     Temp->Next = Head;
        //     Head = Temp;
        // }

        Employee *temp = new Employee(e);
        temp->Next = Head;
        Head = temp;
        
    }

    //**************************************************************
    // description: removes an employee from the front of the list *
    // return: none                                                *
    // precondition: an employee exists in the list                *
    // postcondition: that employee is removed from the list       *
    //                                                             *
    //**************************************************************
    void pop(){
        Employee *temp = new Employee;
        temp = Head;
        Head = Head->Next;
        delete temp;
    }

    //********************************************************************
    // description: prints (just the first 30 employee IDs) to an output *
    // return: none                                                      *
    // precondition: some item exists in the list                        *
    // postcondition: the items are printed to the output stream         *
    //                                                                   *
    //********************************************************************
    void print(ofstream& out){
        Employee* Temp = Head;
        //only print the first 30 employee Id's
        int count = 0;

        while(Temp != NULL && count < 30){
            out << Temp->emp_id << endl;
            // out << Temp->first_name << endl;
            // out << Temp->last_name << endl;
            // out << Temp->gender << endl;
            // out << Temp->email << endl;
            // out << setprecision(2) << fixed << Temp->hourly_pay << endl;
            count++;
            Temp = Temp->Next;
        }
    }

    //************************************************************
    // description: finds an item in the list                    *
    // return: boolean                                           *
    // precondition: an item exists in the list                  *
    // postcondition: a true or false return statement is given  *
    //                                                           *
    //************************************************************
    bool find(string data){
        Employee* Temp = Head;
        bool found = false;

        while(Temp != NULL){
            if(!found){
                if(Temp->emp_id == data){
                    found = true;
                }
                if(Temp->first_name == data){
                    found = true;
                }
                if(Temp->last_name == data){
                    found = true;
                }
                if(Temp->gender == data){
                    found = true;
                }
                if(Temp->email == data){
                    found = true;
                }
            }
            Temp = Temp->Next;
        }
        return found;
    }

    //overloaded function for finding a double value
    bool find(double data){
        Employee* Temp = Head;
        bool found = false;

        while(Temp != NULL){
            if(!found){
                if(Temp->hourly_pay == data){
                    found = true;
                }
            }
            Temp = Temp->Next;
        }
        return found;
    }

    //************************************************************
    // description: deletes an inputted item from the list       *
    // return: none                                              *
    // precondition: an item exists                              *
    // postcondition: if it does, it is deleted                  *
    //                                                           *
    //************************************************************
    void deleteItem(string data){
        Employee* Temp = Head;

        while(Temp != NULL){
            if(Temp->emp_id == data){
                Temp->emp_id = "NULL";
            }
            if(Temp->first_name == data){
                Temp->first_name = "NULL";
            }
            if(Temp->last_name == data){
                Temp->last_name = "NULL";
            }
            if(Temp->gender == data){
                Temp->gender = "NULL";
            }
            if(Temp->email == data){
                Temp->email = "NULL";
            }
            Temp = Temp->Next;
        }
    }

    //overloaded function for deleting a double value
    void deleteItem(double data){
        Employee* Temp = Head;

        while(Temp != NULL){
            if(Temp->hourly_pay == data){
                Temp->hourly_pay = 0;
            }
            Temp = Temp->Next;
        }
    }

    //***************************************************************
    // description: searches for matches to a term that is inputted *
    // return: integer                                              *
    // precondition: a list exists to search from                   *
    // postcondition: the amount of results is returned and the     *
    //      search results are put into the string array            *
    //***************************************************************
    int substringSearch(string input, string A[]){
        Employee* Temp = Head;
        int count = 0;

        //  just for email because that is what the assignment asked
        while(Temp != NULL){
            // if(Temp->emp_id.find(input) != string::npos){
            //     A[count] = Temp->emp_id;
            //     count++;
            // }
            // if(Temp->first_name.find(input) != string::npos){
            //     A[count] = Temp->first_name;
            //     count++;
            // }
            // if(Temp->last_name.find(input) != string::npos){
            //     A[count] = Temp->last_name;
            //     count++;
            // }
            // if(Temp->gender.find(input) != string::npos){
            //     A[count] = Temp->gender;
            //     count++;
            // }
            if(Temp->email.find(input) != string::npos){
                A[count] = Temp->email;
                count++;
            }
            Temp = Temp->Next;
        }
        return count;
    }
    
};

//-----------------------main----------------------//

int main(){

    EmployeeList EmpList;

    string empid;
    string first;
    string last;
    string email;
    string gender;
    double pay;

    ifstream inFile("employees.dat");
    ofstream outFile("outFile.foo");

    //  read in employees
    while(!inFile.eof()){

        inFile>>empid>>first>>last>>email>>gender>>pay;
        Employee e(empid, first, last, email, gender, pay);
        EmpList.push(e);
    
    }

    inFile.close();

    /*  test pop function
        EmpList.pop();
    */

    /*  test find function
        string t;
        t = "Neil";

        if(EmpList.find(t) == true){
            cout << "Found " << t << endl << endl;
        }
        else{
            cout << "Didn't find " << t << endl << endl;
        }
    */

    /*  test delete function
        EmpList.deleteItem(t);
    */

    //  test print function
        EmpList.print(outFile);

    //  test substringSearch function
        string input;
        int size = 5;
        string array[size];
        for(int i = 0; i < size; i++){
            array[i] = "";
        }

        input = "salon";

        outFile << "Found " << EmpList.substringSearch(input,array) 
            << " matches for '" << input << "':" << endl;

        for(int i = 0; i < size; i++){
            outFile << array[i] << endl;
        }

        outFile.close();

    return 0;
}