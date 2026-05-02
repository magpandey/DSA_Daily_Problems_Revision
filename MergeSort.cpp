//This is the code which shows the merge sort in action;/////


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>&nums, int left, int mid, int right){
    vector<int>temp;

    int i = left;
    int j = mid + 1;

    while(i <= mid && j <= right){
        if(nums[i] <=  nums[j]){
            temp.push_back(nums[i]);
            i++;
        }else{
            temp.push_back(nums[j]);
            j++;
        }
    }
   while (i <= mid) {           // left half still has elements
    temp.push_back(nums[i]);
    i++;
}
while (j <= right) {         // right half still has elements
    temp.push_back(nums[j]);
    j++;
}
for(int k = 0; k < temp.size(); k ++){
    nums[k + left] = temp[k];
}
    
}
void mergeSort(vector<int>&nums, int low , int high){

    if(low >= high) return;
    int mid = low + (high - low)/2;    
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low,mid, high,);
}
int main(){
    vector<int> arr = {5,6,7,2,1,8,7,3,9};
    int low = 0;
    int high = arr.size() - 1;
    mergeSort(arr,low, high);

    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}