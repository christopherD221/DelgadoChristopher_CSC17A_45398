/* 
 * File:   main.cpp
 * Author: Christopher Delgado 
 * Created on June 25th, 2021
 * Purpose: Tells how many days in a month
 */

//System Level Libraries
#include <iostream>   //I/O Library
using namespace std;  //Libraries compiled under std

//User Level Libraries

//Global Constants - Science/Math Related
//Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Variable Declarations
    int month, year;
    int days;
    
    //Variable Initialization
              
    //Mapping Process Inputs to Outputs
    cout<<"This program tells you how many days are in a month\n";
    cout<<"Enter a month (1-12)\n";
    cin>>month;
    while(month<1||month>12){
        cout<<"Enter a number 1-12 for the month you would like\n";
        cin>>month;
    }
    cout<<"Enter a year\n";
    cin>>year;
    
    //Display Outputs
    if(month==2){
        if((year%100==0 && year%400==0)||(year%100!=0 && year%4==0)){
            days=29;
        }else{
            days=28;
        }
    }else{
        if(month==4||month==6||month==9||month==11)
            days=30;      
        else
            days=31;     
    }
    cout<<"Days = "<<days;
    
    //Clean Up
    
    //Exit stage right!
    return 0;
}