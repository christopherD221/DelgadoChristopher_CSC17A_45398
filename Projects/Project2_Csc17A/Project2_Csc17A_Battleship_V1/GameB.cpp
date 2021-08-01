/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "GameB.h"
#include <iostream>
#include <iomanip>
using namespace std;

GameB::GameB(){
    compBrd=nullptr;
    userBrd=nullptr;
    guess=nullptr;
    turn=1;
    maxTurn=0;
    size=0;
    name="";
}

GameB::~GameB(){
    delete []compBrd;
    delete []userBrd;
    delete []guess;
}

void GameB::setName(){
    cout<<"Please enter players first name\n";
    cin.ignore();
    getline(cin, name);
}

void GameB::setSize(){
    cout<<"Enter the size of the game board \n";
    //Size has to be 15 because the number of boats is 10
    cout<<"The game board must be at least 15 spaces big\n";
    cin>>size;
    while(size<15){
        cout<<"The game board must be at least 15 spaces big\n";
        cin>>size;
    }
    maxTurn=size;
    
    //Dynamically allocate memory
    compBrd= new int [size];
    userBrd= new int [size];
    guess= new int [size];
}

void GameB::setBrd(){
    for(int n=0; n<size; n++){
        compBrd[n]=n+1;
        userBrd[n]=n+1;
    }
}

void GameB::setTurn(){
    turn++;
}

string GameB::getName()const{
    return name;
}

short GameB::getSize()const{
    return size;
}

short GameB::getTurn()const{
    return turn;
}

short GameB::getMaxT()const{
    return maxTurn;
}

int GameB::getGues(int n)const{
    return guess[n];
}

void GameB::cBoard()const{
   for (int n=0; n<size; n++){
        //Displays heading of game board
        if(n==0){
            cout<<"Turn#: "<<turn<<"                     ";
            cout<<"Max Turn#: "<<maxTurn<<endl;
            cout<<setw(27)<<"Computer Board"<<endl;
        }
        //Outputs Values of game board and accounts for hits and misses
        if(compBrd[n]==0)
            cout<<"   "<<'x';
        else if(compBrd[n]==-1)
            cout<<"   "<<'o';
        else if(compBrd[n]<10)
            cout<<"   "<<compBrd[n];
        else 
            cout<<"  "<<compBrd[n];
        if(n%10==(10-1))
            cout<<endl;    
    }
    cout<<endl;
    
}
 
void GameB::uBoard()const{
    cout<<endl;
    for (int n=0; n<size; n++){
        if(n==0){
            cout<<setw(19)<<name<<"'s Board"<<endl;
        }
        if(userBrd[n]==0)
            cout<<"   "<<'x';
        else if(userBrd[n]==-1)
            cout<<"   "<<'o';
        else if(userBrd[n]<10)
            cout<<"   "<<userBrd[n];
        else 
            cout<<"  "<<userBrd[n];
        if(n%10==(10-1))
            cout<<endl;    
    }
}

void GameB::uHitMiss(bool h, int c){
    bool hit=h;
    int choice=c;
    
    if(hit==true){
        cout<<"-------------------------------------------"<<endl
            <<"You got a hit"<<endl;
        for(int i=0; i<size; i++){
            if(choice==compBrd[i]){
                compBrd[i]=0;
            }
        }   
    }
    if(hit==false){
        for(int j=0; j<size; j++){
            if(choice==compBrd[j]){
                cout<<"-------------------------------------------"<<endl
                    <<"That was a miss"<<endl;
                compBrd[j]=-1;
            }
        }
    }
}

void GameB::cHitMiss(bool h, int c){
    bool hit=h;
    int choice=c;
    
    if(hit==true){
        cout<<"Enemy got a hit at "<<choice<<endl;
        //Marks on board where the hit occurred   
        for(int i=0; i<size; i++){
            if(choice==userBrd[i]){
                guess[i]=userBrd[i];
                userBrd[i]=0;
            }
        }   
    }
    if(hit==false){
        cout<<"Enemy missed their shot at "<<choice<<endl;   
        //Marks where miss occurred
        for(int j=0; j<size; j++){
            if(choice==userBrd[j]){
                guess[j]=userBrd[j];
                userBrd[j]=-1;
            }
        }
    }
}