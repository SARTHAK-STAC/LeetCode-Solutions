#include <unordered_set>
#include <string>
using namespace std;

/*
LeetCode 3 - Longest Substring Without Repeating Characters

Approach:
Use the Sliding Window technique with an unordered_set.
- Expand the window by moving the right pointer.
- If a duplicate character is found, shrink the window
  by removing characters from the left until the duplicate is removed.
- Update the maximum window length after each valid expansion.

Time Complexity: O(n)
Space Complexity: O(min(n, 256))
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLen = 0;
        unordered_set<char> st;

        for (int right = 0; right < s.length(); right++) {

            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};