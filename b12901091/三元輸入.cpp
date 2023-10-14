#include <iostream>
#include <string>
 
using namespace std;
 
int main(void)
{
    int num;
    cin>>num;
    
    bool even=num%2==0;    
  
    cout<<((even)?"Even":"Odd")<<endl;

    return 0;

}