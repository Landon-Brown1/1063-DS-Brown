/*AUTHOR: Landon M. Brown
*ASSIGNMENT TITLE: TakeHomeTest.cpp
*ASSIGNMENT DESCRIPTION: the makeup test for test01
*DUE DATE: 9/24/2019
*DATE CREATED: 9/23/2019
*DATE LAST MODIFIED: 9/24/2019
 */

#include <iostream>
#include <cmath>

using namespace std;

//  (1)
//************************************************************
// description: sum value of all numbers from 3 arrays       *
// return: int                                               *
// precondition: values exist in the arrays                  *
// postcondition: returns the sum                            *
//                                                           *
//************************************************************

int sumArrays(int A[], int B[], int C[], int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum +=A[i];
        sum +=B[i];
        sum +=C[i];
    }
    return sum;
}

//  (2)
//************************************************************
// description: averages values of 2 2D arrays               *
// return: double                                            *
// precondition: values exist in the arrays                  *
// postcondition: returns average of the arrays              *
//                                                           *
//************************************************************

double avg2D(int size, int** A){
    int count = 0;
    double avg = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            avg += A[i][j];
            count++;
        }
    }
    avg /= count;
    return avg;
}

//  (3)
//***************************************************************
// description: prints out a number of "x"'s to the screen      *
// return: none                                                 *
// precondition: parameter is a valid integer                   *
// postcondition: prints correct amount of characters to screen *
//                                                              *
//***************************************************************
void exes(int param){
    for(int i = 0; i < param; i++){
        for(int j = 0; j < pow(2,i); j++){
            cout << "x";
        }
        cout << "\n";
    }
}

struct Stats{
    int min;
    int max;
    int sum;
    double avg;

    Stats(){
        min = INT8_MAX;
        max = INT8_MIN;
        sum = 0;
        avg = 0;
    }

//  (5)
//************************************************************
// description: loaded Stats constructor                     *
// return: none                                              *
// precondition: valid values are passed in                  *
// postcondition: values are assigned correctly              *
//                                                           *
//************************************************************
    Stats(int minn, int maxx, int summ, double avgg){
        min = minn;
        max = maxx;
        sum = summ;
        avg = avgg;
    }
};

//  (4)
//************************************************************
// description: calculates all the values in the Stats struct*
// return: Stats Object                                      *
// precondition: values exist in the array                   *
// postcondition: returns Stats of the array                 *
//                                                           *
//************************************************************
Stats aggregateVals(int A[], int size){
    Stats B;
    B. sum = 0;
    B. avg = 0;
    B. max = INT8_MIN;
    B. min = INT8_MAX;
    for(int i = 0; i < size; i++){
        if(A[i] > B.max){
            B.max = A[i];
        }
        if(A[i] < B.min){
            B.min = A[i];
        }
        B.sum += A[i];
    }
    B.avg = B.sum;
    B.avg /= size;

    return B;
}

//  (6)
//************************************************************
// description: calculates Std Dev of an array               *
// return: double                                            *
// precondition: values exist in the array                   *
// postcondition: returns Std Dev of the array               *
//                                                           *
//************************************************************
double calcStdDev(int A[], int size){
    double avg = 0;
    double sum = 0;

    for(int i = 0; i < size; i++){
        sum += A[i];
    }
    avg = sum/size;
    sum = 0;
    for(int i = 0; i < size; i++){
        sum = pow((A[i]-avg), 2);
    }
    avg = sqrt(sum/size);
    return avg;
}

//  (7)
//************************************************************
// description: creates and initializes an array of integers *
// return: integer pointer                                   *
// precondition: size is a valid integer                     *
// postcondition: returns the initialized array location     *
//                                                           *
//************************************************************
int* initIntArray(int size){
    int *Array = new int[size];
    for(int i = 0; i < size; i++){
        Array[i] = 0;
    }
    return Array;
}

int main(){

    return 0;
}