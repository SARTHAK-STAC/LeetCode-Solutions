#include <bits/stdc++.h>
using namespace std;

// LeetCode 242: Valid Anagram
// Approach: Frequency Count using Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> freq;

        // Count frequency of characters in s
        for (char c : s) {
            freq[c]++;
        }

        // Decrease frequency using characters in t
        for (char c : t) {
            if (--freq[c] < 0) {
                return false;
            }
        }

        return true;
    }
};