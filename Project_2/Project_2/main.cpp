/* 
 * File:   main.cpp
 * Author: Drew Allensworth
 *
 * Created on February 8, 2014, 4:05 PM
 * Purpose: Program for CSC-5 Project 2
 *      Drewbage cribbage game. It's two-hand cribbage, 
 *      1 player against the computer. 
 *      
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>//for rand()
#include <ctime>//for srand()
#include <fstream>//for reading/writing files
using namespace std;

//Structure Declarations not in User Defined Libraries
struct Card{//Declare Card Structure
    short id;//Card id number
    short rank;//Rank of card. From ace to king using numbers
    short suit;//Suit of card. From clubs to spades using numbers
    string name;//Name of card. Ex: a_s (ace of spades)
    short val;//Count value of card. 1 to 10
};
//Global Constants

//Function Prototypes
void filName(vector<string> &,ifstream &);
void filIds(short[], ifstream &, short);
void filVals(short[], ifstream &, short);
void filSuit(short[], ifstream &, short);
char gtDealr();
short slCrdDk();
bool inDeck(short, short[]);
bool inHand(short, const vector<short> &);
bool inHndC(short, const vector<short> &);
void deal(short [], vector<short>  &, vector<short> &,char);
short addCard(short [], vector<short>  &);
void dspHand(vector<short>,const vector<string> &);
void dspHand(short, const vector<string> &);//overloaded function
short strtCrd(short [],bool &);
short cardID(string, const vector<string> &, const short []);
void discrdP(vector<short> &, vector<short> &, 
                const vector<string> &, const short []);
void discrdC(vector<short> &,vector<short> &, const short []);
void rmveCrd(short, vector<short> &);
void copyVec(const vector<short> &, vector<short> &);
short cardVal(short n, const short []);
short vldPlay(const vector<short> &, const short [],
                const short);
void plyCrdP(vector<short> &, const short [], 
                const short [], const vector<string> &, 
                unsigned short &, bool &, int &, char &);
void plyCrdC(vector<short> &, const short [], const vector<string> &, 
                unsigned short &, bool &, int &, char &);
void thePlay(vector<short> &,vector<short> &,
                const short [], const short [],
                const vector<string> &, unsigned short &, 
                bool &, bool &, int &, int &, char &, char &, char);
bool hasCrds(vector<short> &);

void Menu();
int getN();
void def(int);
void plyGame();
//Function Prototypes-Version 2 additions
void banner(char []);
void flCrdDk(Card[],int,char[],char[],char[],char[],char[]);
void cpyVec2(const vector<short> &, vector<short> &);
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
void theShow(const vector<short> &,const vector<short> &,const vector<short> &,
                const short, const char, int &, int &);


//Execution Begins Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    plyGame();break;
        default:   def(inN);}//More options go here!!!
    }while(inN==1);//<- don't forget to change this!!!
    return 0;
}

void Menu(){
    char fName[25]="./Title.dat";
    banner(fName);
    cout<<endl;
    cout<<"Menu for Drewbage Cribbage"<<endl;
    cout<<"Type 1 to Play Game"<<endl;
//    cout<<"Type 2 for Help"<<endl;
//    cout<<"Type 3 for High Scores"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

void plyGame(){
    //Declare Variables
    const float NIB_MUL=1.2;//Multiplier for nibs bonus
    const short DK_SIZE=52;//Holds the size of the Deck arrays == 56
    short crdID[DK_SIZE];//All of the card id’s 0-51; card ID == sub number 
    short crdVal[DK_SIZE];//An array to hold the numerical value for each card
    short crdSuit[DK_SIZE];//An array to hold the suit for each card 
    vector<string> crdName;//An array to hold all of the card names
    short deck[DK_SIZE];//An array to hold the "deck" cards for gameplay
    vector<short> handC;//Vector for computer's hand
    vector<short> handP;//Vector for player's hand
    vector<short> crib;//Vector for the crib
    //file stream objects to fill arrays and vector
    ifstream names;
    ifstream ids;
    ifstream vals;
    ifstream suits;
    //fill the arrays and vectors
    filName(crdName,names);
    filIds(crdID,ids,DK_SIZE);
    filVals(crdVal,vals,DK_SIZE);
    filSuit(crdSuit,suits,DK_SIZE);
    //fills the deck
    filIds(deck,ids,DK_SIZE);
    //seeds the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Display Results of last game
    cout<<"----------------------------"<<endl;
    cout<<"Results of Most Recent Game:"<<endl;
    ifstream fInput;
    fInput.open("./lastGame.dat");
    string lstGame;
    getline(fInput,lstGame);
    (lstGame.length()>0)? cout<<lstGame<<endl:
        cout<<"Game has not been played before"<<endl;
    fInput.close();
    cout<<"----------------------------"<<endl;
    //Game Header
    char fName[25]="./thePlay.dat";
    banner(fName);
    cout<<endl;
    //choose the dealer
    char dealer=gtDealr();
    dealer=='P'?cout<<"The dealer is Player":
        cout<<"The dealer is the computer";
    cout<<endl;
    //deal the cards
    deal(deck,handC,handP,dealer);
    
    //select starting card
    bool isStJk=false;//initialized to false, true if starting card is a Jack
    short starter;//variable containing the starting card ID
    starter=strtCrd(deck,isStJk);//sets both starter and isStJk
    cout<<endl;
    //display the player's hand
    cout<<"Your (Player's) hand contains: ";
    dspHand(handP,crdName);
    cout<<endl;
    //Begins the discard process
    discrdP(handP,crib,crdName,crdID);//discard for Player
    discrdC(handC,crib,crdID);//discard for Computer
    cout<<"The computer has also discarded two cards into the crib."
            <<endl<<endl;
    //display the starter card
    cout<<"The starter card is the: ";
    dspHand(starter,crdName);
    cout<<endl<<endl;
    //Make copies of the hands to use for The Play
    vector<short> c_handC;//Vector for copy of computer's hand
    copyVec(handC,c_handC);//Fully copy handC to c_handC
    vector<short> c_handP;//Vector for copy of player's hand
    copyVec(handP,c_handP);//Fully copy handP to c_handP
    //Variables for The Play
    unsigned short playCnt=0;//holds count for The Play. Values 0-31
    bool plrPass=false,//Indicates if Player has “passed” during play
         cmpPass=false;//Indicates if computer has “passed” during play
    char lastPly;//‘C’ = computer, ‘P’ = Player. For determining who played last
    int pointsP=0,//holds total point for the player
        pointsC=0;//holds total points for the computer
    //'D' means run The Play using lastPly rather than dealer
    thePlay(c_handC,c_handP,crdVal,crdID,crdName,playCnt,
                cmpPass,plrPass,pointsC,pointsP,dealer,lastPly,'D');
    //Continue game if cards remain after the first
    while(hasCrds(c_handP)||hasCrds(c_handC)){
        //reset variables for new game
        plrPass=false;
        cmpPass=false;
        playCnt=0;
        cout<<endl<<"New Round Started: Play Count Reset to 0"<<endl;
        //'P' means run The Play using lastPly rather than dealer
        thePlay(c_handC,c_handP,crdVal,crdID,crdName,playCnt,
                cmpPass,plrPass,pointsC,pointsP,dealer,lastPly,'P');
    }
    //Header for The Play results
    cout<<"---------------------------------------------\n"
        <<"The total points are: Player: "<<pointsP<<"\tComputer: "
            <<pointsC<<endl;
    //Header for The Show
    strcpy(fName,"./theShow.dat");
    banner(fName);
    cout<<endl;
    //Clean the hands of negative values for theShow
    vector<short> clnHndC;//Vector for copy of computer's hand
    cpyVec2(handC,clnHndC);//Fully copy handC to clnHandC
    vector<short> clnHndP;//Vector for copy of player's hand
    cpyVec2(handP,clnHndP);//Fully copy handP to clnHandP 
    //Start The Show--score the hands
    theShow(clnHndP,clnHndC,crib,starter,dealer,pointsP,pointsC);
    //Header for final score results
    cout<<"---------------------------------------------\n"
        <<"The total points are: Player: "<<pointsP<<"\tComputer: "
            <<pointsC<<endl;
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
    cout<<endl<<endl;
}


bool hasCrds(vector<short> &hand){
    for(int i=0;i<hand.size();i++){
        //if any sub has a valid card ID return true
        if(hand[i]>=0)return true;
    }
    return false;//else return false
}   

void thePlay(vector<short> &c_handC,vector<short> &c_handP,
                const short crdVal[], const short crdID[],
                const vector<string> &crdName, unsigned short &playCnt, 
                bool &cmpPass, bool &plrPass, 
                int &pointsC, int &pointsP, char &dealer, 
                char &lastPly, char option){
    char dlFrst;//allows one to set the program to run based on either 
                //either dealer or lastPly depending on the option
    if(option=='D'){
        dlFrst=dealer;
    }else dlFrst=lastPly;
    //Start The Play
    if(dlFrst=='P'){
        do{
           plyCrdC(c_handC,crdVal,crdName,playCnt,cmpPass,
                pointsC,lastPly);
           if(playCnt==31)break;//get out of the loop if 31
           if(plrPass==true&&cmpPass==true)break;//if both players pass
           plyCrdP(c_handP,crdID,crdVal,crdName,playCnt,plrPass, 
                pointsP,lastPly); 
        }while(playCnt<31&&(plrPass==false||cmpPass==false));
    }else{//dealer=='C'
        do{
           plyCrdP(c_handP,crdID,crdVal,crdName,playCnt,plrPass, 
                pointsP,lastPly);
           if(playCnt==31)break;
           if(plrPass==true&&cmpPass==true)break;
           plyCrdC(c_handC,crdVal,crdName,playCnt,cmpPass,
                pointsC,lastPly);
        }while(playCnt<31&&(plrPass==false||cmpPass==false));
    }
    if(plrPass==true&&cmpPass==true){
        playCnt=0;//reset the game count
        if(lastPly=='P'){
            pointsP+=1000;
            cout<<"Last play by Player. +1000 points for the \"GO\"!"<<endl;
        }else{//lastPly=='C'
            pointsC+=1000;
            cout<<"Last play by the computer. +1000 points for the \"GO\"!"
                    <<endl;
                    
        }
    }
}


short vldPlay(const vector<short> &hand, const short crdVal[],
                const short playCnt){
    short val,id;
    for(int i=0;i<hand.size();i++){
        if(hand[i]>=0){
            id=hand[i];
            val=cardVal(id,crdVal);
            if(playCnt+val<=31){
                return hand[i];//return value of first card that's a valid play
            }
        }
    }
    return -1;//if no card in the hand is a valid play, return -1
}

void plyCrdC(vector<short> &c_handC, const short crdVal[], 
                const vector<string> &name, unsigned short &playCnt, 
                bool &cmpPass, int &pointsC, char &lastPly){
    if(hasCrds(c_handC)){//checks if hand has cards
        //gets the first valid playable card and return the ID
        //If there is no playable card in the deck, returns -1
        short card=vldPlay(c_handC,crdVal,playCnt);
        //perform operations if there is a playable card
        if(card>=0){
            short val=cardVal(card,crdVal);//gets the value of the card
            playCnt+=val;//adds the value to the play count
            //Show the Player the card the computer chose
            cout<<"The computer plays the: ";
            dspHand(card,name);
            cout<<endl<<"The play count is: "<<playCnt<<endl;
            if(playCnt==15){//assigns points if count == 15||31
                pointsC+=2000;
                cout<<"The computer scores 2000 points! It's total points are: "
                        <<pointsC<<endl;
            }else if(playCnt==31){
                pointsC+=4000;
                cout<<"The computer scores 4000 points! It's total points are: "
                        <<pointsC<<endl;
            }else;//assigns no points
            lastPly='C';//sets the computer as the most recent player
            rmveCrd(card,c_handC);//removes the card from the hand
        }else{
            cmpPass=true;
            cout<<"The computer has chosen to pass!"<<endl;
        }
    }else{//if hand does not have any cards
        cmpPass=true;
        cout<<"The computer is out if cards and must pass!"<<endl;
    }
} 

void plyCrdP(vector<short> &c_handP, const short id[], 
                const short crdVal[], const vector<string> &name, 
                unsigned short &playCnt, bool &plrPass, 
                int &pointsP, char &lastPly){
    if(hasCrds(c_handP)){
        cout<<"Your (Player's) hand contains: ";
            dspHand(c_handP,name);//displays the Player's hand for review
        //gets the first valid playable card and return the ID
        //If there is no playable card in the deck, returns -1
        short card=vldPlay(c_handP,crdVal,playCnt);
        //perform operations if there is a playable card
        if(card>=0){
            cout<<"Please type the name (as displayed) of the card\n"
                       <<"in your hand you wish to use: "<<endl;
            string crdName;//to hold the user's input
            short crdID;//to hold the looked up cardID
            short val;//to hold the card value
            bool avail;//holds whether the card is found in the Player's hand
            char pass='A';//holds 'P' to pass if user cannot play a card
            do{
                cout<<"Card: ";
                cin>>crdName;
                crdID=cardID(crdName,name,id);//checks if the card name has a card ID
                while(crdID<0){//while card name is invalid
                    cout<<"That is not a valid card name\n"
                            <<"please enter a card name from your hand: ";
                    cout<<"Card: ";
                    cin>>crdName;
                    crdID=cardID(crdName,name,id);
                }
                avail=inHand(crdID,c_handP);//checks if card ID is in plyrs hand
                while(!avail||crdID<0){//while card ID is not in player's hand
                    cout<<"You do not have that card in your hand\n"
                            <<"please enter a card name from your hand: ";
                    cout<<"Card: ";
                    cin>>crdName;
                    crdID=cardID(crdName,name,id);
                    if(cardID>=0){
                        avail=inHand(crdID,c_handP);
                    }    
                }
                val=cardVal(crdID,crdVal);
                if((playCnt+val)>31){
                    //checks hand for a playable card
                    short card=vldPlay(c_handP,crdVal,playCnt);
                    cout<<"Your card selection added to the current points "
                            <<"total\n is greater than 31."<<endl;
                    if(card>=0){//if there is a playable card in the hand
                    cout<<"You have at least one playable card in your hand.\n"
                            <<"Please select another card."<<endl;
                    }else{
                        pass='P';//have the program pass for the player 
                                //if no playable cards are in their hand
                        cout<<"You have no playable card. You must pass!!!"
                                <<endl;
                        plrPass=true;
                    }

                }
            }while(pass!='P'&&(playCnt+val)>31);
            if(pass!='P'&&avail&&(playCnt+val)<=31){//defensive programming
                playCnt = playCnt + val;//add card value to playCnt
                rmveCrd(crdID,c_handP);//remove card from Player's hand
                lastPly='P';//Player is now the most recent one to play
                if(playCnt==15){//assigns points if count == 15||31
                    pointsP+=2000;
                    cout<<"You score 2000 points! Your total point are: "
                            <<pointsP<<endl;
                }else if(playCnt==31){
                    pointsP+=4000;
                    cout<<"You score 4000 points! Your total point are: "
                            <<pointsP<<endl;
                }else;//assigns no points


            }
    //        else cout<<"You have no playable card. You must pass!!!"<<endl;
    //        cout<<"Your (Player's) hand now contains: ";
    //        dspHand(c_handP,name);//displays the Player's hand for review
            cout<<"The play count is: "<<playCnt<<endl;
        }else{
            plrPass=true;
            cout<<"You have no playable card. You must pass!"<<endl;
        }
    }else{//if hand does not have any cards
        plrPass=true;
        cout<<"You have no playable card. You must pass!"<<endl;
    }
}

short cardVal(short n, const short vals[]){
    return vals[n];
}

void cpyVec2(const vector<short> &a, vector<short> &b){
    for(int i=0;i<a.size();i++){
        if(a[i]>=0)b.push_back(a[i]);//only copy non-negative values
    }
}

void copyVec(const vector<short> &a, vector<short> &b){
    for(int i=0;i<a.size();i++){
        b.push_back(a[i]);
    }
}

void discrdC(vector<short> &handC,vector<short> &crib, const short id[]){
    short sub, card;
    bool avail;
    for(int i=0;i<2;i++){
        do{
            sub=rand()%6;//assigns a random number for vector sub from 0-5
            avail=inHndC(sub,handC);//true if card is available
            if(avail){
                card=handC[sub];//assigns value in handC at sub number to card
                crib.push_back(card);//puts that card ID into the crib
                handC[sub]=-1;//removes the ID from the computer's hand
            }
        }while(!avail);//loop again if card is not in deck
    }
}

void discrdP(vector<short> &handP, vector<short> &crib, 
                const vector<string> &name, const short id[]){
    cout<<"Please type the name (as displayed) of the TWO cards\n"
               <<"you wish to discard into the crib"<<endl;
    string crdName;//to hold the user's input
    short crdID;//to hold the looked up cardID
    bool avail;//holds whether the card is found in the Player's hand
    for(int i=0;i<2;i++){
        cout<<"Card "<<i+1<<": ";
        cin>>crdName;
        crdID=cardID(crdName,name,id);//checks if the card name has a card ID
        while(crdID<0){//while card name is invalid
            cout<<"That is not a valid card name\n"
                    <<"please enter a card name from your hand: ";
            cout<<"Card "<<i+1<<": ";
            cin>>crdName;
            crdID=cardID(crdName,name,id);
        }
        avail=inHand(crdID,handP);//checks if card ID is in players hand
        while(!avail||crdID<0){//while card ID is not in player's hand
            cout<<"You do not have that card in your hand\n"
                    <<"please enter a card name from your hand: ";
            cout<<"Card "<<i+1<<": ";
            cin>>crdName;
            crdID=cardID(crdName,name,id);
            if(cardID>=0){
                avail=inHand(crdID,handP);
            }    
        }
        if(avail){//defensive programming
            crib.push_back(crdID);//push card into crib vector
            rmveCrd(crdID,handP);//remove card from Player's hand
        }else cout<<"ERROR: From dscrdP. This message should not be seen"
                <<endl;
        cout<<"Your (Player's) hand now contains: ";
        dspHand(handP,name);//displays the Player's hand for review
    }
}

void rmveCrd(short id, vector<short> &hand){
    for(int i=0;i<hand.size();i++){
        if(hand[i]==id){
            hand[i]=-1;
            break;
        }    
    }
}

short cardID(string str, const vector<string> &name, const short id[]){
    for(int i=0;i<name.size();i++){
        if(name[i]==str){
            return id[i];
        }    
    }
    return -1;
}

short strtCrd(short deck[],bool &isStJak){
    short card;
    bool avail;
    do{
        card=slCrdDk();//assigns a random number from 0-51
        avail=inDeck(card,deck);//true if card is available
        if(avail){
            if(card>=40&&card<=43){//if card ID is equal to any suit Jack
               isStJak=true; 
            }
            deck[card]=-1;//remove card from deck
            return card;
        }
    }while(!avail);//loop again if card is not in deck
}

void dspHand(short n, const vector<string> &name){
    cout<<name[n];
}

void dspHand(vector<short> hand, const vector<string> &crdName){
    for(int i=0;i<hand.size();i++){
        //if the card ID for a given hand sub number is valid
        //then output the corresponding name for that ID number
        if(hand[i]>=0)cout<<crdName[hand[i]]<<"  ";
    }
    cout<<endl;
}

void deal(short deck[], vector<short>  &handC, vector<short> &handP,
                char dealer){
    short card;
    if(dealer=='P'){//deal Player first
        for(int i=0;i<6;i++){//assign six cards
            card=addCard(deck,handP);//for Player
            deck[card]=-1;//remove card from deck
            card=addCard(deck,handC);//for computer
            deck[card]=-1;//remove card from deck
            }
    }else{//dealer=='C'//deal computer first
        for(int i=0;i<6;i++){//assign six cards
            card=addCard(deck,handC);//for computer
            deck[card]=-1;//remove card from deck
            card=addCard(deck,handP);//for Player
            deck[card]=-1;//remove card from deck
        }
    }
}

short addCard(short deck[], vector<short>  &hand){
    short card;
    bool avail;
    do{
        card=slCrdDk();//assigns a random number from 0-51
        avail=inDeck(card,deck);//true if card is available
        if(avail){
            hand.push_back(card);
        }
    }while(!avail);//loop again if card is not in deck
    return card;
}

bool inHand(short id, const vector<short> &hand){
    for(int i=0;i<hand.size();i++){
        if(hand[i]==id){
            return true;
        }       
    }
    return false;
}

bool inHndC(short sub, const vector<short> &hand){
    if (hand[sub]<0){
        return false;
    }else return true;
}

bool inDeck(short sub, short deck[]){
    if (deck[sub]<0){
        return false;
    }else return true;
}

short slCrdDk(){
    return rand()%52;
}

char gtDealr(){
    short n=rand()%2;
    if(n==0){
        return 'C';
    }else return 'P';
}

void filName(vector<string> &crdName,ifstream &names){
    names.open("names.txt", ios::in);
    string tmp;
    int cnt=0;
    while(cnt<52){
        names>>tmp;
        crdName.push_back(tmp);
        cnt++;
    }
    names.close();
}

void filIds(short array[], ifstream &ids, const short MAX){
    ids.open("ids.txt", ios::in);
    short tmp;
    for(int cnt=0;cnt<MAX;cnt++){
        ids>>tmp;
        array[cnt]=tmp;
    }
    ids.close();
}

void filVals(short array[], ifstream &vals, const short MAX){
    vals.open("vals.txt", ios::in);
    short tmp;
    for(int cnt=0;cnt<MAX;cnt++){
        vals>>tmp;
        array[cnt]=tmp;
    }
    vals.close();
}

void filSuit(short array[], ifstream &suits, const short MAX){
    suits.open("suits.txt", ios::in);
    short tmp;
    for(int cnt=0;cnt<MAX;cnt++){
        suits>>tmp;
        array[cnt]=tmp;
    }
    suits.close();
}

//Start of Version 2 Functions
void theShow(const vector<short> &vecHndP,const vector<short> &vecHndC,
                const vector<short> &vecCrib,const short starter, 
                const char dealer, int &pointsP, int &pointsC){
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
    //header
    cout<<"Up Card: "<<cdUpCrd.name<<endl;
    cout<<"---------------------------------------"<<endl;
    //Score hands and output results
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