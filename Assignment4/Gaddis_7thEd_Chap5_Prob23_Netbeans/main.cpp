/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 26, 2014, 3:45 AM
 * Purpose: Program for Gaddis Chapter 5 Problem 23
 *      Pattern Displays: Outputs patterns using loops and "X"s
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare Variables
    int min=1, max=10;
    //the first loop to display a pattern
    //loop for rows
    for(int count=min;count<=max;count++){
        //loop for left 'X's
        for(int i=count;i>0;i--){
            cout<<'X';
        }
        //loop for whitespace
        for(int i=(max-count)*2;i>0;i--){
            cout<<' ';
        }
        //loop for right 'X's
        for(int i=count;i>0;i--){
            cout<<'X';
        }
        //move to next row
        cout<<endl;
    }
    //the second loop to display a pattern
    //loop for rows
    for(int count=max;count>=min;count--){
        //loop for left 'X's
        for(int i=count;i>0;i--){
            cout<<'X';
        }
        //loop for whitespace
        for(int i=(max-count)*2;i>0;i--){
            cout<<' ';
        }
        //loop for right 'X's
        for(int i=count;i>0;i--){
            cout<<'X';
        }
        //move to next row
        cout<<endl;
    }
    //exit stage right
    return 0;
}

