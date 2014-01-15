/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 15, 2014, 6:26 AM
 * Purpose: Program for Gaddis Chapter 3 Problem 4
 *      Average Rainfall: Calculate average rainfall over
 *      three months. 
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare Variables
    string m1, m2, m3;//Names of months
    float n_rain1, n_rain2, n_rain3;//Rainfall in inches
    float avg;
    
    //Get months and rainfall totals
    cout << "Please enter the name of the month and \n"
            << "the month's rainfall total in inches separated by a space."
            <<endl;
    cout << "The first month: ";
    cin >> m1 >> n_rain1;
    cout << "The second month: ";
    cin >> m2 >> n_rain2;
    cout << "The third month: ";
    cin >> m3 >> n_rain3;
    cout << endl;
    
    //Calculate average
    avg = (n_rain1 + n_rain2 + n_rain3) / 3;
    
    //Set Output formatting
    cout << setprecision(2) << fixed << showpoint;
    
    //Output results
    cout << m1 << "\t" << n_rain1 << "in" <<endl
            << m2 << "\t" << n_rain2 << "in" <<endl
            << m3 << "\t" << n_rain3 << "in" <<endl <<endl;
    cout << "The average rainfall for " << m1 <<", " << m2 <<", " 
            << "and " << m3 << " is " << avg << " inches." <<endl;
    
    //exit stage right
    return 0;
}

