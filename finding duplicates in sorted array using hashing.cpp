#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
int main(){
     int n = 10;
    int a[n] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int count[20]={0};
    for(int i=0;i<n;i++){
        ++count[a[i]];
    }
    for(int i=0;i<20;i++){
        if(count[i]>1){
            cout<<i<<" is repeating "<<count[i]<<" "<<endl;
        }
    }
return 0;
}
