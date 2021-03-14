#include "acresistance.h"
#include<iostream>
#include<cmath>
#include<math.h>

using namespace std;

acresistance::acresistance() //constructor
{

}void acresistance::ToResistance(){//this  is the total A.C resistance function which serves  to  display to the user the different circuit can be solved.
int t;
cout<<"Select the type of circuit:"<<endl;
cout<<"1-Series"<<endl;
cout<<"2-Parallel"<<endl;
cout<<"3-Series-Parallel"<<endl;
cin>>t;// accept the user input
if (t==1){
    se();  //calls the series A.c function within the program
}
else{
    if(t==2){
        pa(); // calls the parallel A.c function within the program
    }
    else{
        if (t==3){
                sepa(); // calls the series-parallel A.c function within he program

        }
        else{
            cout<<"Error!"<<endl; // displays error if the if its fails the pervious criteria above
        }
    }
}
}

void acresistance::seR(){  // This is series function which will be call by the series-parallel function.
int n,l,m;
double R,Xc,Xl;
cout<<"Enter the number of resistors in series."<<endl;
cin>>n; // accepts the user input for the number of resistor in series .
if (n!=0) {
double SAr1[n]={0};
cout<<"Enter the value of each resistor."<<endl;
for(int i=0;i<n;i++){ // Receive the value of each resistor or aid of collection of resistor values
cin>>SAr1[i];
}
for(int i=0;i<n;i++){ // This for loop is used to add the resistor values respectively.
R+=SAr1[i];
}
}
cout<<"Enter the number of inductors in series."<<endl; // instrusctions given  to the user how to execute the program respectively
cin>>l;  // accept the user information on the number of inductor in series respectively.
if (l!=0) {
double SAr2[l]={0};
cout<<"Enter the value of each inductor."<<endl;
for(int i=0;i<l;i++){ // This for loop aids in the collection of the inductor values respectively
cin>>SAr2[i];
}
for(int i=0;i<l;i++){
Xl+=2*M_PI*fs*SAr2[i];
}
}
cout<<"Enter the number of capacitors in series."<<endl; // instructions given to the user  how to execute the program respectively
cin>>m;
if (m!=0){
double SAr3[m]={0};
cout<<"Enter the value of each capacitor."<<endl;
for(int i=0;i<m;i++){ // This for loop aids in the collection of the capacitor values in series respectively
cin>>SAr3[i];
}
for(int i=0;i<m;i++){ //   This for loop sum the values capacitive reactance within the circuit.
Xc+=1/(2*M_PI*fs*SAr3[i]);
}
}
magZ=sqrt(pow(R,2)+pow((Xl-Xc),2)); // this stores of the  magnitude of the impemance
angZ=atan((Xl-Xc)/R); // this stores angle of the impedance
realZ+=R;// this stores the real value of the impedance
imagZ+=Xl-Xc; // tihs sotres the iminaginary parto f the impedance
}

void acresistance::paR(){ // this is a parallel function that will be called by the series parallel function respectively
int N;
double G,B,mY,aY,aZ,mZ;
cout<<"Enter the number of branches in parallel."<<endl;
cin>>N;
double P1[N]={0};
double P2[N]={0};
double P3[N]={0};
double P4[N]={0};
double P5[N]={0};
double P6[N]={0};
double P7[N]={0};
double P8[N]={0};
cout<<"Enter the value for the frequency."<<endl;
cin>>fs;
for(int i=0;i<N;i++){ // this for loop  accepts the value for the various component in a parallel branch
    cout<<"Enter the value of the resistance, capacitance and inductance"<<endl;
    cout<<"in this branch respectively."<<endl;
    cin>>P1[i];
    cin>>P2[i];
    cin>>P3[i];
}
for(int i=0;i<N;i++){ // this for loop serve to store the various values for the capacitive and inductive reactance repsectively
  if (P2[i]!=0){
           P4[i]=1/(2*M_PI*fs*P2[i]);
            }
    P5[i]=2*M_PI*fs*P3[i];
        }
for(int i=0;i<N;i++){ // this for loop serve to store the difference between the values of the reactance
        P6[i]=P5[i]-P4[i];
}
for(int i=0;i<N;i++){ //  this  loop serve to store calcualted values for the magnitude and ratio of reactance values
            if (P1[i]!=0){
        P7[i]=(180/M_PI)*P6[i]/P1[i];
            }
        P8[i]=pow((pow(P1[i],2)+pow(P6[i],2)),0.5);
    }

for(int i=0;i<N;i++){
G+=P8[i]*cos(P7[i]); // this line sum the conductance of the admittance
B+=P8[i]*sin(P7[i]); // this line serve to  sum susceptnce
}
mY=pow((pow(G,2)+pow(B,2)),0.5); //calculate the magnitude of the admittance
aY=(180/M_PI)*atan(B/G);  // calculate the angel of the admittance
mZ=1/mY;
aZ=1/aY;
realZ=mZ*cos(aZ);
imagZ=mZ*sin(aZ);
magZ+=mZ;
angZ+=aZ;
}

void acresistance::se(){ // This series function called by the total  A.C resistance function
int n,l,m;
double R,Xc,Xl,f;
cout<<"Enter the value for the frequency."<<endl;
cin>>f;
cout<<"Enter the number of resistors in series."<<endl;
cin>>n;
if (n!=0) {
double SAr1[n]={0};
cout<<"Enter the value of each resistor."<<endl;
for(int i=0;i<n;i++){
cin>>SAr1[i];
}
for(int i=0;i<n;i++){
R+=SAr1[i];
}
}
cout<<"Enter the number of inductors in series."<<endl;
cin>>l;
if (n!=0) {
double SAr2[l]={0};
cout<<"Enter the value of each inductor."<<endl;
for(int i=0;i<l;i++){
cin>>SAr2[i];
}
for(int i=0;i<l;i++){
Xl+=2*M_PI*f*SAr2[i];
}
}
cout<<"Enter the number of capacitors in series."<<endl;
cin>>m;
if (m!=0){
double SAr3[m]={0};
cout<<"Enter the value of each capacitor."<<endl;
for(int i=0;i<m;i++){
cin>>SAr3[i];
}
for(int i=0;i<m;i++){
Xc+=1/(2*M_PI*f*SAr3[i]);
}
}
magZ=sqrt(pow(R,2)+pow((Xl-Xc),2));
angZ=atan((Xl-Xc)/R);
cout<<"Total series impedance is "<<R<<"+("<<(Xl-Xc)<<")j"<<endl; // This prints the series impedance in rectangular form, as well its magnitude and its angle
cout<<"The magnitude of the impedance is "<<magZ<<"."<<endl;
cout<<"The angle of the impedance is "<<angZ<<"."<<endl;
realZ=R;
imagZ=Xl-Xc;
}


void acresistance::pa(){ // This is the parallel function that will be called by the total resistance function.
int N;
double G,B,mY,aY,aZ,mZ;
double f;
cout<<"Enter the number of branches in parallel."<<endl;
cin>>N;
double P1[N]={0};
double P2[N]={0};
double P3[N]={0};
double P4[N]={0};
double P5[N]={0};
double P6[N]={0};
double P7[N]={0};
double P8[N]={0};
cout<<"Enter the value for the frequency."<<endl;
cin>>f;
for(int i=0;i<N;i++){
    cout<<"Enter the value of the resistance, capacitance and inductance"<<endl;
    cout<<"in this branch respectively."<<endl;
    cin>>P1[i];
    cin>>P2[i];
    cin>>P3[i];
}
for(int i=0;i<N;i++){
  if (P2[i]!=0){
           P4[i]=1/(2*M_PI*f*P2[i]);
            }
    P5[i]=2*M_PI*f*P3[i];
        }

for(int i=0;i<N;i++){
        P6[i]=P5[i]-P4[i];
}
for(int i=0;i<N;i++){
            if (P1[i]!=0){
        P7[i]=(180/M_PI)*(1/atan(P6[i]/P1[i]));
            }
        P8[i]=pow((pow(P1[i],2)+pow(P6[i],2)),0.5);
    }
for(int i=0;i<N;i++){
G+=P8[i]*cos(P7[i]);
B+=P8[i]*sin(P7[i]);
}
mY=pow((pow(G,2)+pow(B,2)),0.5);
aY=(180/M_PI)*atan(B/G);
mZ=1/mY;
aZ=1/aY;
realZ=mZ*cos(aZ);
imagZ=mZ*sin(aZ);
cout<<"Total parallel impedance is "<<realZ<<"+"<<imagZ<<"j"<<endl; // this prints the parallel impedance in rectangular form, as well as its magnitude and its angle
cout<<"The magnitude of the impedance is "<<mZ<<"."<<endl;
cout<<"The angle of the impedance is "<<aZ<<"."<<endl;
magZ=mZ;
angZ=aZ;
}

void acresistance::sepa(){ //This is the series parallel function
    int N=0;
cout<<"To calculate the total impedance for the circuit,"<<endl;// menu displayed to the user
cout<<"the equation for the equivalent impedance will have to"<<endl;
cout<<"to be simplified and solved in segments."<<endl;
cout<<"Starting with the smallest backet (B.E.D.M.A.S)."<<endl;
cout<<"Enter the value for the frequency."<<endl;
cin>>fs;
while (N!=3){
    cout<<"Select the type of connection in the branch or '3' for total:"<<endl;
    cout<<"1-series"<<endl;
    cout<<"2-parallel"<<endl;
    cout<<"3-total"<<endl;
    cin>>N;
    if(N==1){
        seR();
    }
    else{
        if(N==2){
            paR();
        }
        else{
            if(N==3){
        magZ=sqrt(pow(realZ,2)+pow(imagZ,2));
        angZ=atan(imagZ/realZ);
        cout<<"Total parallel impedance is "<<realZ<<"+("<<imagZ<<")j"<<endl;//Results printed to the user
        cout<<"The magnitude of the impedance is "<<magZ<<"."<<endl;
        cout<<"The angle of the impedance is "<<angZ<<"."<<endl;
            }
            else{
                cout<<"Error!"<<endl;
            }
        }
    }
}

}

void acresistance::ToCurrent(){// This is the power function that is called by the total A.C resistance function
    double V;
 cout<<"Enter value of total voltage."<<endl;
 cin>>V;
 magI=V/magZ;
 angI=-1*angZ;
 realI=magI*cos(angI);
 imagI=magI*sin(angI);
 cout<<"The total current drawn is "<<realI<<"+("<<imagI<<")j"<<endl;//Displays the current in rectangular form as well as its magnitude and direction
 cout<<"The magnitude of the current is "<<magI<<"."<<endl;
 cout<<"The angle of the current is "<<angI<<"."<<endl;
}

void acresistance::ToPower(){//This is the power function
    magP=magI*magI*magZ;
    angP=angI+angI+angZ;
    realP=magP*cos(angP);
    imagP=magP*sin(angP);
 cout<<"The total power drawn is "<<realP<<"+("<<imagP<<")j"<<endl;//This displays A.C. power
 cout<<"The magnitude of the power is "<<magP<<"."<<endl;
 cout<<"The angle of the power is "<<angP<<"."<<endl;
}
