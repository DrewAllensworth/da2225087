/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 19, 2014, 10:27 AM
 * Purpose: A menu to display and run all of the Assignment 3 programs
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants
const int SEC_DAY=86400;//seconds in a day
const int SEC_HR=3600;//seconds in a hour
const int SEC_MIN=60;//seconds in a minute
const int CNV_DLR_CENTS=100;
//Function Prototypes
void prob2();
void prob3();
void prob5();
void prob7();
void prob9();
void prob12();
void prob15();
void prob23();
void prob24();
void prob25();
//Execution Begins Here!

int main(int argc, char** argv) {
    //declare variables
    char choice;
    //display menu
    //Header
    cout <<"    ~ Assignment 3 Main Menu ~\n" 
          <<"-----------------------------------" <<endl;
    cout <<"All programs are for Gaddis Chapter 4\n" <<endl;
    cout <<"Option #" <<endl;
    //menu options
    cout <<"   1.    Problem  2: Roman Numeral Converter\n"
            <<"   2.    Problem  3: Magic Dates\n"
            <<"   3.    Problem  5: Body Mass Index\n"
            <<"   4.    Problem  7: Time Calculator\n"
            <<"   5.    Problem  9: Math Tutor\n"
            <<"   6.    Problem 12: Bank Charges\n"
            <<"   7.    Problem 15: Personal Best\n"
            <<"   8.    Problem 23: Internet Service Provider\n"
            <<"   9.    Problem 24: Internet Service Provider - part 2\n"
            <<"   10.   Problem 25: Internet Service Provider - part 3\n"
            <<"   11.   Quit the Program\n\n"
            <<"Enter your choice" <<endl;
    //get option choice
    cin >>choice;
    cout <<endl;
        
    //Call programs based on menu choice
    switch(choice){
        case(1):
            prob2();
            break;
        case(2):
            prob3();
            break;
        case(3):
            prob5();
            break;
        case(4):
            prob7();
            break;
        case(5):
            prob9();
            break;
        case(6):
            prob12();
            break;
        case(7):
            prob15();
            break;
        case(8):
            prob23();
            break;
        case(9):
            prob24();
            break;
        case(10):
            prob25();
            break;
        case(11):
            cout <<"Program ending.";
            break;
        default:
            cout <<"The valid choices are 1 through 11.\n"
                    <<"Run the program again and select one of those."
                    <<endl;
    }
    return 0;
}
/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 18, 2014, 10:57 PM
 * Purpose: Gaddis Chapter 4 Problem 2
 *      Roman Numeral Converter: Get a number between 1 and 10 
 *      and display its Roman numeral equivalent
 */
void prob2() {
    //Declare Variables
    int num;
    
    //Get number to convert from user
    cout <<"Please enter a number between 1 and 10\n"
            <<"and I will display its Roman Numeral equivalent:"
            <<endl;
    cin >>num;
    
    //initialize and save output string to variable
    string str="The Roman Numeral equivalent is: ";
    //evaluate user's num and output Roman numeral
    switch(num){
        case(1):
            cout <<str <<"I" <<endl;
            break;
        case(2):
            cout <<str <<"II" <<endl;
            break;
        case(3):
            cout <<str <<"III" <<endl;
            break;
        case(4):
            cout <<str <<"IV" <<endl;
            break;
        case(5):
            cout <<str <<"V" <<endl;
            break;
        case(6):
            cout <<str <<"VI" <<endl;
            break;
        case(7):
            cout <<str <<"VII" <<endl;
            break;
        case(8):
            cout <<str <<"VIII" <<endl;
            break;
        case(9):
            cout <<str <<"IX" <<endl;
            break;
        case(10):
            cout <<str <<"X" <<endl;
            break;
        //Output if num is not between 1 and 10
        default:
            cout <<"You must enter a value between 1 and 10!\n"
                    <<"Please restart the program and try again"
                    <<endl;
    } 
    
    //exit stage right
 
}
/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 18, 2014, 11:44 PM
 * Purpose: Program for Gaddis Chapter 4 Problem 3
 *      Magic Dates: Determines whether the two-digit month 
 *      multiplied by the day is equal to the two-digit year 
 *      (aka a "magic" date) 
 */
void prob3() {
    //Declare Variables
    unsigned int day, month, year;
    
    //Get dates from user
    cout <<"This program determines whether a date is a "
        <<"\"magic\" date" <<endl <<endl;
    cout <<"Please enter the date in the format (MM DD YY)\n"
            <<"The month, day, and year should only be two digits each\n"
            <<"and separated by spaces: ";
    cin >>month >>day >>year;
    
    //Determine and display whether date is "magic"
    if((month*day)==year)
        cout<<"The date is \"magic\"!"; 
    else    
        cout<<"The date is not \"magic\".";
    
    //exit stage right
 
}
/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 19, 2014, 12:15 AM
 * Purpose: Program for Gaddis Chapter 4 Problem 5
 *      Body Mass Index: Calculate BMI then determine and display 
 *      whether the BMI means one is underweight, optimal, or overweight
 */
void prob5() {
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
 
}
/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 19, 2014, 12:59 AM
 * Purpose: Program for Gaddis Chapter 4 Problem 7
 *      Time Calculator: Given a time in seconds, calculate the days,
 *      hours, mins, and seconds. 
 */
void prob7() {
    //Declare Variables
    int inTime=0,//in seconds
        time=0,
        days=0,
        hours=0,
        min=0,
        sec=0;
    
    //Get time from user
    cout <<"Please enter a number of seconds\n"
            <<"and I will break the number down into days, hours, "
            <<"and minutes:" <<endl;
    cin >>inTime;
    time=inTime;
    
    //break down time into days, hours, and minutes
    if(time>=SEC_DAY){
        days=time/SEC_DAY;
        time%=SEC_DAY;
    }if(time>=SEC_HR){
        hours=time/SEC_HR;
        time%=SEC_HR;
    }if(time>=SEC_MIN){
        min=time/SEC_MIN;
        time%=SEC_MIN;
    }
    sec=time;//sets sec to time when <60
    
    //header
    cout <<"The time breakdown is as follows\n"
            <<inTime <<" seconds is equal to: ";
    //Outputs based on whether there are days, hours, or min
    if(days)
        cout <<days <<" days " <<hours <<" hrs " <<min <<" min "
                <<sec <<" sec" <<endl;
    else if(hours)
        cout <<hours <<" hrs " <<min <<" min "
                <<sec <<" sec" <<endl;
    else if(min)
        cout <<min <<" min " <<sec <<" sec" <<endl;
    else
        cout <<sec <<" sec" <<endl;
    
    //exit stage right
 
}
/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 19, 2014, 2:59 AM
 * Purpose: Program for Gaddis Chapter 4 Problem 9
 *      Math Tutor: Displays random addition problems and
 *      determines if user's answer is correct
 */
void prob9() {
    //Declare Variables
    int n1, n2, sum, ans;
    unsigned seed;
    
    //get system time for rand() seed value
    seed=time(0);
    //seed the random number generator
    srand(seed);
    
    //get three digit random numbers
    n1=(rand())%1000;
    n2=(rand())%1000;
    
    //determine sum of random numbers
    sum=n1+n2;
    
    //header
    cout <<"Math Tutor\n"
            <<"----------" <<endl;
    cout <<"Find the sum of two numbers.\n"
            <<"When you've finished, enter your answer. "
            <<endl <<endl;
    cout <<setw(5) <<n1 <<endl;
    cout <<"+ " <<n2 <<endl;
    cout <<"-----" <<endl;
    
    //get user's answer
    cin >>ans;
    
    //determine if user's answer is correct and print results
    if(ans==sum)
        cout <<"Congatulations! Your answer is correct."
                <<endl;
    else{
        cout <<"I'm sorry, your answer is incorrect." <<endl;
        cout <<"You answered " <<ans <<", but the correct answer is "
                <<sum <<endl;
    }
    
    //exit stage right        
  
}
/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 19, 2014, 3:24 AM
 * Purpose: Program for Gaddis Chapter 4 Problem 12
 *      Bank Charges: Determines monthly checking account fees
 */
void prob12() {
    //declare constants
    const int CNV_DLR_CENTS=100;
    //declare variables
    float bBal,//beginning ballance
          chkPct;
    int nChecks, 
        bal,
        chkFee=0,
        baseFee=10,//base checking account fee
        bUndFee=0;//fee for a balance under 400
    
    //get balance and number of checks
    cout <<"Please enter the beginning balance of the account: $";
    cin >>bBal;
    //convert balance to pennies
    bal=(bBal*CNV_DLR_CENTS)+0.5;
    cout <<"Please enter the number of checks you've written: ";
    cin >>nChecks;
    cout <<"---------------------------------------" <<endl;
    
    if(bal>0&&nChecks>0){//validates input
        //Set formatting
        cout <<setprecision(2) <<fixed <<showpoint;
        cout <<"You will be charged the following fees: "
                <<endl;
        cout <<"Base checking account fee: $" <<baseFee <<endl;
        if((bal/CNV_DLR_CENTS)<400){
            bUndFee=15;
            cout <<"Fee for account balance under $400: $"
                    <<bUndFee <<endl;
        }if(nChecks<20){
            chkPct=0.1;
            chkFee=((nChecks*chkPct)*CNV_DLR_CENTS)+0.5;
            cout <<"Check fee: $" <<static_cast<float>(chkFee)/CNV_DLR_CENTS
                    <<endl;
        }else if(nChecks>=20&&nChecks<40){
            chkPct=0.08;
            chkFee=((nChecks*chkPct)*CNV_DLR_CENTS)+0.5;
            cout <<"Check fee: $" <<static_cast<float>(chkFee)/CNV_DLR_CENTS
                    <<endl;
        }else if(nChecks>=40&&nChecks<60){
            chkPct=0.06;
            chkFee=((nChecks*chkPct)*CNV_DLR_CENTS)+0.5;
            cout <<"Check fee: $" <<static_cast<float>(chkFee)/CNV_DLR_CENTS
                    <<endl;
        }else{
            chkPct=0.04;
            chkFee=((nChecks*chkPct)*CNV_DLR_CENTS)+0.5;
            cout <<"Check fee: $" <<static_cast<float>(chkFee)/CNV_DLR_CENTS
                    <<endl;
        }
        cout <<"Total fees for this month: $"
                //bringing everything into pennies then converting
                <<static_cast<float>(((baseFee+bUndFee)*CNV_DLR_CENTS)+chkFee)/CNV_DLR_CENTS
                <<endl;
    }else if(bal<0)
        cout <<"-Urgent Message-\n"
                <<"The account is overdrawn!" <<endl;
    else
        cout <<"You entered a negative number for "
                <<"the number of written checks!\n"
                <<"Please re-run the program.\n"
                <<"If you have not written any checks, enter \"0\"."
                <<endl;
  
}
/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 19, 2014, 5:46 AM
 * Purpose: Gaddis Chapter 4 Problem 15
 *      Personal Best: Arranges three scores with dates
 *      from high to low
 */
void prob15() {
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
  
}
/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 19, 2014, 8:00 AM
 * Purpose: Program for Gaddis Chapter 4 Problem 23
 *      Internet Service Provider: Calculates customer's monthly bill
 *      based on three packages  
 */
void prob23() {
    //Declare variables
    int mChrg,//in pennies
        hAccess,//hours of access
        chgPerH,//in pennies
        hChrg,//in pennies
        hours,
        bill;//in pennies
    char choice;
    
    //get package choice char
    cout <<"Please enter the letter of your subscription package\n"
            <<"(A, B, or C): ";
    cin >>choice;
    //get hours
    cout <<"How many hours were used?" <<endl;
    cin >>hours;
    
    //heading
    cout <<"-------------------------" <<endl;
    //validate hours        
    if(hours>0&&hours<=744){
        //Set formatting
        cout<<setprecision(2)<<fixed<<showpoint;
        //calculate monthly charges based on input
        switch(choice){
            case('a'):
            case('A'):
                mChrg=995;
                hAccess=10;
                chgPerH=200;
                hChrg=(hours>hAccess)?(hours-hAccess)*chgPerH:0;
                bill=mChrg+hChrg;
                cout <<"Your total bill for this month is: $"
                        <<static_cast<float>(bill)/CNV_DLR_CENTS
                        <<endl;
                break;
            case('b'):
            case('B'):
                mChrg=1495;
                hAccess=20;
                chgPerH=100;
                hChrg=(hours>hAccess)?(hours-hAccess)*chgPerH:0;
                bill=mChrg+hChrg;
                cout <<"Your total bill for this month is: $"
                        <<static_cast<float>(bill)/CNV_DLR_CENTS
                        <<endl;
                break;
            case('c'):
            case('C'):
                mChrg=1995;
                bill=mChrg;
                cout <<"Your total bill for this month is: $"
                        <<static_cast<float>(bill)/CNV_DLR_CENTS
                        <<endl;
                break;
            default:
                cout <<"You can only select either Package A, "
                        <<"Package B, or Package C.\n"
                        <<"Please restart the program and "
                        <<"enter one of those letters";
        }
    }else
        cout <<"The number of hours used in a month cannot exceed"
                <<" 744!\n" <<"Please restart the program and try again";
    //exit stage right
  
}
/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 19, 2014, 8:00 AM
 * Purpose: Program for Gaddis Chapter 4 Problem 24
 *      Internet Service Provider: Calculates customer's monthly bill
 *      based on three packages  
 */
void prob24() {
    //Declare variables
    int mChrg,//in pennies
        hAccess,//hours of access
        chgPerH,//in pennies
        hChrg,//in pennies
        hours,
        bill, billA, billB, billC;//in pennies
    char choice;
    
    //get package choice char
    cout <<"Please enter the letter of your subscription package\n"
            <<"(A, B, or C): ";
    cin >>choice;
    //get hours
    cout <<"How many hours were used?" <<endl;
    cin >>hours;
    
    //heading
    cout <<"---------------------------" <<endl;
    //validate hours        
    if(hours>0&&hours<=744){
        //Set formatting
        cout<<setprecision(2)<<fixed<<showpoint;
        //calculate monthly charges based on input
        switch(choice){
            case('a'):
            case('A'):
                //calculate package A rate
                mChrg=995;
                hAccess=10;
                chgPerH=200;
                hChrg=(hours>hAccess)?(hours-hAccess)*chgPerH:0;
                billA=mChrg+hChrg;
                cout <<"Your total bill for this month is: $"
                        <<static_cast<float>(billA)/CNV_DLR_CENTS
                        <<endl;
                //calculate package B rate
                mChrg=1495;
                hAccess=20;
                chgPerH=100;
                hChrg=(hours>hAccess)?(hours-hAccess)*chgPerH:0;
                billB=mChrg+hChrg;
                //display savings if B is less than A
                if(billB<billA){
                    cout <<"------------------------------\n"
                         <<"You could save $" 
                         <<static_cast<float>(billA-billB)/CNV_DLR_CENTS
                         <<" if you switched to Package B\n"
                         <<"Your total bill for this month would be: $"
                         <<static_cast<float>(billB)/CNV_DLR_CENTS
                         <<endl;
                }
                //Calculate package C rate
                mChrg=1995;
                billC=mChrg;
                //display savings if C is less than A
                if(billC<billA){
                    cout <<"You could save $" 
                         <<static_cast<float>(billA-billC)/CNV_DLR_CENTS
                         <<" if you switched to Package C\n"
                         <<"Your total bill for this month would be: $"
                         <<static_cast<float>(billC)/CNV_DLR_CENTS
                         <<endl;
                }    
                break;
            case('b'):
            case('B'):
                //calculate package B rate
                mChrg=1495;
                hAccess=20;
                chgPerH=100;
                hChrg=(hours>hAccess)?(hours-hAccess)*chgPerH:0;
                billB=mChrg+hChrg;
                cout <<"Your total bill for this month is: $"
                        <<static_cast<float>(billB)/CNV_DLR_CENTS
                        <<endl;
                //Calculate package C rate
                mChrg=1995;
                billC=mChrg;
                //Display savings if C is less than B
                if(billC<billB){
                    cout  <<"-----------------------------\n"  
                            <<"You could save $" 
                            <<static_cast<float>(billB-billC)/CNV_DLR_CENTS
                            <<" if you switched to Package C\n"
                            <<"Your total bill for this month would be: $"
                            <<static_cast<float>(billC)/CNV_DLR_CENTS
                            <<endl;
                }
                break;
            case('c'):
            case('C'):
                mChrg=1995;
                bill=mChrg;
                cout <<"Your total bill for this month is: $"
                        <<static_cast<float>(bill)/CNV_DLR_CENTS
                        <<endl;
                break;
            default:
                cout <<"You can only select either Package A, "
                        <<"Package B, or Package C.\n"
                        <<"Please restart the program and "
                        <<"enter one of those letters";
        }
    }else
        cout <<"The number of hours used in a month cannot exceed"
                <<" 744!\n" <<"Please restart the program and try again";
    //exit stage right
  
}
/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 19, 2014, 8:00 AM
 * Purpose: Program for Gaddis Chapter 4 Problem 25
 *      Internet Service Provider: Calculates customer's monthly bill
 *      based on three packages  
 */
void prob25() {
    //Declare variables
    int mChrg,//in pennies
        hAccess,//hours of access
        chgPerH,//in pennies
        hChrg,//in pennies
        hours,
        bill, billA, billB, billC;//in pennies
    char choice;
    string month;
    
    //get package choice char
    cout <<"Please enter the letter of your subscription package\n"
            <<"(A, B, or C): ";
    cin >>choice;
    //get month
    cin.ignore();//for getline
    cout <<"Please enter the name of the month with the first"
            <<" letter capitalized:" <<endl;
    getline (cin, month);
    //get hours
    cout <<"How many hours were used?" <<endl;
    cin >>hours;
    
    //heading
    cout <<"---------------------------" <<endl;
    //Set max hours in each month for hour validation
    int maxHrs;
    maxHrs=month=="January"?744:
           month=="February"?672:
           month=="March"?744:
           month=="April"?720:
           month=="May"?744:
           month=="June"?720:
           month=="July"?744:
           month=="August"?744:
           month=="September"?720:
           month=="October"?744:
           month=="November"?720:
           month=="December"?744:744;    
    //validate hours               
    if(hours>0&&hours<=maxHrs){
        //Set formatting
        cout<<setprecision(2)<<fixed<<showpoint;
        //calculate monthly charges based on input
        switch(choice){
            case('a'):
            case('A'):
                //calculate package A rate
                mChrg=995;
                hAccess=10;
                chgPerH=200;
                hChrg=(hours>hAccess)?(hours-hAccess)*chgPerH:0;
                billA=mChrg+hChrg;
                cout <<"Your total bill for this month is: $"
                        <<static_cast<float>(billA)/CNV_DLR_CENTS
                        <<endl;
                //calculate package B rate
                mChrg=1495;
                hAccess=20;
                chgPerH=100;
                hChrg=(hours>hAccess)?(hours-hAccess)*chgPerH:0;
                billB=mChrg+hChrg;
                //display savings if B is less than A
                if(billB<billA){
                    cout <<"------------------------------\n"
                         <<"You could save $" 
                         <<static_cast<float>(billA-billB)/CNV_DLR_CENTS
                         <<" if you switched to Package B\n"
                         <<"Your total bill for this month would be: $"
                         <<static_cast<float>(billB)/CNV_DLR_CENTS
                         <<endl;
                }
                //Calculate package C rate
                mChrg=1995;
                billC=mChrg;
                //display savings if C is less than A
                if(billC<billA){
                    cout <<"You could save $" 
                         <<static_cast<float>(billA-billC)/CNV_DLR_CENTS
                         <<" if you switched to Package C\n"
                         <<"Your total bill for this month would be: $"
                         <<static_cast<float>(billC)/CNV_DLR_CENTS
                         <<endl;
                }    
                break;
            case('b'):
            case('B'):
                //calculate package B rate
                mChrg=1495;
                hAccess=20;
                chgPerH=100;
                hChrg=(hours>hAccess)?(hours-hAccess)*chgPerH:0;
                billB=mChrg+hChrg;
                cout <<"Your total bill for this month is: $"
                        <<static_cast<float>(billB)/CNV_DLR_CENTS
                        <<endl;
                //Calculate package C rate
                mChrg=1995;
                billC=mChrg;
                //Display savings if C is less than B
                if(billC<billB){
                    cout  <<"-----------------------------\n"  
                            <<"You could save $" 
                            <<static_cast<float>(billB-billC)/CNV_DLR_CENTS
                            <<" if you switched to Package C\n"
                            <<"Your total bill for this month would be: $"
                            <<static_cast<float>(billC)/CNV_DLR_CENTS
                            <<endl;
                }
                break;
            case('c'):
            case('C'):
                mChrg=1995;
                bill=mChrg;
                cout <<"Your total bill for this month is: $"
                        <<static_cast<float>(bill)/CNV_DLR_CENTS
                        <<endl;
                break;
            default:
                cout <<"You can only select either Package A, "
                        <<"Package B, or Package C.\n"
                        <<"Please restart the program and "
                        <<"enter one of those letters";
        }
    }else
        cout <<"The number of hours used in a month (" <<month 
                <<")\n" <<"cannot exceed "
                <<maxHrs <<" or be less than 0!\n" 
                <<"Please restart the program and try again";
    //exit stage right
   
}