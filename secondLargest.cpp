/*
 * Problem: Second Largest Element
 * Given an array of integers, return the second largest distinct element.
 * If it doesn't exist (all elements same or array size < 2), return -1.
 *
 * Approach: Single pass with two variables
 * - largest: tracks the maximum value seen so far
 * - second: tracks the second largest distinct value (initialized to a sentinel like -1)
 * 
 * Rules for each element x:
 * 1. If x > largest:
 *      second = largest (old largest becomes second)
 *      largest = x
 * 2. Else if x < largest and x > second:
 *      second = x
 *    (This handles numbers that are between largest and current second)
 * 3. Ignore duplicates of largest or second (x == largest or x == second)
 *
 * After loop, if second is still sentinel (-1), return -1, else return second.
 *
 * Edge cases: all equal, size 1, already sorted ascending/descending, negative numbers.
 * Time: O(n), Space: O(1)
 *
 * Mindset: Don't sort. Simulate keeping top two distinct values while iterating.
 *          Update second only when a new candidate appears between largest and second.
 */




#include <iostream>
#include <vector>
using namespace std;

int LargestSecond(vector<int>&arr){
    int n = arr.size();
    
    if( n < 2) return -1;
    int largest = arr[0];
    int second = -1;
    
    for(int i = 1;i < n; i ++){
        if(largest < arr[i]){
            second = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > second){
            second = arr[i];
        }
    }
    return second == -1? -1: second;
}
int main(){
    
    vector<int>nums = {8,8,8,8,8};
    
    int secondLargest = LargestSecond(nums);
    cout << "The second largest element is   " << secondLargest;
    return 0;
}


























