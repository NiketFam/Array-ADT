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
void display(array arr){
    for(int i=0;i<arr.length;i++){
        cout<<arr.a[i]<<" ";
    }
}
void swap(int *a,int *b){ 
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
void insert_array(array *arr,int x){
    int i=arr->length-1; // here we put 'i' at last index so that it's starts shifting rather than 1st commpare and then starts shifting  
    while(i>=0 && arr->a[i]>x){ // if x is greater than last element then 'x' will store at last element for example if i take '20' then it's directly store at last index
        arr->a[i+1]=arr->a[i];
        i--;
    }
    arr->a[i+1]=x;
    arr->length++;
}
int isSorted(array arr){ // we are just seeing array is sorted or not that's why we are not taking the array pointer
    for(int i=0;i<arr.length-1;i++){
        if(arr.a[i]>arr.a[i+1]){
            return 0;
        }
     }
     return 1;
}
void serating_pos_neg(array *arr){
    int i=0;
    int j=arr->length-1;
    while(i<j){
    while(arr->a[i]<0){ // Increment i until you find a non-negative number (positive or zero). These will be moved to the right side by swapping.
        i++;
    }
    while(arr->a[j]>=0){ // Decrement j until you find a negative number. These should be moved to the left side by swapping.
        j--;
    }
    if(i<j){
        swap(&arr->a[i],&arr->a[j]); // If i is at a non-negative and j is at a negative number, then swap them to move negative numbers left and non-negative numbers right
    }
}
}
int main(){
     array arr={{-22,5,8,-10,16},20,5};
     //insert_array(&arr,7);
     //cout<<isSorted(arr)<<endl;
     serating_pos_neg(&arr);
     display(arr);
    return 0;
}