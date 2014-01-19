/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 19, 2014, 8:00 AM
 * Purpose: Program for Gaddis Chapter 4 Problem 25
 *      Internet Service Provider: Calculates customer's monthly bill
 *      based on three packages  
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
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
        bill, billA, billB, billC;//in pennies
    char choice;
    string month;
    
    //get package choice char
    cout <<"Please enter the letter of your subscription package\n"
            <<"(A, B, or C): ";
    cin >>choice;
    //get month
    cin.ignore();//for getline
    cout <<"Please enter the name of the month with the first"
            <<" letter capitalized:" <<endl;
    getline (cin, month);
    //get hours
    cout <<"How many hours were used?" <<endl;
    cin >>hours;
    
    //heading
    cout <<"---------------------------" <<endl;
    //Set max hours in each month for hour validation
    int maxHrs;
    maxHrs=month=="January"?744:
           month=="February"?672:
           month=="March"?744:
           month=="April"?720:
           month=="May"?744:
           month=="June"?720:
           month=="July"?744:
           month=="August"?744:
           month=="September"?720:
           month=="October"?744:
           month=="November"?720:
           month=="December"?744:744;    
    //validate hours               
    if(hours>0&&hours<=maxHrs){
        //Set formatting
        cout<<setprecision(2)<<fixed<<showpoint;
        //calculate monthly charges based on input
        switch(choice){
            case('a'):
            case('A'):
                //calculate package A rate
                mChrg=995;
                hAccess=10;
                chgPerH=200;
                hChrg=(hours>hAccess)?(hours-hAccess)*chgPerH:0;
                billA=mChrg+hChrg;
                cout <<"Your total bill for this month is: $"
                        <<static_cast<float>(billA)/CNV_DLR_CENTS
                        <<endl;
                //calculate package B rate
                mChrg=1495;
                hAccess=20;
                chgPerH=100;
                hChrg=(hours>hAccess)?(hours-hAccess)*chgPerH:0;
                billB=mChrg+hChrg;
                //display savings if B is less than A
                if(billB<billA){
                    cout <<"------------------------------\n"
                         <<"You could save $" 
                         <<static_cast<float>(billA-billB)/CNV_DLR_CENTS
                         <<" if you switched to Package B\n"
                         <<"Your total bill for this month would be: $"
                         <<static_cast<float>(billB)/CNV_DLR_CENTS
                         <<endl;
                }
                //Calculate package C rate
                mChrg=1995;
                billC=mChrg;
                //display savings if C is less than A
                if(billC<billA){
                    cout <<"You could save $" 
                         <<static_cast<float>(billA-billC)/CNV_DLR_CENTS
                         <<" if you switched to Package C\n"
                         <<"Your total bill for this month would be: $"
                         <<static_cast<float>(billC)/CNV_DLR_CENTS
                         <<endl;
                }    
                break;
            case('b'):
            case('B'):
                //calculate package B rate
                mChrg=1495;
                hAccess=20;
                chgPerH=100;
                hChrg=(hours>hAccess)?(hours-hAccess)*chgPerH:0;
                billB=mChrg+hChrg;
                cout <<"Your total bill for this month is: $"
                        <<static_cast<float>(billB)/CNV_DLR_CENTS
                        <<endl;
                //Calculate package C rate
                mChrg=1995;
                billC=mChrg;
                //Display savings if C is less than B
                if(billC<billB){
                    cout  <<"-----------------------------\n"  
                            <<"You could save $" 
                            <<static_cast<float>(billB-billC)/CNV_DLR_CENTS
                            <<" if you switched to Package C\n"
                            <<"Your total bill for this month would be: $"
                            <<static_cast<float>(billC)/CNV_DLR_CENTS
                            <<endl;
                }
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
        cout <<"The number of hours used in a month (" <<month 
                <<")\n" <<"cannot exceed "
                <<maxHrs <<" or be less than 0!\n" 
                <<"Please restart the program and try again";
    //exit stage right
    return 0;
}

