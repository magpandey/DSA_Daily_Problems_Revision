#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int Partition(vector<int>&arr, int low , int high){
    int pivot = low;
    int i = low;
    int j = high;
    
    while(i <= j){
        while(arr[i] <= arr[pivot] && i <= high){
            i ++;
        }
        while(arr[j] > arr[pivot] && j > low){
            j --;
        }

        if(i < j){
            swap(arr[j], arr[i]);
        }
        
    }
    swap(arr[pivot], arr[j]);
    return j;
}
void quickSort(vector<int>&nums, int low, int high){
    if(low <high){
        int pivotIndex = Partition(nums, low , high);
        quickSort(nums,low, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1 , high);
    }
}
int main(){
    vector<int>arr ={10,5,7,3,1,2};
    int low = 0;
    int high = arr.size() - 1;
    quickSort(arr,low, high);
    for(int x: arr){
        cout << x << " ";
    }
    return 0;
}