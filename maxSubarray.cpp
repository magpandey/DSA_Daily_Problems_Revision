/*This code here given below is the demonstration for the kadane's algorithm where we will calculate the
maximum sub array sum of the array the maximum subarray sum is the maximum possible sum of any contenuys
part of the given arary */
#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>val){
    vector<int>ans = {};
    int maxsum = val[0];
    int currentsum = val[0];
    for (int i = 1; i < val.size(); i++)
    {
        currentsum = max(val[i],val[i] + currentsum);
        maxsum = max(currentsum,maxsum);
    }
    return maxsum;
}
int main(){

    vector<int>nums = {1,-4,5,4,-3};
    cout << maxSubArray(nums) <<endl;
    return 0;
}
