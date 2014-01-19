/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on January 18, 2014, 7:15 PM
 * Purpose: Gaddis Chapter 3 problem 22
 *      word games: Inserting user derived values into a story
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here!

int main(int argc, char** argv) {
    //Declare Variables
    string name, city, college, profsn, animal, petName;
    int age;
    
    //Header
    cout <<"It's a mad, mad, Mad Lib!\n"
            <<"------------------------" <<endl;
            
    //get values from user
    cout <<"Please enter the following values:" <<endl;
    cout <<"Your First Name: ";
    cin >>name;
    cout <<"Your Age: ";
    cin >>age;
    cout <<"The name of a City: ";
    cin.ignore();//ignore \n for getline()
    getline(cin, city);
    cout <<"The name of a College: ";
    getline(cin, college);
    cout <<"A Profession: ";
    getline(cin, profsn);
    cout <<"A type of Animal: ";
    getline(cin, animal);
    cout <<"A pet's Name: ";
    getline(cin, petName);
    cout <<endl;
    
    //Output MadLib Story
    cout <<"There once was a person named " <<name <<" who lived in "
            <<city <<"." <<endl <<"At the age of " <<age <<", "
            <<name <<" went to college at " <<college <<". " <<name
            <<" graduated\n" <<"and went to work as a " <<profsn
            <<" . Then, " <<name <<" adopted a(n) \n" <<animal <<" named "
            <<petName <<". " <<"They both lived happily ever after!"
            <<endl;
    
    //exit stage right
    return 0;
}

