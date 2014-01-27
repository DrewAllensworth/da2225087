/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 27, 2014, 6:07 AM
 * Purpose: Program for Gaddis Chapter 6 Problem 21
 *      isPrime function: Given a integer as input, the program determines
 *      if the number is prime. The program returns a message stating 
 *      whether the number is prime or not
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//Global Constants

//Function Prototypes
bool isPrime(unsigned int divend);
/*
 * Parameters: divend-> A positive integer > 0 
 *  isPrime() calculates whether a number is prime
 *  the function calls isRemain() to determine if there is a 
 *  remainder after division
 * Output: bool-> true if number is prime, else returns false
 */
bool isRemain(unsigned int divend, unsigned int divis);
/*
 * Parameters: divend-> A positive integer serving as the dividend
 * divis-> A positive integer serving as the divisor
 *  isRemain() determines whether there is a remainder after dividing
 *  the dividend by the divisor.
 * Output: bool-> true if there is a remainder after division, else false 
 */

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare variables
    int n=0;
    //Get integer to test if prime
    while (n<1){
    cout<<"Please enter a positive integer greater than 0\n"
            <<"and I will determine if the number is prime: ";
    cin>>n;
    }
    //header
    cout<<"----------------------------" <<endl;
    //determine and output if the number is prime
    if(isPrime(n)){
        cout<<n <<" is prime." <<endl;
    }else{
        cout<<n <<" is not prime." <<endl;
    }
    //exit stage right
    return 0;
}

bool isPrime(unsigned int divend){
    //declare variables
    bool prime;
    //set divisor
    int divis=2;
    //1 is not prime
    if (divend==1)
        return false;
    //determine if number >= 2 is prime
    while(divis <= sqrt(divend)){
        prime=isRemain(divend,divis);
        if (prime==false)
            return false;
        divis++;
    }
    return true;
}

bool isRemain(unsigned int divend, unsigned int divis){
    if (divend%divis==0){
        return false;
    }else{
        return true;
    }
}