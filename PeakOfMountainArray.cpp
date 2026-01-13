/*
LeetCode 852 — Peak Index in a Mountain Array

PROBLEM IN ONE LINE:
Given a mountain array, find the index of its peak element.

WHAT IS A "MOUNTAIN" ARRAY?
An array arr is a mountain if:
1) It strictly increases up to some index i
2) Then strictly decreases after i
3) i is NOT at the edges (0 < i < n-1)

Example:
[0, 2, 5, 7, 6, 4, 1]
             ^
             peak (index 3)

FORMAL SHAPE:
arr[0] < arr[1] < ... < arr[i]
arr[i] > arr[i+1] > ... > arr[n-1]

You must return i.

-------------------------------------
WHY THIS IS NOT A SIMPLE MAX PROBLEM
-------------------------------------
Yes, the peak is the maximum value, but:
The problem is designed to force O(log n) solution.
So linear scan is technically correct but NOT intended.

LeetCode expects Binary Search.

-------------------------------------
KEY OBSERVATION
-------------------------------------
At any index mid:

If arr[mid] < arr[mid+1]
→ You are on the increasing slope
→ Peak is to the RIGHT

If arr[mid] > arr[mid+1]
→ You are on the decreasing slope
→ Peak is at mid or to the LEFT

So this behaves like a "mountain-shaped" monotonic function.

-------------------------------------
BINARY SEARCH LOGIC
-------------------------------------
We compare mid with mid+1, not with edges.

We shrink the search space until left == right,
which will land exactly on the peak index.

-------------------------------------
CONSTRAINTS
-------------------------------------
3 <= arr.length <= 10^4
0 <= arr[i] <= 10^6
Array is guaranteed to be a valid mountain.

So:
- No flat values
- Exactly one peak
- No tricky invalid cases

-------------------------------------
TIME & SPACE
-------------------------------------
Time: O(log n)
Space: O(1)

-------------------------------------
WHY THIS WORKS
-------------------------------------
Because before the peak, array behaves like increasing,
and after peak, like decreasing.
Binary search exploits this change of slope.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int PeakOfMountain(vector<int>&a){
    int st = 1;
    int end = a.size() - 2;

    while(st <= end){
        int mid = st + (end - st)/2;

        if(a[mid] > a[mid-1] && a[mid] >a[mid+1]){
            return mid;
        }
        else if(a[mid] < a[mid + 1]){
            st = mid + 1;
        }else{
            end = mid -1;
        }
    }
    return -1;
}
int main(){
    vector<int>mountain = {3,4,5,8,9,6,2};

    int maxPeakIndex = PeakOfMountain(mountain);
    cout <<"The Index of the peak element is : " <<maxPeakIndex <<endl;
    return 0;
}















