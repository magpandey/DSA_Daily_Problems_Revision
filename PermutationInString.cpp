#include <iostream>
#include <string>
#include <vector>
using namespace std;

// This takes O(26) time, which is constant O(1) time complexity!
bool isFreqSame(const vector<int>& freq1, const vector<int>& freq2) {
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            return false;
        }
    }
    return true;
}

bool isPermutationExists(string str1, string str2) {
    int n1 = str1.length();
    int windSize = str2.length();

    // Base Case: If the target string is bigger than the main string, 
    // it's impossible for its permutation to exist inside it.
    if (windSize > n1) return false;

    vector<int> freq1(26, 0);
    vector<int> windFreq(26, 0); // Kept outside the loop so we never delete it!

    // 1. Setup Phase: Populate freq1, and fill windFreq with the FIRST window
    for (int i = 0; i < windSize; i++) {
        freq1[str2[i] - 'a']++;
        windFreq[str1[i] - 'a']++;
    }

    // 2. Check the very first window before sliding
    if (isFreqSame(freq1, windFreq)) {
        return true;
    }

    // 3. Sliding Phase: Start 'i' from the first element OUTSIDE the initial window
    for (int i = windSize; i < n1; i++) {
        
        // Add the character entering the window from the right
        char charEntering = str1[i];
        windFreq[charEntering - 'a']++;

        // Remove the character leaving the window from the left
        char charLeaving = str1[i - windSize];
        windFreq[charLeaving - 'a']--;

        // After updating the single incoming/outgoing character, check frequencies
        if (isFreqSame(freq1, windFreq)) {
            return true;
        }
    }

    return false;
}

int main() {
    string str1 = "eidbaooo";
    string str2 = "ab";

    if (isPermutationExists(str1, str2)) {
        cout << "Yes, permutation exists!" << endl;
    } else {
        cout << "No, permutation does not exist." << endl;
    }
    return 0;
}
