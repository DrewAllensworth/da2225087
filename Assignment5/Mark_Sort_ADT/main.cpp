/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 * Created on February 11, 2014, 4:13 AM
 * Purpose: Mark Sort using an ADT and dynamic allocation
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants
const int MX_SIZE=10000;//max allowable size for any array in this program

//ADTs not in user defined Libraries
struct DynAry{
    int *data;
    int utlSize;
};

//Function Prototypes
DynAry *filAray(int);
DynAry *mkeAray(int);
void prntAry(const DynAry *,int);
void swap(int &,int &);
void swap(int *,int,int);
void minPos(DynAry *,int,int);
void mrkSort(DynAry *);
void xcopy(const DynAry *,DynAry *);
void reclaim(DynAry*);

//Executions Begin Here!
int main(int argc, char** argv) {
    //Declare variables and initialize the
    //random number generator
    const int SIZE=200;
    srand(static_cast<unsigned int>(time(0)));
    //create the arrays
    DynAry *brray=mkeAray(SIZE);
    //Fill the arrays
    DynAry *array=filAray(SIZE);
    xcopy(array,brray);
    //Print the array
    prntAry(array,10);
    //Test out the min pos routine
    mrkSort(brray);
    //Print the array
    prntAry(brray,10);
    //Clean up
    reclaim(array);
    reclaim(brray);
    //Exit Stage Right!!!
    return 0;
}

void xcopy(const DynAry *a,DynAry *b){
    for(int i=0;i<b->utlSize;i++){
        b->data[i]=a->data[i];
    }
}

void mrkSort(DynAry *a){
    for(int i=0;i<(a->utlSize)-1;i++){
        minPos(a,a->utlSize,i);
    }
}

void minPos(DynAry *a,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if((a->data[pos])>(a->data[i]))swap(a->data[pos],a->data[i]);
        //if(a[pos]>a[i])swap(a,pos,i);
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void swap(int *a,int i,int j){
    int temp=*(a+i);
    *(a+i)=*(a+j);
    *(a+j)=temp;
}

void prntAry(const DynAry *a,int perLine){
    cout<<endl;
    for(int i=0;i<a->utlSize;i++){
        cout<<a->data[i]<<" ";
        if(i%10==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//create a dynamically allocated array using DynAry structure
DynAry *mkeAray(int n){
    //Verify/Validate the utilize size of the array
    if(n<=1||n>=MX_SIZE)n=2;
    //Declare and allocate the structure
    DynAry *a=new DynAry;
    //Set size member
    a->utlSize=n;
    //Declare and allocate memory for the array
    a->data=new int[a->utlSize];
    //Return the pointer to the structure
    return a;
}

//Fill the dynamically allocated structure with 2 Digit random numbers
DynAry *filAray(int n){
    //Verify/Validate the utilize size of the array
    if(n<=1||n>=MX_SIZE)n=2;
    //Declare and allocate the structure
    DynAry *a=new DynAry;
    //Set size member
    a->utlSize=n;
    //Declare and allocate memory for the array
    a->data=new int[a->utlSize];
    //fill the array with random numbers
    for(int i=0;i<a->utlSize;i++){
        a->data[i]=rand()%90+10;
    }
    //Return the pointer to the structure
    return a;
}
//Deletes the dynamic structure to free memory
void reclaim(DynAry*a){
    //Delete the structure member array first
    delete [] a->data;
    //Delete the structure last
    delete a;
}