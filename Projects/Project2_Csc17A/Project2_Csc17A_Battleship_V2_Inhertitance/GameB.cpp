/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "GameB.h"
#include <iostream>
#include <iomanip>
#include <valarray>
using namespace std;

GameB::GameB(string n, short s){
    turn=1;
    size=s;
    maxTurn=size;
    name=n;
}

GameB::GameB(){
    turn=1;
    size=0;
    maxTurn=0;
    name="";
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