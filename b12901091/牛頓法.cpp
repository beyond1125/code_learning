#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){

    cout<<"enter a number: "; 
    double a,ox;
    cin>>a;

    double x=1.0;
    do{
        ox=x;
        cout<<"-------"<<fixed<<setprecision(5)<<x<<endl;
        x=(x+a/x) / 2.0;

    }while(fabs(ox-x)>1e-6);

    cout<<fixed<<setprecision(15)<<x<<endl;
    cout<<sqrt(a)<<endl;
    
}