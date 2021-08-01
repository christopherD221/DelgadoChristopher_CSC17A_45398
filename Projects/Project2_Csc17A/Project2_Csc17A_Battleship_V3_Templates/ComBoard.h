/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ComBoard.h
 * Author: Christopher Delgado
 *
 * Created on July 31, 2021, 7:46 PM
 */

#ifndef COMBOARD_H
#define COMBOARD_H
#include <valarray>

#include "GameB.h"

using namespace std;

template <class T>
class ComBoard : public GameB{
    private:
        T *compBrd;
    public:
        //Constructor
        ComBoard(string n, short s):GameB(n, s){
            compBrd=nullptr;
        }
        //Copy Constructor
        ComBoard(const ComBoard&);
        //Destructor
        ~ComBoard();
        
        //Fills computer boards with values
        void setBrd();
        //Displays board
        void prntBrd()const;
        //Displays whether there was a hit or a miss
        void hitMiss(bool, int);
};

template <class T>
ComBoard<T>::ComBoard(const ComBoard &obj){
    turn=obj.name;
    size=obj.size;
    maxTurn=obj.maxTurn;
    name=obj.name;
    compBrd= new T[size];
    for(int n=0; n<size; n++){
        compBrd[n]=0;
    }
}

template <class T>
ComBoard<T>::~ComBoard(){
    delete []compBrd;
}

template <class T>
void ComBoard<T>::setBrd(){
    //Dynamically allocates memory
    compBrd= new T [size];
    
    //Fills board
    for(int n=0; n<size; n++){
        compBrd[n]=n+1;
    }
}

template <class T>
void ComBoard<T>::prntBrd()const{
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


template <class T>
void ComBoard<T>::hitMiss(bool h, int c){
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


#endif /* COMBOARD_H */