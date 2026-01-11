/*
In this problem we will be solving the very basic yet conceptwise very important question so the question will be-
returning the new arary from the existing with product of all its element except its own here is an example
arr1 = [1,2,3,4] then result should be
result = [24,12,8,6] see what is happening is that the each element of the arr1 is multiplied except the element at that idex and 
is return or stored in the result arr1


******Requirements******
--->time complexity should be O(n)
--->space complexity should be O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>ProductElement(vector<int>&nums){
    int n = nums.size();
    vector<int> result(n, 1);
    for(int i = 1; i < n; i ++){
        result[i] = result[i-1] * nums[i-1]; 
    }
    int suffix = 1;
    for(int i = n - 2; i >= 0; i --){
        suffix = suffix * nums[i+1];
        result[i]  = suffix * result[i];
    }
    return result;
}
int main(){
    vector<int>arr1 = {1,2,3,4};
    vector<int>result = ProductElement(arr1);
    cout << "The Output returned is : " <<endl; 
    for(auto ele : result){
        cout << ele << " ";
    }
    return 0;
}