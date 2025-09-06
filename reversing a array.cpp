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
void reverse_auxillary(array *arr){ // we are modifying the array that's why we take pointer array
    int i,j;
    int *b=new int[arr->length];
    for(i=arr->length-1,j=0;i>=0;i--,j++){ // here we are decreasing 'i' because in 1st array we put 'i' at last index then that element goes in auxillary array and 'j' will increase the index of the array it's goes on....
        b[j]=arr->a[i];
    }
    for(i=0;i<=arr->length-1;i++){
        arr->a[i]=b[i];
    }
}
void reverse_without_auxillary(array *arr){
    for(int i=0,j=arr->length-1;i<j;i++,j--){ // here we put 'i' at index '0' and 'j' put at last index so i and j will swap then after swapping done then 'i' will increse and 'j' will decrese
        swap(&arr->a[i],&arr->a[j]);
        //  swap(&arr->a[j],&arr->a[i]);
        /*
        Both lines produce the same result because swapping a and b or b and a results in the same 
        final values — you're just reversing the order of inputs to the swap function, but the effect is identical.
        */
    }
}
int main(){
    array arr={{2,3,5,1,7},20,5};
     //reverse_auxillary(&arr);
     reverse_without_auxillary(&arr);
     display(arr);
    return 0;
}