/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 27, 2014, 9:27 AM
 * Purpose: Program for Gaddis Chapter 6 Problem 22
 *      Calculate and output a list of 100 prime numbers to a file
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <fstream>
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
    int n=1, count=1;
    //create file stream object
    ofstream outputFile("primes.txt");
    cout<<"Opening file"<<endl;
    //output number to file if the number is prime, up to 100th prime
    cout<<"Writing data to file primes.txt"<<endl;
    while(count<=100){
        if(isPrime(n)){
            outputFile<<"Prime number " <<count <<" is: " <<n <<"\r\n";
            count++;
        }
        n++;
    }
    //close file
    outputFile.close();
    cout<<"Closing file" <<endl;
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