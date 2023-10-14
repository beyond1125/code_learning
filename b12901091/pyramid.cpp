#include <iostream>
using namespace std;
int main(){

    int num;
    cin>>num;

    for(int i=0;i<num;i++){

        for(int j=0;j<num;j++){
            if(j+1<=num-i-1)
                cout<<" ";
            else
                cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}