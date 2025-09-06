#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
class singleMissing_array{
public:
int sum=0,n=11;
int a[10]={1,2,3,4,5,7,8,9,10,11};
int missing;
int s=n*(n+1)/2; // here we calculating total sum of 1st n natural number becuse if we get sum then we find missing number by subtracting sum of natural number and sum of element in the array
void sorted_array(){
    for(int i=0;i<10;i++){
        sum=sum+a[i];
        missing=s-sum; 
    }
    cout<<"missing array is "<<missing<<endl;
}
};
int main(){
singleMissing_array m;
m.sorted_array();
return 0;
}