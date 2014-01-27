/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 26, 2014, 8:40 PM
 * Purpose: Program for Gaddis Chapter 6 Problem 3
 *      The program gets the sales figures for four sales divisions
 *      and outputs the name and sales of the division 
 *      with the highest sales
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Global Constants

//Function Prototypes
float getSales(string name);
/*
 *Parameters: name->The name of the sales division
 * getSales() asks the user for for the quarterly sales in dollars.
 * It validates that the sales are greater than or equal to zero, 
 * looping until a valid value is entered.
 *Output: Quarterly Sales in dollars as float.
 */
void findHighest(float nWest, float nEast, float sWest, float sEast);
/*
 *Parameters: Four floating point sales numbers for the four sales divisions
 * findHighest() takes in the sales for the four sales divisions and 
 * determines which number is greatest. The corresponding sales division
 * name is printed out.
 *Output: The name of the sales division with the highest sales
 */

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare variables
    float nWest, sWest, nEast, sEast;
    //string name;
    //header
    cout<<"\t\t   Winning Division\n"
            <<"\t----------------------------------------\n"
            <<"Please enter the quarterly sales totals"
            <<" for each sales division" <<endl <<endl;
    //get quarterly sales for each division 
    //name="NorthWest";
    nWest=getSales("Northwest");
    //name="NorthEast";
    nEast=getSales("Northeast");
    //name="SouthWest";
    sWest=getSales("Southwest");
    //name="SouthEast";
    sEast=getSales("Southeast");
    
    //Calculate and output the sales division 
    //with the highest sales number
    findHighest(nWest, nEast, sWest, sEast);
    //exit stage right
    return 0;
}

float getSales(string name){
    //Declare variables
    float sales;
    //Get sales from user
    cout<<"-" <<name <<" Division-\n"
            <<"Please enter the Total Sales for the Quarter: $";
    cin>>sales;
    //validate that sales >= 0
    while(sales<0){
        cout<<"Sales must be greater than or equal to 0\n"
                <<"Please enter the Total Sales for the Quarter: $";
        cin>>sales;
    }
    return sales;
}

void findHighest(float nWest, float nEast, float sWest, float sEast){
    //header
    cout<<"--------------------------------------------" <<endl;
    //set formatting
    cout<<setprecision(2) <<fixed <<showpoint;
    //Find the highest value and output the corresponding sales division
    if((nWest>sWest)&&(nWest>nEast)&&(nWest>sEast)){ 
        cout<<"The highest grossing division is:\n"
                <<"The Northwest Division with $"<<nWest <<" in sales.";
    }else if((sWest>nWest)&&(sWest>nEast)&&(sWest>sEast)){
        cout<<"The highest grossing division is:\n"
                <<"The Southwest Division with $"<<sWest <<" in sales.";
    }else if((nEast>nWest)&&(nEast>sWest)&&(nEast>sEast)){
        cout<<"The highest grossing division is:\n"
                <<"The Northeast Division with $"<<nEast <<" in sales.";
    }else if((sEast>nWest)&&(sEast>sWest)&&(sEast>nEast)){
        cout<<"The highest grossing division is:\n"
                <<"The Southeast Division with $"<<sEast <<" in sales.";
    }else{
        cout<<"There is no greatest Sales Division\n"
            <<"Check the sales to determine if there is a tie"
            <<endl;
    }
    cout<<endl;
}