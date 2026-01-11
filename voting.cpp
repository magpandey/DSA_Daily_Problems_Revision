//Its the moores vooting algorithm
#include <iostream>
#include <vector>
using namespace std;
    int MooresVoting(vector<int>& nums){
        int freq = 1;
        int ans = nums[0];
        for (int  i = 1; i < nums.size(); i++)
        {
            int val = nums[i];
            if(val == ans){
                freq++;
            }else{
                freq--;
            }
            if(freq == 0){
                ans = nums[i];
            }
        }
        return ans;
        
    }


int main(){

     vector<int>arr = {1,2,2,2,1};
    int majorityElement = MooresVoting(arr);
    cout << "The Majority Element is " <<majorityElement << endl;
    return 0;
}