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
int linearSearch(array arr,int key){ //normal searching
    for(int i=0;i<arr.length;i++){
    if(key==arr.a[i]){
        return i;
    }
}
    return -1;
}
// now we are searching key element with using swapping technique i.e transportation
void swap(int *a,int *b){ // we are taking a pointer becuse we are modifying so by taking the poinnter we can modify
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
int linearSearch_tranportation(array *arr,int key){
    for(int i=0;i<arr->length;i++){
        if(key==arr->a[i]){
            swap(&arr->a[i],&arr->a[i-1]);
              return i;
        }
    }
} 
int linearSearch_moveTohead(array *arr,int key){
    for(int i=0;i<arr->length;i++){
        if(key==arr->a[i]){
            swap(&arr->a[i],&arr->a[0]);
              return i;
        }
    }
} 
void display(array arr){
    for(int i=0;i<arr.length;i++){
        cout<<arr.a[i]<<" ";
    }
}
int main(){
array arr={{2,3,5,1,7},20,5};
//cout<<linearSearch(arr,1)<<endl;
//cout<<linearSearch_tranportation(&arr,1)<<endl;
cout<<linearSearch_moveTohead(&arr,1)<<endl;
display(arr);
return 0;
}
