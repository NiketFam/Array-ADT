#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
class array{
    public:
    int a[20];
    int size;
    int length;
};
int get(array arr,int index){
    if(index>=0 && index<arr.length){
        return arr.a[index];
    }
    else {
        return -1;
    }
}
int set(array *arr,int index,int val){
    if(index>=0 && index<arr->length){
        arr->a[index]=val;
    }  
}
int Max(array arr){
    int max=arr.a[0];
    for(int i=0;i<arr.length;i++){
        if(arr.a[i]>max){
            max=arr.a[i];
        }
    }
    return max;
}
int Min(array arr){
    int min=arr.a[0];
    for(int i=0;i<arr.length;i++){
        if(arr.a[i]<min){
            min=arr.a[i];
        }
    }
    return min;
}
int Sum(array arr){
    int sum=0;
    for(int i=0;i<arr.length;i++){
        sum+=arr.a[i];
    }
    return sum;
}
float avg(array arr){
    return (float)Sum(arr)/arr.length;
}
int main(){
   array arr={{5,9,10,13,23},20,5};
   cout<<"getting the particular index value in the array "<<get(arr,3)<<endl;
   cout<<"modifying the value at particular index "<<set(&arr,3,40)<<endl;
   cout<<"maximum value in the arrray "<<Max(arr)<<endl;
   cout<<"minimum value in the array "<<Min(arr)<<endl;
   cout<<"sum of elements in the array "<<Sum(arr)<<endl;
   cout<<"average of the array "<<avg(arr)<<endl;
    return 0;
}