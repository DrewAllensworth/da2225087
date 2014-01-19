/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 18, 2014, 10:57 PM
 * Purpose: Gaddis Chapter 4 Problem 2
 *      Roman Numeral Converter: Get a number between 1 and 10 
 *      and display its Roman numeral equivalent
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare Variables
    int num;
    
    //Get number to convert from user
    cout <<"Please enter a number between 1 and 10\n"
            <<"and I will display its Roman Numeral equivalent:"
            <<endl;
    cin >>num;
    
    //initialize and save output string to variable
    string str="The Roman Numeral equivalent is: ";
    //evaluate user's num and output Roman numeral
    switch(num){
        case(1):
            cout <<str <<"I" <<endl;
            break;
        case(2):
            cout <<str <<"II" <<endl;
            break;
        case(3):
            cout <<str <<"III" <<endl;
            break;
        case(4):
            cout <<str <<"IV" <<endl;
            break;
        case(5):
            cout <<str <<"V" <<endl;
            break;
        case(6):
            cout <<str <<"VI" <<endl;
            break;
        case(7):
            cout <<str <<"VII" <<endl;
            break;
        case(8):
            cout <<str <<"VIII" <<endl;
            break;
        case(9):
            cout <<str <<"IX" <<endl;
            break;
        case(10):
            cout <<str <<"X" <<endl;
            break;
        //Output if num is not between 1 and 10
        default:
            cout <<"You must enter a value between 1 and 10!\n"
                    <<"Please restart the program and try again"
                    <<endl;
    } 
    
    //exit stage right
    return 0;
}

