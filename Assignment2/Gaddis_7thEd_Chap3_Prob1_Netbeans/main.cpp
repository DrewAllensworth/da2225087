/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 15, 2014, 5:12 AM
 * Purpose: Program for Gaddis Chapter 3 Problem 1
 *              Miles per gallon: Calculate miles per gallon  
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare all variables
    short gal;//max gallons of gas car holds
    short mi;//max miles drivable on one tank of gas
    float mpg;
    
    //get max gallons and max miles
    cout << "Please enter the number of gallons of gas\n"
            << "that the car can hold: ";
    cin >> gal;  
    cout << "Please enter the number of miles\n"
            << "that the car can be driven on a full tank of gas: ";
    cin >> mi;
    cout << endl;
          
    //calculate miles per gallon
    mpg = static_cast<float>(mi) / gal;
    
    //output results
    cout << "If you drive " <<mi <<" miles,\n" 
            << "and you use " <<gal <<" gallons of gas,\n" 
            << "then you are getting " <<mpg <<" mpg (miles per gallon)!" <<endl;
    
    //exit stage right
    return 0;
}



