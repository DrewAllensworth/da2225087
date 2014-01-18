/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 17, 2014, 9:16 PM
 * Purpose: Program for Gaddis Chapter 3 Problem 11
 *      Converts Dollars to Yen and Euros
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const float YEN_PER_DOLLAR=104.33;//Number of Yen per Dollar in pennies
const float EUROS_PER_DOLLAR=0.74;//Number of Euros per Dollar in pennies

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare variables
    float dollars, nYen, nEuros;
    
    //Get amount of Dollars to convert
    cout <<"Please enter the value of Dollars which you wish to\n"
            <<"convert to Yen and Euros:" <<endl;
    cin >>dollars;
      
    //convert dollars to yen and euros
    nYen=dollars*YEN_PER_DOLLAR;
    nEuros=dollars*EUROS_PER_DOLLAR;
    
    //Set formatting
    cout <<setprecision(2) <<fixed <<showpoint;
    
    //Output Results
    cout <<"$" <<dollars <<" is equal to:" <<endl;
    cout <<nYen <<" Yen" <<endl;
    cout <<nEuros <<" Euros" <<endl;
    
    //exit stage right
    return 0;
}

