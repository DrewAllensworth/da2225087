/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 15, 2014, 5:40 AM
 * Purpose: Program for Gaddis Chapter 3 Problem 2
 *      Stadium Seating: To calculate the charges 
 *      for stadium seating ticket sales 
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare variables
    //Prices in Dollars. Three stadium seat classes
    float cls_A = 15.0,
            cls_B = 12.0,
            cls_C = 9.0,
            total;//Total income in Dollars
    unsigned short n_A, n_B, n_C;//Number of tickets sold
    
    //Get number of tickets sold
    cout << "Please enter the number of Class 'A' tickets sold: ";
    cin >> n_A;
    cout << "Please enter the number of Class 'B' tickets sold: ";
    cin >> n_B;
    cout << "Please enter the number of Class 'C' tickets sold: ";
    cin >> n_C;
    cout <<endl;
    
    //Calculate total sales
    total = (n_A * cls_A) + (n_B * cls_B) + (n_C * cls_C);
            
    //Set output formatting
    cout <<setprecision(2) <<fixed <<showpoint;
    
    //Output results
    cout << "\tTicket Sales:" <<endl;
    cout << n_A << " Class 'A' tickets at\t" << "$" 
            << cls_A << " ea." <<endl;
    cout << n_B << " Class 'B' tickets at\t" << "$" 
            << cls_B << " ea." <<endl;
    cout << n_C << " Class 'C' tickets at\t" << "$" 
            << cls_C << " ea." <<endl <<endl;
    cout << "The total income is $" << total <<endl;
    
    //exit stage right
    return 0;
}

