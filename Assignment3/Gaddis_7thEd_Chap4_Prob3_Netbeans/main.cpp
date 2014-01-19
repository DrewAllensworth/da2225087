/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 18, 2014, 11:44 PM
 * Purpose: Program for Gaddis Chapter 4 Problem 3
 *      Magic Dates: Determines whether the two-digit month 
 *      multiplied by the day is equal to the two-digit year 
 *      (aka a "magic" date) 
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare Variables
    unsigned int day, month, year;
    
    //Get dates from user
    cout <<"This program determines whether a date is a "
        <<"\"magic\" date" <<endl <<endl;
    cout <<"Please enter the date in the format (MM DD YY)\n"
            <<"The month, day, and year should only be two digits each\n"
            <<"and separated by spaces: ";
    cin >>month >>day >>year;
    
    //Determine and display whether date is "magic"
    if((month*day)==year)
        cout<<"The date is \"magic\"!"; 
    else    
        cout<<"The date is not \"magic\".";
    
    //exit stage right
    return 0;
}

