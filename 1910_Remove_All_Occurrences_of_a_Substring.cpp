#include <bits/stdc++.h>
using namespace std;

// LeetCode 1910: Remove All Occurrences of a Substring
// Approach: Repeatedly Find and Erase
// Time Complexity: O(n²) in the worst case
// Space Complexity: O(1)

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() >0 && s.find(part)<s.length()){
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};