/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 19, 2014, 12:15 AM
 * Purpose: Program for Gaddis Chapter 4 Problem 5
 *      Body Mass Index: Calculate BMI then determine and display 
 *      whether the BMI means one is underweight, optimal, or overweight
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare variables
    short wt,//in lbs 
          ht;//in inches
    float bmi;//body mass index number
    
    //header
    cout <<"BMI Calculator\n"
            <<"--------------" <<endl;
    //Get height and weight
    cout <<"Please enter your weight in lbs: ";
    cin >>wt;
    cout <<"Please enter your height in inches: ";
    cin >>ht;
    
    //Calculate BMI
    bmi=(wt*703)/(ht*ht);
    
    //Output BMI and classification
    //Initialize strings to hold output text
    string strBMI="You have a BMI of: ",
           strClsf="Your BMI places you in the classification of: ";
    if(bmi<18.5){
        cout <<strBMI <<bmi <<endl;
        cout <<strClsf <<"Underweight" <<endl;
    }else if(bmi>25){
        cout <<strBMI <<bmi <<endl;
        cout <<strClsf <<"Overweight" <<endl;
    }else{
        cout <<strBMI <<bmi <<endl;
        cout <<strClsf <<"Optimal" <<endl;
    }    
    //exit stage right
    return 0;
}

