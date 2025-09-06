#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
int main() {
    int n = 10;
    int a[n] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int last_duplicate = 0;  
/*
🎯 EXPLANATION: Why do we use `last_duplicate`?
     🔹 Purpose:
        - To make sure we don't print the same duplicate element
          multiple times.
     🔹 How it works:
        1️⃣ When we detect that a[i] == a[i+1], we have found a duplicate.
        2️⃣ Before printing, we check:
              👉 a[i] != last_duplicate
            This ensures we only print a duplicate once.
        3️⃣ After printing, we update:
              last_duplicate = a[i]
     🔹 Example Walkthrough:
        Array: {3, 6, 8, 8, 10, 12, 15, 15, 15, 20}
        ➡ At index 2 → a[i] = 8 and a[i+1] = 8 → duplicate found.
           Print: "8" ✅ and set last_duplicate = 8.
        ➡ At index 3 → a[i] = 8 again,
           but since last_duplicate = 8, we skip printing ❌.
        ➡ At index 6 → a[i] = 15, a[i+1] = 15 → duplicate found.
           Print: "15" ✅ and set last_duplicate = 15.
        ➡ At index 7 → a[i] = 15 again, 
           but last_duplicate = 15, so skip ❌.
        ➡ At index 8 → a[i] = 15 again,
           still last_duplicate = 15 → skip ❌.
     ✅ Final Output → 8 and 15 printed only once.  
     */
    for (int i = 0; i < n - 1; i++) {   // loop till n-1 to avoid out-of-bounds
        if (a[i] == a[i+1] && a[i] != last_duplicate) {
            cout << "Duplicate element found: " << a[i] << endl;
            last_duplicate = a[i];  // store last printed duplicate
        }
    }
    return 0;
}