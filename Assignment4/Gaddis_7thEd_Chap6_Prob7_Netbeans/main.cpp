/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 27, 2014, 3:45 AM
 * Purpose: Program for Gaddis Chapter 6 Problem 7
 *      Celsius Temperature Table: Outputs a table of the temperatures
 *      0 - 20 degrees Fahrenheit converted to Celsius 
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
float celsius(int temp);

//Execution Begins Here!

int main(int argc, char** argv) {
    //header
    cout<<"Degrees        Degrees\n" <<"Fahrenheit     Celsius\n"
            <<"-------------------------"
            <<endl;
    //set formatting
    cout<<setprecision(1) <<fixed <<showpoint;
    //loop to display the table of temperatures in Fahrenheit and Celsius
    for(int tempF=0;tempF<=20;tempF++){
        //output table
        cout<<setw(4)<<tempF <<"\t\t" <<celsius(tempF)<<endl;
    }
    return 0;
}
/*Parameters: temp->the temperature in degrees Fahrenheit 
 * celsius() takes a temperature in degrees Fahrenheit and converts it 
 * to degrees celsius
 *Output: float->temperature in degrees celsius
 */
float celsius(int temp){
    //return temperature converted to Celsius
    return (5.0/9.0)*(temp-32);
}