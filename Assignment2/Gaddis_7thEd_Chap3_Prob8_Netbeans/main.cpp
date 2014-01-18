/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 17, 2014, 4:44 PM
 * Purpose: Program for Gaddis Chapter 3 Problem 8
 *      How much insurance?: Calculate minimum needed insurance
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare Variables
    int rpCost, minIns;
    
    //Heading
    cout << "-Minimum Recommended Insurance-" <<endl <<endl;
    
    //get structure replacement value
    cout << "Please enter the replacement cost of the structure ($'s)"
            <<endl;
    cin >> rpCost;
    cout <<endl;
    minIns = rpCost * 0.8;//Calculates the minimum insurance
            
    //Output results
    cout << "For a structure with a replacement value of $" 
            <<rpCost <<endl;
    cout << "the minimum recommended insurance you should purchase is $" 
            <<minIns <<endl;
    
    //esit stage right
    return 0;
}

