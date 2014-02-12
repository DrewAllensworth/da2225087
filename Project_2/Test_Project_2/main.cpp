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
struct Card{//Declare Card Structure
    short id;//Card id number
    short rank;//Rank of card. From ace to king using numbers
    short suit;//Suit of card. From clubs to spades using numbers
    string name;//Name of card. Ex: a_s (ace of spades)
    short val;//Count value of card. 1 to 10
};
//Global Constants

//Function Prototypes
void banner(char []);
void flCrdDk(Card[],int,char[],char[],char[],char[],char[]);
void cpyVcAr(const vector<short> &,short[],int size=4);//hands have four cards
void cpyArry(short[],short[],int);
void addUpCd(short[],short,int);
void selSort(short[],int);
void cnvHand(const Card[],Card[],short[],const vector<short> &,const short,
                const int size5=5);
void cnvSHnd(const Card[],Card[],short[],const vector<short> &,
                const int size4=4);
void cnvCard(const Card[],Card &,const short);
void scrPrs(const short [10][2],const Card [],int &);
void scr15s(const short [10][2],const short [10][3],const short [5][4],
                const Card[],int &);
void scrRns(const short [10][3],const short [5][4],const Card[],int &);
void scrFlsh(const Card[],const Card[],int &,const int size5=5);
void scrNbs(const Card[],const Card,int &,const int size4=4);
void dsCdHnd(const Card[],const int);
void scrHand(const short [10][2],const short [10][3],const short [5][4],
                const Card[],const Card[],const Card,int &,const int size=5);
//Execution Begins Here!

int main(int argc, char** argv) {
    //dummy vectors for testing
    vector<short> vecHndP;
    vecHndP.push_back(41);
    vecHndP.push_back(8);
    vecHndP.push_back(5);
    vecHndP.push_back(4);
    vector<short> vecHndC;
    vecHndC.push_back(43);
    vecHndC.push_back(7);
    vecHndC.push_back(15);
    vecHndC.push_back(6);
    vector<short> vecCrib;
    vecCrib.push_back(23);
    vecCrib.push_back(3);
    vecCrib.push_back(19);
    vecCrib.push_back(36);
    //dummy starter card
    short starter=42;
    //dummy dealer
    char dealer='C';
    //dummy points
    int pointsP=1000;
    int pointsC=1000;
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
                            {1,3,4},{2,3,4},//hands
                            {0,2,3},{1,2,3}};
    const short sets_4[ROWS_5][COLS_4]={{0,1,2,3},
                                {0,1,2,4},
                                {0,1,3,4},
                                {0,2,3,4},
                                {1,2,3,4}};
    //Declare Variables
    short upCard=starter;//sets Up Card
    int pointsK=0;//K for "kitty" or, if you prefer "krib"
    //Declare arrays 
    Card crdDeck[DK_SIZE];
    Card handP[HND_SZ5];//hand with up card
    Card handC[HND_SZ5];//hand with up card
    Card crib[HND_SZ5];//hand with up card
    Card sHndP[HND_SZ4];//hand without up card
    Card sHndC[HND_SZ4];//hand without up card
    Card sCrb[HND_SZ4];//hand without up card
    short arHandP[HND_SZ5];//Holds the sorted card ids for player's hand
    short arHandC[HND_SZ5];//Holds the sorted card ids for computer's hand
    short arCrib[HND_SZ5];//Holds the sorted card ids for crib
    short arSHndP[HND_SZ4];//sorted card ids for player's hand without up card
    short arSHndC[HND_SZ4];//sorted card ids for computer's hand w/o up card
    short arSCrb[HND_SZ4];//sorted card ids for crib without up card
    //Character arrays for holding filenames
    char fnIds[]="./ids.txt";
    char fnRanks[]="./ranks.txt";
    char fnSuits[]="./suits.txt";
    char fnNames[]="./names.txt";
    char fnVals[]="./vals.txt";
    //Fill the crdDeck array
    flCrdDk(crdDeck,DK_SIZE,fnIds,fnRanks,fnSuits,fnNames,fnVals);
    //Convert hands with up card
    cnvHand(crdDeck,handP,arHandP,vecHndP,upCard);
    cnvHand(crdDeck,handC,arHandC,vecHndC,upCard);
    cnvHand(crdDeck,crib,arCrib,vecCrib,upCard);
    //convert hands without up card
    cnvSHnd(crdDeck,sHndP,arSHndP,vecHndP);
    cnvSHnd(crdDeck,sHndC,arSHndC,vecHndC);
    cnvSHnd(crdDeck,sCrb,arCrib,vecCrib);
    //fill the Up Card's members
    Card cdUpCrd;
    cnvCard(crdDeck,cdUpCrd,upCard);
    cout<<"Up Card: "<<cdUpCrd.name<<endl;
    cout<<"---------------------------------------"<<endl;
    if(dealer=='C'){//score hands starting with player if computer is dealer
        cout<<"Dealer is the Computer"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"Player's Hand Score:"<<endl;
        scrHand(sets_2,sets_3,sets_4,handP,sHndP,cdUpCrd,pointsP);
        cout<<endl<<"Computer's Hand Score:"<<endl;
        scrHand(sets_2,sets_3,sets_4,handC,sHndC,cdUpCrd,pointsC);
        cout<<endl<<"Crib Score:"<<endl;
        scrHand(sets_2,sets_3,sets_4,crib,sCrb,cdUpCrd,pointsK);
        //assign crib points to dealer 
        pointsC+=pointsK;
        cout<<"Total points for the Computer\n"
                <<"with crib score added: "<<pointsC<<endl;
    }else{//score hands starting with Computer if Player is dealer
        cout<<"Dealer is the Player"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"Computer's Hand Score:"<<endl;
        scrHand(sets_2,sets_3,sets_4,handC,sHndC,cdUpCrd,pointsC);
        cout<<endl<<"Player's Hand Score:"<<endl;
        scrHand(sets_2,sets_3,sets_4,handP,sHndP,cdUpCrd,pointsP);
        cout<<endl<<"Crib Score:"<<endl;
        scrHand(sets_2,sets_3,sets_4,crib,sCrb,cdUpCrd,pointsK);
        //assign crib points to dealer 
        pointsP+=pointsK;
        cout<<"Total points for the Player\n"
                <<"with crib score added: "<<pointsP<<endl;
    }
//    fstream fLstGme("./lastGame.dat",ios::in|ios::out);
//    string lstGame;
//    getline(fLstGme,lstGame);
//    if(lstGame.length()>0){
//        cout<<lstGame<<endl;
//    }else cout<<"Game has not been played before"<<endl;
    //determine who wins and output results to a file
    ofstream fOutput;
    fOutput.open("./lastGame.dat");
    if(pointsP>pointsC){
        cout<<"Player WINS!!!";
        fOutput<<"Player won by "<<(pointsP-pointsC)<<" points!"<<endl;
    }else if(pointsC>pointsP){
        cout<<"Computer WINS!!!";
        fOutput<<"Computer won by "<<(pointsC-pointsP)<<" points!"<<endl;
    }else{
        cout<<"We Have a TIE!!!";
        fOutput<<"The Computer and Player tied!"<<endl;
    }
    fOutput.close();
    ifstream fInput;
    fInput.open("./lastGame.dat");
    string lstGame;
    getline(fInput,lstGame);
    if(lstGame.length()>0){
        cout<<lstGame<<endl;
    }else cout<<"Game has not been played before"<<endl;
    fInput.close();

//    //display the hand
//    cout<<"Hand with Up Card: ";
//    dsCdHnd(handP,HND_SZ5);
//    //score pairs
//    scrPrs(sets_2,handP,pointsP);
//    //score 15s
//    scr15s(sets_2,sets_3,sets_4,handP,pointsP);
//    //score for a flush
//    scrFlsh(handP,sHndP,pointsP);
//    //score nibs
//    scrNbs(sHndP,cdUpCrd,pointsP);
//    //score runs
//    scrRns(sets_3,sets_4,handP,pointsP);
    //output points
//    cout<<"Points: "<<pointsP<<endl;
//    //convert hands
//    cpyVcAr(vecHndP,arHandP,HND_SZ4);
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



void scrHand(const short combi2[10][2],const short combi3[10][3],
                const short combi4[5][4],const Card lngHnd[],
                const Card shrtHnd[],const Card cdUpCrd,int & points,
                const int size){
    //display the hand
    cout<<"Hand with Up Card: ";
    dsCdHnd(lngHnd,size);
    //score pairs
    scrPrs(combi2,lngHnd,points);
    //score 15s
    scr15s(combi2,combi3,combi4,lngHnd,points);
    //score for a flush
    scrFlsh(lngHnd,shrtHnd,points);
    //score nibs
    scrNbs(shrtHnd,cdUpCrd,points);
    //score runs
    scrRns(combi3,combi4,lngHnd,points);
    //output points
    cout<<"Points: "<<points<<endl;
}

void dsCdHnd(const Card hand[],const int size){
    //displays all the contents of a hand
    for(int i=0;i<size;i++){
        cout<<hand[i].name<<"  ";
    }
    cout<<endl;
}

void scrRns(const short combi3[10][3],const short combi4[5][4],
                const Card hand[],int &points){
    bool rnFound=false;//used as a flag value to skip tests if larger runs
                        //are found
    //tests if all five cards are only one away from the next. The moment one
    //card fails the tests move to the next test 
    if((hand[1].rank)-(hand[0].rank)==1){
        if((hand[2].rank)-(hand[1].rank)==1){
            if((hand[3].rank)-(hand[2].rank)==1){
                if((hand[4].rank)-(hand[3].rank)==1){
                    //all cards passed the test
                    //output the card names and assign +5000 points
                    cout<<hand[0].name<<" & "<<hand[1].name<<" & "
                        <<hand[2].name<<" & "<<hand[3].name<<" & "
                        <<hand[4].name<<" = Run of five: +5000 points"
                        <<endl;
                    points+=5000;//give points
                    rnFound=true;//set that a run of five was found.
                                //Skip all other tests if true
                }
            }
        }
    }
    if(!rnFound){
        for(int i=0;i<5;i++){//iterate less than the size of the combi4 array
            if((hand[combi4[i][1]].rank)-(hand[combi4[i][0]].rank)==1){
                if((hand[combi4[i][2]].rank)-(hand[combi4[i][1]].rank)==1){
                    if((hand[combi4[i][3]].rank)-(hand[combi4[i][2]].rank)==1){
                        //all cards passed the test
                        //output the card names and assign +4000 points
                        cout<<hand[combi4[i][0]].name<<" & "
                            <<hand[combi4[i][1]].name<<" & "
                            <<hand[combi4[i][2]].name<<" & "
                            <<hand[combi4[i][3]].name
                            <<" = Run of four: +4000 points"
                            <<endl;
                        points+=4000;//give points
                        rnFound=true;//set that a run of five was found.
                                    //Skip all other tests if true
                    }
                }
            }
        }
    }
    if(!rnFound){
        for(int i=0;i<10;i++){//iterate less than the size of the combi4 array
            if((hand[combi3[i][1]].rank)-(hand[combi3[i][0]].rank)==1){
                if((hand[combi3[i][2]].rank)-(hand[combi3[i][1]].rank)==1){
                    //all cards passed the test
                    //output the card names and assign +3000 points
                    cout<<hand[combi3[i][0]].name<<" & "
                        <<hand[combi3[i][1]].name<<" & "
                        <<hand[combi3[i][2]].name
                        <<" = Run of three: +3000 points"
                        <<endl;
                    points+=3000;//give points
                    rnFound=true;//set that a run of five was found.
                                //Skip all other tests if true
                }
            }
        }
    }
}

void cnvCard(const Card crdDeck[],Card &card,const short id){
    //takes a card Id and fills a card structure element with the proper values
    card.id=crdDeck[id].id;
    card.rank=crdDeck[id].rank;
    card.suit=crdDeck[id].suit;
    card.name=crdDeck[id].name;
    card.val=crdDeck[id].val;
}

void scrNbs(const Card shrtHnd[],const Card cdUpCrd,int &points,
                const int size4){
    if(cdUpCrd.rank==11){
        for(int i=0;i<size4;i++){
            if(shrtHnd[i].rank==cdUpCrd.rank){
                cout<<shrtHnd[i].name<<" makes nibs: +1000 points"
                        <<" and +20% of total points!"<<endl;
                points+=1000;
                points=(points*1.2)+0.05;
            }
        }
    }
}

void scrFlsh(const Card hand[],const Card shrtHnd[],int &points, 
                const int size5){
    int cnt=0;//count to hold how many card have the same suit
    for(int i=0;i<size5;i++){
        if(hand[0].suit==hand[i].suit)cnt++;//increments ctr for each match
    }
    if(cnt==5){
        cout<<"Flush of all five cards: +5000 points"<<endl;
        points+=5000;        
    }
    //if all the cards in the hand except for the up card are the same suit
    //then +4000 points
    if(cnt==4){
        int nCnt=0;
        for(int i=0;i<4;i++){//4 = go through the hand w/o the up card
        //increments nCtr for each suit match without including up card 
        if(shrtHnd[0].suit==shrtHnd[i].suit)nCnt++;
        }
        if(nCnt==4){
        cout<<"Flush of all four hand cards: +4000 points"<<endl;
        points+=4000;        
        }
    }
}

void scr15s(const short combi2[10][2],const short combi3[10][3],
                const short combi4[5][4],const Card hand[],int &points){
    //Go through hand looking for combinations of two cards which add to 15
    for(int i=0;i<10;i++){//goes through const combi2 2D array with 10 rows
        //and two columns. Compares ten combinations of two cards.
        //uses values in card combinations array to check hand for 15s 
        if((hand[combi2[i][0]].val)+(hand[combi2[i][1]].val)==15){
            //if true, print out names and add 2000 point to points total
            cout<<hand[combi2[i][0]].name<<" + "<<hand[combi2[i][1]].name
                    <<" = 15: +2000 points"<<endl;
            points+=2000;
        }
    }
    //Go through hand looking for combinations of three cards which add to 15
    for(int i=0;i<10;i++){//goes through const combi3 2D array with 10 rows
        //and three columns. Compares ten combinations of three cards.
        //uses values in card combinations array to check hand for 15s 
        if((hand[combi3[i][0]].val)+(hand[combi3[i][1]].val)+
                (hand[combi3[i][2]].val)==15){
            //if true, print out names and add 2000 point to points total
            cout<<hand[combi3[i][0]].name<<" + "<<hand[combi3[i][1]].name
                    <<" + "<<hand[combi3[i][2]].name<<" = 15: +2000 points"
                        <<endl;
            points+=2000;
        }
    }
    //Go through hand looking for combinations of four cards which add to 15
    for(int i=0;i<5;i++){//goes through const combi3 2D array with 5 rows
        //and four columns. Compares five combinations of four cards.
        //uses values in card combinations array to check hand for 15s 
        if((hand[combi4[i][0]].val)+(hand[combi4[i][1]].val)+
                (hand[combi4[i][2]].val)+(hand[combi4[i][3]].val)==15){
            //if true, print out names and add 2000 point to points total
            cout<<hand[combi4[i][0]].name<<" + "<<hand[combi4[i][1]].name
                    <<" + "<<hand[combi4[i][2]].name<<" + "
                    <<hand[combi4[i][3]].name<<" = 15: +2000 points"<<endl;
            points+=2000;
        }
    }
    //Trivial case: checks if all five cards add up to 15. If so, +2000 points
    if((hand[0].val)+(hand[1].val)+(hand[2].val)+(hand[3].val)
            +(hand[4].val)==15){
        //if true, print out names and add 2000 point to points total
        cout<<hand[0].name<<" + "<<hand[1].name<<" + "<<hand[2].name<<" + "
                <<hand[3].name<<" + "<<hand[4].name<<" = 15: +2000 points"
                        <<endl;
    }
}

void scrPrs(const short combi[10][2],const Card hand[],int &points){
    for(int i=0;i<10;i++){//goes through const combi 2D array with 10 rows
        //uses values in card combinations array to check hand for pairs 
        if(hand[combi[i][0]].rank==hand[combi[i][1]].rank){
            cout<<hand[combi[i][0]].name<<" & "<<hand[combi[i][1]].name
                    <<" = A Pair: +2000 points"<<endl;
            points+=2000;
        }
    }
}

//creates a "Small" 4 card hand without the up card
void cnvSHnd(const Card crdDeck[],Card crdSHnd[],short arHnd[],
                const vector<short> &vcHnd,const int size4){
    //Declare variables
    short srtArry[size4];
    //convert hands
    cpyVcAr(vcHnd,arHnd);
    //Copy hand array for sorting
    cpyArry(arHnd,srtArry,size4);
    //Sort the hand copy in ascending order
    selSort(srtArry,size4);
    //Copy and add values to members of card hand 
    for(int i=0;i<size4;i++){
        crdSHnd[i].id=crdDeck[srtArry[i]].id;
        crdSHnd[i].rank=crdDeck[srtArry[i]].rank;
        crdSHnd[i].suit=crdDeck[srtArry[i]].suit;
        crdSHnd[i].name=crdDeck[srtArry[i]].name;
        crdSHnd[i].val=crdDeck[srtArry[i]].val;
    }
}


//creates a five card hand with the up card added
void cnvHand(const Card crdDeck[],Card crdHand[],short arHnd[],
                const vector<short> &vcHnd,const short upCard,const int size5){
    //Declare variables
    short srtArry[size5];
    //convert hands
    cpyVcAr(vcHnd,arHnd);
    //add the Up card
    addUpCd(arHnd,upCard,size5);
    //Copy hand array for sorting
    cpyArry(arHnd,srtArry,size5);
    //Sort the hand copy in ascending order
    selSort(srtArry,size5);
    //Copy and add values to members of card hand 
    for(int i=0;i<size5;i++){
        crdHand[i].id=crdDeck[srtArry[i]].id;
        crdHand[i].rank=crdDeck[srtArry[i]].rank;
        crdHand[i].suit=crdDeck[srtArry[i]].suit;
        crdHand[i].name=crdDeck[srtArry[i]].name;
        crdHand[i].val=crdDeck[srtArry[i]].val;
    }
}

void cpyArry(short a[],short b[],const int size){
    //copies one array to another
    for(int i=0;i<size;i++){
        b[i]=a[i];
    }
}

void selSort(short a[], const int size){
    //A selection sort for an array
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

void flCrdDk(Card crdDeck[],const int size,char fnIds[],char fnRanks[],
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