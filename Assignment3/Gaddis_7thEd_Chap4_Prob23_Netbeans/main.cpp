/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 19, 2014, 8:00 AM
 * Purpose: Program for Gaddis Chapter 4 Problem 23
 *      Internet Service Provider: Calculates customer's monthly bill
 *      based on three packages  
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const int CNV_DLR_CENTS=100;
//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare variables
    int mChrg,//in pennies
        hAccess,//hours of access
        chgPerH,//in pennies
        hChrg,//in pennies
        hours,
        bill;//in pennies
    char choice;
    
    //get package choice char
    cout <<"Please enter the letter of your subscription package\n"
            <<"(A, B, or C): ";
    cin >>choice;
    //get hours
    cout <<"How many hours were used?" <<endl;
    cin >>hours;
    
    //heading
    cout <<"-------------------------" <<endl;
    //validate hours        
    if(hours>0&&hours<=744){
        //Set formatting
        cout<<setprecision(2)<<fixed<<showpoint;
        //calculate monthly charges based on input
        switch(choice){
            case('a'):
            case('A'):
                mChrg=995;
                hAccess=10;
                chgPerH=200;
                hChrg=(hours>hAccess)?(hours-hAccess)*chgPerH:0;
                bill=mChrg+hChrg;
                cout <<"Your total bill for this month is: $"
                        <<static_cast<float>(bill)/CNV_DLR_CENTS
                        <<endl;
                break;
            case('b'):
            case('B'):
                mChrg=1495;
                hAccess=20;
                chgPerH=100;
                hChrg=(hours>hAccess)?(hours-hAccess)*chgPerH:0;
                bill=mChrg+hChrg;
                cout <<"Your total bill for this month is: $"
                        <<static_cast<float>(bill)/CNV_DLR_CENTS
                        <<endl;
                break;
            case('c'):
            case('C'):
                mChrg=1995;
                bill=mChrg;
                cout <<"Your total bill for this month is: $"
                        <<static_cast<float>(bill)/CNV_DLR_CENTS
                        <<endl;
                break;
            default:
                cout <<"You can only select either Package A, "
                        <<"Package B, or Package C.\n"
                        <<"Please restart the program and "
                        <<"enter one of those letters";
        }
    }else
        cout <<"The number of hours used in a month cannot exceed"
                <<" 744!\n" <<"Please restart the program and try again";
    //exit stage right
    return 0;
}

