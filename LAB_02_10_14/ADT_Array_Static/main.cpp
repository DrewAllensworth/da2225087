/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on February 10, 2014, 6:30 PM
 * Purpose: showing the use of an abstract data type
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

//Global Constants
const int SIZE=10000;

//ADT's not in user defined Libraries
struct StatAry{
    int data[SIZE];
    int utlSize;
};

//Functional Prototypes
void fillAry(StatAry &,int);
void prntAry(const StatAry &,int);

//Execution begins here
int main(int argc, char** argv) {
    //Declare Variables
    srand(static_cast<unsigned int>(time(0)));
    StatAry sAry;
    //fill the structure
    fillAry(sAry,100);
    //Print the structure
    prntAry(sAry,10);
    //exit stage right
    return 0;
}

void fillAry(StatAry &a,int n){
    //Verify/Validate the utilize size of the array
    if(n<=1||n>SIZE)n=2;
    a.utlSize=n;
    //Fill the array with three digit numbers
    for(int i=0;i<a.utlSize;i++){
        //*(a.data+i)=rand()%900+100;
        a.data[i]=rand()%900+100;
    }
}

void prntAry(const StatAry &a,int perLine){
    //Print the array
    cout<<endl;
    for(int i=0;i<a.utlSize;i++){
        cout<<setw(4)<<a.data[i];
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}