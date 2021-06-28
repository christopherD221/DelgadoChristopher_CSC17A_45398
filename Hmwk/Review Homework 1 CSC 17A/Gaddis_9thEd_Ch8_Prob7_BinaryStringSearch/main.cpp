/* 
 * File:   main.cpp
 * Author: Christopher Delgado
 * Created on June 27th, 2021
 * Purpose: Binary search of a string
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include<string>
using namespace std;  //Libraries compiled under std

//User Level Libraries

//Global Constants - Science/Math Related
//Conversions, Higher Dimensions

//Function Prototypes
void selectionSort(string [], int);
void swap(string&, string&);
int binarySearch(string [], int, string);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Random Number Seed Set Here
    
    //Variable Declarations
    int choice;
    int locate;
    string usrNme;
    const int nNAMES=20;
    string names[nNAMES]={"Collins, Bill", "Smith, Bart", "Allen, Jim", "Griffen, Jim",
                          "Stamey, Marty", "Rose, Geri", "Taylor, Terri", "Johnson, Jill",
                          "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", "James, Jean", 
                          "Weaver, Jim", "Poore, Bob", "Rutherford, Greg", "Javens, Renee",
                          "Harrison, Rose", "Setzer, Cathy", "Pike, Gordon", "Holland, Beth"};
    
    //Variable Initialization
              
    //Mapping Process Inputs to Outputs
    cout<<"Choose a number from this list that corresponds to a name \n";
    for(int n=0; n<20; n++){
        cout<<n+1<<") "<<names[n]<<endl;
    }
    cout<<endl;
    cin>>choice; 
    for(int i=0; i<nNAMES; i++){
        if(choice==i){
            usrNme=names[i-1];
        }
    }
    cout<<usrNme<<endl;
    
    selectionSort(names, nNAMES);
    locate=binarySearch(names, nNAMES, usrNme);
    
    //Display Outputs
    for(int n=0; n<20; n++){
        cout<<n+1<<") "<<names[n]<<endl;
    }
    
    if(locate==-1)
        cout<<"That name does not exists in this array\n";
    else{
        cout<<"\nThe name "<<usrNme<<" was found at element "<<locate+1<<endl;
    }
    
    //Clean Up
    
    //Exit stage right!
    return 0;
}

void selectionSort(string n[], int size){
    string minVal;
    int minIndx;
    
    for(int start=0; start<(size-1); start++){
        minIndx=start;
        minVal =n[start];
        for(int indx=start+1; indx<size; indx++){
            if(n[indx]< minVal){
                minVal=n[indx];
                minIndx=indx;
            }
        }
        swap(n[minIndx], n[start]);
    }
}

void swap(string& a, string& b){
    string temp=a;
    a=b;
    b=temp;
}

int binarySearch(string n[], int size, string uNme){
    int first=0,
        last=size-1,
        middle,
        postion=-1;
    bool found=false;
   
    while(found==false&& first<=last){
        middle=(first+last)/2;
        if(n[middle]==uNme){
            found=true;
            postion=middle;
        }
        else if(n[middle]>uNme)
            last=middle-1;
        else
            first=middle+1;      
    }
    return postion;
}