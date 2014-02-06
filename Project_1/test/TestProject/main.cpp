/* 
 * File:   test.cpp
 * Author: Owner
 *
 * Created on February 4, 2014, 6:35 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>//for rand()
#include <ctime>//for srand()
#include <fstream>//for reading/writing files
using namespace std;

/*
 * Test bed for main.cpp
 */
//function prototypes
void filName(vector<string> &,ifstream &);
void filIds(short[], ifstream &, short);
void filVals(short[], ifstream &, short);
void filSuit(short[], ifstream &, short);
//Choose the dealer
char gtDealr();
//select a random card
short slCrdDk();
//determine if card is available from the deck
bool inDeck(short, short[]);
//determine if card is available from a hand
bool inHand(short, const vector<short> &);
//determine if card is available from the computer's hand
bool inHndC(short, const vector<short> &);
//deal the cards
void deal(short [], vector<short>  &, vector<short> &,char);
//for deal(), adds cards to hands
short addCard(short [], vector<short>  &);
//displays the player's hand
void dspHand(vector<short>,const vector<string> &);
//displays one card
void dspHand(short,const vector<string> &);//overloaded function
//selects starting card for gameplay
short strtCrd(short [],bool &);
//gets card ID for a given string name
short cardID(string, const vector<string> &, const short []); 
//prompts and allows player to discard two cards into the crib
void discrdP(vector<short> &, vector<short> &, 
                const vector<string> &, const short []);
//has the computer randomly discard two cards into the crib
void discrdC(vector<short> &,vector<short> &, const short []);
//removes a card from a hand
void rmveCrd(short, vector<short> &);
//copies the first vector to the second
void copyVec(const vector<short> &, vector<short> &);
//returns the value of a card for a given card ID
short cardVal(short n, const short []);
//returns the value of the first playable card or -1 if no card playable
short vldPlay(const vector<short> &, const short [],
                const short);
//The Play for player. One card choice
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
                
                
//execution begins here
int main(int argc, char** argv) {
    
    //void plyGame()
    //Declare Variables
    //decks and hands
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
    //fills the arrays and vector
    filName(crdName,names);
    filIds(crdID,ids,DK_SIZE);
    filVals(crdVal,vals,DK_SIZE);
    filSuit(crdSuit,suits,DK_SIZE);
    //fills the deck
    filIds(deck,ids,DK_SIZE);
    //seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //choose the dealer
    char dealer=gtDealr();
    cout<<"The Dealer is: "<<dealer<<endl;
    //deal cards
    deal(deck,handC,handP,dealer);
    //select starting card
    bool isStJk=false;//initialized to false, true if starting card is a Jack
    short starter;//variable containing the starting card ID
    starter=strtCrd(deck,isStJk);//sets both starter and isStJk
    //Get and output the starter card
    cout<<"The starter card is the: ";
    dspHand(starter,crdName);
    cout<<endl<<endl;
    //display the player's hand
    cout<<"Your (Player's) hand contains: ";
    dspHand(handP,crdName);
    cout<<endl;
    //Begins the discard process
    discrdP(handP,crib,crdName,crdID);//discard for Player
    discrdC(handC,crib,crdID);//discard for Computer
    cout<<"The computer has also discarded two cards into the crib."
            <<endl;
    //The Play
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
    
    //TESTS
    //'D' means run The Play using lastPly rather than dealer
    thePlay(c_handC,c_handP,crdVal,crdID,crdName,playCnt,
                cmpPass,plrPass,pointsC,pointsP,dealer,lastPly,'D'); 
                 
                
//    if(dealer=='P'){
//        do{
//           plyCrdC(c_handC,crdVal,crdName,playCnt,cmpPass,
//                pointsC,lastPly);
//           plyCrdP(c_handP,crdID,crdVal,crdName,playCnt,plrPass, 
//                pointsP,lastPly); 
//        }while(playCnt<31||(plrPass==false&&cmpPass==false));
//    }else{//dealer=='C'
//        do{
//           plyCrdP(c_handP,crdID,crdVal,crdName,playCnt,plrPass, 
//                pointsP,lastPly);
//           plyCrdC(c_handC,crdVal,crdName,playCnt,cmpPass,
//                pointsC,lastPly);
//        }while(playCnt<31||(plrPass==false&&cmpPass==false));
//    }
//    if(plrPass==true&&cmpPass==true){
//        if(lastPly=='P'){
//            pointsP+=1000;
//            cout<<"Last play by Player. +1000 points for the \"GO\"!\n"
//                    <<"The total points are: Player: "<<pointsP
//                    <<"\tComputer: "<<pointsC<<endl;
//        }else{//lastPly=='C'
//            pointsC+=1000;
//            cout<<"Last play by the computer. +1000 points for the \"GO\"!\n"
//                    <<"The total points are: Player: "<<pointsP
//                    <<"\tComputer: "<<pointsC<<endl;
//        }
//    }
    while(hasCrds(c_handP)||hasCrds(c_handC)){
        //reset variables for new game
        plrPass=false;
        cmpPass=false;
        playCnt=0;
        //'P' means run The Play using lastPly rather than dealer
        thePlay(c_handC,c_handP,crdVal,crdID,crdName,playCnt,
                cmpPass,plrPass,pointsC,pointsP,dealer,lastPly,'P');
    }
    
//    plyCrdP(c_handP,crdID,crdVal,crdName,playCnt,plrPass, 
//                pointsP,lastPly);
//    cout<<"Computer's Hand: ";
//    dspHand(handC,crdName);
//    plyCrdC(c_handC,crdVal,crdName,playCnt,cmpPass,
//                pointsC,lastPly);
//    plyCrdP(c_handP,crdID,crdVal,crdName,playCnt,plrPass, 
//                pointsP,lastPly);
//    cout<<"Computer's Hand: ";
//    dspHand(handC,crdName);
//    plyCrdC(c_handC,crdVal,crdName,playCnt,cmpPass,
//                pointsC,lastPly);
//    plyCrdP(c_handP,crdID,crdVal,crdName,playCnt,plrPass, 
//                pointsP,lastPly);
//    cout<<"Computer's Hand: ";
//    dspHand(handC,crdName);    
//    plyCrdC(c_handC,crdVal,crdName,playCnt,cmpPass,
//                pointsC,lastPly);
//    cout<<"Your hand: ";
//    dspHand(handP,crdName);
//    cout<<"Computer's Hand: ";
//    dspHand(handC,crdName);
//    cout<<endl<<"CRIB"<<endl;
//    dspHand(crib,crdName);
//    cout<<"copy hand c ";
//    dspHand(c_handC,crdName);
//    cout<<endl;
//    cout<<"copy hand p ";
//    dspHand(c_handP,crdName);
//    cout<<endl;
//    short validCard;
//    validCard=cardID("k_s",crdName,crdID);
//    cout<<"Card ID is: "<<validCard<<endl;
//    cout<<"starter: ";
//    dspHand(starter,crdName);
//    cout<<endl;
////    for(int i=0;i<handC.size();i++){
////        cout<<"handC "<<handC[i]<<endl;
////    }
//    for(int i=0;i<handP.size();i++){
//        cout<<"handP "<<handP[i]<<endl;
//    }
//    cout<<"Your (Player's) hand contains: ";
//    dspHand(handP,crdName);
//    for(int i=0;i<DK_SIZE;i++){
//        cout<<"deck "<<deck[i]<<endl;
//    }
//    //determine if in deck
////    cout<<inDeck(slCrdDk(),deck);
////    cout<<endl;
//    cout<<dealer<<endl;
    cout<<"The total points are: Player: "<<pointsP
                    <<"\tComputer: "<<pointsC<<endl;
    cout<<"success";
    return (0);
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
    
} 

void plyCrdP(vector<short> &c_handP, const short id[], 
                const short crdVal[], const vector<string> &name, 
                unsigned short &playCnt, bool &plrPass, 
                int &pointsP, char &lastPly){
    if(hasCrds(c_handP)){
        cout<<"Your (Player's) hand contains: ";
            dspHand(c_handP,name);//displays the Player's hand for review
        cout<<"Please type the name (as displayed) of the card\n"
                   <<"in your hand you wish to use: "<<endl;
        string crdName;//to hold the user's input
        short crdID;//to hold the looked up cardID
        short val;//to hold the card value
        bool avail;//holds whether the card is found in the Player's hand
        char pass;//holds 'P' to pass if user cannot play a card
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
            avail=inHand(crdID,c_handP);//checks if card ID is in players hand
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
                cout<<"Your card selection added to the current points total\n"
                        <<"is greater than 31."<<endl;
                if(card>=0){//if there is a playable card in the hand
                cout<<"You have at least one playable card in your hand.\n"
                        <<"Please select another card."<<endl;
                }else{
                    pass='P';//have the program pass for the player 
                            //if no playable cards are in their hand
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

        }else cout<<"You have no playable card. You must pass!"<<endl;
        cout<<"Your (Player's) hand now contains: ";
        dspHand(c_handP,name);//displays the Player's hand for review
        cout<<endl<<"The play count is: "<<playCnt<<endl;
    }else{//if hand does not have any cards
        plrPass=true;
        cout<<"You have no playable card. You must pass!"<<endl;
    }
}

short cardVal(short n, const short vals[]){
    return vals[n];
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

void dspHand(short n, const vector<string> &name){
    cout<<name[n];
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

bool inDeck(short sub, short deck[]){
    if (deck[sub]<0){
        return false;
    }else return true;
}

bool inHndC(short sub, const vector<short> &hand){
    if (hand[sub]<0){
        return false;
    }else return true;
}

bool inHand(short id, const vector<short> &hand){
    for(int i=0;i<hand.size();i++){
        if(hand[i]==id){
            return true;
        }       
    }
    return false;
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