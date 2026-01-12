// In this leetcode problem
/*
LeetCode 33 — Search in Rotated Sorted Array

Idea:
A rotated sorted array always has ONE half that is properly sorted.
We do NOT care where the rotation happened.
At every step we only answer three questions:

1) Is nums[mid] the target?
2) Which half is sorted?
3) Is the target inside that sorted half?

Logic:
- If nums[left] <= nums[mid], the left half is sorted.
    If target lies between nums[left] and nums[mid],
    search left, else search right.

- Else, the right half is sorted.
    If target lies between nums[mid] and nums[right],
    search right, else search left.

We repeat this until we find the target or the search space collapses.

This keeps O(log n) time because every step throws away half the array,
just like normal binary search.

Key Insight:
Rotation looks confusing, but it never destroys the fact that one half
is always sorted. We exploit that to locate the target.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int search(vector<int> &nums, int t)
{
    int st = 0;
    int end = nums.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if(nums[mid] == t){
            return mid;
        }
        if (nums[st] <= nums[mid])
        {
            if (nums[st] <= t && nums[mid] > t)
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else{
            if(nums[mid] < t && nums[end] >= t){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> rotatedArray = {3, 4, 5, 6, 7, 0, 1, 2};
    int target = 2;
    int foundIndex = search(rotatedArray, target);
    cout << "The target is found at the index " << foundIndex << endl;
    return 0;
}
