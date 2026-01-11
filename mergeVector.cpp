//Its the problem where the we are given the array containing the prices of the stocks at different dates or indexes our job requires us to 
//return the maximum profit that can be obtained .We are required to demostrate the dynamic programning through this question

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> mergeInterval(vector<vector<int>> intervals){
    vector<vector<int>> result;
    sort(intervals.begin(),intervals.end());
    result.push_back(intervals[0]);

    for(int i = 1; i < intervals.size(); i++){
        int currStart = intervals[i][0];
        int currEnd = intervals[i][1];
        int lastEnd = result.back()[1];
        if(currStart <= lastEnd){
            result.back()[1]  = max(lastEnd,currEnd);
        }else{
            result.push_back(intervals[i]);
        }
    }
    return result;
}
int main() {
    vector<vector<int>>intervals = {{1,3},{2,6},{8,10},{15,18}};
    cout << "The Merged non overlapping intervals are " << endl;
    vector<vector<int>> result = mergeInterval(intervals);
    for(auto interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}












