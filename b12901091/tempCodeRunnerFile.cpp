#include<iostream>
#include<cmath>
using namespace std;
int main (){
    int day ;
    cin>>day;
    if(day==2||day==3)
        cout<<"Computer Programming Lecture!"<<endl;
    else if(day==6||day==7)
        cout<<"Weekend!";
    else
        cout<<"No class.";

    return 0;
}