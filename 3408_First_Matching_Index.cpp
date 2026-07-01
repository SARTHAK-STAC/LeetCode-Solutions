#include <string>
using namespace std;

/*
LeetCode - First Matching Index

Approach:
- Traverse the string from left to right.
- Compare the current character with its corresponding
  character from the end of the string.
- Return the first index where both characters match.
- If no matching index exists, return -1.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int firstMatchingIndex(string s) {

        int n = s.length();

        for (int i = 0; i < n; i++) {

            if (s[i] == s[n - i - 1]) {
                return i;
            }
        }

        return -1;
    }
};