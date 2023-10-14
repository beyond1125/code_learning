#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    double input;
    int exp;
    cin>>input>>exp;

    double a=input*pow(10,-(exp-1));
    long long b=(long long) a;
   // cout<<b<<endl;
    if(b%10>=4){
        b/=10;
        b++;
        //cout<<b<<endl;
    }
    else
    {
        b/=10;
    }
    //cout<<b<<endl;
    double output=b*pow(10,(exp));
    if(exp<0)
    cout<<fixed << setprecision(abs(exp)) <<output<<endl;
    else
    cout<<(long long)(b*pow(10,(exp)));


    return 0;
}