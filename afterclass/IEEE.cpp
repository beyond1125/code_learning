#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
void intToBinaryArray(int num, int binary_array[]) {
    for (int i = 31; i >= 0; --i) {
        binary_array[i]=num%2;
        num/=2;
    }
}
int main(){
    int num,binary_array[32],sign,exponent;
    float fraction,float_num;
    
    cin>>num;
    intToBinaryArray(num,binary_array);

    if(binary_array[0])
        sign=-1;
    else
        sign=1;
    
    for(int i=0;i<8;i++){
        exponent+=binary_array[i+1]*pow(2,7-i);
    }
    exponent-=127;

    for(int i=0;i<23;i++){
        fraction+=binary_array[i+9]*pow(2,-(i+1));
    }
    fraction+=1;
    float_num=(float)sign*fraction*pow(2,exponent);

    cout << fixed << setprecision(5) << float_num << endl;


    return 0;
}