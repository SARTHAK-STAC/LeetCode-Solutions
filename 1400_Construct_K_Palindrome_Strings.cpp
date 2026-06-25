#include <bits/stdc++.h>
using namespace std;

// LeetCode 1400: Construct K Palindrome Strings
// Approach: Count Odd Frequency Characters
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) {
            return false;
        }

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int oddCount = 0;

        for (int count : freq) {
            if (count % 2 == 1) {
                oddCount++;
            }
        }

        return oddCount <= k;
    }
};