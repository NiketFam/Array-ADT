#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
class multipleMissing_array{
    public:
    int a[34]={3,7,4,9,12,6,1,11,2,10},n=12;
    int h[30]={0}; // here we are intializing all element as 0 
    void unsorted_array(){
        for(int i=0;i<n;i++){
            h[a[i]]++; // here we are inserting 1 when we get the element from a[] let's suppose a[0]=3 so we insert 1 at index 3 in h[] and if a[1]=7 then we insert 1 at index 7 in h[] and it's goes on.. and where element is missing then it is already intialize as 0
        }
        for(int i=0;i<n;i++){
            if(h[i]==0){ // so we at any index of h[] is that means that index element is missing and we get our multiple missing element
                // IMP POINT-1: WHY WE WANT SIZE MORE IN H[] ARRAY
                // and make sure size of h[] must be greater or equal than maximum size of the original array because maximum element present in
                // the original array then we insert 1 at that index of h[] let's suppose maximum element in the original array is 49 so we insert 1 at index h[49]
                // IMP POINT-2: WHAT THIS PROCESS CALLED?
                // this called Hashing and when you are searching hashing is the best solution and  its take lots of space, when space is constraints then 
                // IMP POINT-3: ABUNDANT MEMORY IN MODERN MACHINES
                // it is not useful but nowadays machine we are using they have abundant memory space so we hardly bother about memory space   

                cout<<"missing element is"<<i<<endl;
            }
        }
    }
};
int main(){
multipleMissing_array m;
m.unsorted_array();
return 0;
}