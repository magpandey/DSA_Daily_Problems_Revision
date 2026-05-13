
#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

void rotateArrayBy(vector<vector<int>>&a, int n){
    for(int i = 0; i < n - 1;  i ++){
        for(int j = i + 1; j < n; j ++){
            swap(a[i][j], a[j][i]);
        }
    }

    for(int i = 0; i < n; i ++){
        reverse(a[i].begin(),a[i].end());
    }
}