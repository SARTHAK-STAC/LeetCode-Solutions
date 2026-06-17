#include <bits/stdc++.h>
using namespace std;

// LeetCode 35: Search Insert Position
// Approach: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(target < nums[mid]) {
                end = mid - 1;
            }
            else if(target > nums[mid]) {
                st = mid + 1;
            }
            else {
                return mid;
            }
        }

        return st;
    }
};