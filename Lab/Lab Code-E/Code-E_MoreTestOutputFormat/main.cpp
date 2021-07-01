/* 
 * File:
 * Author: Christopher Delgado
 * Date: June 29th, 2021
 * Purpose: Further teesting of output format
 * Version:
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed

    //Declare variables or constants here
    //7 characters or less
    int num1,num2,num3,num4;
    
    //Initialize or input data here
    
    
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    cin>>num1;
    cin>>num2;
    cin>>num3;
    cin>>num4;
    
    //Format and display outputs here
    cout<<setw(9)<<num1<<setw(8)<<num1<<".0"<<setw(7)<<num1<<".00"<<endl;
    cout<<setw(9)<<num2<<setw(8)<<num2<<".0"<<setw(7)<<num2<<".00"<<endl;
    cout<<setw(9)<<num3<<setw(8)<<num3<<".0"<<setw(7)<<num3<<".00"<<endl;
    cout<<setw(9)<<num4<<setw(8)<<num4<<".0"<<setw(7)<<num4<<".00";
    
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}