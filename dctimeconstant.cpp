#include "dctimeconstant.h"
#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;

dctimeconstant::dctimeconstant()
{

}

void dctimeconstant::TimeCRC(){
double R,C,Tc;
cout<<"Enter the values of the resistance and capacitance respectively."<<endl;
cin>>R>>C;
Tc=R*C;
cout<<"The time constant is "<<Tc<<"."<<endl;
}

void dctimeconstant::TimeCRL(){
double R,L,Tl;
cout<<"Enter the values of the resistance and inductance respectively."<<endl;
cin>>R>>L;
Tl=L/R;
cout<<"The time constant is "<<Tl<<"."<<endl;
}

void dctimeconstant::TerminalVRC(){
double Vs,t,Vt,R,C;
cout<<"Enter values for supply voltage, time, resistance and capacitance respectively."<<endl;
cin>>Vs>>t>>R>>C;
Vt=Vs*(1-(exp(-t/(R*C))));
cout<<"The terminal voltage for the RC network is "<<Vt<<"."<<endl;
}

void dctimeconstant::TerminalVRL(){
double Vs,t,Vt,R,L;
cout<<"Enter values for the supply voltage, time, resistance and inductance respectively."<<endl;
cin>>Vs>>t>>R>>L;
Vt=Vs*(exp(-t/(L/R)));
cout<<"The terminal voltage for the RL network is "<<Vt<<"."<<endl;
}
