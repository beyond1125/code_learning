#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    int length,width;
    cin >>length>>width;
    if(length%2==0)
        cout<<"No such rhombus.";
    else if(length/2<width){
        cout<<"Not a hollow rhombus.";
    }
    else{
        for(int i=0;i<length;i+=2){

            for(int j=0;j<((length-i)/2);j++)
                cout<<" ";
            
            if((i+1)>2*width){
                for(int j=0;j<width;j++)
                    cout<<"*";
                for(int j=0;j<((i+1)-2*width);j++)
                    cout<<" ";
                for(int j=0;j<width;j++)
                    cout<<"*";
            }
            else{
                for(int j=0;j<i+1;j++)
                    cout<<"*";
            }
            
            for(int j=0;j<((length-i)/2);j++)
                cout<<" ";
            cout<<endl;
        }
        for(int i=length-3;i>=0;i-=2){

            for(int j=0;j<((length-i)/2);j++)
                cout<<" ";
            if((i+1)>2*width){
                for(int j=0;j<width;j++)
                    cout<<"*";
                for(int j=0;j<((i+1)-2*width);j++)
                    cout<<" ";
                for(int j=0;j<width;j++)
                    cout<<"*";
            }
            else{
                for(int j=0;j<i+1;j++)
                    cout<<"*";
            }
            for(int j=0;j<((length-i)/2);j++)
                cout<<" ";
            cout<<endl;
        }
    }
    
    return 0;
}