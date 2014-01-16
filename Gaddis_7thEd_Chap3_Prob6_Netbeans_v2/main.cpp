/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 15, 2014, 7:09 AM
 * Purpose: Program for Gaddis Chapter 3 Problem 6
 *      How Many Widgets?: Calculate the weight of widgets 
 *      given the weight of a pallet. 
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare variables
    float lbWidg = 9.2,//weight of widget in lbs
            pWt,//weight of pallet in lbs
            nWidg;//number of widgets
    
    //get values
    cout << "Please enter the weight of the pallet in lbs: ";
    cin >> pWt;
    cout << endl;
    
    //perform calculations
    nWidg = pWt / lbWidg;
    
    //tests
//    cout << static_cast<float>(nWidg) << endl;
//    cout << static_cast<int>(nWidg) <<endl;
    
    //Output based on if n widgets is an whole number
    
//    if (nWidg == static_cast<int>(nWidg))
//    error for pWt 128.8
    //further tests
    if ((nWidg / static_cast<int>(nWidg)) <= 1.0)
    //if (static_cast<int>(nWidg + 0.999999) == static_cast<int>(nWidg))
        cout << "The number of widgets on the pallet is: "
                << nWidg;
    else 
        cout << "Are you sure the pallet weight is correct?\n"
                << "The number of widgets is not a whole number.\n"
                << "The number of widgets on the pallet is: "
                << nWidg << endl;
    
    //exit stage right
    return 0;
}

