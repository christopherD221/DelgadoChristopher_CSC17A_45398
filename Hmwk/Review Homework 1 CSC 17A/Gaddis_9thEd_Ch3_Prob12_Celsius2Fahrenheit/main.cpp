/* 
 * File:   main.cpp
 * Author: Christopher Delgado
 * Created on June 23rd, 2021
 * Purpose: Converting Celsius to Fahrenheit
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
    int   clsius;
    float fhrnht;
              
    //Mapping Process Inputs to Outputs
    cout<<"Input the degree celsius that you would like to be converted to fahrenheit"<<endl;
    cin>>clsius;
    fhrnht= (1.8)*clsius+32;
    
    //Display Outputs
    cout<<"Celsius = "<<clsius<<endl;
    cout<<"Fahrenheit = "<<fhrnht;
   
    //Clean Up
    
    //Exit stage right!
    return 0;
}