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
array *merge(array *arr1,array *arr2){ // here we take pointer because we want to modiy the array
    int i,j,k; 
    i=j=k=0;
    array *arr3=new array; // we take dynamic array
    while(i<arr1->length && j<arr2->length){ // loop will continue till number of element in arr1 and arr2 is not less than length of arr1 and arr2 respectively
        if(arr1->a[i]<arr2->a[j]){ // if element of arr1 is less than arr2 then 
            arr3->a[k++]=arr1->a[i++]; // move arr1 element in arr3 and incrment i so that j compare its element with next element of arr1 and increment k so that after comparing next element of array it store in next index of arr3
        }
        else{
            arr3->a[k++]=arr2->a[j++];  // if above result false then we will do same for arr2 like earlier we did for arr1         
        }
    }
            for(;i<arr1->length;i++){ // we use this loop because if number of element in arr1(let's suppose no. of element  7) is greater than arr2(let's suppose no. of element  5) then 
            arr3->a[k++]=arr1->a[i];  // at index of 5 in both the array it store in the arr3 but what about extra two element of arr1 so after index 5 it will directly move to the arr3
        }
        for(;j<arr2->length;j++){ // same we will do for arr2 if number of element of arr2 is greater than no. of element arr1
            arr3->a[k++]=arr2->a[j]; 
        }
     arr3->length=arr1->length +arr2->length; // when we merge, we take all elements from arr1 and arr2
     arr3->size=10; //
     return arr3;
}
int main(){
     array arr1={{2,4,6,8,10},10,5};
     array arr2={{1,3,5,7,9},10,5};
    array* arr3=merge(&arr1,&arr2);
    display(*arr3);
    return 0;
}