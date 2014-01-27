/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 22, 2014, 11:47 AM
 * Purpose: Program for Gaddis Chapter 5 Problem 2
 *      Characters for the ASCII codes: displays 127 ASCII chars
 *      from 0 to 127 with linebreak every 16 chars
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //declare variables
    char c=0;//character for output
    //Header
    cout << "ASCII characters from 0 to 127\n"
            <<"-------------------------------" <<endl;
    //Loop through and output ASCII Characters 0 - 127
    for(int count = 1; count <= 127; count++){
       cout << c;
       c++;//move to next ASCII character
       if(count%16<1) //place 16 characters on each line
           cout << endl;
    }
    cout <<endl;
    //exit stage right
    return 0;
}

