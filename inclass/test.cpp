#include<iostream>
#include<cmath>
#include<iomanip>
#include "111.h"
using namespace std;

int main(){
    double left,right;
    getLeftRight(left,right);
    double root=bisection(left,right,1e-10);
    
    cout<<"f("<<root<<") = "<<fixed<<setprecision(11)<<f(root)<<endl;
   
    return 0;
}