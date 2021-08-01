/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UsrBoard.h
 * Author: Christopher Delgado
 *
 * Created on July 31, 2021, 9:12 PM
 */

#ifndef USRBOARD_H
#define USRBOARD_H
#include "GameB.h"

class UsrBoard : public GameB{
    private:
        int *userBrd;
        int *guess;       //Array that holds all of the computers past guesses
    public:
        //Constructor that passes values into base class
        UsrBoard(string n, int s):GameB(n,s){
            userBrd=nullptr;
        }
        //Destructor
        ~UsrBoard();
        
        //Fills board with values
        void setBrd();
        //Displays board
        void prntBrd()const;
        //Displays whether there was a hit or a miss
        void hitMiss(bool, int);
        //Returns value of guess array
        int getGues(int)const;
};



#endif /* USRBOARD_H */

