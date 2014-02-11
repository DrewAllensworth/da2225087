/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on February 10, 2014, 6:30 PM
 * Purpose: Showing an abstract data type using dynamic allocation
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

//Global Constants
const int SIZE=10000;

//ADT's not in user defined Libraries
struct DynAry{
    int *data;
    int utlSize;
};

//Functional Prototypes
DynAry *fillAry(int);
void prntAry(const DynAry *,int);
void reclaim(DynAry*);

//Execution begins here
int main(int argc, char** argv) {
    //Declare Variables
    srand(static_cast<unsigned int>(time(0)));
    //fill the structure
    DynAry *dAry=fillAry(100);
    //Print the structure
    prntAry(dAry,10);
    //reclaim the memory allocation
    reclaim(dAry);
    //exit stage right
    return 0;
}

void reclaim(DynAry*a){
    //Reclaim first the array
    delete [] a->data;
    //Reclaim last the structure
    delete a;
}

DynAry fillAry(int n){
    //Verify/Validate the utilize size of the array
    if(n<=1||n>SIZE)n=2;
    //Declare and allocate the structure
    DynAry *a=new DynAry;
    a->utlSize=n;
    //Declare and allocate memory for the array
    a->data=new int[a->utlSize];
    //Fill the array with three digit numbers
    for(int i=0;i<a->utlSize;i++){
        //(*a).data[i]=rand()%900+100;//different ways to write the same thing
//        *(a->data+i)=rand()%900+100;
//        *((*a).data+i)=rand()%900+100;
        a->data[i]=rand()%900+100;
    }
    //Return the pointer to the structure
    return a;
}


void prntAry(const DynAry *a,int perLine){
    //Print the array
    cout<<endl;
    for(int i=0;i<a->utlSize;i++){
        cout<<setw(4)<<a->data[i];
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}