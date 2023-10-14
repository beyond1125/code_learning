#include<iostream>

using namespace std;

int main(){
    enum Stone{
        BLACK,
        WHITE,
        EMPTY
    };

    enum Stone a= BLACK;
    cout<<a;

    return 0;
    
}