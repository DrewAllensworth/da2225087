/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 19, 2014, 3:24 AM
 * Purpose: Program for Gaddis Chapter 4 Problem 12
 *      Bank Charges: Determines monthly checking account fees
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //declare constants
    const int CNV_DLR_CENTS=100;
    //declare variables
    float bBal,//beginning ballance
          chkPct;
    int nChecks, 
        bal,
        chkFee=0,
        baseFee=10,//base checking account fee
        bUndFee=0;//fee for a balance under 400
    
    //get balance and number of checks
    cout <<"Please enter the beginning balance of the account: $";
    cin >>bBal;
    //convert balance to pennies
    bal=(bBal*CNV_DLR_CENTS)+0.5;
    cout <<"Please enter the number of checks you've written: ";
    cin >>nChecks;
    cout <<"---------------------------------------" <<endl;
    
    if(bal>0&&nChecks>0){//validates input
        //Set formatting
        cout <<setprecision(2) <<fixed <<showpoint;
        cout <<"You will be charged the following fees: "
                <<endl;
        cout <<"Base checking account fee: $" <<baseFee <<endl;
        if((bal/CNV_DLR_CENTS)<400){
            bUndFee=15;
            cout <<"Fee for account balance under $400: $"
                    <<bUndFee <<endl;
        }if(nChecks<20){
            chkPct=0.1;
            chkFee=((nChecks*chkPct)*CNV_DLR_CENTS)+0.5;
            cout <<"Check fee: $" <<static_cast<float>(chkFee)/CNV_DLR_CENTS
                    <<endl;
        }else if(nChecks>=20&&nChecks<40){
            chkPct=0.08;
            chkFee=((nChecks*chkPct)*CNV_DLR_CENTS)+0.5;
            cout <<"Check fee: $" <<static_cast<float>(chkFee)/CNV_DLR_CENTS
                    <<endl;
        }else if(nChecks>=40&&nChecks<60){
            chkPct=0.06;
            chkFee=((nChecks*chkPct)*CNV_DLR_CENTS)+0.5;
            cout <<"Check fee: $" <<static_cast<float>(chkFee)/CNV_DLR_CENTS
                    <<endl;
        }else{
            chkPct=0.04;
            chkFee=((nChecks*chkPct)*CNV_DLR_CENTS)+0.5;
            cout <<"Check fee: $" <<static_cast<float>(chkFee)/CNV_DLR_CENTS
                    <<endl;
        }
        cout <<"Total fees for this month: $"
                //bringing everything into pennies then converting
                <<static_cast<float>(((baseFee+bUndFee)*CNV_DLR_CENTS)+chkFee)/CNV_DLR_CENTS
                <<endl;
    }else if(bal<0)
        cout <<"-Urgent Message-\n"
                <<"The account is overdrawn!" <<endl;
    else
        cout <<"You entered a negative number for "
                <<"the number of written checks!\n"
                <<"Please re-run the program.\n"
                <<"If you have not written any checks, enter \"0\"."
                <<endl;
    return 0;
}
