/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 19, 2014, 2:59 AM
 * Purpose: Program for Gaddis Chapter 4 Problem 9
 *      Math Tutor: Displays random addition problems and
 *      determines if user's answer is correct
 */

//System Libraries
#include <iostream>
#include <cstdlib>//For rand() and srand()
#include <ctime>//For the time function
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare Variables
    int n1, n2, sum, ans;
    unsigned seed;
    
    //get system time for rand() seed value
    seed=time(0);
    //seed the random number generator
    srand(seed);
    
    //get three digit random numbers
    n1=(rand())%1000;
    n2=(rand())%1000;
    
    //determine sum of random numbers
    sum=n1+n2;
    
    //header
    cout <<"Math Tutor\n"
            <<"----------" <<endl;
    cout <<"Find the sum of two numbers.\n"
            <<"When you've finished, enter your answer. "
            <<endl <<endl;
    cout <<setw(5) <<n1 <<endl;
    cout <<"+ " <<n2 <<endl;
    cout <<"-----" <<endl;
    
    //get user's answer
    cin >>ans;
    
    //determine if user's answer is correct and print results
    if(ans==sum)
        cout <<"Congatulations! Your answer is correct."
                <<endl;
    else{
        cout <<"I'm sorry, your answer is incorrect." <<endl;
        cout <<"You answered " <<ans <<", but the correct answer is "
                <<sum <<endl;
    }
    
    //exit stage right        
    return 0;
}

