/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 * Created on February 11, 2014, 8:13 AM
 * Purpose: Mark Sort Database using an ADT and dynamic allocation
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
void filAray(DynAry *,DynAry *,int);
DynAry *mkeAray(int);
void prntAry(const DynAry *,const DynAry *,int);
void prntAry(const DynAry *,int);
void swap(int &,int &);
void minPos(const DynAry *,const DynAry *,int,int);
void mrkSort(const DynAry *,const DynAry *);
void reclaim(DynAry*);

//Executions Begin Here!
int main(int argc, char** argv) {
    //Declare variables and initialize the
    //random number generator
    const int SIZE=200;
    DynAry *array=mkeAray(SIZE);
    DynAry *index=mkeAray(SIZE);
    srand(static_cast<unsigned int>(time(0)));
    //Fill the arrays
    filAray(array,index,SIZE);
    //Print the arrays
    prntAry(array,index,10);
    //Test out the min pos routine
    mrkSort(array,index);
    //Print the array
    prntAry(array,index,10);
    prntAry(index,10);
    prntAry(array,10);
    //Clean up
    reclaim(array);
    reclaim(index);
    //Exit Stage Right!!!
    return 0;
}

void mrkSort(const DynAry *a,const DynAry *indx){
    for(int i=0;i<(indx->utlSize)-1;i++){
        minPos(a,indx,indx->utlSize,i);
    }
}

void minPos(const DynAry *a,const DynAry *indx,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if((a->data[indx->data[pos]])>(a->data[indx->data[i]]))
                swap(indx->data[pos],indx->data[i]);
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void prntAry(const DynAry *a,int perLine){
    cout<<endl;
    for(int i=0;i<a->utlSize;i++){
        cout<<a->data[i]<<" ";
        if(i%10==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void prntAry(const DynAry *a,const DynAry *indx,int perLine){
    cout<<endl;
    for(int i=0;i<a->utlSize;i++){
        cout<<a->data[indx->data[i]]<<" ";
        if(i%10==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Fill one array with 2 Digit random numbers and the index with consecutive
void filAray(DynAry *a,DynAry *indx,int n){
    for(int i=0;i<n;i++){
        a->data[i]=rand()%90+10;
        indx->data[i]=i;
    }
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

//Deletes the dynamic structure to free memory
void reclaim(DynAry*a){
    //Delete the structure member array first
    delete [] a->data;
    //Delete the structure last
    delete a;
}