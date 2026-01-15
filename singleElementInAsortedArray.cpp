/*
LeetCode 540 — Single Element in a Sorted Array

PROBLEM IN ONE LINE:
In a sorted array where every element appears exactly twice
except one element that appears once, find that single element.

Example:
[1,1,2,3,3,4,4,8,8] → 2
[3,3,7,7,10,11,11] → 10

-------------------------------------
CRITICAL CONSTRAINTS
-------------------------------------
- Array is sorted
- All numbers appear exactly twice
- Except ONE number that appears once
- Must run in O(log n)
- Must use O(1) space

So:
- No hash maps
- No counting
- No linear scan

Binary search is mandatory.

-------------------------------------
KEY PATTERN
-------------------------------------
Before the single element:
Pairs start at EVEN index
(0,1), (2,3), (4,5)...

After the single element:
Pairs start at ODD index
(1,2), (3,4), (5,6)...

This index shift is the entire trick.

-------------------------------------
WHY THIS SHIFT HAPPENS
-------------------------------------
The single element "breaks" the pairing.
Everything to the right of it gets shifted by one index.

So:
Left side is perfectly aligned.
Right side is misaligned.

We binary search for where this misalignment begins.

-------------------------------------
BINARY SEARCH LOGIC
-------------------------------------
At any mid:

Make mid EVEN.
Because pairs always start at even index before the single.

Then:
If nums[mid] == nums[mid + 1]
→ This pair is valid
→ Single element is to the RIGHT

Else
→ Pair is broken
→ Single element is at mid or to the LEFT

We shrink the search space until left == right.

-------------------------------------
WHAT WE RETURN
-------------------------------------
When left == right,
that index points to the single element.

-------------------------------------
TIME & SPACE
-------------------------------------
Time: O(log n)
Space: O(1)

-------------------------------------
MENTAL MODEL
-------------------------------------
We are not searching values.
We are searching the point where pairing breaks.
That break is caused by the single element.
*/

#include <iostream>
#include <vector>

int SingleInSorted(vector<int>&arr){
    int st = 0, end = arr.size() - 1;
    if(arr.size() == 1) return arr[0];
    while(st <= end){
        int mid = st + (end -st)/2;
        if(mid == 0 && arr[mid + 1] != arr[mid]) return arr[mid];
        if(mid == arr.size() - 1 && arr[mid-1] != arr[mid]) return arr[mid];

        if(arr[mid - 1]!= arr[mid] && arr[mid + 1]!= arr[mid]) return arr[mid];

        if(mid % 2 == 0){
            if(arr[mid -1] == arr[mid]){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }else{
            if(arr[mid-1] == arr[mid]){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }
    return -1;
}
int main(){
    vector<int>nums = {1,1,2,3,3,4,4,8,8};
    int singleNumber = SingleInSorted(nums);
    cout << "The unique element in the array is " <<singleNumber;
    return 0;
}

















