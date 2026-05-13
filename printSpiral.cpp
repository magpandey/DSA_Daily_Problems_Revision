#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralMatrixTraversal(vector<vector<int>> &a, int m, int n)
{
    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;
    vector<int> ans;

    while (top <= bottom && left <= right)
    {

        for (int i = left; i <= right; i++)
        {
            ans.push_back(a[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(a[i][right]);
        }
        right--;
        if (top >= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(a[bottom][i]);
            }
            bottom--;
        }
        if (right >= left)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(a[i][left]);
            }
            left++;
        }
    }
    return ans;
}
