#include<iostream>
using namespace std;

int main() {
    int n = 10;
    int a[n] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};

    /*
     🎯 EXPLANATION OF LOGIC
     🔹 Goal: Count how many times each duplicate element appears.
     🔹 Step 1: Use `i` to traverse the array.
     🔹 Step 2: When we find `a[i] == a[i+1]`, it means duplicates start.
     🔹 Step 3: Introduce `j = i + 1` to count how long the duplicate sequence continues.
                - While `a[j] == a[i]`, increment `j`.
     🔹 Step 4: At this point:
                - `j` points to the first unique element after duplicates.
                - The count of duplicates = `j - i`.
     🔹 Step 5: Print result → element `a[i]` appears `(j - i)` times.
     🔹 Step 6: Update `i = j - 1` so that next iteration starts fresh
                after the duplicates (avoiding re-checking them).
     🔹 Time Complexity:
        - The `while` loop only advances `j` forward without resetting.
        - So overall, each element is checked once → O(n).
     ✅ Example Walkthrough:
        Array = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20}
        ➡ i=2 → a[i]=8, a[i+1]=8 → duplicate found.
           j runs until j=4 → stops at 10.
           Count = j-i = 4-2 = 2 → "8 is appearing 2 times".
           Then i = j-1 = 3 → loop continues.
        ➡ i=6 → a[i]=15, a[i+1]=15 → duplicate found.
           j runs until j=9 → stops at 20.
           Count = j-i = 9-6 = 3 → "15 is appearing 3 times".
           Then i = j-1 = 8 → loop continues.
        ➡ Output → Correctly prints counts of duplicates only once.
*/
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i+1]) {
            int j = i + 1;   // start checking from next index
            while (a[j] == a[i]) {
                j++;
            }
            cout << a[i] << " is appearing " << (j - i) << " times" << endl;
            i = j - 1;  // move i just before next unique element
        }
    }
    return 0;
}