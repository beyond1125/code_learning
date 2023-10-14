#include<cstdio>
using namespace std;

int main (){
    
    for(int k=0;k<3;k++){
        printf("+--------+--------+--------+\n");
        for(int j=0;j<9;j++){
            printf("| ");
            for(int i=0;i<3;i++)
                printf("%1d*%1d=%2d | ", 3*k+i+1, j+1, (3*k+i+1)*(j+1));
            printf("\n");
        }
    }
    

    return 0;
}