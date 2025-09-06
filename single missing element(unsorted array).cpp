#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
class singleMissing_array{
public:
int a[51]={17,6,8,9,10,11,13,14,15,16,7},n=11;
int first=a[0],last=a[0],sum=0; // here we are taking intializinf first value as maximum and minimum further will assign actual maximum and minimum value
int s;
int missing;
void unsorted_array(){
    for(int i=0;i<n;i++){
        if(a[i]<first){ // here we are finding minimum element 
            first=a[i];
        }
        if(a[i]>last){ // here we are finding maximum element
            last=a[i];
        }
        sum+=a[i];
        s=(last*(last+1))/2 - (first*(first-1))/2;
        /*
        WHY WE ARE ADDING +1:
        (last*(last+1))/2 here we adding +1 because we know that sum of n natural number is n(n+1)/2 so if we focus on (n+1) we are adding so that we can find the sum let's suppose we have to find sum of 10 natural number then we do 10*11/2 so we add 1 in 10 and 10 is maximum number in 1st 10 natural number
        WHY WE ARE ADDING -1:
        (first*(first-1))/2 here we adding -1 because we know that sum of n natural number is n(n+1)/2 but here we use same formula but little bit different for example we alredy find sum of 10 natural number but what if we have to find sum from "6 to 10" then how we find because we know that formula only works when it's starts from 1 so what we will do is 
        we find sum of first 5 natural number then we subtract with sum of 10 natural number then we get required sum if we calculate sum of first 5 natural number 5(5+1)/2 => 5*6/2 we focus 6 is minimum number of that required sum( sum from "6 to 10") and instead of doing this 5(5+1)/2 if we will do like this (6-1)((6-1)+1)/2 here n=(6-1) and n+1=(6-1)+1
        */
        missing=s-sum;
    }
    cout<<"missing number is "<<missing<<endl;
}
};
int main(){
singleMissing_array m;
m.unsorted_array();
return 0;
}