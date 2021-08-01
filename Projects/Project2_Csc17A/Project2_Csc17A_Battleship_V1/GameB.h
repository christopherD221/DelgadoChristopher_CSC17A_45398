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
    private:
        int *compBrd;     //Array that displays computers board
        int *userBrd;     //Array that displays user board
        int *guess;       //Array that holds all of the computers past guesses
        short turn;       //Current turn
        short maxTurn;    //Max turn allowed in game
        short size;       //Size of game boards
        string name;      //Holds the name of the player
    public:
        //Constructor
        GameB();
        //Destructor
        ~GameB();
        //Sets the name variable
        void setName();
        //User inputs size and pointers get dynamically allocated 
        void setSize();
        //Fills user and computer boards with values
        void setBrd();
        //Increments turn by 1 every time it is called
        void setTurn();
        
        //Accessor Functions
        string getName()const;
        short getTurn()const;
        short getMaxT()const;
        short getSize()const;
        int getGues(int)const;
        
        //Outputs computer and user boards
        void cBoard()const;
        void uBoard()const;
        
        //Determines whether or not computer or user got a hit
        void uHitMiss(bool, int);
        void cHitMiss(bool, int);
};

#endif /* GAMEB_H */

