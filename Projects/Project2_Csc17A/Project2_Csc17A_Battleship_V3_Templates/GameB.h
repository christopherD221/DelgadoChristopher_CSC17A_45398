/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameB.h
 * Author: Christopher Delgado
 *
 * Created on July 30, 2021, 10:29 PM
 */

#ifndef GAMEB_H
#define GAMEB_H
#include <string>

using namespace std;

class GameB{
    protected:
        //int *guess;       //Array that holds all of the computers past guesses
        short turn;       //Current turn
        short maxTurn;    //Max turn allowed in game
        short size;       //Size of game boards
        string name;      //Holds the name of the player
    public:
        //Constructor passes in name and size
        GameB(string, short);
        GameB();
   
        //Fills user and computer boards with values
        virtual void setBrd()=0;
        //Increments turn by 1 every time it is called
        void setTurn();
        
        //Accessor Functions
        string getName()const;
        short getTurn()const;
        short getMaxT()const;
        short getSize()const;
        
        //Outputs computer and user boards
        virtual void prntBrd()const=0;
        
        //Determines whether or not computer or user got a hit
        virtual void hitMiss(bool, int)=0;
};

#endif /* GAMEB_H */

