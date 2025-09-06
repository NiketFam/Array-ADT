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
array *Union(array *arr1,array *arr2){
    int i,j,k;
    i=j=k=0;
    array *arr3=new array;
    while(i<arr1->length && j<arr2->length){
        if(arr1->a[i]<arr2->a[j]){
            arr3->a[k++]=arr1->a[i++];
        }
        else if(arr2->a[j]<arr1->a[i]){
            arr3->a[k++]=arr2->a[j++];            
        }
        else{
            arr3->a[k++]=arr1->a[i++]; // we are doing union so if any one of the element in common in both the array(set) then we take only 1 time either from arr1 or arr2 so that in final appears ones
            j++;  // (arr3->a[k++]=arr2->a[j++]; i++) here we do increment j because as earier we discuss that if element is common then we take only one times so if i and j at particular index then we take common element either from arr1 or arr2, here we take that element from arr1 so we have to increment j so that it can compare next element of j with i
        }
    }
    for(;i<arr1->length;i++){
        arr3->a[k++]=arr1->a[i];
    }
    for(;j<arr2->length;j++){
        arr3->a[k++]=arr2->a[j];
    }
    arr3->length=k; // here we don't take total length of arr1 and arr2 because we don't need it because we know there is common element in both so we take length of arr3 is 'k'
    arr3->size=10;
    return arr3;
}
array *Intersection(array *arr1,array *arr2){
    int i,j,k;
    i=j=k=0;
    array *arr3=new array;
    while(i<arr1->length && j<arr2->length){
        if(arr1->a[i]<arr2->a[j]){
            i++; // here we don't move the element because we need common elment only so if element of arr1 is less than arr2 then just increment i only
        }
        else if(arr2->a[j]<arr1->a[i]){
           j++; // same reason like above one
        }
        else if(arr1->a[i]=arr2->a[j]){ // if element is commmon then move to arr3
            arr3->a[k++]=arr1->a[i++]; 
            j++;  
        }
    }
    // Main reason for this for loop is  if element of arr1 is greater than arr2 then it will move to arr3 but we want common element so if arr1 is more element than arr2 so that element will not there in arr2 that means that element will not common so we not inculde that element

    // for(;i<arr1->length;i++){
    //     arr3->a[k++]=arr1->a[i];
    // }
    // for(;j<arr2->length;j++){
    //     arr3->a[k++]=arr2->a[j];
    // }
    arr3->length=k; // here we don't take total length of arr1 and arr2 because we don't need it because we know there is common element in both so we take length of arr3 is 'k'
    arr3->size=10;
    return arr3;
}
array *Difference(array *arr1,array *arr2){
    int i,j,k;
    i=j=k=0;
    array *arr3=new array;
    while(i<arr1->length && j<arr2->length){
        if(arr1->a[i]<arr2->a[j]){
            arr3->a[k++]=arr1->a[i++];
        }
        else if(arr2->a[j]<arr1->a[i]){
            j++; //as we are doing difference of arr1-arr2 that means element of arr2  not there in arr1 so we increment j       
        } // 
        else{
            j++;
            i++;  // if element is commmon in both the array then we not include that element so we increment i and j both
        }
    }
    for(;i<arr1->length;i++){
        arr3->a[k++]=arr1->a[i];
    }
    // we not include below for loop beacuse we are doing arr1-arr2 so we only take element of arr1 only we not include arr2 element because that not part of our arr1-arr2

    // for(;j<arr2->length;j++){
    //     arr3->a[k++]=arr2->a[j];
    // }
    arr3->length=k; // here we don't take total length of arr1 and arr2 because we don't need it because we know there is common element in both so we take length of arr3 is 'k'
    arr3->size=10;
    return arr3;
}
int main(){
    array arr1={{2,6,10,15,25},10,5};
    array arr2={{3,6,7,15,20},10,5};
    // array* arr3=Union(&arr1,&arr2);
    // array* arr3=Intersection(&arr1,&arr2);
    array* arr3=Difference(&arr1,&arr2);
    display(*arr3); 
}