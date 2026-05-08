/*      
Union of two sorted arrays
Subscribe to TUF+

Hints
Company
Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. The elements in the union must be in ascending order.



The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.


Example 1

Input: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]

Output: [1, 2, 3, 4, 5, 7]

Explanation:

The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2

Example 2

Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]

Output: [1, 3, 4, 5, 6, 7, 8, 9]

Explanation:

The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from nums2
*/

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int>ans;

        int i = 0;
        int j = 0;


        while(i < m && j < n){
            if(nums1[i] == nums2[j]){
                if (ans.empty() || ans.back() != nums1[i]){
                ans.push_back(nums1[i]);
                i ++;
                j ++;
                }else{
                    i ++;
                    j ++;
                }
            }
            else if(nums1[i] > nums2[j]){
               if(ans.empty() || ans.back() != nums2[j]){
                 ans.push_back(nums2[j]);
                j ++;
               }else{
                j ++;
               }
            }else {
               if(ans.empty() || ans.back() != nums1[i]){
                 ans.push_back(nums1[i]);
                i ++;
               }else{
                i++;
               }
            }
        }
        while(i < m){
           if(ans.empty() || ans.back() != nums1[i]){
            ans.push_back(nums1[i]);
            i ++ ;
           }else{
            i ++;
           }
        }
        while(j < n){
            if(ans.empty() || ans.back() != nums2[j]){
            ans.push_back(nums2[j]);
            j ++;
        }else{
            j++;
        }
        }

        return ans;

    }
};