/* ex1_cpu_time.cpp */
#include <iostream>
#include <ctime>
int main(){
// Variables
clock_t start, end;
double cpu_time_used;
start = clock();
// Program runs here.
int sum=0;
for(int i=0;i<999;i++)
    sum+=i;
std::cout<<sum<<endl;
end = clock();
// Calculate time
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
std::cout << "Time taken: " << cpu_time_used << " seconds" << std::endl;
return 0;
}