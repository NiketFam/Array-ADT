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
int binarySearch(array arr,int key){ // here we are not taking the array of pointer because we're just accessing the array not modifying it
    int l=0;
    int h=arr.length-1;
    int mid=(l+h)/2;
    while(l<=h){
        if(key==arr.a[mid]){
            return mid;
        }
        else if(key<arr.a[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}
int rec_binarSearch(array arr,int l,int h,int key){
    if(l<=h){
        int mid=(l+h)/2;
        if(key==arr.a[mid]){
            return mid;
        }
        else if(key<arr.a[mid]){
            return rec_binarSearch(arr,l,mid-1,key);
        }
        else{
            return rec_binarSearch(arr,mid+1,h,key);
        }
    }
    return -1;
}
int main(){
   array arr={{5,9,10,13,23},20,5};
   //cout<<binarySearch(arr,10);
   cout<<rec_binarSearch(arr,0,arr.length-1,23);
    return 0;
}