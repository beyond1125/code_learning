#include<iostream>
#include<cmath>

using namespace std;

int main(){
    cout<<"Enter an integer"<<endl;
    int num;
    cin >> num;

    int upper=(int)sqrt((double)num);

    bool prime = true;
    for(int i=2;i<upper;++i){
        cout<<"checking "<<i<<endl;
        if (num%i==0){
            prime=false;
            break;
        }
    }
    cout<<(prime?"prime":"not prime")<<endl;
    return 0;
}
