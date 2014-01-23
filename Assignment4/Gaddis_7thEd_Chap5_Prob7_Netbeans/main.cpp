/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 22, 2014, 1:59 PM
 * Purpose: Gaddis Chapter 5 Problem 7
 *      Pennies for Pay: program calculates salary and total pay
 *      when the salary starts at one penny then doubles each day 
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //declare variables 
    const int CNV_DLR_CENTS=100;
    float salary,
                  pay=0;
    int days;//number of days worked
//get days and validate >= 1 
    cout <<"Please enter the number of days you've worked: ";
    cin >>days;
    if(days<1){    
        do{
            cout <<"The days you've worked must be greater than "
                    <<"or equal to one\n"
                    <<"Please enter the number of days you've worked: ";
            cin >>days;
        }while(days<1)
    ;}
    //set formatting
    cout <<setprecision(2) <<fixed <<showpoint;
    //calculate salary and pay for each day
    salary=1;
    for(int count=1;count<=days;count++){
        cout <<"Salary for day " <<count <<": $"
                    <<static_cast<double>(salary)/CNV_DLR_CENTS
                    <<endl;
        pay+=salary;
        salary*=2;
    }
    //output total pay
    cout <<"-------------------------------------" <<endl;
    cout <<"Total Pay for " <<days <<" days: $" 
            <<static_cast<float>(pay)/CNV_DLR_CENTS;
    //exit stage right
    return 0;
}

