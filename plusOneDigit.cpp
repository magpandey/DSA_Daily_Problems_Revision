/*
Problem: Plus One on a digit array

We are given a number as digits, not as an integer.
Example:
[1,2,3] = 123 → after +1 → [1,2,4]
[9]     = 9   → after +1 → [1,0]
[9,9,9]       → [1,0,0,0]

Why we do NOT convert to a number:
Because the number may be too large to fit in int or long long.
Converting causes overflow and gives wrong answers.

Correct logic:
We simulate real addition from right to left.

Start from last digit:
- If digit < 9: just add 1 and stop.
- If digit == 9: make it 0 and carry 1 to the left.
Repeat this process.

If all digits were 9:
- Everything becomes 0
- Add a new leading 1 at the front.

This gives O(n) time and no overflow.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> plusOneDigit(vector<int>&digits){
    int n = digits.size();
    for(int i = n-1; i >= 0; i --){
        if(digit[i] != 9){
            digit[i]++;
            return digits;
        }
        else{
            digit[i] = 0;
        }
    }
    digits.insert(digits.begin(),1);//It ensures that if this else runs when all elements are 9 then 
                                    //a extra 1 is added or inserted at the beginning of the vector;
    return digits;
}
int main (){
    vector<int>nums = {9};
    vector<int>result = plusOneDigit(nums);
    cout << "The digits after add plus 1 " <<endl;
    for(auto ele : nums){
        cout << ele <<" ";
    }
    return 0;
}

//Here is wrong and naive method that beginner think about when they first try to enter the mayhem of 
//the Leetcode problems
/*
Problem: Plus One on a digit array

We are given a number as digits, not as an integer.
Example:
[1,2,3] = 123 → after +1 → [1,2,4]
[9]     = 9   → after +1 → [1,0]
[9,9,9]       → [1,0,0,0]

Why we do NOT convert to a number:
Because the number may be too large to fit in int or long long.
Converting causes overflow and gives wrong answers.

Correct logic:
We simulate real addition from right to left.

Start from last digit:
- If digit < 9: just add 1 and stop.
- If digit == 9: make it 0 and carry 1 to the left.
Repeat this process.

If all digits were 9:
- Everything becomes 0
- Add a new leading 1 at the front.

This gives O(n) time and no overflow.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> plusOneDigit(vector<int>&digits){
    int n = digits.size();
    long long num = 0;
    for(int i = 0; i < n; i ++){
        num = digits[i] + num * 10;
    }
    num = num + 1;
    vector<int>ans;
    while(num > 0){
        int d = num % 10;
        ans.push_back(d);
        num = num / 10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main (){
    vector<int>nums = {9};
    vector<int>result = plusOneDigit(nums);
    cout << "The digits after add plus 1 " <<endl;
    for(auto ele : result){
        cout << ele <<" ";
    }
    return 0;
}











