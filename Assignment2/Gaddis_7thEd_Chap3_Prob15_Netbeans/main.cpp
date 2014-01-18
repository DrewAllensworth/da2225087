/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 18, 2014, 12:59 AM
 * Purpose:
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
    int n1, n2, ans;
    unsigned seed;
    
    //get system time for rand() seed value
    seed=time(0);
    //seed the random number generator
    srand(seed);
    
    //get three digit random numbers
    n1=(rand())%1000;
    n2=(rand())%1000;
    
    //determine sum of random numbers
    ans=n1+n2;
    
    //header
    cout <<"Math Tutor\n"
            <<"----------" <<endl;
    cout <<"Find the sum of two numbers.\n"
            <<"When you've finished, press enter "
            <<"to display the correct answer." <<endl <<endl;
    cout <<"  " <<n1 <<endl;
    cout <<"+ " <<n2 <<endl;
    cout <<"-----";
    //pause until enter is pressed
    cin.get();
    cout <<setw(5) <<ans <<endl;
    
    //exit stage right        
    return 0;
}

