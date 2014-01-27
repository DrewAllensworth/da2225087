/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 27, 2014, 4:32 AM
 * Purpose: Program for Gaddis Chapter 6 Problem 10
 *      Lowest Score Drop: Gets five test scores, calculates and drops 
 *      the lowest score, sums the remaining four, then displays the average
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
void getScore(int testN, int &score, int min=0, int max=100);
/*
 * Parameters: testN-> the test number as int, score->pass-by-reference 
 * test score, min-> default lower bound for the input validation, 
 * max-> default upper bound for the input validation.
 *  getScore() asks the user for a test score and returns the value by 
 *  reference. The score is validated such that it must be between the 
 *  specified bounds. The program loops until such a value is received.
 * Output: returns the test score via pass-by-reference 
 */
float calcAverage(int score1, int score2, int score3, int score4, int score5);
/*
 * Parameters: each parameter is one of five test scores as integers
 *  calcAverage() receives five test scores as arguments and calls
 *  findLowest() which returns the lowest of five values. calcAverage()
 *  then sums all five scores, subtracts the lowest score, then finds
 *  and returns the average of the four values.
 * Output: float->The average of the four highest scores
 */
int findLowest(int score1, int score2, int score3, int score4, int score5);
/*
 * Parameters: each parameter is one of five test scores as integers
 *  findLowest() receives five test scores as arguments. Calculates 
 *  and returns the lowest of the five scores.
 * Output: int->The lowest of five scores 
 */

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare variables
    int score1, score2, score3, score4, score5;
    float avg;
    //Get test scores
    getScore(1,score1);
    getScore(2,score2);
    getScore(3,score3);
    getScore(4,score4);
    getScore(5,score5);
    //drop the lowest score and calculate the average
    avg=calcAverage(score1, score2, score3, score4, score5);
    //header
    cout<<"---------------------------------------" <<endl;
    //Output the average
    cout<<"The average of the four highest test scores is: " <<avg <<endl;
    //exit stage right
    return 0;
}

void getScore(int testN, int &score, int min, int max){
    //get test score
    cout<<"Please enter the score for test " <<testN <<": ";
    cin>>score;
    //validate score within valid range
    while(score<min||score>max){
        cout<<"The score must be greater than or equal to " <<min 
                <<" and less than or equal to " <<max <<endl;
        cout<<"Please enter the score for test " <<testN <<": ";
        cin>>score;
    }
}

float calcAverage(int score1, int score2, int score3, int score4, int score5){
    //Declare variables
    int sum, low;
    //Calculate average, starting with summing all numbers
    sum=score1+score2+score3+score4+score5;
    //find lowest score
    low=findLowest(score1, score2, score3, score4, score5);
    //validate lowest score and error handling
    if(low<0){
        cout<<"Unable to drop lowest score" <<endl;
        return static_cast<float>(sum)/5.0;
    }
    //drop the lowest score from the sum
    sum-=low;
    //return the average of the four remaining scores
    return static_cast<float>(sum)/4.0;
}

int findLowest(int score1, int score2, int score3, int score4, int score5){
    if((score1<=score2)&&(score1<=score3)&&(score1<=score4)
            &&(score1<=score5)){
        return score1;//if score 1 was lowest
    }else if((score2<=score1)&&(score2<=score3)&&(score2<=score4)
            &&(score2<=score5)){
        return score2;//if score 2 was lowest
    }else if((score3<=score1)&&(score3<=score2)&&(score3<=score4)
            &&(score3<=score5)){
        return score3;//if score 3 was lowest
    }else if((score4<=score1)&&(score4<=score2)&&(score4<=score3)
            &&(score4<=score5)){
        return score4;//if score 4 was lowest
    }else if((score5<=score1)&&(score5<=score2)&&(score5<=score3)
            &&(score5<=score4)){
        return score5;//if score 5 was lowest
    }else{//defensive programming
        cout<<endl <<"There was an error in findLowest()\n"
                <<"could not find lowest score" <<endl;
        return -1;
    }
}