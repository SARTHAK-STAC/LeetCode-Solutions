#include <bits/stdc++.h>
using namespace std;

// LeetCode 205: Isomorphic Strings
// Approach: Two Hash Maps for Bidirectional Character Mapping
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;

        for (int i = 0; i < s.size(); i++) {
            if (sToT.find(s[i]) == sToT.end()) {
                sToT[s[i]] = t[i];
            } else if (sToT[s[i]] != t[i]) {
                return false;
            }

            if (tToS.find(t[i]) == tToS.end()) {
                tToS[t[i]] = s[i];
            } else if (tToS[t[i]] != s[i]) {
                return false;
            }
        }

        return true;
    }
};