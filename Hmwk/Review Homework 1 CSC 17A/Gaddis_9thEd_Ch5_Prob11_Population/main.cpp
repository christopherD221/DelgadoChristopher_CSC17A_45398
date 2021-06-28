/* 
 * File:   main.cpp
 * Author: Christopher Delgado
 * Created on June 25th, 2021
 * Purpose: Calculate population increase over time
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include<iomanip>     //Formatting library
using namespace std;  //Libraries compiled under std

//User Level Libraries

//Global Constants - Science/Math Related
//Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Variable Declarations
    int   nDays;
    float popult;
    float popInc;
    
    //Variable Initialization
              
    //Mapping Process Inputs to Outputs
    cout<<"Enter the number of staring organisms. This number has to be 2 or greater \n";
    cin>>popult;
    while(popult<2){
        cout<<"Please enter a number >= 2\n";
        cin>>popult;        
    }
    cout<<"Enter average daily population increase in percentages\n";
    cin>>popInc;
    cout<<"Enter the number of days that the population will multiply\n";
    cin>>nDays;
    cout<<"Day 0 population = "<<popult<<endl;
    
    //Display Outputs
    //makes population increase percentage  easier to work with
    popInc/=100;
    
    for(int n=1; n<=nDays; n++){
        popult=(popult*popInc)+popult;
        cout<<setprecision(0)<<fixed;
        cout<<"Day "<<n<<" population = "<<popult<<endl;
    }
    
    //Clean Up
    
    //Exit stage right!
    return 0;
}