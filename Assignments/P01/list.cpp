#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Employee{
    
    string emp_id; 
    string first_name;
    string last_name;
    string gender;
    string email;
    double hourly_pay;
    Employee *Next;

    Employee(){
        emp_id = "";
        first_name = "";
        last_name = "";
        gender = "";
        email = "";
        hourly_pay = 0.0;
    }

    Employee(string id,string first,string last,string sex,string mail, double pay){
        emp_id = id;
        first_name = first;
        last_name = last;
        gender = sex;
        email = mail;
        hourly_pay = pay * 1.0;
    }
};
class EmployeeList{

private:
    Employee* Head;

public:
    EmployeeList(){
        Head = NULL;
    }

    void push(Employee e){
        Employee* Temp = new Employee(e);

        if(Head == NULL){
            Head = Temp;
            Temp->Next = NULL;
        }else{
            Temp->Next = Head;
            Head = Temp;
        }
        
    }

    void pop(Employee e){
        Employee* Temp = new Employee(e);

        if(Head == NULL){
            Head = Temp;
        }else{
            Employee* Temp2 = Head;

            while(Temp2->Next != NULL){

                Temp2 = Temp2->Next;
            }

            Temp2->Next = Temp;
        }
    }

    void print(){
        Employee* Temp = Head;

        while(Temp != NULL){
            cout << Temp->emp_id << endl;
            cout << Temp->first_name << endl;
            cout << Temp->last_name << endl;
            cout << Temp->gender << endl;
            cout << Temp->email << endl;
            cout << setprecision(2) << fixed << Temp->hourly_pay << endl;
            if(Temp->Next){
                cout << endl;
            }
            Temp = Temp->Next;
        }
    }

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

            // if(Temp->Next){
            //     cout << endl;
            // }
            Temp = Temp->Next;
        }
        return found;
    }

    bool find(double data){
        Employee* Temp = Head;
        bool found = false;

        while(Temp != NULL){
            if(!found){
                if(Temp->hourly_pay == data){
                    found = true;
                }
            }

            // if(Temp->Next){
            //     cout << endl;
            // }
            Temp = Temp->Next;
        }
        return found;
    }

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
            // if(Temp->Next){
            //     cout << endl;
            // }
            Temp = Temp->Next;
        }
    }

    void deleteItem(double data){
        Employee* Temp = Head;

        while(Temp != NULL){
            if(Temp->hourly_pay == data){
                Temp->hourly_pay = 0;
            }
            // if(Temp->Next){
            //     cout << endl;
            // }
            Temp = Temp->Next;
        }
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


    while(!inFile.eof()){

        inFile>>empid>>first>>last>>email>>gender>>pay;
        Employee e(empid, first, last, email, gender, pay);
        EmpList.push(e);
    
    }

    //EmpList.print();

    string t;
    t = "Neil";

    if(EmpList.find(t) == true){
        cout << "Found" << endl << endl;
    }
    else{
        cout << "Didn't find" << endl << endl;
    }

    EmpList.deleteItem(t);

    EmpList.print();


    return 0;
}