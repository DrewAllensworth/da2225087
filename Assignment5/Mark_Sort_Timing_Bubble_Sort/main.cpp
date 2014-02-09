/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 * Created on February 7, 2014, 8:13 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

//Global Constants

//Function Prototypes
void filAray(int [],int);
void prntAry(const int [],int,int);
void bSort(int [], int);
void xcopy(const int [],int [],int);

//Executions Begin Here!
int main(int argc, char** argv) {
    //Open a file to record the data
    ofstream output;
    output.open("BubbleTimeStudy.dat");
    //Declare variables and initialize the
    //random number generator
    const int SIZE=150000;
    int array[SIZE],brray[SIZE];
    srand(static_cast<unsigned int>(time(0)));
    //Fill the arrays
    filAray(array,SIZE);
    //Print the array
    //prntAry(array,SIZE,10);
    //Test out the min pos routine
    for(int size=10000;size<SIZE;size+=10000){
        xcopy(array,brray,size);
        int strTime=time(0);
        bSort(brray,size);
        int endTime=time(0);
        cout<<"Total Time Taken = "<<endTime-strTime
                <<" secs for array size = "<<size<<endl;
        output<<size<<" "<<endTime-strTime<<endl;
    }
    //Print the array
    //prntAry(brray,SIZE,10);
    //Exit Stage Right!!!
    output.close();
    return 0;
}

void xcopy(const int a[],int b[],int n){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
}

void bSort(int a[], int size){
    bool swp;
    int tmp;
    do{
        swp=false;
        for(int i=0;i<size-1;i++){
            if(a[i]>a[i+1]){
                tmp=a[i];
                a[i]=a[i+1];
                a[i+1]=tmp;
                swp=true;
            }
        }
    }while(swp);
}


void prntAry(const int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%10==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//2 Digit random numbers
void filAray(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}