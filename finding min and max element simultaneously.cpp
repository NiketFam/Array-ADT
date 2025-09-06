#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
int main(){
     int n = 10;
    int a[n] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int min=a[0];
    int max=a[0];
    for(int i=0 ;i<n;i++){
        if(a[i]<min){
            min=a[i];
        }
        else if(a[i]>max){
            max=a[i];
        }
    }
    cout<<"minimum element is "<<min<<endl;
    cout<<"maximum element is "<<max<<endl;
return 0;
}
