#include "dcresistance.h"
#include<iostream>
#include<cmath>
#include<math.h>

using namespace std;

dcresistance::dcresistance()
{

}

void dcresistance::ToResistance(){
int t;
cout<<"Select the type of circuit:"<<endl;
cout<<"1-Series"<<endl;
cout<<"2-Parallel"<<endl;
cout<<"3-Series-Parallel"<<endl;
cin>>t;
if (t==1){
    se();
}
else{
    if(t==2){
        pa();
    }
    else{
        if (t==3){
            sepa();
        }
        else{
            cout<<"Error!"<<endl;
        }
    }
}
}

double dcresistance::seR(){
int n;
double ans;
cout<<"Enter the number of resistors in series."<<endl;
cin>>n;
double SAr[n]={0};
cout<<"Enter the value of each resistor."<<endl;
for(int i=0;i<n;i++){
cin>>SAr[i];
}
for(int i=0;i<n;i++){
R+=SAr[i];
}
return ans;
}

double dcresistance::paR(){
int n;
double P, ans;
cout<<"Enter the number of resistors in parallel."<<endl;
cin>>n;
double PAr[n]={0};
cout<<"Enter the value of each resistor."<<endl;
for(int i=0;i<n;i++){
cin>>PAr[i];
}
for(int i=0;i<n;i++){
P+=1/PAr[i];
}
ans=1/P;
return ans;
}

void dcresistance::se(){
int n;
cout<<"Enter the number of resistors in series."<<endl;
cin>>n;
double SAr[n]={0};
cout<<"Enter the value of each resistor."<<endl;
for(int i=0;i<n;i++){
cin>>SAr[i];
}
for(int i=0;i<n;i++){
R+=SAr[i];
}
cout<<"Total series resistance is "<<R<<"."<<endl;
}


void dcresistance::pa(){
int n;
double P;
cout<<"Enter the number of resistors in parallel."<<endl;
cin>>n;
double PAr[n]={0};
cout<<"Enter the value of each resistor."<<endl;
for(int i=0;i<n;i++){
cin>>PAr[i];
}
for(int i=0;i<n;i++){
P+=1/PAr[i];
}
R=1/P;
cout<<"Total parallel resistance is "<<R<<"."<<endl;
}



void dcresistance::sepa(){
int N=0;
cout<<"To calculate the total resistance for the circuit,"<<endl;
cout<<"the equation for the equivalent resistance will have to"<<endl;
cout<<"to be simplified and solved in segments."<<endl;
cout<<"Starting with the smallest backet (B.E.D.M.A.S)."<<endl;
while (N!=3){
    cout<<"Select the type of connection in the branch or '3' for total:"<<endl;
    cout<<"1-series"<<endl;
    cout<<"2-parallel"<<endl;
    cout<<"3-total"<<endl;
    cin>>N;
    if(N==1){
        R+=seR();
    }
    else{
        if(N==2){
            R+=paR();
        }
        else{
            if(N==3){
                cout<<"The total resistance in the series parallel is "<<R<<"."<<endl;
            }
            else{
                cout<<"Error!"<<endl;
            }
        }
    }
}


}

void dcresistance::ToCurrent(){
 double V;
 cout<<"Enter value of total voltage."<<endl;
 cin>>V;
 I=V/R;
 cout<<"The total current drawn is "<<I<<"."<<endl;
}

void dcresistance::ToPower(){
double P;
P=(I*I)*R;
cout<<"The total power is "<<P<<"."<<endl<<endl;
}


