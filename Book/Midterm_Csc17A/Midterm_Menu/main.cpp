/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Purpose:  Menu using Functions,
 *           extend for midterm
 */

//System Libraries
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

//User Libraries
//Structure used in Problem 1
struct Chkings{
    int accNum;
    string name;
    string address;
    float begBal;
    float wthdraw;
    float deposit;
};

//Structure used in Problem 2
struct Pay{
    string empName;   //Employee name
    int hrsWrkd;      //Hours worked by employee
    int payRate;      //Pay rate per hour
    int totPay;       //Total paid to employee
};

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();

//Functions For Problem #1
void filData(Chkings [], int, float &, float &);
void prntDta(Chkings [], int, float);

//Functions For Problem #2
void filData(Pay [], int);
void calcPay(Pay [], int);
void prntChk(Pay [], int, string, string);
void cnvtNum(Pay [], int);

//Functions For Problem #5
int nFact(int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='6');
    
    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Menu
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 1
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm1(){
    cout<<"Problem 1"<<endl;
    //Declare variables here
    Chkings *account=0; //Structure pointer for dynamic allocation 
    short counter=0;    //holds the amount of people that will input data
    float wthdTot;      //Total amount of withdraws
    float depTot;       //Total amount of deposits
    float accTot;       //Account total after all withdraws and deposits
    
    //Map inputs to outputs here, i.e. the process
    cout<<"Enter the number of people that will be checking their accounts\n";
    cin>>counter;
    account= new Chkings[counter];
    
    //Display the results
    for(int n=0; n<counter; n++){
        //Resets totals after every successful loop
        wthdTot=0;
        depTot=0;
        
        filData(account, n, wthdTot, depTot);
        accTot= account[n].begBal+depTot-wthdTot;
        prntDta(account, n, accTot);
    }
    
    //clean up
    delete []account;
}

void filData(Chkings a[], int n, float &wT, float &dT){
    int checks=0;
    int deposit=0;
    
    cout<<"\nAccount info for person #"<<n+1<<endl;
    cout<<"Enter your account number: ";
    cin>>a[n].accNum;
    while((a[n].accNum/10000)>9 || (a[n].accNum/10000)==0){
        cout<<"Please enter a 5 digit number\n";
        cin>>a[n].accNum;
    }
    cout<<"Enter name on the account: ";
    cin.ignore();
    getline(cin, a[n].name);
   
    cout<<"Enter the address on the account: ";
    getline(cin, a[n].address);
    
    cout<<"Enter the account balance at the beginning of the month: ";
    cin>>a[n].begBal;
    
    cout<<"How many checks did you write this month: ";
    cin>>checks;
    for(int i=0; i<checks; i++){
        cout<<"Enter the amount from check "<<i+1<<": ";
        cin>>a[n].wthdraw;
        wT+=a[n].wthdraw;
    }
    
    cout<<"How many deposits did you make this month: ";
    cin>>deposit;
    for(int i=0; i<deposit; i++){
        cout<<"Enter the amount from deposit "<<i+1<<": ";
        cin>>a[n].deposit;
        dT+=a[n].deposit;
    }
}

void prntDta(Chkings a[], int n, float tot){
    cout<<"\nAccount number: "<<a[n].accNum<<endl;
    cout<<"Name on the account: "<<a[n].name<<endl;
    cout<<"Address: "<<a[n].address<<endl;
    cout<<"Beginning balance: $"<<a[n].begBal<<endl;
    cout<<"Your account total is: "<<tot<<endl;
    if(tot<0){
        cout<<"There is an additional $50 charge for being overdraw\n";
        cout<<"Your adjusted account value is: "<<tot-50<<endl<<endl;
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 2
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm2(){
    cout<<"Problem 2"<<endl;
    //Declare variables here
    int numEmp;
    string compNme;
    string compAdd;    //Holds company address
    Pay *empPay=0;
    
    //Initialize variables here
    
    //Map inputs to outputs here, i.e. the process
    cout<<"Enter the name of the company\n";
    cin.ignore();
    getline(cin, compNme);
    cout<<"Enter the address of the company\n";
    getline(cin, compAdd);
    cout<<"Enter the amount of employees that will be payed\n";
    cin>>numEmp;
    empPay= new Pay [numEmp];
    
    //Display the results
    for(int n=0; n<numEmp; n++){
        cout<<"\nEnter the info for employee #"<<n+1<<endl;
        filData(empPay, n);
        calcPay(empPay, n);
        prntChk(empPay, n, compNme, compAdd);
    }
    
    //clean up
    delete []empPay;
}

void filData(Pay p[], int n){
    cout<<"Enter the employees name: ";
    cin.ignore();
    getline(cin, p[n].empName);
    
    cout<<"Enter the amount of hours worked by the employee: ";
    cin>>p[n].hrsWrkd;
    while(p[n].hrsWrkd<0){
        cout<<"Cannot enter a number less than 0\n";
        cout<<"Please enter it again\n";
        cin>>p[n].hrsWrkd;        
    }
    
    cout<<"Enter the pay rate per hour of the employee: ";
    cin>>p[n].payRate;
    while(p[n].payRate<0){
        cout<<"Cannot enter a number less than 0\n";
        cout<<"Please enter it again\n";
        cin>>p[n].payRate;        
    }
}

void calcPay(Pay p[], int n){
    if(p[n].hrsWrkd<=20){
        p[n].totPay= p[n].hrsWrkd*p[n].payRate;
    }
    if(p[n].hrsWrkd>=21 && p[n].hrsWrkd<=40){
        p[n].totPay= (20*p[n].payRate)+((p[n].hrsWrkd-20)*(p[n].payRate*2));
    }
    if(p[n].hrsWrkd>=41){
        p[n].totPay= (20*p[n].payRate)+(20*(p[n].payRate*2))+((p[n].hrsWrkd-40)*(p[n].payRate*3)); 
    }
}

void prntChk(Pay p[], int n, string name, string addrs){
    cout<<fixed<<setprecision(2);
    cout<<"\n"<<name<<endl;
    cout<<addrs<<endl;
    cout<<p[n].empName<<" $";
    cout<<p[n].totPay<<endl;
    cnvtNum(p, n);
    cout<<"\n____________\n";
}

void cnvtNum(Pay p[], int n){
    unsigned short n1000s, n100s, n10s, n1s;
    n1000s= p[n].totPay/1000;
    n100s= p[n].totPay%1000/100;
    n10s= p[n].totPay%100/10;
    n1s= p[n].totPay%10;
    
    cout<<(n1000s==9?"NINE THOUSAND ":
           n1000s==8?"EIGHT THOUSAND ":
           n1000s==7?"SEVEN THOUSAND ":
           n1000s==6?"SIX THOUSAND ":
           n1000s==5?"FIVE THOUSAND ":
           n1000s==4?"FOUR THOUSAND ":
           n1000s==3?"THREE THOUSAND ":
           n1000s==2?"TWO THOUSAND ":
           n1000s==1?"ONE THOUSAND ":"");
    
    cout<<(n100s==9?"NINE HUNDRED ":
           n100s==8?"EIGHT HUNDRED ":
           n100s==7?"SEVEN HUNDRED ":
           n100s==6?"SIX HUNDRED ":
           n100s==5?"FIVE HUNDRED ":
           n100s==4?"FOUR HUNDRED ":
           n100s==3?"THREE HUNDRED ":
           n100s==2?"TWO HUNDRED ":
           n100s==1?"ONE HUNDRED ":"");
    
    cout<<(n10s==9?"NINETY ":
           n10s==8?"EIGHTY ":
           n10s==7?"SEVENTY ":
           n10s==6?"SIXTY ":
           n10s==5?"FIFTY ":
           n10s==4?"FOURTY ":
           n10s==3?"THIRTY ":
           n10s==2?"TWENTY ":"");
    
    if(n10s==1){
        cout<<(n1s==9?"NINETEEN":
               n1s==8?"EIGHTTEEN":
               n1s==7?"SEVENTEEN":
               n1s==6?"SIXTEEN":
               n1s==5?"FIFTHTEEN":
               n1s==4?"FOURTEEN":
               n1s==3?"THIRTEEN":
               n1s==2?"TWELVE":
               n1s==1?"ELEVEN":"");
    }else{
        cout<<(n1s==9?"NINE":
               n1s==8?"EIGHT":
               n1s==7?"SEVEN":
               n1s==6?"SIX":
               n1s==5?"FIVE":
               n1s==4?"FOUR":
               n1s==3?"THREE":
               n1s==2?"TWO":
               n1s==1?"ONE":"");
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 3
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm3(){
    cout<<"Problem 3"<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 4
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm4(){
    cout<<"problem 4"<<endl;
}


/*//////////////////////////////////////////
 *                                         *
 *       Problem 5                         *
 *                                         *
 *                                         *
 /////////////////////////////////////////*/ 
void prblm5(){
    char charVar='0';
    int counter=2;
    
    //Char Range
    while(charVar>=0){
        charVar=nFact(counter);
        counter++;
    }
    cout<<"n! limit for a char (Byte Variable) is "<<counter-2<<endl;
    cout<<"n! limit for a unsigned char is 5\n";
    cout<<"n! limit for a short is 7\n";
    cout<<"n! limit for a unsigned short is 8\n";
    cout<<"n! limit for an int is 12\n";
    cout<<"n! limit for a unsigned int is 12\n";
    cout<<"n! limit for a long int is 12\n";
    cout<<"n! limit for a unsigned long int is 12\n";
    cout<<"n! limit for a long long int is 20\n";
    cout<<"n! limit for a unsigned long long int is 21\n";
    cout<<"n! limit for a float is 34\n";
    cout<<"n! limit for a double is 170\n";
}

int nFact(int n){
    int temp=1;
    for(int i=2; i<=n; i++){
        temp*=i;
    }
    return temp;
}

/*//////////////////////////////////////////
 *                                         *
 *       Problem 6                         *
 *                                         *
 *                                         *
 /////////////////////////////////////////*/ 
void prblm6(){
    cout<<"Part a)\n";
    cout<<"51.1875 base 10 = 110011.0011 base 2\n";
    cout<<"                = 63.14 base 8\n";
    cout<<"                = 33.3 base 16\n";
    cout<<"In NASA format: CCC00006\n\n";
    
    cout<<"3.19921875 base 10 = 11.00110011 base 2\n";
    cout<<"                   = 3.146 base 8\n";
    cout<<"                   = 3.33 base 16\n";
    cout<<"In NASA format: CCC00002\n\n";
    
    cout<<"0.2 base 10 = 0.(0011) base 2\n";
    cout<<"            = 0.(14) base 8\n";
    cout<<"            = 0.(3) base 16\n";
    cout<<"In NASA format: CCCCCCFE\n\n";
    
    cout<<"Part b)\n";
    cout<<"-51.1875 base 10 in NASA format: 334400006\n";
    cout<<"-3.19921875 base 10 in NASA format: 33400002\n";
    cout<<"-0.2 base 10 in NASA format: 333334FE\n\n";
    
    cout<<"Part c)\n";
    cout<<"69999902 in NASA format converted to base 10 = 1.640625 base 10\n";
    cout<<"69999903 in NASA format converted to base 10 = 3.28125 base 10\n";
    cout<<"966667FF in NASA format converted to base 10 = 1.17500007152557373047 base 10\n\n";
}