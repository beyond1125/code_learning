#include<iostream>
#include<cstdint>
using namespace std;
int main(){
    unsigned int input;
    cin>> input;
    unsigned char *p= reinterpret_cast<unsigned char *>(&input);
    //cout<<(unsigned int)*p<<endl;
    for(int i=0;i<sizeof(unsigned int);i++){
        cout<<(int)(*(p+3-i))<<endl;
    }
    
    return 0;
}