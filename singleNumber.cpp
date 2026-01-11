//This is fairly easy to understand problem what is happening is in array named digits there is only 
//one element which is only having the frequency one thet is it only exist once return that element
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int singleNumber(vector<int>&nums){
 int ans = 0;
 for(int i = 0; i < nums.size(); i++){
    ans = ans ^ nums[i];//this is what xor doies a^a = 0 and a^0 = a
 }
  return ans;  
}
int main(){
    vector<int>digits = {1,2,1,5,5}
    int singleDigit = singleNumber(digits)
    count << "The single Number in the array was " <<singleDigit <<endl;
    return 0;
}