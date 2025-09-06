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
/*
This is a function to print all elements in the array.
Takes parameter array arr by value (makes a copy).
Loops from index 0 to length-1, and prints each element
cout << arr.a[i] << " "; — outputs each element followed by space.
Since we’re not modifying anything, it’s fine to pass by value.
*/
void append(array *arr,int x){
    if(arr->length<arr->size){
        arr->a[arr->length++]=x;
    }
}
/*
 This function adds an element x to the end of the array.
Takes a pointer to array (array *arr) because we are modifying the actual object.
arr->length is the current count.
If array is not full (length < size), insert x at a[length].
Then length++ — increases length to account for the new element.
 arr->a[...] and arr->length use the arrow -> because arr is a pointer.
*/
void insert(array *arr,int index,int x){
   if(index>=0 && index<=arr->length && arr->length< arr->size){ 
    for(int i=arr->length;i>index;i--){
        arr->a[i]=arr->a[i-1];
    }
        arr->a[index]=x;
        arr->length++;
}
}
/*
 This starts the insert function — adds a value x at any given position (index).
First checks:
index is valid (non-negative and within bounds).
length < size ensures there’s room for more elements.

LOOP PART
 This loop shifts all elements from the end to the right, starting from length to index + 1.
Why? To make space for the new element at index.
If you want to insert at position 2, then element at 2 is moved to 3, 3 to 4, and so on.
This loop works in reverse because if you go forward, you'll overwrite values.

After shifting:
Place the new value at index: arr->a[index] = x;
Increase the length since a new element is added.
Done! This function inserts without data loss.
*/
int delete_arr(array *arr,int index){
    if(index>=0 && index<=arr->length && arr->length< arr->size ){
        for(int i=index;i<arr->length-1;i++){
            arr->a[i]=arr->a[i+1];
        }
        arr->length--;
    }
    return 0;
}
int main(){
 array arr={{2,3,5,1,7},20,5}; //size=20 , length=5
 //append(&arr,10);
 //insert(&arr,2,9);
 delete_arr(&arr,3);
display(arr);
return 0;
}