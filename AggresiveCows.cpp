#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to check if it's possible to place 'k' cows 
// with at least 'mid' distance between them.
bool canPlaceCows(const vector<int>& stalls, int k, int mid) {
    int count = 1; // Place the first cow in the first stall
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= mid) {
            count++;
            lastPos = stalls[i]; // Update the position of the last placed cow
        }
        if (count >= k) return true; // All cows successfully placed
    }
    return false;
}

int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> stalls(n);
    for (int i = 0; i < n; i++) cin >> stalls[i];

    // Step 1: Sort the stall positions
    sort(stalls.begin(), stalls.end());

    // Step 2: Binary search for the maximum possible minimum distance
    int low = 1; // Minimum possible distance
    int high = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, k, mid)) {
            ans = mid;    // mid is possible, try for a larger distance
            low = mid + 1;
        } else {
            high = mid - 1; // mid is too large, try smaller
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}
