/* 
 * File:   main.cpp
 * Author: Christopher Delgado
 * Created on June 27th, 2021
 * Purpose: COnverting fahrenheit to celsius using a function
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <iomanip>
using namespace std;  //Libraries compiled under std

//User Level Libraries

//Global Constants - Science/Math Related
//Conversions, Higher Dimensions

//Function Prototypes
void celsius(int, float, float&);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Variable Declarations
    int   fahrht;
    float cel;
    float mult;
    
    //Variable Initialization
    mult=(5.0f/9.0f);
              
    //Mapping Process Inputs to Outputs
    cout<<mult<<endl;
    //Display Outputs
    for(int n=0; n<=20; n++){
        fahrht=n;
        celsius(fahrht, mult, cel);
    }
    
    //Clean Up
    
    //Exit stage right!
    return 0;
}

void celsius (int fah, float m, float& celsus){
    celsus=m*(fah-32);
    cout<<fixed<<setprecision(2);
    cout<<"Fahrenheit = "<<fah<<"      Celsius = "<<celsus<<endl;
}