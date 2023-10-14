#include<iostream>
#include<ctime>
using namespace std;
int main(){
    
    srand((long int)time(0));

    const int NUM=10;
    int correct_num;
    for(int i=0;i<NUM;i++){
        int a =(rand()%16)+5;
        int b =rand()%a;

        cout<<a<<" - "<<b<<" = ";
        int ans;
        cin>>ans;

        cout<<((ans==a-b)?"correct":"wrong")<<endl;
        bool correct=(ans==a-b);
        if(correct)
            correct_num++;
            
    }
    cout<<"-----------Correct "<<correct_num<<" out of "<<NUM;
    if(correct_num==NUM)
    cout<<"Perfect"<<endl;
    return 0;
}