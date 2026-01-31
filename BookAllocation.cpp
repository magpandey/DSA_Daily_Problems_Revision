#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IsValid(int arr[],int mid,int n,int m){
    int sum = 0;
    int student = 1;
    for (int i = 0; i < n; i++)
    {
        if(sum + arr[i] <= mid){
            sum = sum + arr[i];
        }else{
            student++;
            sum = arr[i];
        }
        if(student > m){
            return false;
        }else{
            return true;
        }
    }
    
}



int allocateBooks(int arr[],int n,int m){
    int low = 0;
    int high = 0;
    for(int i = 0; i < n; i ++){
        high = high + arr[i];
    }
    while(low < high){
        int mid = low +  (high - low)/2;
        if(IsValid(arr,mid,n,m)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int>bookPages = {2,1,4,3,5};
    int n = bookPages.size();
    int m = 2;
    int ans = allocateBooks(bookPages,n,m);
    cout << "the answer is " <<ans <<endl;
}