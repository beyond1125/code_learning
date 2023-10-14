#include<iostream>
using namespace std;
int main(){
    char a[2];
    int interval;

    cin>>a>>interval;
    interval-=1;
    
    
    a[0]-=('A'+1);//C=1,D=2,A=6,B=7
    a[1]-='0';
    

    if(a[0]<=0)
        a[0]+=7;
    int inputPosition=a[1]*7-5+a[0];
    //cout<<inputPosition;
    int outputPosition=inputPosition+interval;
    int outputChar=(outputPosition+5)%7;
    if(outputChar>=6)
        outputChar-=7;
    cout<<char(char(outputChar)+'A'+1)<<char(char((outputPosition+4)/7)+'0')<<endl;
    
    return 0;
}