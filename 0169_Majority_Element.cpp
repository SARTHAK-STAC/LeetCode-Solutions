#include <vector>
#include <algorithm>
using namespace std;

/*
LeetCode 169 - Majority Element

Approach:
1. Sort the array.
2. Count the frequency of consecutive elements.
3. Return the element whose frequency exceeds n/2.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int freq = 1, ans = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                freq++;
            } else {
                freq = 1;
                ans = nums[i];
            }

            if (freq > n / 2) {
                return ans;
            }
        }

        return ans;
    }
};