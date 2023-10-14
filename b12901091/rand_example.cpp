#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    int seed=time(0);
    srand(seed);
    cout<<"the random seed ="<<seed<<endl;
    cout<<rand()<<endl;
    cout<<rand()<<endl;
    cout<<rand()<<endl;
    cout<<rand()<<endl;
    return 0;
}