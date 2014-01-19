/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 19, 2014, 5:46 AM
 * Purpose: Gaddis Chapter 4 Problem 15
 *      Personal Best: Arranges three scores with dates
 *      from high to low
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
    float htA,
          htB,
          htC;
    string name,
           dtA,
           dtB,
           dtC;
    
    //Get name, heights, and dates from user
    cout <<"Please enter your first and last name:"
            <<endl;
    getline(cin, name);
    cout <<"Please enter your top three jumps" <<endl;
    cout <<"First, enter the date of the jump in (MM/DD/YYYY) format: ";
    getline(cin, dtA);
    cout <<"Next, enter the height of the jump in meters "
            <<"(range between 2.0 and 5.0): ";
    cin >>htA;
    cin.ignore();
    cout <<"The date of the second jump (MM/DD/YYYY): ";
    getline(cin, dtB);
    cout <<"The height in meters (2.0-5.0): ";
    cin >>htB;
    cin.ignore();
    cout <<"The date of the third jump (MM/DD/YYYY): ";
    getline(cin, dtC);
    cout <<"The height in meters (2.0-5.0): ";
    cin >>htC;
    //header
    cout <<"-----------------------------------------" <<endl;        
    //Set flag for data validation
    bool inR=0;
    inR=htA<2||htA>5?0:
           htB<2||htB>5?0:
           htC<2||htC>5?0:1;    
    if(inR){
        //Header
        cout <<"This report details the three best jumps for "
                <<name <<endl;
        //Sorting
        cout<<"The sorted order is from high to low"<<endl;
        if(htA>htB&&htA>htC){
             cout<<"1: " <<dtA <<", " <<htA <<"m" <<endl;
             if(htB>htC){
                  cout<<"2: " <<dtB <<", " <<htB <<"m" <<endl;
                  cout<<"3: " <<dtC <<", " <<htC <<"m" <<endl;
             }else{
                  cout<<"2: " <<dtC <<", " <<htC <<"m" <<endl;
                  cout<<"3: " <<dtB <<", " <<htB <<"m" <<endl;
             }
        }else if(htB>htA&&htB>htC){
             cout<<"1: " <<dtB <<", " <<htB <<"m" <<endl;
             if(htA>htC){
                  cout<<"2: " <<dtA <<", " <<htA <<"m" <<endl;
                  cout<<"3: " <<dtC <<", " <<htC <<"m" <<endl;  
             }else{
                  cout<<"2: " <<dtC <<", " <<htC <<"m" <<endl;
                  cout<<"3: " <<dtA <<", " <<htA <<"m" <<endl;
             }
        }else{
             cout<<"1: " <<dtC <<", " <<htC <<"m" <<endl;
             if(htA>htB){
                  cout<<"2: " <<dtA <<", " <<htA <<"m" <<endl;
                  cout<<"3: " <<dtB <<", " <<htB <<"m" <<endl;
             }else{
                  cout<<"2: " <<dtB <<", " <<htB <<"m" <<endl;
                  cout<<"3: " <<dtA <<", " <<htA <<"m" <<endl;
             }
        }
    }else
        cout <<"I'm sorry, one or more of your heights was outside of the\n"
                <<"appropriate range (2.0-5.0). Please restart the program\n"
                <<"and enter heights between 2 meters and 5 meters."
                <<endl;
    //exit stage right    
    return 0;
}

