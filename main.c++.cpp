#include<iostream>
#include<cmath>
#include<math.h>
#include "dctimeconstant.h"
#include "dcresistance.h"
#include "acresistance.h"

using namespace std;

int main(){ //driver function of the program
dcresistance d; // object that links the main function with dcreesistance class
dctimeconstant t; //object that links the main function wt
acresistance a;
int N=1;
while((N!=0)&&(N<7)){
cout<<"Welcome to the Electrical Networks problem solver!"<<endl;
cout<<"Select the problem you wish to solve, or enter anyother number to end program:"<<endl;
cout<<"1-Total resistance, current and power for a dc circuit"<<endl;
cout<<"2-Time constant for a series/parallel dc RC network"<<endl;
cout<<"3-Terminal voltage in a series/parallel dc RC network"<<endl;
cout<<"4-Time constant for a series/parallel dc RL network"<<endl;
cout<<"5-Terminal voltage in a series/parallel dc RL network"<<endl;
cout<<"6-Total resistance, current and power for a ac circuit"<<endl;
cin>>N;


if (N==1){
    d.ToResistance();
    d.ToCurrent();
    d.ToPower(); }
else{ if (N==2){
    t.TimeCRC();
}
    else{
        if (N==3){
            t.TerminalVRC();
        }
        else{
            if (N==4){
                t.TimeCRL();
            }
            else{
                if (N==5){
                    t.TerminalVRL();
                }
                else{
                    if (N==6){
                    a.ToResistance();
                    a.ToCurrent();
                    a.ToPower();
                    }
                    else{
                        cout<<"Program terminated"<<endl;
                    }
                }
            }
        }
}
}


}
}
