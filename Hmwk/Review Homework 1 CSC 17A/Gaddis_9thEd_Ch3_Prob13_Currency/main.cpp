/* 
 * File:   main.cpp
 * Author: Christopher Delgado
 * Created on June 25th, 2021
 * Purpose: Converts US currency to yen and euros
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include<iomanip>     //Format Library
using namespace std;  //Libraries compiled under std

//User Level Libraries

//Global Constants - Science/Math Related
//Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Variable Declarations
    int   choice;
    float dollars;
    const float YENPDOL=98.93;
    const float EROPDOL=0.74;
    float convsin;
    
    //Variable Initialization
              
    //Mapping Process Inputs to Outputs
    cout<<"Do you want to convert dollars to yen, or dollars to euros?\n";
    cout<<"1)Dollars to yen\n"<<"2)Dollars to euros\n";
    cin>>choice;
    while(choice<1||choice>2){
        cout<<"Please select between 1 or 2\n";
        cin>>choice;
    }
    cout<<"Input the dollar amount\n";
    cin>>dollars;
    while(dollars<0){
        cout<<"You cannot have negative dollars\n"<<"Please reenter dollars amount\n";
        cin>>dollars;
    }
    
    //Display Outputs
    if(choice==1){
        convsin=dollars*YENPDOL;
        cout<<"Dollars = "<<dollars<<endl;
        cout<<"Yen     = "<<setprecision(2)<<fixed<<convsin<<endl;
    }
    if(choice==2){
        convsin=dollars*EROPDOL;
        cout<<"Dollars = "<<dollars<<endl;
        cout<<"Yen     = "<<setprecision(2)<<fixed<<convsin<<endl;
    }    
    
    //Clean Up
    
    //Exit stage right!
    return 0;
}