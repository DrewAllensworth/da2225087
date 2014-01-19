/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 18, 2014, 3:27 PM
 * Purpose: Gaddis Chapter 3 Problem 21
 *      Stock Transaction Program: Calculates profit/loss
 *      and broker commission
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const float CNV_DLR_CENTS=1.0e2;
const int CNV_PCT=100;
//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare variables
    float commPct=2.0e-2;
            
    int purPrc=3287,//in pennies
            sellPrc=3392,//in pennies
            pur,
            sell,
            tPur,
            tSell, 
            profit,
            pComm,//commission from stick purchase
            sComm;//commission from stock sale;  
    unsigned int shrsSld=1000, shrsPur=1000;
    
    //Perform calculations
    pur=shrsPur*purPrc;//in pennies
    sell=shrsSld*sellPrc;//in pennies
    pComm=(pur*commPct)+0.005;//in pennies
    sComm=(sell*commPct)+0.005;//in pennies
    tPur=pur+pComm;
    tSell=sell-sComm;
    profit=tSell-tPur;
    
    //Set formatting
    cout <<setprecision(2) <<fixed <<showpoint;
    //Header
    cout <<"Stock Transaction Summary\n"
            <<"-------------------------" <<endl;
    cout <<"Purchases" <<endl;
    cout <<shrsPur <<" shares of stock @ $" 
            <<static_cast<float>(purPrc/CNV_DLR_CENTS) 
            <<" = $" <<static_cast<float>(pur/CNV_DLR_CENTS) <<endl;
    cout <<"Broker Commission @ " <<commPct*CNV_PCT <<"%" 
            <<" = $" <<static_cast<float>(pComm/CNV_DLR_CENTS)
            <<endl;
    cout <<endl;
    cout <<"Sales" <<endl;
    cout <<shrsSld <<" shares of stock @ $" 
            <<static_cast<float>(sellPrc/CNV_DLR_CENTS) 
            <<" = $" <<static_cast<float>(sell/CNV_DLR_CENTS)<<endl;
    cout <<"Broker Commission @ " <<commPct*CNV_PCT <<"%" 
            <<" = $" <<static_cast<float>(sComm/CNV_DLR_CENTS)
            <<endl <<endl;
    cout <<"Your total profit in the sale was $" 
            <<static_cast<float>(profit/CNV_DLR_CENTS) <<endl;
           
    //exit stage right
    return 0;
}

