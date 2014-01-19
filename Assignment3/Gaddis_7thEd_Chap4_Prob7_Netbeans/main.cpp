/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 19, 2014, 12:59 AM
 * Purpose: Program for Gaddis Chapter 4 Problem 7
 *      Time Calculator: Given a time in seconds, calculate the days,
 *      hours, mins, and seconds. 
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const int SEC_DAY=86400;//seconds in a day
const int SEC_HR=3600;//seconds in a hour
const int SEC_MIN=60;//seconds in a minute

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare Variables
    int inTime=0,//in seconds
        time=0,
        days=0,
        hours=0,
        min=0,
        sec=0;
    
    //Get time from user
    cout <<"Please enter a number of seconds\n"
            <<"and I will break the number down into days, hours, "
            <<"and minutes:" <<endl;
    cin >>inTime;
    time=inTime;
    
    //break down time into days, hours, and minutes
    if(time>=SEC_DAY){
        days=time/SEC_DAY;
        time%=SEC_DAY;
    }if(time>=SEC_HR){
        hours=time/SEC_HR;
        time%=SEC_HR;
    }if(time>=SEC_MIN){
        min=time/SEC_MIN;
        time%=SEC_MIN;
    }
    sec=time;//sets sec to time when <60
    
    //header
    cout <<"The time breakdown is as follows\n"
            <<inTime <<" seconds is equal to: ";
    //Outputs based on whether there are days, hours, or min
    if(days)
        cout <<days <<" days " <<hours <<" hrs " <<min <<" min "
                <<sec <<" sec" <<endl;
    else if(hours)
        cout <<hours <<" hrs " <<min <<" min "
                <<sec <<" sec" <<endl;
    else if(min)
        cout <<min <<" min " <<sec <<" sec" <<endl;
    else
        cout <<sec <<" sec" <<endl;
    
    //exit stage right
    return 0;
}

