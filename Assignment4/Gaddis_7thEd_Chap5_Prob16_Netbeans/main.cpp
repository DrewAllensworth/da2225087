/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 25, 2014, 9:50 PM
 * Purpose: Program for Gaddis Chapter 5 Problem 16
 *      To calculate the balance of a savings account after n months
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare Variables
    const int CNV_PCT=100;
    int nMonths;
    float an_iRate,
            iRate,
            m_iRate, 
            sBal, 
            bal, 
            depos, 
            tDepos=0, 
            wthdrl, 
            tWthdrl=0, 
            tot_int=0, 
            m_int;
    //get the annual interest rate
    cout<<"Please enter the annual interest rate for the savings account: %";
    cin>>iRate;
    //calculate annual interest rate
    an_iRate=iRate/CNV_PCT;
    //calculate the monthly interest rate
    m_iRate=an_iRate/12.0;
    //get the starting balance for the account
    cout<<"Please enter the starting balance of the account: $";
    cin>>sBal;
    //assign balance for loop 
    bal=sBal;
    //get the number of months since the account's establishment
    cout<<"Please enter the number of months that have passed" 
            <<" since the account was established: ";
    cin>>nMonths;
    //loop to calculate the deposits, withdrawals, interest, and balance
    for(int count=1; count<=nMonths; count++){
        //get deposits
        cout<<"Please enter the total deposits for month " <<count
                    <<": $";
            cin>>depos;
        //validate deposits > 0 
        while(depos<0){
            cout<<"Total deposits must be greater than or equal to 0"<<endl;
            cout<<"Please enter the total deposits for month " <<count
                    <<": $";
            cin>>depos;
        }
        //calculate total deposits
        tDepos+=depos;
        //re-calculate total balance
        bal+=depos;
        //get withdrawals
        cout<<"Please enter the total withdrawals for month " <<count
                    <<": $";
            cin>>wthdrl;
        //validate withdrawals > 0 
        while(wthdrl<0){
            cout<<"Total withdrawals must be greater than or equal to 0"<<endl;
            cout<<"Please enter the total withdrawals for month " <<count
                    <<": $";
            cin>>wthdrl;
        }
        //calculate total withdrawals
        tWthdrl+=wthdrl;
        //re-calculate total balance
        bal-=wthdrl;
        //calculate the monthly interest gained
        m_int=bal*m_iRate;
        //calculate total interest
        tot_int+=m_int;
        //add interest to balance
        bal+=m_int;
        //exit loop if balance goes negative
        if(bal<0){
            cout<<endl<<"-----------!!!!!!!!!!!!!-------------\n"
                    <<"The account balance has gone negative.\n"
                    <<"The account is now closed and the program "
                    <<"has terminated at month: " <<count<<endl 
                    <<"-----------!!!!!!!!!!!!!-------------"<<endl;
            break;
        }       
    }
    //set formatting for output
    cout<<setprecision(2) <<fixed <<showpoint;
    //header
    cout<<endl;
    cout<<"\tAccount Summary\n"
            <<"-----------------------------------" <<endl;
    //Output results
    cout<<"Total Deposits: $" <<tDepos <<endl;
    cout<<"Total Withdrawals: $" <<tWthdrl <<endl;
    cout<<"The total interest earned on the account is: $" <<tot_int
            <<endl;
    cout<<"The ending balance is: $" <<bal <<endl;
    //exit stage right
    return 0;
}

