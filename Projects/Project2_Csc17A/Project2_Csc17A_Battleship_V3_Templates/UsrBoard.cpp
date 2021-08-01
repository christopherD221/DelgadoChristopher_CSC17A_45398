/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "UsrBoard.h"
#include <iostream>
#include <iomanip>

using namespace std;

UsrBoard::~UsrBoard(){
    delete []userBrd;
    delete []guess;
}

void UsrBoard::setBrd(){
    //Dynamically allocates memory
    userBrd= new int [size];
    guess= new int [size];
    
    //Fills board
    for(int n=0; n<size; n++){
        userBrd[n]=n+1;
    }
}

void UsrBoard::prntBrd()const{
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

void UsrBoard::hitMiss(bool h, int c){
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

int UsrBoard::getGues(int n)const{
    return guess[n];
}