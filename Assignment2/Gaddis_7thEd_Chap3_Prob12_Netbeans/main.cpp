/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 17, 2014, 10:19 PM
 * Purpose: Program for Gaddis Chapter 3 Problem 12
 *      Monthly Sales Tax: Calculate and display monthly sales
 *      report with tax breakdown
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Global Constants
const float ST_SLS_TAX=4.0e-2;//State sales tax percent
const float CO_SLS_TAX=2.0e-2;//County sales tax percent
//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare all variables
    float totCol,//total collected 
          sales,
          sTaxAmt,//state sales tax amt
          cTaxAmt,//county sales tax amt
          tTax;
    string month;
    int year;
    
    //Get month, year, and total collected sales
    cout <<"Please enter the month that the report will be generated for\n"
            <<"followed by the year (YYYY)" <<endl;
    cin >>month >>year;
    cout <<"Please enter the total amount collected ($'s)" <<endl;
    cin >>totCol;
        
    //calculate sales and taxes
    float tmpTax=ST_SLS_TAX+CO_SLS_TAX;
    sales=totCol/(1+tmpTax);
    tTax=totCol-sales;
    //calculate state and county tax amt
    float stPct=ST_SLS_TAX/tmpTax;
    float coPct=CO_SLS_TAX/tmpTax;
    sTaxAmt=tTax*stPct;
    cTaxAmt=tTax*coPct;
    
    //set formatting
    cout <<setprecision(2) <<fixed <<showpoint;
    //Output report heading
    cout <<"Report for: " <<month <<" " <<year <<endl;
    cout <<"------------------------------" <<endl;
    //Output Report
    cout <<"Total Collected:   $" <<totCol <<endl;
    cout <<"Sales:             $" <<sales <<endl;
    cout <<"County Sales Tax:  $" <<cTaxAmt <<endl;
    cout <<"State Sales Tax:   $" <<sTaxAmt <<endl;
    cout <<"Total Sales Tax:   $" <<tTax <<endl;
    
    //exit stage right
    return 0;
}

