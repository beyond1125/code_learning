#include<iostream>
#include<cmath>
using namespace std;
int check_a(char answer[4],char guess[4]){
    int count=0;
    for(int i=0;i<4;i++)
    {
        if(answer[i]==guess[i])
            count++;
    }
    return count;
}
int check_b(char answer[4],char guess[4]){
    int count=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(answer[i]==guess[j])
                count++;
        }
    }
    return count;
}
int main(){
    char answer[4],guess[4];
    cin>>answer;
    cin>>guess;
    int a=check_a(answer,guess);
    int b=check_b(answer,guess)-check_a(answer,guess);
    cout<< a <<"A"<< b <<"B"<<endl;
    return 0;
}