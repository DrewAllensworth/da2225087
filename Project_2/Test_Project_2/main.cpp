/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on February 8, 2014, 8:56 PM
 * Purpose: Testbed for V.2 of Drewbage cribbage game.
 */

//System Libraries
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>//for rand()
#include <ctime>//for srand()
#include <fstream>//for reading/writing files
using namespace std;
//Structure Declarations
struct card{//Declare Card Structure
    short id;//Card id number
    short rank;//Rank of card. From ace to king using numbers
    short suit;//Suit of card. From clubs to spades using numbers
    string name;//Name of card. Ex: a_s (ace of spades)
    short val;//Count value of card. 1 to 10
};
//Global Constants

//Function Prototypes
void banner(char []);
void flCrdDk(card[],int,char[],char[],char[],char[],char[]);
void cpyVcAr(const vector<short> &,short[],int size=4);//hands have four cards
void cpyArry(short[],short[],int);
void addUpCd(short[],short,int);
void selSort(short[],int);
void cnvHand(const card[],card[],short[],const vector<short> &,const short,const int size5=5);
//Execution Begins Here!

int main(int argc, char** argv) {
    //dummy vectors for testing
    vector<short> tstHndP;
    tstHndP.push_back(31);
    tstHndP.push_back(3);
    tstHndP.push_back(17);
    tstHndP.push_back(1);
    vector<short> tstHndC;
    tstHndC.push_back(30);
    tstHndC.push_back(5);
    tstHndC.push_back(15);
    tstHndC.push_back(0);
    //dummy starter card
    short starter=42;
    //dummy dealer
    char dealer='P';
    //END DUMMY VALS
    //Declare constant variables
    const int DK_SIZE=52;//The size of the deck
    const int HND_SZ5=5;//The size of a hand
    const int HND_SZ4=4;//The size if the crib hand
    const int COLS_2=2;//Constant to hold the column size for 2D array
    const int COLS_3=3;//Constant to hold the column size for 2D array
    const int COLS_4=4;//Constant to hold the column size for 2D array
    const int ROWS_10=10;//Constant to hold the row size for 2D array
    const int ROWS_5=5;//Constant to hold the row size for 2D array
    //Declare constant arrays
    const short sets_2[ROWS_10][COLS_2]={{0,1},{0,2},//2D array to hold all  
                            {0,3},{0,4},//possible combinations of two cards.  
                            {1,2},{1,3},//Used for scoring hands
                            {1,4},{2,3},
                            {2,4},{3,4}};
                                
    const short sets_3[ROWS_10][COLS_3]={{0,1,2},{0,1,3},//2D array to hold all                             {0,2,3},{1,2,3},
                            {0,1,4},{0,2,4},//possible card combinations of 
                            {1,2,4},{0,3,4},//three cards. Used for scoring 
                            {1,3,4},{2,3,4}};//hands
    const short sets_4[ROWS_5][COLS_4]={{0,1,2,3},
                                {0,1,2,4},
                                {0,1,3,4},
                                {0,2,3,4},
                                {1,2,3,4}};
    //Declare Variables
    short upCard=starter;//sets Up Card
    //Declare arrays 
    card crdDeck[DK_SIZE];
    card handP[HND_SZ5];
    card handC[HND_SZ5];
    card crib[HND_SZ5];
    short arHandP[HND_SZ5];//Holds the sorted card ids for player's hand
    short arHandC[HND_SZ5];//Holds the sorted card ids for computer's hand
    short arCrib[HND_SZ5];//Holds the sorted card ids for crib
    //Character arrays for holding filenames
    char fnIds[]="./ids.txt";
    char fnRanks[]="./ranks.txt";
    char fnSuits[]="./suits.txt";
    char fnNames[]="./names.txt";
    char fnVals[]="./vals.txt";
    //Fill the crdDeck array
    flCrdDk(crdDeck,DK_SIZE,fnIds,fnRanks,fnSuits,fnNames,fnVals);
    //Convert hands
    cnvHand(crdDeck,handP,arHandP,tstHndP,upCard);
//    //convert hands
//    cpyVcAr(tstHndP,arHandP,HND_SZ4);
//    //add Up card
//    addUpCd(arHandP,upCard,HND_SZ5);
//    for(int i=0;i<HND_SZ5;i++){
//        cout<<arHandP[i]<<endl;
//    }
//    selSort(arHandP,HND_SZ5);
//    for(int i=0;i<HND_SZ5;i++){
//        cout<<arHandP[i]<<endl;
//    }    
//    const int COLS_4=4;
//    const int COLS_2=2;
//    int cards[4][COLS_4]={{0,1,1,1},
//                          {1,1,2,1},
//                          {2,1,3,1},
//                          {3,1,4,1}};
//    int poss[4][COLS_2]={{0,1},
//                        {0,3},
//                        {1,2},
//                        {2,3}};
//    int hand[4]={2,1,3,0};
//    
//    cout<<cards[hand[poss[2][1]]][2]<<"+";
//    cout<<cards[hand[poss[2][0]]][2]<<" = ";
//    cout<<(cards[hand[poss[2][1]]][2])+(cards[hand[poss[2][0]]][2]);
                                  
//    char fName[25]="./Title.dat";
//    banner(fName);
//    cout<<endl;
//    strcpy(fName,"./thePlay.dat");
//    banner(fName);
//    cout<<endl;
//    strcpy(fName,"./theShow.dat");
//    banner(fName);
//    cout<<endl;
    return 0;
}

void cnvHand(const card crdDeck[],card crdHand[],short arHnd[],
                const vector<short> &vcHnd,const short upCard,const int size5){
    //Declare variables
    short srtArry[size5];
    //convert hands
    cpyVcAr(vcHnd,arHnd);
    //add the Up card
    addUpCd(arHnd,upCard,size5);
    for(int i=0;i<size5;i++){
        cout<<arHnd[i]<<endl;
    }
    //Copy hand array for sorting
    cpyArry(arHnd,srtArry,size5);
    //Sort the hand copy in ascending order
    selSort(srtArry,size5);
    for(int i=0;i<size5;i++){
        cout<<srtArry[i]<<endl;
    }
    //Copy and add values to members of card hand 
    for(int i=0;i<size5;i++){
        crdHand[i].id=crdDeck[srtArry[i]].id;
        crdHand[i].rank=crdDeck[srtArry[i]].rank;
        crdHand[i].suit=crdDeck[srtArry[i]].suit;
        crdHand[i].name=crdDeck[srtArry[i]].name;
        crdHand[i].val=crdDeck[srtArry[i]].val;
        cout<<crdHand[i].id<<" "<<crdHand[i].name<<" "<<crdHand[i].val<<endl;
    }
}

void cpyArry(short a[],short b[],const int size){
    for(int i=0;i<size;i++){
        b[i]=a[i];
    }
}

void selSort(short a[], const int size){
    int strtScn, minVal, minIndx;
    for(strtScn=0;strtScn<size-1;strtScn++){
        minIndx=strtScn;
        minVal=a[strtScn];
        for(int i=strtScn+1;i<size;i++){
            if(a[i]<minVal){
                minVal=a[i];
                minIndx=i;
            }
        }
        a[minIndx]=a[strtScn];
        a[strtScn]=minVal;
    }
    
}

void addUpCd(short hand[],short upCard,const int size){
    hand[size-1]=upCard;//always add upCard to last position in hand array
}

void cpyVcAr(const vector<short> &vcHnd,short aHnd[],const int size){
    for(int i=0;i<size;i++){
        aHnd[i]=vcHnd[i];//copies value in vector[i] to array[i]
    }
}

void banner(char fName[]){
    //Declare variables
    ifstream input;
    string str;
    //open file
    input.open(fName);
    for(int i=0;i<7;i++){
        getline(input,str,'\n');
        cout<<str<<endl;
    }
    //clean up
    input.close();
}

void flCrdDk(card crdDeck[],const int size,char fnIds[],char fnRanks[],
                char fnSuits[],char fnNames[],char fnVals[]){
    ifstream ids;
    ifstream ranks;
    ifstream suits;
    ifstream names;
    ifstream vals;
    //Open the file stream objects using the character arrays for filenames
    ids.open(fnIds, ios::in);
    ranks.open(fnRanks, ios::in);
    suits.open(fnSuits, ios::in);
    names.open(fnNames, ios::in);
    vals.open(fnVals, ios::in);
    //Fill the array
    for(int i=0;i<size;i++){
        ids>>crdDeck[i].id;
        ranks>>crdDeck[i].rank;
        suits>>crdDeck[i].suit;
        names>>crdDeck[i].name;
        vals>>crdDeck[i].val;
    }
    //Clean up
    ids.close();
    ranks.close();
    suits.close();
    names.close();
    vals.close();   
}