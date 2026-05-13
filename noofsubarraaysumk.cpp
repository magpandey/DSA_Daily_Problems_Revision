#include <iostream>
#include <vector>

using namespace std;


int noOfSubarrayWithSumequalK(vector<int>&a, int k){
    int n = a.size();

    int i = 0;
    int j = 0;
    int count = 0;
    int sum = 0;
    while(j < n){
         sum = a[i];
        if(sum == k){
            i ++;
            j ++;
            count ++;
        }
        else if(sum < k){
            j ++;
        }
        else{
            j --;
        }

    }
}