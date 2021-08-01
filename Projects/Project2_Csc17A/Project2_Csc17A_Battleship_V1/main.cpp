/* 
 * File:   main.cpp
 * Author: Christopher Delgado
 * Created on July 27th, 2021
 * Purpose: Battleship
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <ctime>      //For random number generator
#include <iomanip>    //Formatting library
#include <string>     //string library to hold players name 
#include <fstream>    //File library
using namespace std;  //Libraries compiled under std

//User Level Libraries
#include "GameB.h"

struct Stats{
    short nTurn;
    string name;
};

//Global Constants - Science/Math Related
//Conversions, Higher Dimensions

//Function Prototypes
void srtScrn(char, const int, GameB &);                           //Displays starting screen and instructions                                 
void filBoat(int [], const int, GameB &);                         //Fills computers boats with random values 
void usrBoat(int [], const int, GameB &);                         //Fills player choice for boats
void dsplyBd(int[], const int, GameB &, int[]);                   //Displays user and computer board
void hitMiss(GameB &, int [], const int, int);                    //Function that figures out if player got a hit or a miss
void cmpChce(GameB &, int [], const int);                         //Function that figures out if computer got a hit or a miss
bool winLose(int [], int[], GameB &, bool, bool &);               //Determines whether or not the game has been won or lost
void hiScore(ofstream &, ifstream &, GameB &);                    //Opens high score file and checks if you have high score
void statFle(Stats &, ofstream &, ifstream &, GameB &);           //Puts Stats structure into a binary file

//Execution Begins Here!
int main(int argc, char** argv) {
    //Random Number Seed Set Here
    srand(static_cast<unsigned int>(time(0)));
    
    //Variable Declarations 
    const int NBOATS=10;                     //Number of boats
    int boats[NBOATS];                       //Array that holds value of boats
    int pBoats[NBOATS];                      //Array that holds value of player boats
    int choice;                              //User choice of where to shoot on board
    bool loop;                               //Used for do while loop
    char start;                              //Used to start game 
    ofstream highScr;                        //Used to open and read the high score file
    ifstream inptScr;                        //Input your high score into the high score file
    ofstream outStat;                        //Outputs stats structure from a file
    ifstream inptSta;                        //Inputs stats structure in file
    Stats gmeStat;                           //Game stats structure
    bool win;                                //States if game was won
    GameB gBoards;
    
    //Variable Initialization   
    win=false;
       
    //Mapping Process Inputs to Outputs
    //Presents start screen and instructions 
    srtScrn(start, NBOATS, gBoards);
    
    //User inputs the size of the board they want to play on   
    gBoards.setSize();
    
    //Assigns random value to boats
    filBoat(boats, NBOATS, gBoards);   
    
    //Fills user and computer board
    gBoards.setBrd();
   
    //Fills user boats
    usrBoat(pBoats, NBOATS, gBoards);
    
    //Displays both boards before any turns have been made
    dsplyBd(pBoats, NBOATS, gBoards, boats);
    
    do{
        //Game play function that determines a hit or a miss
        hitMiss(gBoards, boats, NBOATS, choice);
      
        //Computers Choice      
        cmpChce(gBoards, pBoats, NBOATS);
        
        //Displays user and computers altered board
        dsplyBd(pBoats, NBOATS, gBoards, boats);
       
        //Function either returns false or true
        loop=winLose(boats, pBoats, gBoards, loop, win);
        
    }while(loop);
    
    //If you win then it will display game stats and high score
    if(win==true){
        statFle(gmeStat, outStat, inptSta, gBoards);
        hiScore(highScr, inptScr, gBoards);
    }
    
    //Exit stage right!
    return 0;
}

//Displays start screen and instructions
void srtScrn(char start, const int NBOATS, GameB &g){
    //Asks user to start or exit
    cout<<"Welcome to Battleship\n";
    cout<<"Press Y to play or press N to exit\n";
    cin>>start;
    while(start!='y'&&start!='Y'&&start!='n'&&start!='N'){   //Input validation using while loop
        cout<<"Please enter either Y or N\n";
        cin>>start;
    }
    switch(start){   //Pressing Y leads to rest of code while N exits program
        case('Y'):
        case('y'):
            break;
        case('N'):
        case('n'):
            exit (0);
            break;
    }
    //Instructions for game
    cout<<"You will have to sink all of the computers ships in order to win!\n";
    cout<<"Each row is labeled from 1-10, 11-20, etc.\n";
    cout<<"The computer will randomly place "<<NBOATS<<" boats 1 space big and "
        <<"it is your objective to find them and sink them.\n";
    cout<<"A hit will be indicated by a \"x\" and a miss will be indicated by a \"o\".\n\n";
    
    //Gets name of the player
    g.setName();
}

//Display the game board
void dsplyBd(int boat[], const int NBOATS, GameB &g, int boats[]){
    //Displays computers boats for testing purposes
    for(int n=0; n<10; n++){
        cout<<boats[n]<<",";
    }
    cout<<endl;
    
    //Displays computer board
    g.cBoard();
    
    cout<<endl;
    cout<<"Your boats#: ";
    for(int i=0; i<NBOATS; i++){
        if(i==NBOATS-1){
            if(boat[i]==0)
                cout<<"";
            else
                cout<<boat[i];
        }
        else{
            if(boat[i]==0)
                cout<<"";
            else   
                cout<<boat[i]<<", ";
        }
    }
    //Displays the users board accounting for hits and misses
    g.uBoard();
}

//Adds values to boats 1-5
void filBoat(int a[], const int NBOATS, GameB &g){
    for(int n=0; n<NBOATS; n++){
        a[n]=rand()%g.getSize()+1;
    }
    //Keeps computer from repeating numbers when picking boats
    for(int i=0; i<=10000; i++){
        for(int n=0; n<NBOATS; n++){
            for(int j=0; j<NBOATS; j++){
                if(n==j)
                    cout<<"";
                else if(a[n]==a[j])
                    a[n]=rand()%g.getSize()+1;
            }
        }
    }
}

//Holds value for user boats
void usrBoat(int a[], const int NBOATS, GameB &g){
    cout<<"Please enter "<<NBOATS<<" values for your boats from 1-"<<g.getSize()<<endl;
    for(int n=0; n<NBOATS; n++){
        cout<<"Boat #"<<n+1<<") ";
        cin>>a[n];
    }
    //Input validation for all scenarios
    for(int i=0; i<=10000; i++){
        for(int n=0; n<NBOATS; n++){
            for(int j=0; j<NBOATS; j++){
                if(n==j)
                    cout<<"";
                else if(a[n]==a[j]){
                    cout<<"You entered "<<a[n]<<" twice, please enter a new number"<<endl;
                    cin>>a[n];
                }
            }
            while(a[n]>g.getSize()||a[n]<1){
                cout<<a[n]<<" is not between 1 and "<<g.getSize()<<endl;
                cout<<"Please enter a new number"<<endl;
                cin>>a[n];
            }
        }  
    }
}

//Function informs user whether or not they got a hit or a miss
void hitMiss(GameB &g, int boats[], const int NBOATS, int choice){
    cout<<endl<<"Which spot do you wanna shoot"<<endl;
    cin>>choice;
    while(choice<1||choice>g.getSize()){     //Input validation for keeping choice input between 1-30
        cout<<"Please pick a number between 1-"<<g.getSize()<<endl;
        cin>>choice;
    }
    bool hit=false;
    
    for(int n=0; n<NBOATS; n++){
        if(choice==boats[n]){
            boats[n]=0;
            hit=true;
        }
    }
    
    //Finds out if there was a hit or a miss
    g.uHitMiss(hit, choice);
}

//Used for the computers turn  
void cmpChce(GameB &g, int pBoats[], const int NBOATS){
    bool hit=false;
    int cChoice=rand()%g.getSize()+1;
    
    //Prevents computer from choosing same number 
    for(int i=0; i<g.getSize(); i++){
        for(int j=0; j<g.getSize(); j++){
            if(cChoice==g.getGues(j))
                cChoice=rand()%g.getSize()+1;
        }
    }
    //If choice is equal to one of the boats then it is a hit
    for(int n=0; n<NBOATS; n++){
        if(cChoice==pBoats[n]){
           pBoats[n]=0;
            hit=true;
        }
    }
    
    //Finds out if computer got a hit or a miss
    g.cHitMiss(hit, cChoice);
}

//Function that informs if game has been won or lost
bool winLose(int boats[], int pBoats[], GameB &g, bool loop, bool &win){
    //Informs the player that they have sunken all the ships
    if(boats[0]==0&& boats[1]==0&& boats[2]==0&& boats[3]==0&& boats[4]==0,
       boats[5]==0&& boats[6]==0&& boats[7]==0&& boats[8]==0&& boats[9]==0){  
        cout<<"\nYou sunk all the ships!\n";
        cout<<"You won!\n";
        win=true;
        return false;
    }
    //If all your boats get sunk you lose
    else if(pBoats[0]==0&& pBoats[1]==0&& pBoats[2]==0&& pBoats[3]==0&& pBoats[4]==0,
            pBoats[5]==0&& pBoats[6]==0&& pBoats[7]==0&& pBoats[8]==0&& pBoats[9]==0){
        cout<<"\nAll your ships have been sunk.\n";
        cout<<"You Lost! :(\n";
        return false;
    }
    //Informs the player that they have run out of turns and lost
    else if(g.getTurn()==g.getMaxT()){              
        cout<<"\nYou ran out of turns.\n";
        cout<<"You Lost! :(\n";
        return false;
    }
    else{
        g.setTurn();
        return true;
    }    
}

void hiScore(ofstream &oFile, ifstream &iFile, GameB &g){
    //Get the high score and put it into the variable check
    int check;
    iFile.open("Highscore.txt");
    iFile>>check;
    iFile.close();
    
    //Check if you got a high score
    if(check<g.getTurn()){
        cout<<"You did not beat the high score of "<<check<<" turns"<<endl;
    }
    if(check>g.getTurn()){
        cout<<"You hold the new high score of winning in "<<g.getTurn()<<" turns"<<endl;
        oFile.open("Highscore.txt", ios::trunc);
        oFile<<g.getTurn();
        oFile.close();
    }
    if(check==g.getTurn()){
        cout<<"You tied the high score of "<<g.getTurn()<<" turns"<<endl;
    }
}

void statFle(Stats & game, ofstream &oFile, ifstream &iFile, GameB &g){
    game.nTurn=g.getTurn();
    game.name=g.getName();
    
    //Opening the file and writing structure to file
    oFile.open("Stats.txt", ios::out | ios::binary);
    oFile.write(reinterpret_cast<char *>(&game), sizeof(game));
    oFile.close();
    
    //Writing the data back into the structure an displaying it
    iFile.open("Stats.txt", ios::in | ios::binary);
    if(iFile){
        iFile.read(reinterpret_cast<char *>(&game), sizeof(game));
        cout<<"\nPlayer Stats:\n______________";
        cout<<"\nPlayer name: "<<game.name<<endl;
        cout<<"Turn taken to win: "<<game.nTurn<<endl<<endl;
    }
    else
        cout<<"\nThe file was not opened properly\n";
    iFile.close();
}