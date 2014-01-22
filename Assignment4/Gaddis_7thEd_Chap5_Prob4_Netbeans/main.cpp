/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 22, 2014, 12:42 PM
 * Purpose: Program for Gaddis Chapter 5 Problem 4
 *      Calories Burned: outputs number of calories burned for every
 *      five minutes after 10 up to 30
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare variables
    const int MAX = 30,
              FACTOR = 39, //conversion is 3.9 * 10 for integer arithmetic
              CNV_DEC = 10;//conversion back to decimal
    int cals=0,
        min;
    cout <<"Calories Burned\n"
            <<"----------------" <<endl;
    //Keep running sum up to MAX iterations
    for(min = 0; min<=MAX; min++){
        cals=min*FACTOR;//accumulator 
        if(min>=10&&min%5==0)
            cout <<"The number of calories burned at " <<min 
                    //outputs an int cals converted to float
                    <<" minutes is: " <<static_cast<float>(cals)/CNV_DEC
                    <<endl;
    }
    cout <<endl;
    //exit stage right
    return 0;
}

