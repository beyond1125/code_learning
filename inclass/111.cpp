#include <iostream>
using namespace std;

double f(double x){
    return x*x*x-3*x*x+x-10.0;
}

void getLeftRight(double& left,double& right){
    while(true){
        
        cout<<"Left:";
        cin>>left;
        cout<<"Right:";
        cin>>right;


        if(f(left)*f(right)<0.0)
            break;
        cout<<"--> f(left)*f(right)>=0,please try again. "<<endl;
    }
    cout << left <<endl;
    cout << right <<endl;
}

double bisection(double left,double right,double epsilon){
    do{
        double middle=(left+right)/2.0;
        if (f(middle)*f(right)<0)
            left=middle;
        else
            right=middle;
    }while(right-left>epsilon);
    return left;
}